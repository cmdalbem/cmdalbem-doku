/*
UFRGS - INF01056 Desafios de Programação
GRUPO: Cristiano Medeiros Dalbem
       Luca Couto Manique Barreto
       Gustavo Garcia Valdez
Maio de 2010

                                748 - Exponentiation
                                UVa username: cmdalbem
                                Accepted @ submission #7991482
*/
#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#include <math.h>

#include <vector>
#include <algorithm>
#include <cassert>
#include <utility>
#include <functional>
#include <string>


using namespace std;

// can be any SIGNED integral type
typedef signed char Digit;


struct bignum : vector<Digit> {
    static const int base = 10;

    bool sign; // false -> positive, true -> negative
    
    bignum() : sign(false) {}
    
    bignum(long long x) : sign(x < 0)
    {
        if (x<0)
            x = -x;
        while (x > 0) {
            push_back(x % base);
            x /= base;
        }
    }
    
    bignum(const string& s)
    {
        sign = (s[0] == '-');
        resize(s.length() - sign);
        
        transform(s.begin()+sign, s.end(),
            rbegin(),
            bind2nd( minus<Digit>(), '0' )
        );
        clean();
    }
    
    bignum& clean()
    {
        reverse_iterator i = find_if(rbegin(), rend(),
            bind2nd(not_equal_to<Digit>(), Digit(0))
            );
        const int n = distance(i, rend());
        resize(n);
        if (empty())
            sign = false;
        return *this;
    }
    
    operator long long() const
    {
        long long x = 0;
        long long weight = 1;
        for (const_iterator i=begin(); i!=end(); ++i) {
            x += *i * weight;
            weight *= base;
        }
        return sign ? -x : x;
    }
    
    operator string() const
    {
        string res;
        if (sign)
            res = "-";
        if (empty())
            res = "0";
        else
            for (const_reverse_iterator i=rbegin(); i!=rend(); ++i)
                res += '0' + *i;
        return res;
    }
};

typedef bignum::iterator b_it;
typedef bignum::const_iterator b_cit;
typedef bignum::const_reverse_iterator b_crit;


// a += b, ignoring signal
void add_inplace(bignum& a, const bignum& b)
{
    a.resize( 1 + max(a.size(), b.size()) );
    b_it i;
    b_cit j;
    Digit carry = 0;
    for (i=a.begin(), j=b.begin();
         i!=a.end();
         ++i) {
        *i += (j!=b.end() ? *j++ : 0) + carry;
        if (*i >= bignum::base) {
            *i -= bignum::base;
            carry = 1;
        } else
            carry = 0;
    }
    assert(carry == 0);
    a.clean();
}

// a -= b, ignoring signal, assume a is larger than b
void subtract_inplace(bignum& a, const bignum& b)
{
    bignum x=a, y=b;

    b_it i;
    b_cit j;
    Digit borrow = 0;
    for (i=a.begin(), j=b.begin();
         i!=a.end();
         ++i) {
        *i -= (j!=b.end() ? *j++ : 0) + borrow;
        if (*i < 0) {
            *i += bignum::base;
            borrow = 1;
        } else
            borrow = 0;
    }
    assert(borrow == 0);
    a.clean();
}




bool operator<(const bignum& a, const bignum& b)
{
    if (a.sign and !b.sign)
        return true;
    if (!a.sign and b.sign)
        return false;
    // same sign
    if (a.size() != b.size())
        // a is shorter XOR a is negative
        return (a.size() < b.size()) != a.sign;
    // also same length
    pair<b_crit, b_crit> m = mismatch(a.rbegin(), a.rend(), b.rbegin());
    if (m.first == a.rend())
        return false; // a == b
    return (*m.first < *m.second) != a.sign;
}

bool operator==(const bignum& a, const bignum& b)
{
    return a.sign == b.sign and
            a.size() == b.size() and
           equal(a.begin(),  a.end(), b.begin());
}

// bring in the other relational operators
using namespace std::rel_ops;







// high-level operations

bignum& operator+=(bignum& a, const bignum& b)
{
    if (a.sign == b.sign)
        add_inplace(a, b);
    else {
        a.sign = !a.sign;
        if ((!a.sign and b < a) or (a.sign and a < b)) {
            // a has greater magnitude, a-=b won't change a's sign
            a.sign = !a.sign;
            subtract_inplace(a, b);
        } else {
            bignum bb = b;
            subtract_inplace(bb, a);
            a.swap(bb);
        }
    }
    return a;
}

bignum& operator-=(bignum& a, const bignum& b)
{
    if (!a.empty())
        a.sign = !a.sign;
    operator+=(a, b);
    if (!a.empty())
        a.sign = !a.sign;
    return a;
}

bignum operator+(const bignum& a, const bignum& b)
{
    bignum c(a);
    return c += b;
}
bignum operator-(const bignum& a, const bignum& b)
{
    bignum c(a);
    return c -= b;
}

bignum operator-(const bignum& a)
{
    bignum b = a;
    b.sign = !a.sign;
    return b;
}

bignum operator*(const bignum& a, const bignum& b)
{
    if (a.empty() or b.empty())
        return bignum();

    if (a.size() + b.size() < 19) {
        long long x = a;
        long long y = b;
        return x*y;
    }
    
    const unsigned n = max(a.size(), b.size());
    const unsigned h = n/2;
    bignum w, x; // a = 10^h * w + x
    bignum y, z; // b = 10^h * y + z
    b_cit ha, hb;
    ha = (h > a.size()) ? a.end() : a.begin()+h;
    hb = (h > b.size()) ? b.end() : b.begin()+h;

    x.assign(a.begin(), ha);
    w.assign(ha, a.end());
    x.clean();
    w.clean();
    
    z.assign(b.begin(), hb);
    y.assign(hb, b.end());
    z.clean();
    y.clean();
    
    
    bignum p = w*y;
    bignum q = x*z;
    bignum r = (w+x) * (y+z);


    // result = 10^(2*h) * p + 10^h * (r-p-q) + q
    bignum result;
    result.resize(a.size() + b.size());
    fill(result.begin(), result.begin()+2*h, 0);
    copy(p.begin(), p.end(), result.begin() + 2*h);
    result.clean();    
    
    r -= p+q;

    // p = 10^h * r
    p.resize(r.size() + h);
    fill(p.begin(), p.begin()+h, 0);
    copy(r.begin(), r.end(), p.begin()+h);
    p.clean();

    result += q;

    result += p;
        
    result.sign = a.sign != b.sign;
    return result;
}

bignum& operator*=(bignum& a, const bignum& b)
{
    a = a*b;
    return a;
}

bignum& operator<<=(bignum& b, int i)
{
        b.resize(b.size()+1);
        copy(b.begin(), b.end()-1, b.begin()+1);
        b[0] = 0;
        return b;
}

bignum& operator/=(bignum& x, const bignum& y)
{
        bignum temp;
        temp.resize(x.size());

        temp.sign = x.sign != y.sign;

        bignum row;
        bignum ty = y;
        ty.sign = false;
        bignum one = 1;

        for (int i=x.size()-1; i>=0; --i) {
                row <<= 1;
                row[0] = x[i];
                row.clean();
                while (ty <= row) {
                        ++temp[i];
                        row -= ty;
                }
        }
        return (x = temp).clean();
}

bignum operator/(const bignum& a, const bignum& b)
{
    bignum c = a;
    c /= b;
    return c;
}





#include <iostream>
#include <iterator>
#include <string>
#include <cctype>

ostream& operator<<(ostream& o, const bignum& b)
{
    if (b.sign)
        o << "-";
    if (b.empty())
        o << "0";
    else
        copy(b.rbegin(), b.rend(), ostream_iterator<int>(o));
    return o;
}

istream& operator>>(istream& i, bignum& b)
{
    char c;
    if (i >> c) {
        if (c=='-') {
            b.sign = true;
            if (!i.get(c))
                goto end;
        } else {
            b.sign = false;
            if (c=='+') {
                if (!i.get(c))
                    goto end;
            } else if (!isdigit((unsigned char)c)) {
                i.putback(c);
                i.setstate(istream::failbit);
                goto end;
            }
        }
        b.clear();
        do {
            b.push_back(c - '0');
            if (!i.get(c))
                break;
        } while ( isdigit((unsigned char)c) );
        if (i.good())
            i.putback(c);
        reverse(b.begin(), b.end());
        b.clean();
    }
end:
    return i;
}



		

int main()
{
	string real;
	int n;
	
	while( cin >> real >> n )
	{
		bignum num;
		bignum orig;
		int houses=0;
		int orighouses;
		
		int i=real.length()-1;
		while(real[i]=='0')
			i--;
		
		real.resize(i+1);
		
		for(;i>0 && real[i]!='.';i--)
			houses++;
		
		num=0;
		int j=0;
		for(int k=0;k<real.length();k++,j++)
			if(real[k]!='.')
				num += (real[k]-48) * pow(10,real.length()-2-j);
			else
				j--;
		
		//cout<<houses<<"of ";
		//cout<<real<<"("<<houses<<")"<<" -> "<<num<<" -> "<<endl;
		
		orig = num;
		orighouses=houses;
	
		//exponentiation
		for( int i=1;i<n;i++ )
		{
			houses+=orighouses;
			num *= orig;
		}
		
	
		bignum::reverse_iterator rit;

		int numbersize=num.size();
		
		
		if( real[0] == '0' ) //special case where real < 0,5
		{
			cout<<".";
			for(int k=0;k<houses-num.size();k++)
				cout<<0;
			cout<<num<<endl;
		}
		else //general case
		{
			int k =1;
			for(rit=num.rbegin(); rit<num.rend(); rit++, k++)
				if(k == numbersize-houses+1)
				{
					cout<<".";
					rit--;
				}
				else
					cout<<(int)*rit;
			cout<<endl;
		}
		
	}
	
	
}

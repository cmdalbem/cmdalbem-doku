package trab

abstract class Tipo
case class Inteiro() extends Tipo
case class Boleano() extends Tipo
case class Unidade() extends Tipo
case class Funcao(t1: Tipo, t2: Tipo) extends Tipo
case class Refer(t: Tipo) extends Tipo
case class Var() extends Tipo //qual a funcionalidade desse tipo?

abstract class Expr
// Fun�oes de valores
case class N (n:Int) extends Expr
case class B (b:Boolean) extends Expr
case class U (u:Unit) extends Expr
case class Skip() extends Expr
case class Fn (s:String, t: Tipo, e: Expr) extends Expr
// Fun��es de diretivas
case class Sum (e1: Expr, e2: Expr) extends Expr
case class Prod (e1: Expr, e2: Expr) extends Expr
case class Cmp (e1: Expr, e2: Expr) extends Expr
case class If (e1: Expr, e2: Expr, e3: Expr) extends Expr
case class Seq (e1: Expr, e2: Expr) extends Expr
case class Asg (l: String, e: Expr) extends Expr
case class Deref (l: String) extends Expr
case class While (e1: Expr, e2: Expr) extends Expr
case class App (e1: Expr, e2: Expr) extends Expr
case class X (s:String) extends Expr
case class Let (s:String, t: Tipo, e1: Expr, e2: Expr) extends Expr
case class LetRec (s:String, f: Funcao, fn: Fn, e2: Expr) extends Expr
//case class LetRec (s1: String, f: Funcao, s2: String, e1: Expr, e2: Expr) extends Expr


class L2Interpreter {

//////////////////////////////
//// Verificador de Tipos ////
//////////////////////////////
//
//
def typecheck(e:Expr, gamma: List[(String,Tipo)]) : Option[Tipo] = e match {
case N (_) => Some(Inteiro())
case B (_) => Some(Boleano())
case U (_) => Some(Unidade())

case Sum (e1, e2) => (typecheck(e1,gamma), typecheck(e2,gamma)) match {
    case (Some(Inteiro()), Some(Inteiro())) => Some(Inteiro())
    case _ => None
}

case Prod (e1, e2) => (typecheck(e1,gamma), typecheck(e2,gamma)) match {
    case (Some(Inteiro()), Some(Inteiro())) => Some(Inteiro())
    case _ => None
}

case Cmp (e1, e2) => (typecheck(e1,gamma), typecheck(e2,gamma)) match {
    case (Some(Inteiro()), Some(Inteiro())) => Some(Boleano())
    case _ => None
}

case If (e1, e2, e3) => typecheck(e1,gamma) match {
    case Some(Boleano()) =>
      val Tipo_e2: Option[Tipo] = typecheck(e2,gamma)
      val Tipo_e3: Option[Tipo] = typecheck(e3,gamma)
      if((Tipo_e2!=None)&&(Tipo_e3!=None)&&(Tipo_e2==Tipo_e3)){
        Tipo_e2
      }
      else{
        None
      }
    case _ => None
}

case Asg (l, e) => typecheck(e,gamma) match {
    case Some(Inteiro()) => Some(Unidade())
    case _ => None
}

case Deref (l) => Some(Inteiro())

case Skip() => Some(Unidade())

case Seq (e1, e2) => typecheck(e1,gamma) match {
    case Some(Unidade()) =>
      val Tipo_e2: Option[Tipo] = typecheck(e2,gamma)
      if(Tipo_e2!=None){
        Tipo_e2
      }
      else{
        None
      }
    case _ => None
}

case While (e1, e2) => (typecheck(e1,gamma), typecheck(e2,gamma)) match {
    case (Some(Boleano()), Some(Unidade())) => Some(Unidade())
    case _ => None
}

case X (s) =>
  val variable: Option[(String, Tipo)] = gamma.find {e => e._1 == s}
  if(variable != None)
    Some(variable.get._2)
  else
    None

case Fn (s, t, e) =>
  val tipo_e: Option[Tipo] = typecheck(e,gamma.::(s,t))
  if(tipo_e != None)
    Some(Funcao(t,tipo_e.get))
  else
    None

case App (e1, e2) => typecheck(e1,gamma) match{
    case Some(Funcao(t1: Tipo, t2: Tipo)) =>
      val tipo_e2 : Option[Tipo] = typecheck(e2,gamma)
      if(tipo_e2.get == t1)
        Some(t2)
      else
        None
    case _ => None
}

case Let (s, t, e1, e2) => typecheck(e1,gamma) match {
    case Some(t) =>
      typecheck(e2,gamma.::(s,t))
    case _ => None
}

/*case LetRec (s1, f, s2, e1, e2) => typecheck(e2,(s1,f) :: gamma.:: (s2,f.t1)) match {
    case Some(f.t2) =>
      typecheck(e2,gamma.:: (s1,f))
    case _ => None
}*/
case LetRec (s1, f, fn, e2) => typecheck(e2,(s1,f) :: gamma.:: (fn.s,f._1)) match {
    case Some(f.t2) =>
      typecheck(e2,gamma.:: (s1,f))
    case _ => None
}

}




///////////////////
///// Avaliacao ///
///////////////////
//
//
def isvalue(e:Expr) : Boolean = e match {
case N(_) => true
//case X(_) => true  ???pq essa parte t� comentada se t� certa???
case B(_) => true
case U(_) => true
case Fn(_,_,_) => true
case Skip() => true
case X(_) => true
case _ => false
}

type Endereco = String

type Memoria = List[(Endereco,Int)]

def step(e: Expr, sigma: Memoria): Option[(Expr, Memoria)] = e match {
// valores (folhas da árvore de resolução)
case N(_) => None
case B(_) => None
case U(_) => None
case Fn(_,_,_) => None
case Skip() => None
case X(_) => None

// funções
case Sum (e1, e2) => (e1,e2) match{
    case (N(n1),N(n2)) => Some ((N(n1 + n2), sigma))
    case (e1, e2) =>
      if (isvalue(e1)) {
        step(e2,sigma) match {
          case Some((e2lin, sigmalin)) => Some((Sum(e1,e2lin), sigmalin))
          case None => None }
      }
      else {
        step(e1, sigma) match {
          case Some((e1lin, sigmalin)) => Some((Sum(e1lin, e2), sigmalin))
          case None => None }
      }
  }

case Prod (e1, e2) => (e1,e2) match{
    case (N(n1),N(n2)) => Some ((N(n1 * n2), sigma))
    case (e1, e2) =>
      if (isvalue(e1)) {
        step(e2,sigma) match {
          case Some((e2lin, sigmalin)) => Some((Prod(e1,e2lin), sigmalin))
          case None => None }
      }
      else {
        step(e1, sigma) match {
          case Some((e1lin, sigmalin)) => Some((Prod(e1lin, e2), sigmalin))
          case None => None }
      }
  }

case Cmp (e1, e2) => (e1,e2) match{
    case (N(n1),N(n2)) => Some ((B(n1 >= n2), sigma))
    case (e1, e2) => if (isvalue(e1)) {
        step(e2,sigma) match {
          case Some((e2lin, sigmalin)) => Some((Cmp(e1,e2lin), sigmalin))
          case None => None }
      }
      else {
        step(e1, sigma) match {
          case Some((e1lin, sigmalin)) => Some((Cmp(e1lin, e2), sigmalin))
          case None => None }
      }
  }

case If(B(true), e2, e3) => Some(e2, sigma)
case If(B(false), e2, e3) => Some(e3, sigma)
case If(e1, e2, e3) => (e1,e2,e3) match {
    //case (B(true), e2, e3) => Some(e2, sigma)
    //case (B(false), e2, e3) => Some(e3, sigma)
    case (e1,e2,e3) => step(e1,sigma) match {
        case Some((e1lin,sigmalin)) => Some((If(e1lin,e2,e3),sigmalin))
        case None => None }
    }

case Seq(Skip(),e2) => Some(e2, sigma)
case Seq(e1,e2) => (e1,e2) match {
    //case(U(e1),e2) => Some(e2,sigma)
    case(e1,e2) => step(e1,sigma) match {
        case Some((e1lin,sigmalin)) => Some( Seq(e1lin,e2),sigmalin )
        case None => None }
    }

case Asg(l,e) => (l,e) match {
    case (l,N(n1)) =>
      {
        val value = sigma.find(s => s._1 == l)
        if(value != None) {
			val sigmalin = (l,n1) :: sigma.remove(s => s._1 == l)
			Some(Skip(),sigmalin)
		}
        else
          None

      }
    case (l,e) => step(e,sigma) match {
        case Some((elin,sigmalin)) => Some( Asg(l,elin),sigmalin )
        case None => None
    }
}

case Deref (l) => (l) match {
    case (l) =>
      {
        val value = sigma.find(s => s._1 == l)
        if(value != None)
          Some(N(value.get._2),sigma)
        else
          None
      }
}

case While(e1,e2) => Some((
                          If( e1, Seq( e2, While(e1,e2)), Skip() ) ,
                          sigma))

case App (e1,e2) => (e1,e2) match {
      case (Fn(s,t1,e1),n1) => {
          if (isvalue(n1))
            Some(replace(n1,s,e1),sigma)
          else
            None
      }
      case (e1,e2) =>
        if (isvalue(e1)) {
          step(e2,sigma) match {
            case Some((e2lin, sigmalin)) => Some((App(e1,e2lin), sigmalin))
            case None => None }
        }
        else {
          step(e1, sigma) match {
            case Some((e1lin, sigmalin)) => Some((App(e1lin, e2), sigmalin))
            case None => None }
        }
}

case Let (s,t,e1,e2) => {
    if (isvalue(e1))
      Some(replace(e1,s,e2),sigma)
    else
      step(e1,sigma) match {
        case Some((e1lin, sigmalin)) => Some(Let(s,t,e1lin,e2), sigmalin)
        case None => None
      }
}

//case class LetRec (s1: String, f: Funcao, s2: String, e1: Expr, e2: Expr) extends Expr
case LetRec (s,f,s1,e1,e2) => Some(
                                    replace( Fn( s1,
                                                 f.t1,
                                                 LetRec( s,f,s1,e1,e1)
                                               ),
                                             s,
                                             e2
                                            ),
                                    sigma
                                  )
}0

/*case LetRec (s,f,e1,e2) => (s,f,e1,e2) match {
    case (s, f, Fn(s1,t1,ef), e2) /*if(f._1 == t1)*/ => Some( replace( Fn(s1,t1,LetRec(s,f,Fn(s1,t1,ef),ef))  , s, e2 ),
                                                              sigma)
}*/

def eval(e: Expr, sigma:Memoria): Option[(Expr, Memoria)] = step(e,sigma) match {
  case None => Some((e,sigma))
  case Some((elin, sigmalin)) => eval(elin, sigmalin) }

///////////////////////////////////////////////////////////////////
/////adicionei a parte de substitui��o tal como tem nos slides/////
/////ela � usada pra substituir o x na parte das fun��es na L2/////
//////////deem uma olhada l� pra entenderem a utilidade////////////
////////////////////substitui e por v//////////////////////////////
///////////////////////////////////////////////////////////////////
def replace(v: Expr, s: String, e: Expr): Expr = e match {

case X(s1) if (s == s1) => v
case N(n) => N(n)
case B(b) => B(b)
case Sum(e1, e2) => Sum(replace(v,s,e1),replace(v,s,e2))
case Prod(e1, e2) => Prod(replace(v,s,e1),replace(v,s,e2))
case Cmp (e1, e2) => Cmp(replace(v,s,e1),replace(v,s,e2))
case If (e1, e2, e3) => If(replace(v,s,e1),replace(v,s,e2),replace(v,s,e3))
case Asg (s1, e1) => Asg(s1,replace(v,s,e1))
case Seq (e1, e2) => Seq(replace(v,s,e1),replace(v,s,e2))
case While (e1, e2) => While(replace(v,s,e1),replace(v,s,e2))
case App (e1, e2) => App(replace(v,s,e1),replace(v,s,e2))
case Fn (s1, t, e1) if s != s1 => Fn(s1, t, replace(v,s,e1))
case Let (s1, t, e1, e2) if s != s1 => Let(s1, t, replace(v, s, e1),replace(v, s, e2))
case LetRec (s1, t, e1, e2) if s != s1 => LetRec(s1, t,replace(v, s, e1),replace(v, s, e2))
//case LetRec (s1, t, s2, e1, e2) if s != s1 => LetRec(s1, t,s2, replace(v, s, e1),replace(v, s, e2))
case _ => e

  }

}


object Main {

  type Memoria = List[(String,Int)]

  def main(args: Array[String]): Unit = {

    /******************************************************************/
    // (5+10) + (100+10);
    /* val ex:Expr = Sum(Sum(N(5),N(10)), Sum(N(10),N(100)))*/


    // l1 := 2+2;
    // 5+2;
    /* val ex: Expr = Seq( Asg( "l1",Sum(N(2),N(2)) ),
                        Sum(N(5),N(2) ))*/


    // while( !l1 >= 1 ) {
    //   l1 := l1 - 1;
    //   l2 := l2 + 1;
    // }
    /* val ex: Expr = While( Cmp(Deref("l1"),N(1)),
                          Seq( Asg("l1",Sum(Deref("l1"),N(-1))),
                               Asg("l2",Sum(Deref("l2"),N(1))))
                        )*/


    // (2+3) + (3>=true)
    /* val ex: Expr = Sum( Sum(N(2),N(3)), Cmp(N(3),B(true)) ) */


    // (fn x:Int => x+10) 10
    /* val ex: Expr = App( Fn("x", Inteiro(), Sum(X("x"),N(10))), N(10) ) */


    // let x: int->int =
    //        fn y:Int => y+10
    // in
    //    x 10
    // end
    /*val ex: Expr = Let( "x", Funcao(Inteiro(),Inteiro()), Fn("y", Inteiro(), Sum(X("y"),N(10))), App(X("x"),N(10)) ) */

    // let rec fat: int->int =
    //      fn x: int => if 0>=x thn 1 else x*fat(x-1)
    // in
    //      fat 5
    // end
    val ex: Expr = LetRec( "fat", Funcao(Inteiro(),Inteiro()),
                                Fn( "x",
                                	Inteiro(),
		                            If( Cmp(N(0),X("x")),
		                                  /*IF*/ N(1),
		                                  /*ELSE*/ Prod( X("x"), App(X("fat"), Sum(X("x"),N(-1)) ))
		                              )
		                          ),
                            /*IN*/ App(X("fat"),N(5))
                          )



    /******************************************************************/

    val sigma: Memoria = List(("l1",5), ("l2",0))
    val gamma: List[(String,Tipo)] = List(("x",Inteiro()), ("y", Inteiro()))
    val interpretador = new L2Interpreter()
    val tipo = interpretador.typecheck(ex,gamma)
    val res = interpretador.eval(ex,sigma)

    println()
    println("Expressao: " + ex)
    println()
    println("Tipo: " + tipo)

    res match {
        case Some((exp_final, sigma_final)) =>
          println("Avaliacao: " + exp_final)
          println(sigma_final)
    }
  }
}

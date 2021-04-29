lvalue→ id
{ ... $lvalue = lvalue_expr(sym); }
lvalue→ local id
{ ... $lvalue = lvalue_expr(sym); }
lvalue→ global id
{ ... $lvalue = lvalue_expr(sym); }


expr*lvalue_expr (symbol *sym){

  assert (sym);
  expr*e =(expr*)malloc (sizeof(expr));
  memset(e,0,sizeof(expr));

e->next =(expre*)0;
e->sym = sym;

switch (sym->type){

case var_s:			e->type=var_e;break;
case programfunc_s: 		e->type=programfunc_e;break;
case libaryfunc_s:	       e->type=libaryfunc_e;break;
default:assert(0);


}

return e;
}

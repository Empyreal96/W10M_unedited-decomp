// _PnpCtxRegCreateTree 
 
int __fastcall PnpCtxRegCreateTree(int *a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r0

  if ( a1 )
    v6 = *a1;
  else
    v6 = 0;
  return SysCtxRegCreateTree(v6, a2, a3, a4, a5, a6);
}

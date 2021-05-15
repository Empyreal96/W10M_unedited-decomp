// _PnpCtxRegOpenKey 
 
int __fastcall PnpCtxRegOpenKey(int *a1, int a2, int a3, int a4)
{
  int v4; // r0

  if ( a1 )
    v4 = *a1;
  else
    v4 = 0;
  return SysCtxRegOpenKey(v4, a2, a3, a4);
}

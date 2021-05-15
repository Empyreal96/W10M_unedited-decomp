// _PnpCtxRegQueryInfoKey 
 
int __fastcall PnpCtxRegQueryInfoKey(int a1, int a2, int a3, int a4, int a5)
{
  return RegRtlQueryInfoKey(a2, a3, 0, a5);
}

// _PnpCtxRegSetValue 
 
int __fastcall PnpCtxRegSetValue(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return RegRtlSetValue(a2, a3, a4, a5, a6);
}

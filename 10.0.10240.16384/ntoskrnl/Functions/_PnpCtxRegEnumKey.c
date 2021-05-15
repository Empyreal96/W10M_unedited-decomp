// _PnpCtxRegEnumKey 
 
int __fastcall PnpCtxRegEnumKey(int a1, int a2, int a3, int a4, unsigned int *a5)
{
  return RegRtlEnumKey(a2, a3, a4, a5);
}

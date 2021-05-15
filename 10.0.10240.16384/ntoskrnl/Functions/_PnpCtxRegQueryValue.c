// _PnpCtxRegQueryValue 
 
int __fastcall PnpCtxRegQueryValue(int a1, int a2, unsigned __int16 *a3, _DWORD *a4, int a5, unsigned int *a6)
{
  return RegRtlQueryValue(a2, a3, a4, a5, a6);
}

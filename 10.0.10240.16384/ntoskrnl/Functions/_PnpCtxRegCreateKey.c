// _PnpCtxRegCreateKey 
 
int __fastcall PnpCtxRegCreateKey(int *a1, int a2, unsigned __int16 *a3, int a4, int a5, int a6, int a7, int a8)
{
  int result; // r0
  int v9; // r0

  if ( a1 && (v9 = *a1) != 0 )
    result = RegRtlCreateKeyTransacted(a2, a3, 0, a5, a6, 0, a7, a8, *(_DWORD *)(v9 + 4));
  else
    result = sub_7C7564();
  return result;
}

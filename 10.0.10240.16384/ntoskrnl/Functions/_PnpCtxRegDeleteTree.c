// _PnpCtxRegDeleteTree 
 
int __fastcall PnpCtxRegDeleteTree(int *a1, int a2, unsigned __int16 *a3)
{
  int result; // r0
  int v4; // r0

  if ( a1 && (v4 = *a1) != 0 )
    result = RegRtlDeleteTreeInternal(a2, a3, *(_DWORD *)(v4 + 4), 0);
  else
    result = sub_7F0DAC();
  return result;
}

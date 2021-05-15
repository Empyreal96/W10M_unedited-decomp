// _PnpCtxRegDeleteKey 
 
int __fastcall PnpCtxRegDeleteKey(int *a1, int a2, unsigned __int16 *a3)
{
  int v4; // r0
  int v5; // r2

  if ( a1 && (v4 = *a1) != 0 )
    v5 = *(_DWORD *)(v4 + 4);
  else
    v5 = 0;
  return RegRtlDeleteKeyTransacted(a2, a3, v5);
}

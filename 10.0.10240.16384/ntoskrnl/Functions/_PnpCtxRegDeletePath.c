// _PnpCtxRegDeletePath 
 
int __fastcall PnpCtxRegDeletePath(int a1, int a2, int a3, int a4)
{
  int v5; // r3

  if ( a1 && *(_DWORD *)a1 )
    v5 = *(_DWORD *)(*(_DWORD *)a1 + 4);
  else
    v5 = 0;
  return RegRtlDeletePathInternal(a2, a3, a4, v5);
}

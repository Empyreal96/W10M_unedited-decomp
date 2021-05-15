// KeReadyThread 
 
int __fastcall KeReadyThread(int a1)
{
  int v2; // r5
  int result; // r0
  int v4; // r0

  v2 = *(_DWORD *)(a1 + 116);
  if ( (*(_DWORD *)(v2 + 116) & 7) == 0 || (v4 = KfRaiseIrql(2), (result = KiInSwapSingleProcess(a1, v2, v4)) == 0) )
    result = KiFastReadyThread(a1);
  return result;
}

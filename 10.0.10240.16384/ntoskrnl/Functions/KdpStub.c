// KdpStub 
 
int __fastcall KdpStub(char a1, char a2, _DWORD *a3, int a4)
{
  int v6; // r4
  int result; // r0

  if ( *a3 == -2147483645 && a3[4] && ((v6 = a3[5], v6 == 3) || v6 == 4 || v6 == 5 || v6 == 1) )
  {
    *(_DWORD *)(a4 + 64) += 2;
    result = 1;
  }
  else if ( !KdPitchDebugger
         && KdAutoEnableOnEvent
         && KdPreviouslyEnabled
         && !KdDebuggerEnabled
         && KdEnableDebugger() >= 0
         && KdDebuggerEnabled )
  {
    result = KdpTrap(a1, a2);
  }
  else
  {
    result = 0;
  }
  return result;
}

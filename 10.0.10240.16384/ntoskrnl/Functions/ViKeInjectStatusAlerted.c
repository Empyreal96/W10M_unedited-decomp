// ViKeInjectStatusAlerted 
 
BOOL __fastcall ViKeInjectStatusAlerted(int a1, int a2)
{
  _DWORD *v2; // r4
  BOOL result; // r0

  result = 0;
  if ( a1 )
  {
    v2 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    if ( PsInitialSystemProcess )
    {
      if ( v2 != (_DWORD *)PsInitialSystemProcess
        && v2 != (_DWORD *)PsIdleProcess
        && VfFaultsInjectResourceFailure(0, a2, (int)&PsIdleProcess, PsIdleProcess)
        && !VfUtilIsLocalSystem(v2) )
      {
        result = 1;
      }
    }
  }
  return result;
}

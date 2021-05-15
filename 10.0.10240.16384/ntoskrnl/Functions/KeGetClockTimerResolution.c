// KeGetClockTimerResolution 
 
_DWORD *__fastcall KeGetClockTimerResolution(_DWORD *result, _DWORD *a2)
{
  *a2 = KeTimeIncrement;
  *result = KiLastRequestedTimeIncrement;
  return result;
}

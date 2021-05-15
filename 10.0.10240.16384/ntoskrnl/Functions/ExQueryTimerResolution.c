// ExQueryTimerResolution 
 
_DWORD *__fastcall ExQueryTimerResolution(_DWORD *result, _DWORD *a2, _DWORD *a3)
{
  *result = KeMaximumIncrement;
  *a2 = KeMinimumIncrement;
  *a3 = KeTimeIncrement;
  return result;
}

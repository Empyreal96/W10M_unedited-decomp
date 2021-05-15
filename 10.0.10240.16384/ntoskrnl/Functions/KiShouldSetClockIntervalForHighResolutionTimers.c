// KiShouldSetClockIntervalForHighResolutionTimers 
 
BOOL __fastcall KiShouldSetClockIntervalForHighResolutionTimers(__int64 a1, unsigned __int64 a2)
{
  return !KiClockIntervalIsSetForHighResolutionTimers && a2 < a1 + (unsigned __int64)(unsigned int)KeMaximumIncrement;
}

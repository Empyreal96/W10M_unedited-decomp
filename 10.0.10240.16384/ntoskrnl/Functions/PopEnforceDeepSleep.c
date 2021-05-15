// PopEnforceDeepSleep 
 
int __fastcall PopEnforceDeepSleep(int a1)
{
  unsigned __int64 v2; // r2
  unsigned __int64 v3; // kr00_8
  int result; // r0
  int v5; // r1
  int v6; // r1

  __dmb(0xBu);
  v2 = KiMaxDynamicTickDuration;
  do
    v3 = __ldrexd(&PopMaxDynamicTickDurationOriginalValue);
  while ( !v3 && __strexd(v2, &PopMaxDynamicTickDurationOriginalValue) );
  __dmb(0xBu);
  result = PopDeepSleepPhaseEngaged();
  if ( a1 )
  {
    if ( !result )
    {
      KeSetMaxDynamicTickDuration((unsigned int)(a1 * (_DWORD)dword_989680));
      PopDeepSleepEnforced = 1;
      return PopControlDeepSleep(1, v5);
    }
  }
  else if ( !result )
  {
    return result;
  }
  if ( PopDeepSleepEnforced )
  {
    KeSetMaxDynamicTickDuration(PopMaxDynamicTickDurationOriginalValue);
    result = PopControlDeepSleep(0, v6);
    PopDeepSleepEnforced = 0;
  }
  return result;
}

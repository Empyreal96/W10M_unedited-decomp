// WdipSemWriteTimeoutEvent 
 
int __fastcall WdipSemWriteTimeoutEvent(int a1, int a2, int a3, int a4)
{
  int result; // r0

  if ( a1 && a3 )
    result = WdipSemWriteEvent(WdipSemRegHandle, MEMORY[0x61CB14], (int)WDI_SEM_EVENT_SCENARIO_TIMEOUT, a3);
  else
    result = -1073741811;
  return result;
}

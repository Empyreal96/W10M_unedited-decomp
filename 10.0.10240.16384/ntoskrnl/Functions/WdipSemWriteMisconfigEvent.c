// WdipSemWriteMisconfigEvent 
 
int __fastcall WdipSemWriteMisconfigEvent(int a1)
{
  int result; // r0

  if ( a1 )
    result = WdipSemWriteEvent(WdipSemRegHandle, MEMORY[0x61CB14], (int)WDI_SEM_EVENT_INIT_MISCONFIG, 0);
  else
    result = -1073741811;
  return result;
}

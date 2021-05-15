// WdipSemWriteScenarioLimitExceededEvent 
 
int __fastcall WdipSemWriteScenarioLimitExceededEvent(int a1, int a2)
{
  int result; // r0

  if ( a1 && a2 )
    result = WdipSemWriteEvent(WdipSemRegHandle, dword_61CB14, a1, 0);
  else
    result = -1073741811;
  return result;
}

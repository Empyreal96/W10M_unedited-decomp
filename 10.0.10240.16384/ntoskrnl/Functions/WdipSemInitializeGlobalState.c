// WdipSemInitializeGlobalState 
 
_BYTE *WdipSemInitializeGlobalState()
{
  _BYTE *result; // r0

  WdipSemPushLock = 0;
  WdipSemRegHandle = 0;
  dword_61CB14 = 0;
  WdipSemEnabled = 0;
  WdipSemTimeoutEnabled = 0;
  WdipSemTimeoutValue = 0;
  WdipSemDisabledScenarioTable = 0;
  WdipDiagLoggerId = 0;
  WdipContextLoggerId = 0;
  memset(&WdipSemPool, 0, 72);
  WdipSemPool = (int)&WdipSemPool;
  dword_61CAC4 = (int)&WdipSemPool;
  dword_61CAD0 = 0;
  memset(byte_61CAD8, 0, sizeof(byte_61CAD8));
  memset(WdipSemScenarioTable, 0, 260);
  memset(WdipSemProviderTable, 0, 4104);
  dword_61C764 = 0;
  WdipSemEnabledInstanceTable = (int)&WdipSemEnabledInstanceTable;
  dword_61B744 = (int)&WdipSemEnabledInstanceTable;
  dword_61B748 = 0;
  dword_61B74C = 0;
  result = WdipSemClearFrequentScenarioTable();
  WdipSemInitialized = 1;
  return result;
}

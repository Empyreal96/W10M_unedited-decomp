// WdipSemShutdown 
 
int WdipSemShutdown()
{
  _BYTE *v0; // r0

  WdipSemEnabled = 0;
  WdipSemTimeoutEnabled = 0;
  WdipSemTimeoutValue = 600;
  WdipSemDisabledScenarioTable = 0;
  WdipSemDisableAllProviders();
  WdipDiagLoggerId = 0;
  WdipContextLoggerId = 0;
  memset(WdipSemScenarioTable, 0, 260);
  memset(WdipSemProviderTable, 0, 4104);
  dword_61C764 = 0;
  WdipSemEnabledInstanceTable = (int)&WdipSemEnabledInstanceTable;
  dword_61B744 = (int)&WdipSemEnabledInstanceTable;
  dword_61B748 = 0;
  dword_61B74C = 0;
  v0 = WdipSemClearFrequentScenarioTable();
  return WdipSemFreePool(v0);
}

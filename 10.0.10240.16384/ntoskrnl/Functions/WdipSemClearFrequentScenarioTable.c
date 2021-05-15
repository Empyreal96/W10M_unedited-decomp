// WdipSemClearFrequentScenarioTable 
 
_BYTE *WdipSemClearFrequentScenarioTable()
{
  _BYTE *result; // r0

  result = memset(WdipSemFrequentScenarioTable, 0, 520);
  dword_61CAA4 = 0;
  return result;
}

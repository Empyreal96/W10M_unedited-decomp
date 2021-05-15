// PfSnBuildScenarioEventDescriptors 
 
unsigned int __fastcall PfSnBuildScenarioEventDescriptors(unsigned __int16 *a1, int a2, _WORD *a3, _DWORD *a4)
{
  unsigned int result; // r0
  int v9; // r2

  result = wcslen(a1);
  *a3 = result;
  *a4 = a3;
  a4[1] = 0;
  a4[2] = 2;
  a4[3] = 0;
  v9 = (unsigned __int16)*a3;
  a4[4] = a1;
  a4[5] = 0;
  a4[7] = 0;
  a4[6] = 2 * v9;
  a4[8] = a1 + 30;
  a4[9] = 0;
  a4[10] = 4;
  a4[11] = 0;
  a4[12] = a2;
  a4[13] = 0;
  a4[14] = 4;
  a4[15] = 0;
  return result;
}

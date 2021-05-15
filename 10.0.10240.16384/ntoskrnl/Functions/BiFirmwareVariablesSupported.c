// BiFirmwareVariablesSupported 
 
int BiFirmwareVariablesSupported()
{
  int result; // r0
  int v1; // r4
  char v2[8]; // [sp+18h] [bp-50h] BYREF
  int v3[5]; // [sp+20h] [bp-48h] BYREF
  __int16 v4; // [sp+34h] [bp-34h]
  __int16 v5; // [sp+36h] [bp-32h]
  char v6; // [sp+38h] [bp-30h]
  char v7; // [sp+39h] [bp-2Fh]
  char v8; // [sp+3Ah] [bp-2Eh]
  char v9; // [sp+3Bh] [bp-2Dh]
  char v10; // [sp+3Ch] [bp-2Ch]
  char v11; // [sp+3Dh] [bp-2Bh]
  char v12; // [sp+3Eh] [bp-2Ah]
  char v13; // [sp+3Fh] [bp-29h]
  int v14; // [sp+4Ch] [bp-1Ch]

  v3[4] = -1947934879;
  v4 = -27702;
  v5 = 4562;
  v6 = -86;
  v7 = 13;
  v8 = 0;
  v9 = -32;
  v10 = -104;
  v11 = 3;
  v12 = 43;
  v13 = -116;
  if ( BiOpenKeyNonBcd(0, L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\BCD", 131097, v3) < 0
    || (RtlInitUnicodeString((unsigned int)v2, L"ForceVariableCheck"), v1 = ZwQueryValueKey(), ZwClose(), v1)
    || v14 )
  {
    result = sub_81351C();
  }
  else
  {
    result = 1;
  }
  return result;
}

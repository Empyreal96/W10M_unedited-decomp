// CmIsLastKnownGoodBoot 
 
BOOL CmIsLastKnownGoodBoot()
{
  int v1; // [sp+8h] [bp-90h] BYREF
  int v2; // [sp+Ch] [bp-8Ch] BYREF
  int v3[2]; // [sp+10h] [bp-88h] BYREF
  int v4[32]; // [sp+18h] [bp-80h] BYREF

  v2 = 0;
  v3[0] = 0;
  v1 = 0;
  v4[0] = 0;
  v4[1] = 32;
  v4[2] = (int)L"Current";
  v4[3] = (int)v3;
  v4[4] = 4;
  v4[5] = (int)v3;
  v4[6] = 0;
  v4[7] = 0;
  v4[8] = 32;
  v4[9] = (int)L"LastKnownGood";
  v4[10] = (int)&v1;
  v4[11] = 4;
  v4[12] = (int)&v1;
  v4[13] = 0;
  v4[14] = 0;
  v4[15] = 32;
  v4[16] = (int)L"Default";
  v4[17] = (int)&v2;
  v4[18] = 4;
  v4[19] = (int)&v2;
  v4[20] = 0;
  v4[21] = 0;
  v4[22] = 0;
  v4[23] = 0;
  v4[24] = 0;
  v4[25] = 0;
  v4[26] = 0;
  v4[27] = 0;
  return RtlQueryRegistryValuesEx(0, (int)L"\\Registry\\Machine\\System\\Select", (int)v4, 0) >= 0
      && v1 == v3[0]
      && v3[0] != v2;
}

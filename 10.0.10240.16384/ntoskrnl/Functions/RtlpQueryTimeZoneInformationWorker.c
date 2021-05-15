// RtlpQueryTimeZoneInformationWorker 
 
int __fastcall RtlpQueryTimeZoneInformationWorker(int a1, unsigned int a2)
{
  int v4; // r4
  int v5; // r0
  int v7; // [sp+4h] [bp-150h] BYREF
  int v8; // [sp+8h] [bp-14Ch] BYREF
  __int16 v9[2]; // [sp+Ch] [bp-148h] BYREF
  int v10; // [sp+10h] [bp-144h]
  __int16 v11[2]; // [sp+14h] [bp-140h] BYREF
  int v12; // [sp+18h] [bp-13Ch]
  __int16 v13[2]; // [sp+1Ch] [bp-138h] BYREF
  int v14; // [sp+20h] [bp-134h]
  int v15[76]; // [sp+24h] [bp-130h] BYREF

  v7 = 0;
  v4 = RtlpGetRegistryHandle(2, L"TimeZoneInformation", 0, &v8);
  if ( v4 >= 0 )
  {
    memset((_BYTE *)a1, 0, a2);
    memset(v15, 0, 280);
    v15[2] = (int)L"Bias";
    v15[3] = a1;
    v10 = a1 + 4;
    v9[0] = 0;
    v9[1] = 64;
    v15[9] = (int)L"StandardName";
    v15[10] = (int)v9;
    v15[16] = (int)L"StandardBias";
    v15[17] = a1 + 84;
    v15[22] = 288;
    v15[23] = (int)L"StandardStart";
    v15[24] = a1 + 68;
    *(_DWORD *)(a1 + 68) = -16;
    v14 = a1 + 88;
    v13[0] = 0;
    v13[1] = 64;
    v15[29] = 288;
    v15[30] = (int)&szDaylightName;
    v15[31] = (int)v13;
    v15[37] = (int)L"DaylightBias";
    v15[38] = a1 + 168;
    v15[43] = 288;
    v15[44] = (int)L"DaylightStart";
    v15[45] = a1 + 152;
    v15[46] = 50331648;
    *(_DWORD *)(a1 + 152) = -16;
    v15[1] = 288;
    v15[4] = 0x4000000;
    v15[8] = 288;
    v15[11] = 0x1000000;
    v15[15] = 288;
    v15[18] = 0x4000000;
    v15[25] = 50331648;
    v15[32] = 0x1000000;
    v15[36] = 288;
    v15[39] = 0x4000000;
    if ( a2 >= 0x1B0 )
    {
      v12 = a1 + 172;
      v11[0] = 0;
      v11[1] = 256;
      v15[57] = 288;
      v15[60] = 0x4000000;
      v15[49] = (int)RtlpQueryTimeZoneKeyNameRoutine;
      v15[51] = (int)&szTimeZoneKeyName;
      v15[52] = (int)v11;
      v15[53] = 0;
      v15[58] = (int)L"DynamicDaylightTimeDisabled";
      v15[59] = (int)&v7;
    }
    v5 = RtlpQueryRegistryValues(0x40000000, v8, v15, 0);
    v4 = v5;
    if ( a2 >= 0x1B0 && v5 >= 0 )
      *(_BYTE *)(a1 + 428) = v7 != 0;
    ZwClose();
  }
  return v4;
}

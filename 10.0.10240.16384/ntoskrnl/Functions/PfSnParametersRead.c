// PfSnParametersRead 
 
int __fastcall PfSnParametersRead(int a1)
{
  int v2; // r5
  int result; // r0
  int v4; // r7
  char *v5; // r8
  int v6; // r3
  int v7; // r3
  int v8; // r3
  int v9; // r3
  int v10; // [sp+8h] [bp-268h] BYREF
  char *v11; // [sp+Ch] [bp-264h]
  int v12; // [sp+10h] [bp-260h] BYREF
  int v13; // [sp+14h] [bp-25Ch]
  char v14[8]; // [sp+18h] [bp-258h] BYREF
  char v15; // [sp+20h] [bp-250h] BYREF
  char v16[4]; // [sp+40h] [bp-230h] BYREF
  char v17[4]; // [sp+44h] [bp-22Ch] BYREF
  char v18[96]; // [sp+48h] [bp-228h] BYREF
  unsigned __int16 v19[128]; // [sp+A8h] [bp-1C8h] BYREF
  char v20[4]; // [sp+1A8h] [bp-C8h] BYREF
  char v21[4]; // [sp+1ACh] [bp-C4h] BYREF
  unsigned __int16 v22[96]; // [sp+1B0h] [bp-C0h] BYREF

  v13 = a1;
  memmove((int)v14, a1 + 64, 0x198u);
  v12 = 0;
  v2 = *(_DWORD *)(a1 + 4);
  v10 = 4;
  if ( PfpGetParameter(v2, L"EnablePrefetcher", 4, &v12, &v10) < 0 )
    return sub_817900();
  v11 = &v15;
  v4 = 0;
  v5 = v14;
  do
  {
    if ( &v12 )
    {
      if ( ((1 << v4) & v12) != 0 )
        v6 = 1;
      else
        v6 = 2;
    }
    else
    {
      v6 = 0;
    }
    *(_DWORD *)v5 = v6;
    v5 += 4;
    RtlStringCbCopyW((int)v22, 0xA0u);
    RtlStringCbCatW(v22, 0xA0u, (int)L"MaxNumPages", v7);
    v10 = 4;
    PfpGetParameter(v2, v22, 4, v11, &v10);
    RtlStringCbCopyW((int)v22, 0xA0u);
    RtlStringCbCatW(v22, 0xA0u, (int)L"MaxNumSections", v8);
    v10 = 4;
    PfpGetParameter(v2, v22, 4, v11 + 4, &v10);
    RtlStringCbCopyW((int)v22, 0xA0u);
    RtlStringCbCatW(v22, 0xA0u, (int)L"TimerPeriod", v9);
    v10 = 8;
    PfpGetParameter(v2, v22, 3, v11 + 8, &v10);
    ++v4;
    v11 += 16;
  }
  while ( v4 < 2 );
  v10 = 96;
  PfpGetParameter(v2, L"PrefetchRoot", 1, v18, &v10);
  v10 = 4;
  PfpGetParameter(v2, L"PrefetchFlags", 4, v20, &v10);
  v10 = 4;
  PfpGetParameter(v2, L"MaxNumActiveTraces", 4, v16, &v10);
  v10 = 4;
  PfpGetParameter(v2, L"MaxNumSavedTraces", 4, v17, &v10);
  v10 = 256;
  PfpGetParameter(v2, L"HostingAppList", 1, v19, &v10);
  v19[127] = 0;
  wcsupr(v19);
  v10 = 4;
  PfpGetParameter(v2, L"NumTracePeriods", 4, v21, &v10);
  result = PfSnParametersVerify(v14);
  if ( result >= 0 )
  {
    memmove(v13 + 64, (int)v14, 0x198u);
    result = 0;
  }
  return result;
}

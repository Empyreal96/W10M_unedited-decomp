// PpmProcessSettingsFromQueryTable 
 
int __fastcall PpmProcessSettingsFromQueryTable(unsigned int a1, int a2, int a3)
{
  int v4; // r9
  int v5; // r10
  int v6; // r8
  __int16 **v7; // r4
  unsigned int v8; // r5
  __int16 *v9; // r5
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // r3
  int v17; // [sp+10h] [bp-38h] BYREF
  _DWORD v18[12]; // [sp+18h] [bp-30h] BYREF

  v4 = 0;
  v5 = 20;
  do
  {
    v6 = *(_DWORD *)(a3 + 8);
    v7 = &PpmPolicyAliasList;
    v8 = 0;
    while ( wcsicmp(v6, (unsigned __int16 *)*v7) )
    {
      ++v8;
      v7 += 2;
      if ( v8 >= 0x14 )
        goto LABEL_7;
    }
    v9 = v7[1];
    v10 = *((_DWORD *)v9 + 1);
    v11 = *((_DWORD *)v9 + 2);
    v12 = *((_DWORD *)v9 + 3);
    v18[0] = *(_DWORD *)v9;
    v18[1] = v10;
    v18[2] = v11;
    v18[3] = v12;
LABEL_7:
    v17 = **(_DWORD **)(a3 + 12);
    if ( v17 != -1 )
    {
      if ( !memcmp((unsigned int)v18, (unsigned int)&GUID_PROCESSOR_PERF_INCREASE_HISTORY, 16) )
      {
        v13 = PpmProfileStatus | 4;
LABEL_10:
        PpmProfileStatus = v13;
        goto LABEL_16;
      }
      if ( !memcmp((unsigned int)v18, (unsigned int)&GUID_PROCESSOR_PERF_DECREASE_HISTORY, 16) )
      {
        v13 = PpmProfileStatus | 8;
        goto LABEL_10;
      }
      if ( !memcmp((unsigned int)v18, (unsigned int)&GUID_PROCESSOR_PERF_CORE_PARKING_HISTORY, 16) )
      {
        v13 = PpmProfileStatus | 0x10;
        goto LABEL_10;
      }
      v4 = 1;
      PpmSetProfilePolicySetting(a1, (unsigned int)v18, a2, (int)&v17, 4);
    }
LABEL_16:
    a3 += 28;
    --v5;
  }
  while ( v5 );
  return v4;
}

// PpmRegisterSpmSettings 
 
int __fastcall PpmRegisterSpmSettings(int a1, int a2)
{
  _DWORD *v3; // r6
  int v4; // r1
  int v5; // r4
  unsigned int i; // r7
  _DWORD *v7; // r3
  int v8; // r0
  int v9; // r1
  int v10; // r2
  int v11; // r3
  int v12; // r1
  unsigned __int16 *v13; // r4
  __int16 v14; // r3
  int v15; // r4
  int v16; // r4
  int v17; // r5
  int v19; // [sp-4h] [bp-B0h]
  int v20[2]; // [sp+4h] [bp-A8h] BYREF
  __int16 v21; // [sp+Ch] [bp-A0h] BYREF
  __int16 v22; // [sp+Eh] [bp-9Eh]
  const __int16 *v23; // [sp+10h] [bp-9Ch]
  int v24; // [sp+14h] [bp-98h]
  __int16 v25; // [sp+1Ch] [bp-90h] BYREF
  __int16 v26; // [sp+1Eh] [bp-8Eh]
  const __int16 *v27; // [sp+20h] [bp-8Ch]
  __int16 v28; // [sp+24h] [bp-88h] BYREF
  __int16 v29; // [sp+26h] [bp-86h]
  const __int16 *v30; // [sp+28h] [bp-84h]
  int v31; // [sp+2Ch] [bp-80h]
  unsigned __int16 *v32; // [sp+30h] [bp-7Ch]
  int v33; // [sp+34h] [bp-78h] BYREF
  int v34; // [sp+38h] [bp-74h] BYREF
  int v35[14]; // [sp+3Ch] [bp-70h] BYREF
  int v36; // [sp+74h] [bp-38h] BYREF
  int v37; // [sp+78h] [bp-34h]
  __int16 *v38; // [sp+7Ch] [bp-30h]
  int v39; // [sp+80h] [bp-2Ch]
  int v40; // [sp+84h] [bp-28h]
  int v41; // [sp+88h] [bp-24h]

  v24 = 0;
  v35[0] = -1;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v3 = 0;
  if ( sub_455E68(L"v1", a2, v20) >= 0 )
  {
    v30 = L"v1";
    v28 = 2 * LOWORD(v20[0]);
    v29 = 2 * LOWORD(v20[0]) + 2;
  }
  v25 = 0;
  v26 = 0;
  v27 = 0;
  if ( sub_455E68(L"Default", v4, v20) >= 0 )
  {
    v27 = L"Default";
    v25 = 2 * LOWORD(v20[0]);
    v26 = 2 * LOWORD(v20[0]) + 2;
  }
  v36 = 24;
  v37 = a1;
  v38 = &v28;
  v40 = 0;
  v41 = 0;
  v39 = 576;
  v5 = ZwOpenKey();
  if ( v5 >= 0 )
  {
    v3 = PpmAllocateQueryTable((int)v35);
    if ( !v3 )
    {
      v5 = -1073741670;
      goto LABEL_24;
    }
    PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
    for ( i = 0; i < (unsigned __int8)PpmProfileCount; i = (unsigned __int8)(i + 1) )
    {
      v7 = (_DWORD *)(PpmProfiles + 424 * i);
      v20[0] = (int)v7;
      v8 = v7[2];
      v9 = v7[3];
      v10 = v7[4];
      v11 = v7[5];
      v36 = v8;
      v37 = v9;
      v38 = (__int16 *)v10;
      v39 = v11;
      if ( !memcmp((unsigned int)&v36, (unsigned int)&GUID_POWER_POLICY_PROFILE_LOW_POWER, 16) )
      {
        v21 = 0;
        v22 = 0;
        v23 = 0;
        if ( sub_455E68(L"VideoBatching", v12, &v33) < 0 )
          goto LABEL_16;
        v14 = v33;
        v23 = L"VideoBatching";
      }
      else
      {
        v13 = *(unsigned __int16 **)v20[0];
        v21 = 0;
        v22 = 0;
        v23 = 0;
        if ( !v13 || sub_455E68(v13, v12, &v34) < 0 )
          goto LABEL_16;
        v14 = v34;
        v23 = (const __int16 *)v13;
      }
      v21 = 2 * v14;
      v22 = 2 * v14 + 2;
LABEL_16:
      v35[8] = 24;
      v35[9] = v24;
      v35[10] = (int)&v21;
      v35[11] = 576;
      v35[12] = 0;
      v35[13] = 0;
      if ( ZwOpenKey() >= 0 )
      {
        v35[2] = 24;
        v35[3] = v31;
        v35[4] = (int)&v25;
        v35[5] = 576;
        v35[6] = 0;
        v35[7] = 0;
        v15 = ZwOpenKey();
        ZwClose();
        if ( v15 >= 0 )
        {
          v5 = RtlpQueryRegistryValues(0x40000000, v32, v3, 0, v19, 1u);
          ZwClose();
          if ( v5 < 0 )
            goto LABEL_24;
          PpmReleaseLock(&PpmPerfPolicyLock);
          v16 = PpmProcessSettingsFromQueryTable((unsigned int)&v36, 0, (int)v3);
          v17 = PpmProcessSettingsFromQueryTable((unsigned int)&v36, 1, (int)v3);
          PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
          if ( v16 || v17 )
            PpmEnableProfile(v20[0]);
        }
      }
    }
    PpmReleaseLock(&PpmPerfPolicyLock);
    v5 = 0;
    PpmProfileStatus |= 2u;
  }
LABEL_24:
  if ( v24 )
    ZwClose();
  if ( v3 )
    ExFreePoolWithTag((unsigned int)v3);
  return v5;
}

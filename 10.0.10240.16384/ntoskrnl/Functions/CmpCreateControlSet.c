// CmpCreateControlSet 
 
int __fastcall CmpCreateControlSet(int a1)
{
  int v1; // r9
  int v3; // r4
  int v4; // r10
  int v5; // r4
  int v6; // r0
  int v8; // r2
  int v9; // r2
  int v10; // r3
  int v11; // r2
  int v12; // r3
  int v13; // [sp+14h] [bp-26Ch] BYREF
  int v14; // [sp+18h] [bp-268h] BYREF
  int v15; // [sp+1Ch] [bp-264h]
  unsigned __int16 v16; // [sp+20h] [bp-260h] BYREF
  __int16 v17; // [sp+22h] [bp-25Eh]
  char *v18; // [sp+24h] [bp-25Ch]
  int v19; // [sp+28h] [bp-258h] BYREF
  int v20; // [sp+2Ch] [bp-254h]
  int *v21; // [sp+30h] [bp-250h]
  int v22; // [sp+34h] [bp-24Ch]
  int v23; // [sp+38h] [bp-248h]
  int v24; // [sp+3Ch] [bp-244h]
  unsigned int v25; // [sp+40h] [bp-240h] BYREF
  char v26[4]; // [sp+44h] [bp-23Ch] BYREF
  int v27; // [sp+4Ch] [bp-234h]
  char v28[4]; // [sp+50h] [bp-230h] BYREF
  int v29; // [sp+54h] [bp-22Ch] BYREF
  unsigned __int16 v30[4]; // [sp+58h] [bp-228h] BYREF
  char v31[4]; // [sp+60h] [bp-220h] BYREF
  int v32; // [sp+64h] [bp-21Ch]
  int v33; // [sp+68h] [bp-218h]
  char v34[128]; // [sp+E0h] [bp-1A0h] BYREF
  char v35[288]; // [sp+160h] [bp-120h] BYREF

  v14 = 0;
  v15 = 0;
  v1 = 0;
  v19 = 24;
  v20 = 0;
  v22 = 64;
  v23 = 0;
  v24 = 0;
  v21 = &CmpSystemSelectPathString;
  v3 = NtOpenKey();
  if ( v3 >= 0 )
  {
    v3 = NtQueryValueKey(v27, &CmpCurrentString, 1, (int)v31, 128, (unsigned int)v28);
    NtClose();
    if ( v3 >= 0 )
    {
      v4 = *(_DWORD *)&v31[v33];
      v19 = 24;
      v20 = 0;
      v22 = 64;
      v21 = &CmpCurrentControlSetPathString;
      v23 = 0;
      v24 = 0;
      v3 = NtCreateKey((int)&v13, 32, (int)&v19, 0, 0);
      if ( v3 >= 0 )
      {
        sprintf_s((int)v34, 128, (int)"\\Registry\\Machine\\System\\ControlSet%03d", v4);
        RtlInitAnsiString((unsigned int)v30, (unsigned int)v34);
        v18 = v35;
        v16 = 0;
        v17 = 256;
        v3 = RtlAnsiStringToUnicodeString(&v16, v30, 0, 0);
        if ( v3 >= 0 )
        {
          v3 = NtSetValueKey(v13, (int)CmSymbolicLinkValueName, 0, 6, (int)v18, v16);
          if ( v3 >= 0 )
          {
            v19 = 24;
            v20 = v13;
            v22 = 64;
            v21 = &CmpControlIdConfigDbString;
            v23 = 0;
            v24 = 0;
            v5 = NtOpenKey();
            v6 = NtClose();
            if ( v5 < 0 )
              return sub_966C40(v6);
            if ( NtQueryValueKey(v15, &CmpCurrentConfigString, 1, (int)v31, 128, (unsigned int)v28) < 0 )
              goto LABEL_21;
            if ( v32 != 4 )
              goto LABEL_21;
            v25 = *(_DWORD *)&v31[v33];
            v19 = 24;
            v20 = 0;
            v22 = 64;
            v21 = &CmpHardwareProfilesPathString;
            v23 = 0;
            v24 = 0;
            if ( NtOpenKey() < 0 )
              goto LABEL_21;
            sprintf_s((int)v34, 128, (int)"%04d", v25);
            RtlInitAnsiString((unsigned int)v30, (unsigned int)v34);
            v18 = v35;
            v16 = 0;
            v17 = 256;
            RtlAnsiStringToUnicodeString(&v16, v30, 0, 0);
            v19 = 24;
            v20 = 0;
            v22 = 64;
            v21 = (int *)&v16;
            v23 = 0;
            v24 = 0;
            if ( NtOpenKey() >= 0 )
            {
              v8 = *(_DWORD *)(a1 + 132);
              if ( *(_WORD *)(v8 + 8) == 3 )
                *(_WORD *)(v8 + 8) = 1;
              v9 = *(_DWORD *)(a1 + 132);
              v10 = *(unsigned __int16 *)(v9 + 4);
              if ( v10 == 2 )
                goto LABEL_15;
              if ( v10 == 1 )
              {
LABEL_34:
                CmpAddAliasEntry(v15, *(_DWORD *)(a1 + 132) + 4, v25);
LABEL_15:
                v19 = 24;
                v20 = v15;
                v22 = 64;
                v21 = &CmpStrCurrentDockInfoString;
                v23 = 0;
                v24 = 0;
                NtCreateKey((int)&v13, 131103, (int)&v19, 0, 0);
                CmpAddDockingInfo(v13, *(_DWORD *)(a1 + 132) + 4);
                NtClose();
                if ( *(_WORD *)(*(_DWORD *)(a1 + 132) + 8) == 1 )
                  v1 = 1;
                goto LABEL_17;
              }
              if ( v10 != 3 )
              {
LABEL_17:
                v19 = 24;
                v20 = 0;
                v22 = 64;
                v21 = &CmpHardwareProfilesCurrentPathString;
                v23 = 0;
                v24 = 0;
                if ( NtCreateKey((int)&v13, 32, (int)&v19, 0, 0) >= 0 )
                {
                  sprintf_s(
                    (int)v34,
                    128,
                    (int)"\\Registry\\Machine\\System\\CurrentControlSet\\Hardware Profiles\\%04d",
                    v25);
                  RtlInitAnsiString((unsigned int)v30, (unsigned int)v34);
                  v18 = v35;
                  v16 = 0;
                  v17 = 256;
                  RtlAnsiStringToUnicodeString(&v16, v30, 0, 0);
                  NtSetValueKey(v13, (int)CmSymbolicLinkValueName, 0, 6, (int)v18, v16);
                  NtClose();
                }
                if ( v1 )
                {
                  v30[0] = 1;
                  v30[1] = 2;
                  v30[2] = 0;
                  CmSetAcpiHwProfile(
                    v30,
                    (int (__fastcall *)(unsigned int, int *, _DWORD))CmpHwprofileDefaultSelect,
                    v11,
                    (int)&v29,
                    v26);
                  NtClose();
                }
                goto LABEL_21;
              }
              if ( CmpCloneHwProfile(v15, 0, v14, v25, *(_WORD *)(v9 + 8), &v14, &v25) >= 0 )
              {
                if ( NtSetValueKey(v15, (int)&CmpCurrentConfigString, 0, 4, (int)&v25, 4u) < 0 )
                {
LABEL_21:
                  v12 = v14;
LABEL_22:
                  if ( v15 )
                  {
                    NtClose();
                    v12 = v14;
                  }
                  if ( v12 )
                    NtClose();
                  return 0;
                }
                goto LABEL_34;
              }
            }
            v12 = 0;
            v14 = 0;
            goto LABEL_22;
          }
        }
        NtClose();
      }
    }
  }
  return v3;
}

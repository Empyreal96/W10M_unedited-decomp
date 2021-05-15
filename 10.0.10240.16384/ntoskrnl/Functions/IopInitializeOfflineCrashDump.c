// IopInitializeOfflineCrashDump 
 
int __fastcall IopInitializeOfflineCrashDump(_DWORD *a1)
{
  int result; // r0
  int v3; // r8
  int *v4; // r6
  unsigned int v5; // r3
  int v6; // r0
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int *v10; // r6
  int v11; // r1
  int v12; // r2
  int v13; // r3
  int v14; // r0
  char v15; // r3
  int v16; // r0
  int v17; // r0
  char v18; // [sp+8h] [bp-48h] BYREF
  char v19[3]; // [sp+9h] [bp-47h] BYREF
  int v20; // [sp+Ch] [bp-44h] BYREF
  int v21[2]; // [sp+10h] [bp-40h] BYREF
  __int16 v22[2]; // [sp+18h] [bp-38h] BYREF
  const __int16 *v23; // [sp+1Ch] [bp-34h]
  int v24; // [sp+20h] [bp-30h] BYREF
  int v25; // [sp+28h] [bp-28h] BYREF
  __int16 v26; // [sp+2Ch] [bp-24h]
  __int16 v27; // [sp+2Eh] [bp-22h]
  char v28; // [sp+30h] [bp-20h]
  char v29; // [sp+31h] [bp-1Fh]
  char v30; // [sp+32h] [bp-1Eh]
  char v31; // [sp+33h] [bp-1Dh]
  char v32; // [sp+34h] [bp-1Ch]
  char v33; // [sp+35h] [bp-1Bh]
  char v34; // [sp+36h] [bp-1Ah]
  char v35; // [sp+37h] [bp-19h]

  v25 = 2012912317;
  v26 = 857;
  v27 = 19762;
  v28 = -67;
  v29 = 96;
  v30 = 40;
  v31 = -12;
  v32 = -25;
  v33 = -113;
  v34 = 120;
  v35 = 75;
  v22[0] = 126;
  v22[1] = 128;
  result = 0;
  v20 = 0;
  v23 = L"\\Registry\\Machine\\System\\CurrentControlSet\\Control\\CrashControl";
  v19[0] = 0;
  v24 = 1;
  v18 = 0;
  v3 = 0;
  dword_632A20 = 0;
  if ( !a1 )
    return sub_50A6BC();
  v4 = a1 + 562;
  v5 = a1[562];
  if ( v5 && v5 <= 2 )
  {
    v6 = *v4;
    v7 = a1[563];
    v8 = a1[564];
    v9 = v4[3];
    v10 = v4 + 4;
    PoOffCrashConfigTable = v6;
    dword_61F9A4 = v7;
    dword_61F9A8 = v8;
    *(_DWORD *)algn_61F9AC = v9;
    v11 = v10[1];
    v12 = v10[2];
    v13 = v10[3];
    dword_61F9B0 = *v10;
    dword_61F9B4 = v11;
    dword_61F9B8 = v12;
    *(_DWORD *)algn_61F9BC = v13;
    v14 = IopOpenRegistryKey(&v20, 0, v22, 131097, 0);
    if ( v14 < 0 )
    {
      dword_632A20 = v14;
LABEL_19:
      result = v20;
      goto LABEL_20;
    }
    if ( IopGetRegistryValue(v20, L"EnableOfflineDumps", 0, v21) < 0 )
      goto LABEL_24;
    if ( *(_DWORD *)(v21[0] + 12) )
      v3 = *(_DWORD *)(*(_DWORD *)(v21[0] + 8) + v21[0]);
    ExFreePoolWithTag(v21[0], 0);
    if ( v3 == 1 )
    {
      v15 = 1;
      OfflineDumpEnabled = 1;
    }
    else
    {
LABEL_24:
      OfflineDumpEnabled = 0;
      if ( (unsigned int)PoOffCrashConfigTable < 2 || (dword_61F9A8 & 4) == 0 )
        goto LABEL_12;
      v15 = 4;
    }
    v18 = v15;
LABEL_12:
    if ( IoGetEnvironmentVariableEx(L"OfflineMemoryDumpUseCapability", &v25, v19, &v24, 0) < 0 || v19[0] != v18 )
      IoSetEnvironmentVariableEx(L"OfflineMemoryDumpUseCapability", &v25, &v18, 1, 7);
    if ( OfflineDumpEnabled )
    {
      v16 = IopCachePreviousBootData(&v20);
      v17 = IopInitializeInMemoryDumpData(v16);
      IopConstructInMemoryDumpHeader(v17);
      if ( IopGetRegistryValue(v20, L"AttemptOffline", 0, v21) >= 0 )
      {
        if ( *(_DWORD *)(v21[0] + 12) )
          DumpPolicyAttemptOffline = *(_DWORD *)(*(_DWORD *)(v21[0] + 8) + v21[0]);
        ExFreePoolWithTag(v21[0], 0);
      }
    }
    goto LABEL_19;
  }
  dword_632A20 = -1073741736;
LABEL_20:
  if ( result )
    result = ObCloseHandle(result, 0);
  return result;
}

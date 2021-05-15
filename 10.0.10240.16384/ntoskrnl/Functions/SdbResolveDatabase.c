// SdbResolveDatabase 
 
int __fastcall SdbResolveDatabase(int a1, unsigned int a2, int *a3, unsigned __int16 *a4)
{
  int v5; // r7
  int v7; // r8
  _BYTE *v8; // r9
  unsigned int v9; // r5
  unsigned int *v10; // r3
  unsigned int v11; // t1
  int v12; // r0
  int v13; // r0
  int v14; // r5
  int v15; // r2
  int v16; // r2
  int v17; // r3
  int v18; // r0
  int v19; // r2
  int v20; // r0
  int v21; // r5
  int v22; // r2
  int v23; // r0
  int v24; // r2
  int v25; // r2
  int v26; // r3
  int v27; // r0
  int v28; // r2
  int v29; // r3
  int v31; // [sp+Ch] [bp-64h] BYREF
  unsigned int v32; // [sp+10h] [bp-60h]
  int v33; // [sp+14h] [bp-5Ch]
  unsigned int *v34; // [sp+18h] [bp-58h]
  unsigned __int16 v35; // [sp+20h] [bp-50h] BYREF
  unsigned __int16 v36; // [sp+22h] [bp-4Eh]
  unsigned __int16 *v37; // [sp+24h] [bp-4Ch]
  unsigned __int16 v38; // [sp+28h] [bp-48h] BYREF
  __int16 v39; // [sp+2Ah] [bp-46h]
  _BYTE *v40; // [sp+2Ch] [bp-44h]
  unsigned __int16 v41; // [sp+30h] [bp-40h] BYREF
  _BYTE v42[6]; // [sp+32h] [bp-3Eh]
  int v43; // [sp+38h] [bp-38h]
  int v44; // [sp+3Ch] [bp-34h]
  unsigned __int16 *v45; // [sp+40h] [bp-30h]
  int v46; // [sp+44h] [bp-2Ch]
  int v47; // [sp+48h] [bp-28h]
  int v48; // [sp+4Ch] [bp-24h]

  v5 = 0;
  v31 = 0;
  v38 = 0;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  *(_DWORD *)v42 = 0;
  *(_WORD *)&v42[4] = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v32 = a2;
  v33 = a1;
  v7 = 0;
  v8 = 0;
  if ( !a4 )
    return 0;
  *a4 = 0;
  v9 = 0;
  v10 = (unsigned int *)&off_618888;
  while ( 1 )
  {
    v11 = *v10;
    v34 = v10 + 2;
    if ( !memcmp(v11, a2, 16) )
      break;
    ++v9;
    v10 = v34;
    a2 = v32;
    if ( v9 >= 3 )
      goto LABEL_7;
  }
  v7 = (int)*(&off_618888 + 2 * v9 + 1);
  v31 = v7;
LABEL_7:
  if ( v9 < 3 )
  {
    v5 = SdbpGetStandardDatabasePath(v33, v7);
    if ( a3 )
      *a3 = v7;
    return v5;
  }
  v12 = AslGuidToString_UStr(&v41, v32);
  if ( v12 >= 0 )
  {
    v13 = wcslen(L"\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\InstalledSDB");
    v14 = v41 + 2 * (v13 + 2);
    v8 = AslAlloc(v13, v14);
    if ( !v8 )
    {
      AslLogCallPrintf(1, (int)"SdbResolveDatabase", 1106, "Failed to allocate %ld bytes for key path", v14);
      goto LABEL_36;
    }
    v40 = v8;
    v39 = v14;
    v38 = 0;
    RtlAppendUnicodeToString(
      &v38,
      (int)L"\\Registry\\Machine\\Software\\Microsoft\\Windows NT\\CurrentVersion\\AppCompatFlags\\InstalledSDB",
      v15,
      0);
    RtlAppendUnicodeToString(&v38, (int)L"\\", v16, v17);
    RtlAppendUnicodeStringToString(&v38, &v41);
    v43 = 24;
    v44 = 0;
    v46 = 576;
    v45 = &v38;
    v47 = 0;
    v48 = 0;
    v18 = ZwOpenKey();
    if ( v18 < 0 )
    {
      AslLogCallPrintf(1, (int)"SdbResolveDatabase", 1122, "Failed to open Key \"%ws\" [%x]", v40, v18);
      goto LABEL_36;
    }
    if ( a3 )
    {
      v20 = AslRegistryGetUInt32_UStr(&v31, 0, &g_ustrDatabaseType);
      if ( v20 < 0 )
      {
        AslLogCallPrintf(1, (int)"SdbResolveDatabase", 1134, "Failed to get database type [%x]", v20);
        *a3 = 0;
        goto LABEL_36;
      }
      *a3 = v31 & 0x7FFFFFFF;
    }
    v21 = v33;
    SdbGetAppPatchDirEx(v33, a4, v19, 0);
    v37 = a4;
    v35 = 2 * wcslen(a4);
    v36 = 520;
    v23 = RtlAppendUnicodeToString(&v35, (int)L"\\CUSTOM\\", v22, 520);
    if ( v23 >= 0 )
    {
      v25 = *(unsigned __int16 *)(v21 + 420);
      v26 = 34404;
      if ( (v25 == 34404 || v25 == 512 || (v26 = 43620, v25 == 43620))
        && (v23 = RtlAppendUnicodeToString(&v35, (int)L"CUSTOM64\\", v25, v26), v23 < 0) )
      {
        v24 = 1159;
      }
      else
      {
        v27 = RtlAppendUnicodeStringToString(&v35, &v41);
        if ( v27 < 0 )
        {
          AslLogCallPrintf(
            1,
            (int)"SdbResolveDatabase",
            1168,
            "RtlAppendUnicodeStringToString failed while creating CustomSdb path [%x]",
            v27);
          goto LABEL_23;
        }
        v23 = RtlAppendUnicodeToString(&v35, (int)L".sdb", v28, v29);
        if ( v23 >= 0 )
        {
          if ( v35 < (unsigned int)v36 - 2 )
          {
            v5 = v35 >> 1;
            a4[v5] = 0;
            goto LABEL_36;
          }
          AslLogCallPrintf(1, (int)"SdbResolveDatabase", 1183, "Insufficient buffer for the database path");
          goto LABEL_23;
        }
        v24 = 1176;
      }
    }
    else
    {
      v24 = 1150;
    }
    AslLogCallPrintf(
      1,
      (int)"SdbResolveDatabase",
      v24,
      "RtlAppendUnicodeToString failed while creating CustomSdb path [%x]",
      v23);
LABEL_23:
    *a4 = 0;
    goto LABEL_36;
  }
  AslLogCallPrintf(1, (int)"SdbResolveDatabase", 1085, "Failed to convert guid to string [%x]", v12);
LABEL_36:
  if ( v8 )
    ExFreePoolWithTag((unsigned int)v8);
  if ( *(_DWORD *)&v42[2] )
    AslUnicodeStringFree(&v41);
  return v5;
}

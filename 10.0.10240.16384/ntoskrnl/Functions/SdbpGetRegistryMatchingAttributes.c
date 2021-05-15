// SdbpGetRegistryMatchingAttributes 
 
int __fastcall SdbpGetRegistryMatchingAttributes(int a1, int a2, _DWORD *a3, int *a4, unsigned int *a5, int *a6, int *a7, _DWORD *a8, int *a9, unsigned int *a10)
{
  unsigned int v11; // r5
  int v13; // r10
  int v14; // r9
  int v15; // r8
  int v16; // r0
  int v17; // r2
  int v18; // r3
  _WORD *v19; // r0
  _WORD *v20; // r7
  int v21; // r0
  int v22; // r2
  int v23; // r3
  int v24; // r0
  unsigned int v25; // r0
  int v26; // r0
  unsigned int v27; // r0
  int v28; // r3
  int v29; // r0
  int v30; // r0
  int v31; // r6
  int v32; // r2
  int v33; // r3
  int v34; // r0
  int v35; // r2
  int v36; // r3
  int v38; // [sp+0h] [bp-30h]
  __int64 v39; // [sp+4h] [bp-2Ch]

  v38 = 0;
  v39 = 0i64;
  *a5 = 0;
  v11 = 0;
  *a6 = 0;
  *a3 = 0;
  *a4 = 0;
  *a7 = 0;
  *a8 = 0;
  a8[1] = 0;
  v13 = 0;
  v14 = 0;
  *a9 = 0;
  v15 = 0;
  *a10 = 0;
  v16 = SdbFindFirstTag(a1, a2, 24577);
  if ( v16 )
  {
    v19 = (_WORD *)SdbGetStringTagPtr(a1, v16, v17, v18);
    v20 = v19;
    if ( !v19 || !*v19 )
    {
      AslLogCallPrintf(1, (int)"SdbpGetRegistryMatchingAttributes", 732, "Failed to read key path", 0);
      return v15;
    }
    v21 = SdbFindFirstTag(a1, a2, 24624);
    if ( v21 )
      v38 = SdbGetStringTagPtr(a1, v21, v22, v23);
    v24 = SdbFindFirstTag(a1, a2, 16465);
    if ( v24 )
    {
      v25 = SdbReadDWORDTag(a1, v24, 0);
      v11 = v25;
      if ( !v25 )
      {
        AslLogCallPrintf(1, (int)"SdbpGetRegistryMatchingAttributes", 751, "Failed to read value type", v38);
        return v15;
      }
      if ( v25 <= 2 )
        goto LABEL_29;
      switch ( v25 )
      {
        case 3u:
          v30 = SdbFindFirstTag(a1, a2, 36882);
          v31 = v30;
          if ( !v30 )
          {
            AslLogCallPrintf(
              1,
              (int)"SdbpGetRegistryMatchingAttributes",
              798,
              "Failed to get TAG_REG_VALUE_DATA_BINARY",
              v38);
            return v15;
          }
          v14 = SdbGetBinaryTagData(a1, v30);
          if ( !v14 )
          {
            AslLogCallPrintf(1, (int)"SdbpGetRegistryMatchingAttributes", 804, "Failed to read value data", v38);
            return v15;
          }
          v27 = SdbGetTagDataSize(a1, v31, v32, v33);
          goto LABEL_19;
        case 4u:
          v29 = SdbFindFirstTag(a1, a2, 16466);
          if ( !v29 )
          {
            AslLogCallPrintf(
              1,
              (int)"SdbpGetRegistryMatchingAttributes",
              778,
              "Failed to get TAG_REG_VALUE_DATA_DWORD",
              v38);
            return v15;
          }
          v28 = SdbReadDWORDTag(a1, v29, 0);
          v27 = 0;
          goto LABEL_20;
        case 7u:
LABEL_29:
          v34 = SdbFindFirstTag(a1, a2, 24625);
          if ( !v34 )
          {
            AslLogCallPrintf(
              1,
              (int)"SdbpGetRegistryMatchingAttributes",
              764,
              "Failed to get TAG_REG_VALUE_DATA_SZ",
              v38);
            return v15;
          }
          v13 = SdbGetStringTagPtr(a1, v34, v35, v36);
          if ( !v13 )
          {
            AslLogCallPrintf(1, (int)"SdbpGetRegistryMatchingAttributes", 770, "Failed to read value data", v38);
            return v15;
          }
          break;
        case 0xBu:
          v26 = SdbFindFirstTag(a1, a2, 20507);
          if ( !v26 )
          {
            AslLogCallPrintf(
              1,
              (int)"SdbpGetRegistryMatchingAttributes",
              788,
              "Failed to get TAG_REG_VALUE_DATA_QWORD",
              v38);
            return v15;
          }
          v39 = SdbReadQWORDTag(a1, v26, 0, 0);
          break;
        default:
          AslLogCallPrintf(1, (int)"SdbpGetRegistryMatchingAttributes", 811, "Unknown registry value type", v38);
          return v15;
      }
    }
    v27 = 0;
LABEL_19:
    v28 = 0;
LABEL_20:
    v15 = 1;
    *a3 = v20;
    *a4 = v38;
    *a5 = v11;
    *a6 = v13;
    *a7 = v28;
    *(_QWORD *)a8 = v39;
    *a9 = v14;
    *a10 = v27;
    return v15;
  }
  AslLogCallPrintf(1, (int)"SdbpGetRegistryMatchingAttributes", 726, "Failed to get key path tag", 0);
  return v15;
}

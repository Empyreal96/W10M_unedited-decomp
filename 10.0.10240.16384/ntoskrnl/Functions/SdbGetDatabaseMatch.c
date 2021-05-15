// SdbGetDatabaseMatch 
 
int __fastcall SdbGetDatabaseMatch(int a1, unsigned __int16 *a2, int a3, int a4, int a5)
{
  int v8; // r5
  int v9; // r2
  unsigned int v11; // r0
  int v12; // r4
  int *v13; // r5
  unsigned __int16 *v14; // [sp+8h] [bp-D0h] BYREF
  int v15; // [sp+Ch] [bp-CCh] BYREF
  int v16; // [sp+10h] [bp-C8h] BYREF
  char v17[44]; // [sp+14h] [bp-C4h] BYREF
  int v18; // [sp+40h] [bp-98h] BYREF
  char v19[124]; // [sp+44h] [bp-94h] BYREF

  memset(v17, 0, sizeof(v17));
  v18 = 0;
  memset(v19, 0, sizeof(v19));
  v8 = 0;
  v15 = 0;
  v16 = 10;
  v14 = 0;
  if ( a4 )
    v16 = 26;
  if ( AslFileMappingCreate(&v14, a2, -1, a4, a5) < 0 )
  {
    AslLogCallPrintf(1, "SdbGetDatabaseMatch", 3660, "Failed to create initialize file mapping");
  }
  else
  {
    if ( !SdbpCreateSearchDBContext(&v16, v14) )
      return sub_7CD384();
    v11 = SdbpSearchDB(a1, *(_DWORD *)(a1 + 4), v9, (int)&v16, &v18);
    if ( v11 > 0x10 )
    {
      AslLogCallPrintf(1, "SdbGetDatabaseMatch", 3683, "The database has more matches than SDB_MAX_EXES");
      v11 = 16;
    }
    if ( v11 )
    {
      v12 = v11 - 1;
      if ( (int)(v11 - 1) >= 0 )
      {
        v13 = &v18 + 2 * v12;
        while ( (v13[1] & 2) != 0 || SdbTagIDToTagRef(a1, *(_DWORD *)(a1 + 4), *v13, &v15) )
        {
          --v12;
          v13 -= 2;
          if ( v12 < 0 )
            goto LABEL_17;
        }
        AslLogCallPrintf(1, "SdbGetDatabaseMatch", 3702, "Failed to convert tagid to tagref");
LABEL_17:
        v8 = v15;
      }
    }
  }
  SdbpReleaseSearchDBContext(&v16);
  AslFileMappingDelete(v14);
  return v8;
}

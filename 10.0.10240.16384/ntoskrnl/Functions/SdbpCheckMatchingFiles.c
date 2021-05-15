// SdbpCheckMatchingFiles 
 
int __fastcall SdbpCheckMatchingFiles(int a1, int a2, int a3, int a4, int a5, int *a6)
{
  int v6; // r4
  int v7; // r3
  unsigned __int16 *v8; // r5
  int v9; // r6
  int *v12; // r9
  int v13; // r0
  int v14; // r2
  int v15; // r3
  unsigned __int16 *v16; // r0
  unsigned __int16 *v17; // r9
  int v18; // r0
  int v19; // r2
  unsigned int v20; // r0
  int v21; // r3
  int v22; // r2
  int *v23; // r10
  int v24; // r8
  int *v25; // r4
  bool v26; // cc
  int v27; // r3
  int v29; // [sp+8h] [bp-38h] BYREF
  int *v30; // [sp+Ch] [bp-34h]
  unsigned __int16 *v31; // [sp+10h] [bp-30h] BYREF
  unsigned int v32; // [sp+14h] [bp-2Ch] BYREF
  int v33; // [sp+18h] [bp-28h]
  int v34; // [sp+1Ch] [bp-24h]
  int v35; // [sp+20h] [bp-20h]

  v30 = (int *)a1;
  v32 = 0;
  v33 = a2;
  v6 = 0;
  v7 = a6[11];
  v8 = 0;
  v9 = 0;
  v35 = a3;
  v12 = (int *)a1;
  v29 = 0;
  v31 = 0;
  if ( v7 )
  {
    v9 = 1;
    v6 = 1;
  }
  else
  {
    v13 = SdbFindFirstTag(a3, a5, 24577);
    if ( v13 )
    {
      v16 = (unsigned __int16 *)SdbGetStringTagPtr(a3, v13, v14, v15);
      v17 = v16;
      if ( !v16 )
      {
        AslLogCallPrintf(1, (int)"SdbpCheckMatchingFiles", 2055, "Failed to get the string from the database");
        goto LABEL_33;
      }
      if ( !a6[1] || *v16 != 42 )
      {
        v20 = wcslen(v16);
        v21 = *a6;
        v22 = v20;
        v34 = v20;
        if ( (v21 & 1) == 0 )
        {
          if ( !SdbpInitializeSearchDBContext(a6) )
          {
            AslLogCallPrintf(1, (int)"SdbpCheckMatchingFiles", 2106, "Failed to initialize SEARCHDBCONTEXT");
            goto LABEL_33;
          }
          v22 = v34;
        }
        v23 = (int *)a6[9];
        v24 = 0;
        if ( *v23 <= 0 )
          goto LABEL_28;
        v25 = v23 + 1;
        while ( 1 )
        {
          if ( !SdbpResolveMatchingFile(v33, a6, v17, v22, v25, &v31) )
          {
            AslLogCallPrintf(1, (int)"SdbpCheckMatchingFiles", 2130, "Failed to resolve matching file");
            v6 = v29;
            v8 = v31;
            goto LABEL_33;
          }
          v8 = v31;
          v32 = 0;
          if ( AslFileMappingCreate(&v32, v31, 0, 0, 0) >= 0 )
          {
            if ( SdbpCheckAllAttributes(&v29, v33, v35, a5, v32) >= 0 )
            {
              v6 = v29;
              if ( v24 > 0 )
                a6[10] = 1;
LABEL_28:
              v27 = *v17;
              if ( v27 == 37 || v27 == 92 || v27 == 46 )
                a6[10] = 1;
LABEL_32:
              v9 = 1;
              goto LABEL_33;
            }
            AslFileMappingDelete(v32);
            v32 = 0;
            if ( v8 )
              ExFreePoolWithTag((unsigned int)v8);
          }
          else if ( v8 )
          {
            ExFreePoolWithTag((unsigned int)v8);
          }
          v8 = 0;
          ++v24;
          v22 = v34;
          v25 += 6;
          v26 = v24 < *v23;
          v31 = 0;
          if ( !v26 )
          {
            v6 = v29;
            goto LABEL_28;
          }
        }
      }
      v18 = SdbpCheckAllAttributes(&v29, a2, a3, a5, a6[1]);
      if ( AslFileNotFound(v18) || v19 >= 0 )
      {
        v6 = v29;
        goto LABEL_32;
      }
      AslLogCallPrintf(1, (int)"SdbpCheckMatchingFiles", 2080, "Failed to check file attributes [%x]", v19);
      v6 = v29;
LABEL_33:
      v12 = v30;
    }
  }
  AslFileMappingDelete(v32);
  if ( v8 )
    ExFreePoolWithTag((unsigned int)v8);
  *v12 = v6;
  return v9;
}

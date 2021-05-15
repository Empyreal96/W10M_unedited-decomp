// SdbpCheckMatchingTextEntry 
 
int __fastcall SdbpCheckMatchingTextEntry(int a1, int *a2, unsigned __int16 *a3, int a4, unsigned int a5, unsigned int a6, unsigned int a7, int *a8, _DWORD *a9)
{
  unsigned __int16 *v9; // r9
  int v11; // r4
  unsigned int v12; // r6
  int v13; // r5
  int *v15; // r5
  int v16; // r4
  _DWORD *v17; // r7
  unsigned int v18; // r0
  int v19; // r2
  int v20; // r1
  int v21; // r2
  bool v22; // cc
  int v23; // r2
  int v24; // r3
  unsigned __int16 *v26; // r0
  unsigned int v27; // r3
  unsigned int v28; // r5
  unsigned int v29; // r7
  int v30; // r2
  int v31; // r1
  unsigned int v32; // r4
  _BYTE *v33; // r0
  unsigned int v34; // r8
  int v35; // r0
  unsigned __int16 *v36; // [sp+8h] [bp-38h] BYREF
  unsigned __int16 *v37; // [sp+Ch] [bp-34h]
  int v38; // [sp+10h] [bp-30h] BYREF
  int v39; // [sp+14h] [bp-2Ch]
  int v40; // [sp+18h] [bp-28h]
  int v41; // [sp+1Ch] [bp-24h]

  v41 = a4;
  v40 = 0;
  v9 = 0;
  v36 = 0;
  v37 = a3;
  v11 = *a2;
  *a8 = 0;
  v12 = 0;
  v13 = 0;
  *a9 = 0;
  v38 = 0;
  if ( (v11 & 1) == 0 )
  {
    if ( !SdbpInitializeSearchDBContext(a2) )
    {
      AslLogCallPrintf(1, (int)"SdbpCheckMatchingTextEntry", 1424, "Failed to initialize SEARCHDBCONTEXT");
      goto LABEL_17;
    }
    a3 = v37;
  }
  v15 = (int *)a2[9];
  v16 = 0;
  if ( *v15 > 0 )
  {
    v17 = v15 + 1;
    while ( 1 )
    {
      v18 = wcslen(a3);
      if ( !SdbpResolveMatchingFile(a1, a2, v37, v18, v17, &v36) )
      {
        AslLogCallPrintf(1, (int)"SdbpCheckMatchingTextEntry", 1448, "Failed to resolve matching text file");
        v9 = v36;
        goto LABEL_60;
      }
      v9 = v36;
      v19 = AslFileMappingCreate(&v38, v36, 0, 0, 0);
      v12 = v38;
      if ( v19 >= 0 )
        v19 = AslFileMappingEnsureMappedAs(v38);
      if ( !AslFileNotFound(v19) )
        break;
      AslFileMappingDelete(v12);
      v12 = 0;
      v38 = 0;
      if ( v9 )
        ExFreePoolWithTag((unsigned int)v9);
      v9 = 0;
      ++v16;
      v17 += 6;
      v22 = v16 < *v15;
      v36 = 0;
      if ( !v22 )
        goto LABEL_15;
      a3 = v37;
    }
    if ( v21 < 0 )
    {
      AslLogCallPrintf(1, (int)"SdbpCheckMatchingTextEntry", 1480, "Failed to map file [%x]", v21);
LABEL_60:
      v13 = 0;
      goto LABEL_17;
    }
    if ( v16 > 0 )
      *a9 = 1;
    if ( v12 )
    {
      v26 = (unsigned __int16 *)AslFileMappingGetViewBase(v12, v20, *(_DWORD *)(v12 + 532), *(_DWORD *)(v12 + 528));
      v28 = a7;
      v29 = 0;
      v36 = v26;
      if ( v30 || a7 < v27 )
      {
        v39 = 0;
      }
      else
      {
        v28 = v27;
        v39 = 0;
      }
      if ( a5 <= v28 )
      {
        if ( a6 == 3 )
          v31 = 2;
        else
          v31 = 1;
        v38 = v31;
        if ( !v28 )
        {
LABEL_58:
          v23 = v40;
          goto LABEL_16;
        }
        while ( 1 )
        {
          if ( v29 > a5 )
            v29 = v29 - a5 + v31;
          v32 = v28 - v29;
          if ( v28 - v29 > 0x1000 )
            v32 = 4096;
          v33 = AslAlloc((int)v26, v32 + 2);
          v34 = (unsigned int)v33;
          if ( !v33 )
            break;
          if ( (unsigned __int16 *)((char *)v36 + v29) < v36 )
          {
            AslLogCallPrintf(1, (int)"SdbpCheckMatchingTextEntry", 1558, "Overflow doing pointer addition");
            goto LABEL_60;
          }
          memmove((int)v33, (int)v36 + v29, v32);
          if ( !a6 )
            goto LABEL_55;
          if ( a6 <= 2 )
          {
            v35 = AslStringSearchA(v34, v32, v41, a5);
          }
          else
          {
            if ( a6 != 3 )
            {
LABEL_55:
              AslLogCallPrintf(1, (int)"SdbpCheckMatchingTextEntry", 1592, "Unknown file encoding");
              goto LABEL_60;
            }
            v35 = AslStringSearchW(v34, v32 >> 1, v41, a5 >> 1);
          }
          if ( v35 )
            v40 = 1;
          v29 += v32;
          v26 = (unsigned __int16 *)ExFreePoolWithTag(v34);
          if ( v29 >= v28 )
            goto LABEL_58;
          v31 = v38;
        }
        AslLogCallPrintf(1, (int)"SdbpCheckMatchingTextEntry", 1551, "Failed to allocate temp buffer");
        goto LABEL_60;
      }
    }
  }
LABEL_15:
  v23 = 0;
LABEL_16:
  v13 = 1;
  *a8 = v23;
LABEL_17:
  v24 = *v37;
  if ( v24 == 37 || v24 == 92 || v24 == 46 )
    *a9 = 1;
  if ( v9 )
    ExFreePoolWithTag((unsigned int)v9);
  if ( v12 )
    AslFileMappingDelete(v12);
  return v13;
}

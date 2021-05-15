// SdbpResolveMatchingFile 
 
int __fastcall SdbpResolveMatchingFile(int a1, int a2, _WORD *a3, int a4, int *a5, unsigned __int16 **a6)
{
  int v9; // r10
  int v10; // r0
  unsigned int v11; // r3
  unsigned int v12; // r3
  unsigned int v13; // r2
  int v14; // r0
  unsigned int v15; // r5
  unsigned __int16 *v16; // r0
  unsigned __int16 *v17; // r4
  int v18; // r0
  int v19; // r0
  unsigned int v20; // r0
  int v21; // r2
  unsigned int v23; // [sp+8h] [bp-28h] BYREF
  unsigned __int16 *v24; // [sp+Ch] [bp-24h] BYREF
  int v25; // [sp+10h] [bp-20h]

  v23 = 0;
  v24 = 0;
  *a6 = 0;
  v25 = a2;
  v9 = 0;
  if ( !a4 )
  {
    AslLogCallPrintf(1, (int)"SdbpResolveMatchingFile", 519, "Invalid match file length");
    return v9;
  }
  if ( *a3 == 37 )
  {
    v10 = AslEnvExpandStrings2(*(_DWORD *)(a2 + 28), a3, 0, 0, &v23, (*(_DWORD *)(a1 + 404) & 4) != 0);
    if ( v10 < 0 && v10 != -1073741789 )
    {
      AslLogCallPrintf(1, (int)"SdbpResolveMatchingFile", 545, "AslEnvExpandStrings2 failed [%x]", v10);
      return v9;
    }
    v11 = 2 * v23;
  }
  else
  {
    v12 = a5[1];
    v13 = v12 + a4;
    if ( v12 + a4 < v12 )
    {
      v21 = 558;
      goto LABEL_33;
    }
    v11 = v13 + 1;
    if ( v13 + 1 < v13 )
    {
      v21 = 563;
      goto LABEL_33;
    }
  }
  if ( v11 + 20 < v11 )
  {
    v21 = 569;
LABEL_33:
    AslLogCallPrintf(1, (int)"SdbpResolveMatchingFile", v21, "Invalid path size");
    return v9;
  }
  v23 = v11 + 20;
  v14 = RtlULongLongToULong(2 * (v11 + 20), (unsigned __int64)(v11 + 20) >> 31, &v23);
  if ( v14 < 0 )
  {
    AslLogCallPrintf(1, (int)"SdbpResolveMatchingFile", 574, "Invalid buffer size");
    return v9;
  }
  v15 = 520;
  if ( v23 >= 0x208 )
    v15 = v23;
  v16 = (unsigned __int16 *)AslAlloc(v14, v15);
  v17 = v16;
  if ( !v16 )
  {
    AslLogCallPrintf(1, (int)"SdbpResolveMatchingFile", 582, "Out of memory");
    return v9;
  }
  if ( *a3 != 37 )
  {
    memmove((int)v16, *a5, 2 * a5[1]);
    memmove((int)&v17[a5[1]], (int)a3, 2 * (a4 + 1));
LABEL_21:
    v19 = AslPathClean(v17, v17, v15 >> 1);
    if ( v19 >= 0 )
    {
      if ( AslPathToNetworkPathNt(&v24, v17) < 0 )
      {
        if ( wcsnicmp((int)v17, L"\\??\\", 4) )
        {
          v20 = wcslen(v17);
          memmove((int)(v17 + 4), (int)v17, 2 * (v20 + 1));
          memmove((int)v17, (int)L"\\??\\", 8u);
        }
      }
      else
      {
        ExFreePoolWithTag((unsigned int)v17);
        v17 = v24;
      }
      v9 = 1;
      *a6 = v17;
      v17 = 0;
    }
    else
    {
      AslLogCallPrintf(1, (int)"SdbpResolveMatchingFile", 624, "AslPathClean failed [%x]", v19);
    }
    goto LABEL_28;
  }
  v18 = AslEnvExpandStrings2(*(_DWORD *)(v25 + 28), a3, v16, v15 >> 1, &v23, (*(_DWORD *)(a1 + 404) & 4) != 0);
  if ( v18 >= 0 )
    goto LABEL_21;
  AslLogCallPrintf(
    1,
    (int)"SdbpResolveMatchingFile",
    599,
    "AslEnvExpandStrings2 failed to expand strings for %ws [%x]",
    a3,
    v18);
LABEL_28:
  if ( v17 )
    ExFreePoolWithTag((unsigned int)v17);
  return v9;
}

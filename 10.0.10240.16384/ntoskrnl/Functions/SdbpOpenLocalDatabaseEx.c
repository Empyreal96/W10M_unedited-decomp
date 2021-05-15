// SdbpOpenLocalDatabaseEx 
 
int __fastcall SdbpOpenLocalDatabaseEx(int a1, _DWORD *a2, int a3, unsigned int **a4, unsigned int *a5)
{
  _DWORD *v5; // r6
  int v7; // r4
  unsigned int v8; // r5
  const char *v10; // r3
  int v11; // r2
  unsigned int v12; // r0
  int v13; // r2
  unsigned int *v14; // r0
  _DWORD *v15; // r6
  int v16; // r1
  int v17; // r2
  int v18; // r3
  unsigned int v20; // [sp+0h] [bp-238h]
  int v22; // [sp+Ch] [bp-22Ch] BYREF
  unsigned __int16 v23[276]; // [sp+10h] [bp-228h] BYREF

  v5 = a2;
  v7 = 0;
  v8 = *a5;
  if ( (*a5 & 0xF0000000) != 0 )
    v8 >>= 28;
  v22 = 0;
  if ( v8 >= 0x10 )
  {
    v10 = "Bad index 0x%lx";
    v20 = v8;
    v11 = 872;
LABEL_24:
    AslLogCallPrintf(1, (int)"SdbpOpenLocalDatabaseEx", v11, v10, v20);
    return v7;
  }
  SdbpCloseLocalDatabaseEx(a1, (int)a2, v8, 0);
  v12 = SdbResolveDatabase(a1, v5, &v22, v23);
  if ( !v12 || v12 >= 0x104 )
  {
    v10 = "Cannot resolve database, the path length is 0x%lx";
    v20 = v12;
    v11 = 905;
    goto LABEL_24;
  }
  AslStringUpper(v23);
  if ( *(_WORD *)(a1 + 420) == 0x7FFF )
    goto LABEL_12;
  if ( wcsstr((char *)v23, (char *)L"\\CUSTOM64\\") )
  {
    if ( *(_WORD *)(a1 + 420) != 332 )
      goto LABEL_12;
LABEL_15:
    AslLogCallPrintf(
      3,
      (int)"SdbpOpenLocalDatabaseEx",
      927,
      "Database \"%ws\" is not of the same type as the main EXE",
      v23);
    return v7;
  }
  v13 = *(unsigned __int16 *)(a1 + 420);
  if ( v13 == 34404 || v13 == 512 || v13 == 43620 )
    goto LABEL_15;
LABEL_12:
  v14 = SdbOpenDatabaseEx(v23);
  if ( v14 )
  {
    v15 = (_DWORD *)(a1 + 24 * v8);
    v15[9] = v14;
    v15[10] = 2;
    *(_DWORD *)(a1 + 16) |= 1 << v8;
    if ( a2 )
    {
      v16 = a2[1];
      v17 = a2[2];
      v18 = a2[3];
      v15[5] = *a2;
      v15[6] = v16;
      v15[7] = v17;
      v15[8] = v18;
      v15[10] |= 1u;
    }
    else
    {
      v15[5] = 0;
      v15[6] = 0;
      v15[7] = 0;
      v15[8] = 0;
    }
    v7 = 1;
    if ( v8 == 1 )
      *(_DWORD *)(a1 + 8) = v14;
    *a5 = v8 << 28;
    if ( a4 )
      *a4 = v14;
  }
  else
  {
    AslLogCallPrintf(1, (int)"SdbpOpenLocalDatabaseEx", 943, "Failed to open database");
  }
  return v7;
}

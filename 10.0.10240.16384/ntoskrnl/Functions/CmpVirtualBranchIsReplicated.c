// CmpVirtualBranchIsReplicated 
 
BOOL __fastcall CmpVirtualBranchIsReplicated(int a1, int *a2, bool *a3)
{
  _DWORD *v4; // r7
  int v7; // r4
  int (__fastcall **v8)(void *); // r6
  int v9; // r0
  int (__fastcall **v10)(void *); // r5
  int v11; // r0
  unsigned int v12; // r2
  bool v13; // r3
  int (__fastcall **v15)(void *); // [sp+8h] [bp-30h] BYREF
  int v16; // [sp+Ch] [bp-2Ch] BYREF
  int v17; // [sp+10h] [bp-28h] BYREF
  unsigned __int16 v18; // [sp+18h] [bp-20h] BYREF
  _BYTE v19[6]; // [sp+1Ah] [bp-1Eh]

  v16 = -1;
  v4 = 0;
  v18 = 0;
  *(_DWORD *)v19 = 0;
  *(_WORD *)&v19[4] = 0;
  v15 = 0;
  *a3 = 0;
  if ( a1 )
  {
    if ( !*(_WORD *)a2 )
      return CmpVEEnabled && (*(_WORD *)(a1 + 106) & 0x100) != 0;
    v8 = *(int (__fastcall ***)(void *))(a1 + 20);
  }
  else
  {
    if ( CmpGetCmHiveFromVirtualPath((int)a2, (int)&v15, (int)a3, 0) < 0 )
      return 0;
    v8 = v15;
    v4 = CmpMasterHive;
  }
  if ( CmpBlockTwoHiveWrites(v4, v8, 1) < 0 )
    return 0;
  v9 = CmpFindPathByName(a1, a2, (int)&v18, &v17, &v15);
  v10 = v15;
  v7 = v9;
  if ( v15 && (v11 = ((int (__fastcall *)(int (__fastcall **)(void *), int, int *))v15[1])(v15, v17, &v16)) != 0 )
  {
    if ( v7 )
    {
      if ( !CmpVEEnabled || (*(_WORD *)(v11 + 2) & 0x100) == 0 )
        v7 = 0;
    }
    else
    {
      v13 = CmpVEEnabled && (*(_WORD *)(v11 + 2) & 0x100) != 0;
      *a3 = v13;
      v12 = 0;
      if ( v18 >> 1 )
      {
        while ( *(_WORD *)(*(_DWORD *)&v19[2] + 2 * v12) != 92 )
        {
          v12 = (unsigned __int16)(v12 + 1);
          if ( v12 >= v18 >> 1 )
            goto LABEL_28;
        }
        *a3 = 0;
      }
    }
LABEL_28:
    ((void (__fastcall *)(int (__fastcall **)(void *), int *, unsigned int))v10[2])(v10, &v16, v12);
  }
  else
  {
    v7 = 0;
  }
  CmpUnblockTwoHiveWrites(v4, v8);
  return v7;
}

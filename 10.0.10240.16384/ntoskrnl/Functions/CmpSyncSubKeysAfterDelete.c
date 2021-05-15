// CmpSyncSubKeysAfterDelete 
 
BOOL __fastcall CmpSyncSubKeysAfterDelete(int a1, int a2, int a3, _DWORD *a4, _WORD *a5)
{
  unsigned int v5; // r8
  int v9; // r5
  unsigned int v10; // r7
  _WORD *v11; // r0
  _WORD *v12; // r6
  int v14; // [sp+0h] [bp-38h] BYREF
  unsigned int v15; // [sp+4h] [bp-34h] BYREF
  int v16; // [sp+8h] [bp-30h]
  int v17; // [sp+Ch] [bp-2Ch] BYREF
  char v18[40]; // [sp+10h] [bp-28h] BYREF

  v5 = 0;
  v14 = -1;
  v16 = a1;
  while ( 1 )
  {
    v9 = CmpFindSubKeyByNumber(a3, a4, v5, &v15);
    if ( v9 < 0 )
      return 0;
    v10 = v15;
    if ( v15 == -1 )
      return v9 >= 0;
    v11 = (_WORD *)(*(int (__fastcall **)(int, unsigned int, int *))(a3 + 4))(a3, v15, &v14);
    v12 = v11;
    if ( !v11 )
    {
      v9 = -1073741670;
LABEL_13:
      if ( v12 )
        (*(void (__fastcall **)(int, int *))(a3 + 8))(a3, &v14);
      return v9 >= 0;
    }
    CmpInitializeKeyNameString(v11, (int)v18, a5);
    CmpFindSubKeyByNameWithStatus(v16, a2, (int)v18, &v17);
    if ( v17 == -1 )
    {
      if ( *((_DWORD *)v12 + 5) + *((_DWORD *)v12 + 6) )
        CmpDeleteTree(a3, v10);
      v9 = CmpFreeKeyByCell(a3, v10, 1);
      if ( v9 < 0 )
        goto LABEL_13;
    }
    else
    {
      ++v5;
    }
    (*(void (__fastcall **)(int, int *))(a3 + 8))(a3, &v14);
  }
}

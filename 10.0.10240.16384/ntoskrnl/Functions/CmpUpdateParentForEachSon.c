// CmpUpdateParentForEachSon 
 
int __fastcall CmpUpdateParentForEachSon(int a1, int a2, int a3, int a4)
{
  int (*v5)(void); // r3
  int v7; // r0
  _DWORD *v8; // r7
  int v9; // r4
  unsigned int v10; // r4
  unsigned int v11; // r6
  unsigned int v12; // r4
  int v13; // r0
  int v15; // [sp+0h] [bp-28h] BYREF
  int v16; // [sp+4h] [bp-24h] BYREF
  _DWORD v17[8]; // [sp+8h] [bp-20h] BYREF

  v15 = a1;
  v16 = a2;
  v17[0] = a3;
  v17[1] = a4;
  v5 = *(int (**)(void))(a1 + 4);
  v16 = -1;
  v17[0] = -1;
  v7 = v5();
  v8 = (_DWORD *)v7;
  if ( v7 )
  {
    v10 = 0;
    v11 = *(_DWORD *)(v7 + 24) + *(_DWORD *)(v7 + 20);
    if ( v11 )
    {
      while ( CmpFindSubKeyByNumber(a1, v8, v10, &v15) >= 0 && v15 != -1 && HvpMarkCellDirty(a1, v15, 0, 0) )
      {
        if ( ++v10 >= v11 )
          goto LABEL_8;
      }
    }
    else
    {
LABEL_8:
      v12 = 0;
      if ( !v11 )
      {
LABEL_12:
        v9 = 1;
LABEL_13:
        (*(void (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v17);
        return v9;
      }
      while ( 1 )
      {
        CmpFindSubKeyByNumber(a1, v8, v12, &v15);
        if ( v15 == -1 )
          break;
        v13 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v15, &v16);
        if ( !v13 )
          break;
        *(_DWORD *)(v13 + 16) = a2;
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v16);
        if ( ++v12 >= v11 )
          goto LABEL_12;
      }
    }
    v9 = 0;
    goto LABEL_13;
  }
  return 0;
}

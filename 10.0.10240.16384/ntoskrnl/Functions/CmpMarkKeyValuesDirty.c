// CmpMarkKeyValuesDirty 
 
BOOL __fastcall CmpMarkKeyValuesDirty(int a1, int a2, int a3, int a4)
{
  __int16 v5; // r3
  BOOL v6; // r4
  int v8; // r1
  int v9; // r1
  int v10; // r0
  int v11; // r4
  int *v12; // r8
  int v13; // r7
  int v14; // t1
  int v15; // r0
  int v16; // r2
  int v17; // r3
  int v19; // [sp+0h] [bp-20h] BYREF
  int v20; // [sp+4h] [bp-1Ch] BYREF
  _DWORD v21[6]; // [sp+8h] [bp-18h] BYREF

  v19 = a2;
  v20 = a3;
  v21[0] = a4;
  v5 = *(_WORD *)(a3 + 2);
  v6 = 1;
  v20 = -1;
  v21[0] = -1;
  v19 = -1;
  if ( (v5 & 2) != 0 )
    return v6;
  if ( !HvpMarkCellDirty(a1, a2, 0, 0) )
    return 0;
  v8 = *(_DWORD *)(a3 + 48);
  if ( v8 != -1 && !HvpMarkCellDirty(a1, v8, 0, 0) )
    return 0;
  v9 = *(_DWORD *)(a3 + 44);
  if ( v9 != -1 )
  {
    if ( !HvpMarkCellDirty(a1, v9, 0, 0) )
      return 0;
    v10 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(a3 + 44), &v19);
    v11 = v10;
    if ( !v10 )
      return 0;
    v6 = HvpMarkCellDirty(a1, *(_DWORD *)(v10 + 4), 0, 0) && HvpMarkCellDirty(a1, *(_DWORD *)(v11 + 8), 0, 0);
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v19);
    if ( !v6 )
      return v6;
  }
  if ( !*(_DWORD *)(a3 + 36) )
    return v6;
  if ( !HvpMarkCellDirty(a1, *(_DWORD *)(a3 + 40), 0, 0) )
    return 0;
  v12 = (int *)(*(int (__fastcall **)(int, _DWORD, _DWORD *))(a1 + 4))(a1, *(_DWORD *)(a3 + 40), v21);
  if ( !v12 )
    return 0;
  v13 = 0;
  if ( *(_DWORD *)(a3 + 36) )
  {
    while ( HvpMarkCellDirty(a1, *v12, 0, 0) )
    {
      v14 = *v12++;
      v15 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v14, &v20);
      if ( !v15 )
        break;
      v6 = CmpMarkValueDataDirty(a1, v15, v16, v17);
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v20);
      if ( v6 )
      {
        if ( (unsigned int)++v13 < *(_DWORD *)(a3 + 36) )
          continue;
      }
      goto LABEL_24;
    }
    v6 = 0;
  }
LABEL_24:
  (*(void (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v21);
  return v6;
}

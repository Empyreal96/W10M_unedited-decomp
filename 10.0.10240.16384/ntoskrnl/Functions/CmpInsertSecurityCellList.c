// CmpInsertSecurityCellList 
 
int __fastcall CmpInsertSecurityCellList(int a1, int a2, int a3, int a4)
{
  int v4; // r10
  int (__fastcall *v6)(int, int, int *); // r4
  int v8; // r8
  int v9; // r7
  int v10; // r6
  int v11; // r4
  int v13; // r4
  int v14; // r0
  int v15; // r0
  int v16; // [sp+0h] [bp-40h] BYREF
  int v17; // [sp+4h] [bp-3Ch] BYREF
  int v18; // [sp+8h] [bp-38h] BYREF
  int v19; // [sp+Ch] [bp-34h] BYREF
  int v20; // [sp+10h] [bp-30h]
  int v21; // [sp+14h] [bp-2Ch]
  int v22; // [sp+18h] [bp-28h] BYREF
  int v23; // [sp+1Ch] [bp-24h]

  v4 = 0;
  v20 = a4;
  v6 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v16 = -1;
  v17 = -1;
  v22 = -1;
  v23 = a2;
  v18 = -1;
  v19 = -1;
  v21 = 0;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = v6(a1, a3, &v22);
  if ( !v11 )
    return sub_7EA138();
  if ( a3 < 0 )
    goto LABEL_4;
  v14 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v23, &v19);
  v9 = v14;
  if ( v14 )
  {
    if ( (*(_WORD *)(v14 + 2) & 4) != 0 )
    {
      if ( !v20 )
      {
LABEL_4:
        *(_DWORD *)(v11 + 4) = a3;
        *(_DWORD *)(v11 + 8) = a3;
        goto LABEL_5;
      }
    }
    else if ( !v20 )
    {
      v10 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v14 + 16), &v18);
      if ( !v10 )
      {
LABEL_38:
        if ( v9 )
          (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v19);
        goto LABEL_28;
      }
      goto LABEL_19;
    }
    v10 = v14;
LABEL_19:
    v15 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v10 + 44), &v17);
    v8 = v15;
    if ( !v15 )
    {
LABEL_35:
      if ( v10 && v10 != v9 )
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v18);
      goto LABEL_38;
    }
    v4 = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(v15 + 4), &v16);
    if ( !v4 )
    {
LABEL_33:
      if ( v8 )
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v17);
      goto LABEL_35;
    }
    if ( !HvpMarkCellDirty(a1, *(_DWORD *)(v10 + 44), 0, 0) || !HvpMarkCellDirty(a1, *(_DWORD *)(v8 + 4), 0, 0) )
    {
LABEL_31:
      if ( v4 )
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v16);
      goto LABEL_33;
    }
    *(_DWORD *)(v11 + 4) = *(_DWORD *)(v8 + 4);
    *(_DWORD *)(v11 + 8) = *(_DWORD *)(v4 + 8);
    *(_DWORD *)(v8 + 4) = a3;
    v21 = 1;
    *(_DWORD *)(v4 + 8) = a3;
LABEL_5:
    if ( CmpAddSecurityCellToCache(a1, a3, 0) >= 0 )
    {
      if ( v4 )
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v16);
      if ( v8 )
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v17);
      if ( v10 && v10 != v9 )
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v18);
      if ( v9 )
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v19);
      v13 = 1;
      goto LABEL_14;
    }
    if ( v21 )
    {
      *(_DWORD *)(v8 + 4) = *(_DWORD *)(v11 + 4);
      *(_DWORD *)(v4 + 8) = *(_DWORD *)(v11 + 8);
    }
    goto LABEL_31;
  }
LABEL_28:
  v13 = 0;
LABEL_14:
  (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v22);
  return v13;
}

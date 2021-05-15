// CmpCommitRenameKeyUoW 
 
int __fastcall CmpCommitRenameKeyUoW(int *a1, _DWORD *a2)
{
  int v3; // r3
  int v5; // r4
  int v6; // r5
  int v7; // r5
  int v8; // r0
  int v9; // r9
  int v10; // r8
  int v11; // r7
  int v12; // r2
  int v13; // r3
  int v14; // r2
  int v15; // r2
  unsigned int v16; // r2
  unsigned int v17; // r2
  int v18; // r1
  int v19; // r2
  int v21; // [sp+8h] [bp-38h] BYREF
  int v22; // [sp+Ch] [bp-34h] BYREF
  int v23; // [sp+10h] [bp-30h] BYREF
  int v24; // [sp+14h] [bp-2Ch]
  _DWORD v25[10]; // [sp+18h] [bp-28h] BYREF

  v22 = -1;
  v23 = -1;
  v21 = -1;
  v24 = 0;
  v3 = a1[6];
  v5 = *(_DWORD *)(v3 + 20);
  v6 = (*(int (__fastcall **)(int, _DWORD, int *))(v5 + 4))(v5, *(_DWORD *)(*(_DWORD *)(v3 + 40) + 24), &v23);
  if ( !v6 )
    return -1073741670;
  if ( !HvpMarkCellDirty(v5, *(_DWORD *)(*(_DWORD *)(a1[6] + 40) + 24), 1, 0)
    || !HvpMarkCellDirty(v5, *(_DWORD *)(a1[6] + 24), 1, 0)
    || !HvpMarkCellDirty(v5, *(_DWORD *)(a1[12] + 24), 1, 0)
    || !CmpMarkIndexDirty(v5, *(_DWORD *)(*(_DWORD *)(a1[6] + 40) + 24), *(_DWORD *)(a1[12] + 24)) )
  {
    v7 = -1073741443;
LABEL_22:
    (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v23);
    return v7;
  }
  v8 = (*(int (__fastcall **)(int, _DWORD, int *))(v5 + 4))(v5, *(_DWORD *)(a1[6] + 24), &v21);
  v9 = v8;
  if ( !v8 )
  {
    v7 = -1073741670;
    goto LABEL_22;
  }
  v10 = HvAllocateCell(v5, -4 - *(_DWORD *)(v8 - 4));
  v11 = v24;
  if ( v10 == -1 )
  {
    v7 = -1073741443;
    goto LABEL_18;
  }
  memmove(v24, v9, -4 - *(_DWORD *)(v9 - 4));
  (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v21);
  v9 = 0;
  if ( !CmpAddSubKeyEx(v5, *(_DWORD *)(*(_DWORD *)(a1[6] + 40) + 24), v10, 0)
    || !CmpRemoveSubKey(v5, *(_DWORD *)(*(_DWORD *)(a1[6] + 40) + 24), *(_DWORD *)(a1[12] + 24)) )
  {
    v7 = -1073741670;
LABEL_20:
    if ( v11 )
    {
      (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v22);
      CmpFreeKeyByCell(v5, v10, 0);
    }
    goto LABEL_22;
  }
  if ( !CmpUpdateParentForEachSon(v5, v10, v12, v13) )
  {
    v7 = -1073741670;
    CmpRemoveSubKey(v5, *(_DWORD *)(*(_DWORD *)(a1[6] + 40) + 24), v10);
    CmpAddSubKeyEx(v5, *(_DWORD *)(*(_DWORD *)(a1[6] + 40) + 24), *(_DWORD *)(a1[12] + 24), 0);
LABEL_18:
    if ( v9 )
      (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v21);
    goto LABEL_20;
  }
  HvFreeCell(v5, *(_DWORD *)(a1[12] + 24));
  CmpFlushNotifiesOnKeyBodyList(a1[12]);
  *(_DWORD *)(a1[12] + 24) = -1;
  CmpMarkKcbDeleted((_DWORD *)a1[12]);
  v14 = a1[6];
  a1[13] = *(_DWORD *)(v14 + 24);
  *(_DWORD *)(v14 + 24) = v10;
  *(_DWORD *)(v11 + 16) = *(_DWORD *)(*(_DWORD *)(a1[6] + 40) + 24);
  *(_DWORD *)(v6 + 4) = *a2;
  *(_DWORD *)(v6 + 8) = a2[1];
  v15 = *(_DWORD *)(a1[6] + 40);
  *(_DWORD *)(v15 + 88) = *a2;
  *(_DWORD *)(v15 + 92) = a2[1];
  if ( (*(_WORD *)(v11 + 2) & 0x20) != 0 )
    v16 = (unsigned __int16)(2 * *(_WORD *)(v11 + 72));
  else
    v16 = *(unsigned __int16 *)(v11 + 72);
  if ( *(unsigned __int16 *)(v6 + 52) < v16 )
  {
    *(_WORD *)(v6 + 52) = v16;
    *(_WORD *)(*(_DWORD *)(a1[6] + 40) + 96) = v16;
  }
  v17 = *(unsigned __int16 *)(v11 + 74);
  if ( *(_DWORD *)(v6 + 56) < v17 )
    *(_DWORD *)(v6 + 56) = v17;
  (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v22);
  (*(void (__fastcall **)(int, int *))(v5 + 8))(v5, &v23);
  v18 = a1[6];
  v25[0] = a1[12];
  v25[1] = v18;
  CmpSearchKeyControlBlockTree((int (__fastcall *)(int, int, int))CmpRefreshParent, *(_DWORD *)(v18 + 20), (int)v25);
  CmpSearchForOpenSubKeys(a1[6], 3, v19, 0);
  return 0;
}

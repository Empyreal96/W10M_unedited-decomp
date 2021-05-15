// CmpCommitAddKeyUoW 
 
int __fastcall CmpCommitAddKeyUoW(int *a1, _DWORD *a2)
{
  int v3; // r3
  int v5; // r8
  int v6; // r7
  int v7; // r5
  int v8; // r4
  __int64 v9; // r0
  int v10; // r0
  unsigned int v11; // r9
  int v12; // r2
  int v13; // r0
  int v14; // r1
  _WORD *v15; // r8
  int v16; // r2
  unsigned int v17; // r2
  unsigned int v18; // r2
  int v19; // r0
  int v21; // [sp+4h] [bp-34h]
  int v22; // [sp+10h] [bp-28h] BYREF
  _DWORD v23[9]; // [sp+14h] [bp-24h] BYREF

  v22 = -1;
  v23[0] = -1;
  v3 = a1[6];
  v5 = a1[10];
  v6 = *(_DWORD *)(v3 + 20);
  v7 = 0;
  v8 = (*(int (__fastcall **)(_DWORD, _DWORD, _DWORD *))(*(_DWORD *)(*(_DWORD *)(v3 + 40) + 20) + 4))(
         *(_DWORD *)(*(_DWORD *)(v3 + 40) + 20),
         *(_DWORD *)(*(_DWORD *)(v3 + 40) + 24),
         v23);
  if ( !v8 )
    return -1073741670;
  if ( !HvpMarkCellDirty(v6, *(_DWORD *)(a1[6] + 24), 1, 0) )
    return -1073741443;
  v9 = *(_QWORD *)(*(_DWORD *)(a1[6] + 40) + 20);
  if ( !HvpMarkCellDirty(v9, SHIDWORD(v9), 1, 0)
    || !HvpMarkCellDirty(*(_DWORD *)(*(_DWORD *)(a1[6] + 40) + 20), *(_DWORD *)(v8 + 4 * v5 + 28), 1, 0) )
  {
    return -1073741443;
  }
  v10 = CmpCopyKeyPartial(v6, *(_DWORD *)(a1[6] + 24), v6, *(_DWORD *)(*(_DWORD *)(a1[6] + 40) + 24), 38, v21, v5);
  v11 = v10;
  if ( v10 == -1 )
    return -1073741670;
  if ( CmpAddSubKeyEx(v6, *(_DWORD *)(*(_DWORD *)(a1[6] + 40) + 24), v10, 0) )
  {
    v12 = a1[6];
    a1[12] = *(_DWORD *)(v12 + 24);
    *(_DWORD *)(v12 + 24) = v11;
    v13 = (*(int (__fastcall **)(int, unsigned int, int *))(v6 + 4))(v6, v11, &v22);
    v14 = *(_DWORD *)(v13 + 44);
    v15 = (_WORD *)v13;
    *(_DWORD *)(v13 + 16) = *(_DWORD *)(*(_DWORD *)(a1[6] + 40) + 24);
    CmpAssignSecurityToKcb(a1[6], v14, 0, 0);
    *(_DWORD *)(v8 + 4) = *a2;
    *(_DWORD *)(v8 + 8) = a2[1];
    v16 = *(_DWORD *)(a1[6] + 40);
    *(_DWORD *)(v16 + 88) = *a2;
    *(_DWORD *)(v16 + 92) = a2[1];
    if ( (v15[1] & 0x20) != 0 )
      v17 = (unsigned __int16)(2 * v15[36]);
    else
      v17 = (unsigned __int16)v15[36];
    if ( *(unsigned __int16 *)(v8 + 52) < v17 )
    {
      *(_WORD *)(v8 + 52) = v17;
      *(_WORD *)(*(_DWORD *)(a1[6] + 40) + 96) = v17;
    }
    v18 = (unsigned __int16)v15[37];
    if ( *(_DWORD *)(v8 + 56) < v18 )
      *(_DWORD *)(v8 + 56) = v18;
    (*(void (__fastcall **)(int, int *))(v6 + 8))(v6, &v22);
  }
  else
  {
    v7 = -1073741670;
  }
  v19 = *(_DWORD *)(*(_DWORD *)(a1[6] + 40) + 20);
  (*(void (__fastcall **)(int, _DWORD *))(v19 + 8))(v19, v23);
  if ( v7 < 0 )
    CmpFreeKeyByCell(v6, v11, 0);
  return v7;
}

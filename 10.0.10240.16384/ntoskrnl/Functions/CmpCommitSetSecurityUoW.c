// CmpCommitSetSecurityUoW 
 
int __fastcall CmpCommitSetSecurityUoW(int a1, _DWORD *a2)
{
  int v3; // r3
  __int64 v4; // r4
  int v5; // r9
  int v6; // r6
  int (__fastcall *v7)(_DWORD, _DWORD, int *); // r3
  _DWORD *v8; // r8
  int v9; // r5
  unsigned int v10; // r7
  int v11; // r0
  int v12; // r10
  int v13; // r3
  int v14; // r0
  _DWORD *v15; // r1
  int v16; // r2
  int v18; // [sp+8h] [bp-38h] BYREF
  int v19; // [sp+Ch] [bp-34h] BYREF
  int v20; // [sp+10h] [bp-30h] BYREF
  unsigned int v21; // [sp+14h] [bp-2Ch]
  _DWORD *v22; // [sp+18h] [bp-28h]
  int v23; // [sp+1Ch] [bp-24h]

  v19 = -1;
  v20 = -1;
  v18 = -1;
  v3 = *(_DWORD *)(a1 + 24);
  v22 = a2;
  v23 = a1;
  v4 = *(_QWORD *)(v3 + 20);
  v5 = 0;
  v6 = 0;
  v7 = *(int (__fastcall **)(_DWORD, _DWORD, int *))(v4 + 4);
  v21 = HIDWORD(v4);
  v8 = (_DWORD *)v7(v4, HIDWORD(v4), &v19);
  if ( !v8 )
    return -1073741670;
  if ( !HvpMarkCellDirty(v4, SHIDWORD(v4), 1, 0) )
  {
LABEL_16:
    v9 = -1073741443;
    goto LABEL_17;
  }
  v5 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(v4 + 4))(v4, *(_DWORD *)(a1 + 48), &v20);
  if ( v5 )
  {
    v10 = v8[11];
    v11 = (*(int (__fastcall **)(_DWORD, unsigned int, int *))(v4 + 4))(v4, v10, &v18);
    v6 = v11;
    if ( v11 )
    {
      v12 = *(_DWORD *)(v11 + 4);
      HIDWORD(v4) = *(_DWORD *)(v11 + 8);
      if ( HvpMarkCellDirty(v4, v10, 1, 0)
        && HvpMarkCellDirty(v4, SHIDWORD(v4), 1, 0)
        && HvpMarkCellDirty(v4, v12, 1, 0) )
      {
        v9 = CmpAssignSecurityDescriptor(v4, v21, (int)v8, (_WORD *)(v5 + 20), 1u);
        if ( v9 < 0 )
        {
          v8[11] = v10;
        }
        else
        {
          v13 = *(_DWORD *)(v6 + 12);
          if ( v13 == 1 )
          {
            (*(void (__fastcall **)(_DWORD, int *))(v4 + 8))(v4, &v18);
            v6 = 0;
            CmpRemoveSecurityCellList(v4, v10);
            HvFreeCell(v4, v10);
          }
          else
          {
            *(_DWORD *)(v6 + 12) = v13 - 1;
          }
          v15 = v22;
          v14 = v23;
          v8[1] = *v22;
          v8[2] = v15[1];
          v16 = *(_DWORD *)(v14 + 24);
          *(_DWORD *)(v16 + 88) = *v15;
          *(_DWORD *)(v16 + 92) = v15[1];
          CmpAssignSecurityToKcb(*(_DWORD *)(v14 + 24), v8[11], 0, 0);
        }
        goto LABEL_17;
      }
      goto LABEL_16;
    }
  }
  v9 = -1073741670;
LABEL_17:
  (*(void (__fastcall **)(_DWORD, int *))(v4 + 8))(v4, &v19);
  if ( v5 )
    (*(void (__fastcall **)(_DWORD, int *))(v4 + 8))(v4, &v20);
  if ( v6 )
    (*(void (__fastcall **)(_DWORD, int *))(v4 + 8))(v4, &v18);
  return v9;
}

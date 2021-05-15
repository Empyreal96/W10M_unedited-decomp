// CmpTransMgrCommitUoW 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmpTransMgrCommitUoW(int *a1, _DWORD *a2)
{
  int v3; // r3
  int v4; // r5
  int v6; // r0
  int v7; // r0
  int v8; // r7 OVERLAPPED
  int v9; // r8 OVERLAPPED
  _DWORD *v10; // r9
  unsigned int v11; // r3
  int v12; // r2
  int v14[2]; // [sp+8h] [bp-28h] BYREF
  int v15[8]; // [sp+10h] [bp-20h] BYREF

  v15[1] = (int)v15;
  v15[0] = (int)v15;
  v3 = a1[9];
  v4 = 0;
  if ( v3 <= 6 )
  {
    if ( v3 == 6 )
    {
      CmpLockRegistry();
      CmpLockKcbExclusive((_DWORD *)a1[6]);
      CmpLockHiveFlusherShared(*(_DWORD *)(a1[6] + 20));
      v6 = CmpCommitDeleteValueKeyUoW(a1, a2);
LABEL_7:
      v4 = v6;
      if ( v6 >= 0 )
        CmpReportNotify(
          a1[6],
          *(void (__fastcall ***)(void *, int *))(a1[6] + 20),
          *(_DWORD *)(a1[6] + 24),
          0,
          4,
          (int)v15);
      goto LABEL_26;
    }
    if ( !v3 )
    {
      CmpLockRegistryExclusive();
      v4 = CmpCommitAddKeyUoW(a1, a2);
      if ( v4 >= 0 )
      {
        *(_DWORD *)(a1[6] + 124) = 0;
        CmpReportNotify(
          a1[6],
          *(void (__fastcall ***)(void *, int *))(a1[6] + 20),
          *(_DWORD *)(a1[6] + 24),
          0,
          1,
          (int)v15);
      }
      goto LABEL_27;
    }
    if ( v3 != 2 )
    {
      if ( (unsigned int)(v3 - 4) <= 1 )
      {
        CmpLockRegistry();
        CmpLockKcbExclusive((_DWORD *)a1[6]);
        CmpLockHiveFlusherShared(*(_DWORD *)(a1[6] + 20));
        v6 = CmpCommitSetValueKeyUoW(a1, a2);
        goto LABEL_7;
      }
      goto LABEL_28;
    }
    CmpLockRegistryExclusive();
    CmpReportNotify(a1[6], *(void (__fastcall ***)(void *, int *))(a1[6] + 20), *(_DWORD *)(a1[6] + 24), 0, 1, (int)v15);
    v7 = CmpCommitDeleteKeyUoW(a1, a2);
LABEL_10:
    v4 = v7;
LABEL_27:
    CmpUnlockRegistry();
    goto LABEL_28;
  }
  switch ( v3 )
  {
    case 7:
      v14[0] = -1;
      CmpLockRegistry();
      CmpLockKcbExclusive((_DWORD *)a1[6]);
      CmpLockHiveFlusherShared(*(_DWORD *)(a1[6] + 20));
      *(_QWORD *)&v8 = *(_QWORD *)(a1[6] + 20);
      v10 = (_DWORD *)(*(int (__fastcall **)(_DWORD, _DWORD, int *))(v8 + 4))(
                        *(_DWORD *)(a1[6] + 20),
                        *(_DWORD *)(a1[6] + 24),
                        v14);
      if ( v10 )
      {
        if ( !HvpMarkCellDirty(v8, v9, 0, 0) )
        {
          (*(void (__fastcall **)(int, int *))(v8 + 8))(v8, v14);
          CmpUnlockHiveFlusher(*(_DWORD *)(a1[6] + 20));
          CmpUnlockKcb((_DWORD *)a1[6]);
          CmpUnlockRegistry();
          v4 = -1073741443;
          break;
        }
        v11 = v10[13] ^ (v10[13] ^ (a1[12] << 16)) & 0xF0000;
        v10[13] = v11;
        *(_DWORD *)(a1[6] + 104) = *(_DWORD *)(a1[6] + 104) & 0xFFFFFFF0 | HIWORD(v11) & 0xF;
        v10[1] = *a2;
        v10[2] = a2[1];
        v12 = a1[6];
        *(_DWORD *)(v12 + 88) = *a2;
        *(_DWORD *)(v12 + 92) = a2[1];
        (*(void (__fastcall **)(int, int *))(v8 + 8))(v8, v14);
      }
      else
      {
        v4 = -1073741670;
      }
LABEL_26:
      CmpUnlockHiveFlusher(*(_DWORD *)(a1[6] + 20));
      CmpUnlockKcb((_DWORD *)a1[6]);
      goto LABEL_27;
    case 9:
      CmpLockRegistryExclusive();
      v4 = CmpCommitSetSecurityUoW(a1, a2);
      if ( v4 >= 0 )
        CmpReportNotify(
          a1[6],
          *(void (__fastcall ***)(void *, int *))(a1[6] + 20),
          *(_DWORD *)(a1[6] + 24),
          0,
          10,
          (int)v15);
      goto LABEL_27;
    case 12:
      CmpLockRegistryExclusive();
      v7 = CmpCommitRenameKeyUoW(a1, a2);
      goto LABEL_10;
  }
LABEL_28:
  CmpSignalDeferredPosts((unsigned int)v15);
  return v4;
}

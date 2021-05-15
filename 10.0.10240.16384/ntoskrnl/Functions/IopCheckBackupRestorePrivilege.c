// IopCheckBackupRestorePrivilege 
 
int __fastcall IopCheckBackupRestorePrivilege(int result, _DWORD *a2, char a3, int a4)
{
  int v4; // r6
  int v6; // r1
  int v7; // r8
  int v9; // r9
  int v10; // r7
  int v11; // r7
  int v12; // r0
  int v13; // r2
  __int64 v14; // kr08_8
  int v15; // r2
  int v16; // [sp+10h] [bp-38h] BYREF
  int v17; // [sp+14h] [bp-34h]
  int v18; // [sp+18h] [bp-30h] BYREF
  int v19; // [sp+1Ch] [bp-2Ch]
  int v20; // [sp+20h] [bp-28h]

  v4 = result;
  v6 = *(_DWORD *)(result + 12);
  v7 = 0;
  v9 = 0;
  if ( (v6 & 0x100) != 0 || (*a2 & 0x4000) == 0 )
    return result;
  v10 = *(_DWORD *)(result + 16);
  *(_DWORD *)(result + 12) = v6 | 0x100;
  if ( (v10 & 0x2000000) != 0 )
    return sub_7FAAB0();
  if ( a4 != 1 && a4 != 3 && a4 != 5 )
  {
    v9 = 1;
    goto LABEL_11;
  }
  if ( (v10 & 0x11200A9) == 0 )
    goto LABEL_11;
  v16 = 1;
  v17 = 1;
  v18 = SeBackupPrivilege;
  v19 = dword_922BA4;
  v20 = 0;
  if ( !a3 )
  {
LABEL_18:
    v7 = 1;
    SeAppendPrivileges(v4, &v16);
    v14 = *(_QWORD *)(v4 + 16);
    result = -17957034;
    *(_DWORD *)(v4 + 20) = v10 & 0x11200A9 | HIDWORD(v14);
    v15 = *(_DWORD *)(v4 + 12);
    *(_DWORD *)(v4 + 16) = v14 & 0xFEEDFF56;
    *(_DWORD *)(v4 + 12) = v15 | 2;
    v10 &= 0xFEEDFF56;
    goto LABEL_11;
  }
  result = *(_DWORD *)(result + 28);
  if ( !result )
  {
    result = *(_DWORD *)(v4 + 36);
    goto LABEL_10;
  }
  if ( *(int *)(v4 + 32) >= 2 )
  {
LABEL_10:
    result = SepPrivilegeCheck(result, &v18, 1, 1, a3);
    if ( !result )
      goto LABEL_11;
    goto LABEL_18;
  }
LABEL_11:
  v11 = v10 & 0x11F0116;
  if ( (v11 || v9)
    && (v17 = 1,
        v16 = 1,
        v19 = dword_922B9C,
        v20 = 0,
        v18 = SeRestorePrivilege,
        (result = SePrivilegeCheck(&v16, (int *)(v4 + 28), a3)) != 0) )
  {
    SeAppendPrivileges(v4, &v16);
    v12 = *(_DWORD *)(v4 + 16);
    *(_DWORD *)(v4 + 20) |= v11;
    v13 = *(_DWORD *)(v4 + 12);
    *(_DWORD *)(v4 + 16) = v12 & 0xFEE0FEE9;
    result = v13 | 4;
    *(_DWORD *)(v4 + 12) = v13 | 4;
  }
  else if ( !v7 )
  {
    *a2 &= 0xFFFFBFFF;
  }
  return result;
}

// VfThunkAddSpecialDriverThunks 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall VfThunkAddSpecialDriverThunks(int a1, int a2, int a3, int a4)
{
  _DWORD *v6; // r4
  int v8; // r0
  int *v9; // r2
  int v10; // r1 OVERLAPPED
  _DWORD *v11; // r1
  int varg_r0[4]; // [sp+18h] [bp+8h] BYREF

  varg_r0[1] = a2;
  varg_r0[2] = a3;
  varg_r0[3] = a4;
  varg_r0[0] = a1;
  v6 = (_DWORD *)ViThunkCreateThunkTable(a2, a3, a4);
  if ( !v6 )
    return -1073741670;
  VfDriverLock();
  if ( (*(_DWORD *)(a4 + 52) & 0x2000000) != 0 )
    ViThunkRecoverPristines(v6);
  v8 = ViThunkFindNextSpecialTable(varg_r0, 1, 0);
  if ( !v8 )
  {
    v8 = ExAllocatePoolWithTag(1, 20, 1951821133);
    if ( !v8 )
    {
      __dmb(0xBu);
      ViDriversLoadLockOwner = 0;
      KeReleaseMutex((int)&ViDriversLoadLock);
      return -1073741670;
    }
    v9 = &ViVerifierDriverAddedSpecialThunkListHead;
    *(_DWORD *)(v8 + 8) = a1;
    *(_DWORD *)(v8 + 12) = v8 + 12;
    *(_DWORD *)(v8 + 16) = v8 + 12;
    v10 = ViVerifierDriverAddedSpecialThunkListHead;
    *(_QWORD *)v8 = *(_QWORD *)&v10;
    if ( *(int **)(v10 + 4) != &ViVerifierDriverAddedSpecialThunkListHead )
      __fastfail(3u);
    *(_DWORD *)(v10 + 4) = v8;
    ViVerifierDriverAddedSpecialThunkListHead = v8;
    ++ViVerifierSpecialThunkTables;
  }
  VfThunksExtended = 1;
  __dmb(0xFu);
  ++ViActiveVerifierThunks;
  v11 = *(_DWORD **)(v8 + 16);
  *v6 = v8 + 12;
  v6[1] = v11;
  if ( *v11 != v8 + 12 )
    __fastfail(3u);
  *v11 = v6;
  *(_DWORD *)(v8 + 16) = v6;
  __dmb(0xBu);
  ViDriversLoadLockOwner = 0;
  KeReleaseMutex((int)&ViDriversLoadLock);
  return 0;
}

// CmUnloadKey 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall CmUnloadKey(int a1, char a2, unsigned int *a3, int a4)
{
  __int64 v5; // r4
  BOOL v7; // r8
  unsigned int *v8; // r9
  unsigned int v9; // r2
  unsigned int v10; // r2
  unsigned int *v11; // r1
  unsigned int v12; // r2
  int v13; // r3
  int v14; // r5
  unsigned int v15; // r2
  unsigned int v16; // r2
  int v17; // r3
  int v18; // r3
  int v19; // r0
  int v20; // r0
  unsigned int v21; // r3
  _DWORD *v22; // r0
  unsigned int v23; // r2
  int v24; // r5
  unsigned int v25; // r1
  __int16 v26; // r3
  unsigned int v27; // r6
  int v29; // r0
  int v30; // r1 OVERLAPPED
  _DWORD *v31; // r2 OVERLAPPED
  unsigned int v32; // r2
  unsigned int v33; // r2
  unsigned int *v34; // r1
  unsigned int v35; // r2
  int v36; // r3
  int v37; // r3
  __int64 v38; // r0
  int v39; // r0
  int **v40; // r0
  unsigned int v41; // r2
  unsigned int v42; // r2
  int v43; // r3
  int v44; // r3
  int v46; // [sp+4h] [bp-24h]
  int v48; // [sp+Ch] [bp-1Ch]
  int v49; // [sp+10h] [bp-18h]
  int v50; // [sp+14h] [bp-14h]
  int v51; // [sp+18h] [bp-10h]
  int v52; // [sp+1Ch] [bp-Ch]

  v46 = (int)a3;
  v5 = *(_QWORD *)(a1 + 20);
  v7 = (*(_DWORD *)(v5 + 3228) & 0x20) != 0;
  __dmb(0xBu);
  v8 = (unsigned int *)(v5 + 3324);
  do
  {
    v9 = __ldrex(v8);
    v10 = v9 + 1;
  }
  while ( __strex(v10, v8) );
  __dmb(0xBu);
  *(_DWORD *)(v5 + 4 * (((_BYTE)v10 - 1) & 0x7F) + 3328) = 6;
  __dmb(0xBu);
  v11 = (unsigned int *)(v5 + 2536);
  do
    v12 = __ldrex(v11);
  while ( !v12 && __strex(1u, v11) );
  __dmb(0xBu);
  if ( v12 || (*(_DWORD *)(v5 + 92) & 0x40) != 0 )
  {
    __dmb(0xBu);
    do
    {
      v41 = __ldrex(v8);
      v42 = v41 + 1;
    }
    while ( __strex(v42, v8) );
    __dmb(0xBu);
    *(_DWORD *)(v5 + 4 * (((_BYTE)v42 - 1) & 0x7F) + 3328) = 7;
    if ( v7 )
    {
      v43 = CmpActiveAppHiveUnloadCount - 1;
      __dmb(0xBu);
      CmpActiveAppHiveUnloadCount = v43;
      v44 = CmpActiveAppHiveUnloadCount;
      __dmb(0xBu);
      if ( !v44 )
      {
        __dmb(0xFu);
        if ( CmpActiveAppHiveUnloadEvent )
          ExfUnblockPushLock((int)&CmpActiveAppHiveUnloadEvent, 0);
      }
    }
    return -1073741431;
  }
  if ( !*(_DWORD *)(v5 + 3256) )
  {
    v13 = *(_DWORD *)(v5 + 92) | 0x40;
    *(_DWORD *)(v5 + 92) = v13;
    CmpTraceHiveUnloadStart(v5 + 1976, v5 + 1984, 64, v13, a2, v46, a4, v48, v49, v50, v51, v52);
    v14 = CmpDestroyHive(v5, SHIDWORD(v5));
    __dmb(0xBu);
    if ( v14 < 0 )
    {
      do
      {
        v32 = __ldrex(v8);
        v33 = v32 + 1;
      }
      while ( __strex(v33, v8) );
      __dmb(0xBu);
      *(_DWORD *)(v5 + 4 * (((_BYTE)v33 - 1) & 0x7F) + 3328) = 9;
      *(_DWORD *)(v5 + 92) &= 0xFFFFFFBF;
      __dmb(0xBu);
      v34 = (unsigned int *)(v5 + 2536);
      do
        v35 = __ldrex(v34);
      while ( v35 == 1 && __strex(0, v34) );
      __dmb(0xBu);
      if ( v7 )
      {
        v36 = CmpActiveAppHiveUnloadCount - 1;
        __dmb(0xBu);
        CmpActiveAppHiveUnloadCount = v36;
        v37 = CmpActiveAppHiveUnloadCount;
        __dmb(0xBu);
        if ( !v37 )
        {
          __dmb(0xFu);
          if ( CmpActiveAppHiveUnloadEvent )
            ExfUnblockPushLock((int)&CmpActiveAppHiveUnloadEvent, 0);
        }
      }
    }
    else
    {
      do
      {
        v15 = __ldrex(v8);
        v16 = v15 + 1;
      }
      while ( __strex(v16, v8) );
      __dmb(0xBu);
      *(_DWORD *)(v5 + 4 * (((_BYTE)v16 - 1) & 0x7F) + 3328) = 8;
      if ( v7 )
      {
        __dmb(0xBu);
        *(_DWORD *)(v5 + 3856) = 1;
        v17 = CmpActiveAppHiveUnloadCount - 1;
        __dmb(0xBu);
        CmpActiveAppHiveUnloadCount = v17;
        v18 = CmpActiveAppHiveUnloadCount;
        __dmb(0xBu);
        if ( !v18 )
        {
          __dmb(0xFu);
          if ( CmpActiveAppHiveUnloadEvent )
            ExfUnblockPushLock((int)&CmpActiveAppHiveUnloadEvent, 0);
        }
      }
      CmpFlushNotifiesOnKeyBodyList(a1);
      CmpMarkKcbDeleted(a1);
      v19 = CmpCleanUpSubKeyInfo(*(_DWORD *)(a1 + 40));
      v20 = CmpUnlockRegistry(v19);
      v21 = *a3 & 0xFFFFFFFD;
      *a3 = v21;
      if ( (v21 & 4) != 0 )
      {
        UNLOCK_HIVE_LOAD(v20);
        *a3 &= 0xFFFFFFFB;
      }
      CmpRemoveFromHiveFileList(v5);
      v22 = CmpDestroySecurityCache((_DWORD *)v5);
      v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v23 + 0x134);
      v24 = v5 + 3232;
      if ( *(_DWORD *)(v5 + 3232) != (_DWORD)v5 + 3232 )
      {
        v29 = CmpLockHiveListExclusive(v22);
        *(_QWORD *)&v30 = *(_QWORD *)v24;
        if ( *(_DWORD *)(*(_DWORD *)v24 + 4) != v24 || *v31 != v24 )
          __fastfail(3u);
        *v31 = v30;
        *(_DWORD *)(v30 + 4) = v31;
        v22 = (_DWORD *)CmpUnlockHiveList(v29);
      }
      v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v26 = *(_WORD *)(v25 + 0x134) + 1;
      *(_WORD *)(v25 + 308) = v26;
      if ( !v26 && *(_DWORD *)(v25 + 100) != v25 + 100 && !*(_WORD *)(v25 + 310) )
        KiCheckForKernelApcDelivery((int)v22);
      if ( (*(_DWORD *)(v5 + 92) & 0x400) != 0 )
      {
        v38 = *(_QWORD *)(v5 + 1816);
        if ( *(_DWORD *)(v38 + 4) != (_DWORD)v5 + 1816 || *(_DWORD *)HIDWORD(v38) != (_DWORD)v5 + 1816 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v38) = v38;
        *(_DWORD *)(v38 + 4) = HIDWORD(v38);
      }
      if ( (*(_DWORD *)(v5 + 3228) & 2) != 0 )
        CmpRemoveHiveFromMapping(v5);
      HIDWORD(v5) = CmpFlushHive(v5, 44);
      if ( HIDWORD(v5) == -1073741811 )
        HIDWORD(v5) = 0;
      if ( v5 < 0 && (*(_BYTE *)(v5 + 72) & 4) != 0 )
      {
        v39 = CmpReferenceKeyControlBlockUnsafe(a1);
        *(_DWORD *)(v5 + 2528) = a1;
        CmpLockHiveListExclusive(v39);
        v40 = (int **)off_920784;
        *(_DWORD *)(v5 + 1824) = &CmpFailedUnloadListHead;
        *(_DWORD *)(v5 + 1828) = v40;
        if ( *v40 != &CmpFailedUnloadListHead )
          __fastfail(3u);
        *v40 = (int *)(v5 + 1824);
        off_920784 = (void *)(v5 + 1824);
        CmpUnlockHiveList(v40);
        CmpArmLazyWriter(1, 0, 0);
        *(_BYTE *)(v5 + 3865) = 1;
        if ( v7 )
        {
          __dmb(0xBu);
          *(_DWORD *)(v5 + 3856) = 0;
          __dmb(0xFu);
          if ( *(_DWORD *)(v5 + 3860) )
            ExfUnblockPushLock(v5 + 3860, 0);
        }
      }
      else
      {
        v27 = *(_DWORD *)(v5 + 952) + 4096;
        HvFreeHive(v5, 1);
        if ( v5 >= 0 && (*(_DWORD *)(v5 + 92) & 0x8000) == 0 && (__int64)(*(_QWORD *)(v5 + 1944) - v27) > 0x100000 )
          CmpDoFileSetSizeEx(v5, 0, v27, 0, 0);
        CmpCmdHiveClose(v5);
        if ( v7 )
        {
          __dmb(0xBu);
          *(_DWORD *)(v5 + 3856) = 0;
          __dmb(0xFu);
          if ( *(_DWORD *)(v5 + 3860) )
            ExfUnblockPushLock(v5 + 3860, 0);
        }
        CmpSignalUnloadEventArrayForHive(v5);
      }
      v14 = 0;
    }
    CmpTraceHiveUnloadStop(v14);
    return v14;
  }
  return sub_7D262C(1, 1);
}

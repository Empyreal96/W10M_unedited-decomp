// CmpDoReconcileNextHive 
 
int __fastcall CmpDoReconcileNextHive(int a1, int *a2)
{
  int v3; // r10
  int v4; // r9
  int v6; // r4
  int v7; // r7
  int v8; // r0
  int v9; // r6
  unsigned int v10; // r2
  __int64 v11; // r0
  int v12; // r1
  unsigned int v13; // r0
  unsigned int v14; // r2
  unsigned int v15; // r6
  unsigned int v16; // r0
  int v17; // r1
  int v18; // r0
  unsigned __int64 v19; // [sp+8h] [bp-30h]

  v3 = 0;
  v4 = dword_60E324 * (_DWORD)dword_989680;
  v19 = (unsigned int)dword_60E324 * (unsigned __int64)(unsigned int)dword_989680;
  if ( !CmpNoWrite )
  {
    if ( CmpGetNextActiveHive(0) )
      return sub_7D37F0(MEMORY[0xFFFF93B0], MEMORY[0xFFFF93B4]);
    v6 = CmpGetNextFailedUnloadHive(0);
    if ( v6 )
    {
      do
      {
        v7 = CmpGetNextFailedUnloadHive(v6);
        if ( CmpFlushHive(v6, 12) >= 0 )
        {
          v8 = KeAbPreAcquire((unsigned int)&CmpHiveListHeadLock, 0, 0);
          v9 = v8;
          do
            v10 = __ldrex((unsigned __int8 *)&CmpHiveListHeadLock);
          while ( __strex(v10 | 1, (unsigned __int8 *)&CmpHiveListHeadLock) );
          __dmb(0xBu);
          if ( (v10 & 1) != 0 )
            ExfAcquirePushLockExclusiveEx(&CmpHiveListHeadLock, v8, (unsigned int)&CmpHiveListHeadLock);
          if ( v9 )
            *(_BYTE *)(v9 + 14) |= 1u;
          v11 = *(_QWORD *)(v6 + 1824);
          if ( *(_DWORD *)(v11 + 4) != v6 + 1824 || *(_DWORD *)HIDWORD(v11) != v6 + 1824 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v11) = v11;
          *(_DWORD *)(v11 + 4) = HIDWORD(v11);
          __pld(&CmpHiveListHeadLock);
          v12 = CmpHiveListHeadLock;
          if ( (CmpHiveListHeadLock & 0xFFFFFFF0) <= 0x10 )
            v13 = 0;
          else
            v13 = CmpHiveListHeadLock - 16;
          if ( (CmpHiveListHeadLock & 2) != 0 )
            goto LABEL_26;
          __dmb(0xBu);
          do
            v14 = __ldrex((unsigned int *)&CmpHiveListHeadLock);
          while ( v14 == v12 && __strex(v13, (unsigned int *)&CmpHiveListHeadLock) );
          if ( v14 != v12 )
LABEL_26:
            ExfReleasePushLock(&CmpHiveListHeadLock, v12);
          KeAbPostRelease((unsigned int)&CmpHiveListHeadLock);
          v15 = *(_DWORD *)(v6 + 952) + 4096;
          HvFreeHive(v6, 1);
          if ( (*(_DWORD *)(v6 + 92) & 0x8000) == 0 && (__int64)(*(_QWORD *)(v6 + 1944) - v15) > 0x100000 )
            CmpDoFileSetSizeEx(v6, 0, v15, 0, 0);
          CmpCmdHiveClose(v6);
          v16 = CmpSignalUnloadEventArrayForHive(v6);
          CmpLockRegistry(v16, v17);
          v18 = CmpDereferenceKeyControlBlock(*(_DWORD *)(v6 + 2528));
          CmpUnlockRegistry(v18);
        }
        else
        {
          v3 = 1;
        }
        v6 = v7;
      }
      while ( v7 );
    }
    if ( v3 )
    {
      *a2 = v4;
      a2[1] = HIDWORD(v19);
    }
  }
  return v3;
}

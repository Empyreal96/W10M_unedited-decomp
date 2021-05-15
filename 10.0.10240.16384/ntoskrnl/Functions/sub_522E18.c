// sub_522E18 
 
void __fastcall sub_522E18(int a1, int a2, int a3)
{
  unsigned int v3; // r5
  _DWORD *v4; // r6
  _DWORD *v5; // r7
  int v6; // r9
  int v7; // r0
  int v8; // r5
  unsigned int v9; // r2
  _DWORD *v10; // r2
  __int64 v11; // kr00_8
  int v12; // r2
  int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  unsigned int v16; // r1

  if ( a3 + 1 >= v3 )
  {
    if ( v5 )
    {
      *v5 = 0;
      v7 = KeAbPreAcquire((unsigned int)&CcAsyncReadWorkQueueLock, 0, 0);
      v8 = v7;
      do
        v9 = __ldrex((unsigned __int8 *)&CcAsyncReadWorkQueueLock);
      while ( __strex(v9 | 1, (unsigned __int8 *)&CcAsyncReadWorkQueueLock) );
      __dmb(0xBu);
      if ( (v9 & 1) != 0 )
        ExfAcquirePushLockExclusiveEx(&CcAsyncReadWorkQueueLock, v7, (unsigned int)&CcAsyncReadWorkQueueLock);
      if ( v8 )
        *(_BYTE *)(v8 + 14) |= 1u;
      v10 = (_DWORD *)*v4;
      if ( (_DWORD *)*v4 != v4 )
      {
        v11 = *(_QWORD *)v10;
        if ( (_DWORD *)v10[1] != v4 || *(_DWORD **)(v11 + 4) != v10 )
          __fastfail(3u);
        *v5 = v10;
        *v4 = v11;
        v12 = CcNumberActiveAsyncReadWorkerThreads;
        *(_DWORD *)(v11 + 4) = v4;
        ++*(_DWORD *)(v12 + 4 * v6);
      }
      __pld(&CcAsyncReadWorkQueueLock);
      v13 = CcAsyncReadWorkQueueLock;
      if ( (CcAsyncReadWorkQueueLock & 0xFFFFFFF0) <= 0x10 )
        v14 = 0;
      else
        v14 = CcAsyncReadWorkQueueLock - 16;
      if ( (CcAsyncReadWorkQueueLock & 2) != 0 )
        goto LABEL_22;
      __dmb(0xBu);
      do
        v15 = __ldrex((unsigned int *)&CcAsyncReadWorkQueueLock);
      while ( v15 == v13 && __strex(v14, (unsigned int *)&CcAsyncReadWorkQueueLock) );
      if ( v15 != v13 )
LABEL_22:
        ExfReleasePushLock(&CcAsyncReadWorkQueueLock, v13);
      KeAbPostRelease((unsigned int)&CcAsyncReadWorkQueueLock);
      if ( !*v5 )
      {
        __dmb(0xBu);
        do
          v16 = __ldrex(&CcDbgFoundAsyncReadThreadListEmpty);
        while ( __strex(v16 + 1, &CcDbgFoundAsyncReadThreadListEmpty) );
        __dmb(0xBu);
      }
    }
    JUMPOUT(0x4586FE);
  }
  JUMPOUT(0x4586E8);
}

// ExShutdownSystem 
 
_DWORD *__fastcall ExShutdownSystem(int a1)
{
  _DWORD *result; // r0
  _DWORD *v3; // r4
  int v4; // r0
  int v5; // r0
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r2

  result = PsGetServerSiloGlobals(0);
  v3 = result;
  if ( a1 )
  {
    if ( a1 == 1 && (PopShutdownCleanly & 2) != 0 )
      result = (_DWORD *)ExSwapinWorkerThreads(0);
  }
  else
  {
    ExpRecordShutdownTime();
    v4 = v3[6];
    ExpTooLateForErrors = 1;
    ExpShuttingDown = 1;
    if ( v4 )
    {
      ObfDereferenceObject(v4);
      v3[6] = 0;
    }
    v5 = v3[5];
    if ( v5 )
    {
      ObfDereferenceObjectWithTag(v5);
      v3[5] = 0;
    }
    v6 = KeAbPreAcquire((unsigned int)&ExpKeyManipLock, 0, 0);
    v7 = v6;
    do
      v8 = __ldrex((unsigned __int8 *)&ExpKeyManipLock);
    while ( __strex(v8 | 1, (unsigned __int8 *)&ExpKeyManipLock) );
    __dmb(0xBu);
    if ( (v8 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&ExpKeyManipLock, v6, (unsigned int)&ExpKeyManipLock);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    if ( ExpControlKey )
    {
      ObfDereferenceObject(ExpControlKey);
      ExpControlKey = 0;
    }
    if ( dword_61A10C )
    {
      ObfDereferenceObject(dword_61A10C);
      dword_61A10C = 0;
    }
    if ( ExpProductTypeKey )
    {
      ObCloseHandle(ExpProductTypeKey);
      ExpProductTypeKey = 0;
    }
    if ( ExpSetupKey )
    {
      ObCloseHandle(ExpSetupKey);
      ExpSetupKey = 0;
    }
    __pld(&ExpKeyManipLock);
    v9 = ExpKeyManipLock;
    v10 = ExpKeyManipLock - 16;
    if ( (ExpKeyManipLock & 0xFFFFFFF0) <= 0x10 )
      v10 = 0;
    if ( (ExpKeyManipLock & 2) != 0 )
      goto LABEL_27;
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)&ExpKeyManipLock);
    while ( v11 == v9 && __strex(v10, (unsigned int *)&ExpKeyManipLock) );
    if ( v11 != v9 )
LABEL_27:
      ExfReleasePushLock(&ExpKeyManipLock, v9);
    result = (_DWORD *)KeAbPostRelease((unsigned int)&ExpKeyManipLock);
  }
  return result;
}

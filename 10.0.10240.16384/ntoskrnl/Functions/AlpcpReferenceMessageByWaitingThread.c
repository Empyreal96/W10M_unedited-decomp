// AlpcpReferenceMessageByWaitingThread 
 
int __fastcall AlpcpReferenceMessageByWaitingThread(int a1, int *a2)
{
  int *v2; // r6
  int v3; // r7
  int v4; // r10
  int v5; // r9
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  int *v9; // r5
  unsigned int v10; // r1
  int v11; // r0
  int v12; // r6
  unsigned int v13; // r2
  unsigned int v14; // r1

  v2 = a2;
  v3 = 0;
  v4 = -1073741275;
  v5 = 0;
  v6 = KeAbPreAcquire((unsigned int)&AlpcpPortListLock, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex((unsigned __int8 *)&AlpcpPortListLock);
  while ( __strex(v8 | 1, (unsigned __int8 *)&AlpcpPortListLock) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&AlpcpPortListLock, v6, (unsigned int)&AlpcpPortListLock);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v9 = (int *)AlpcpPortList;
  if ( (int *)AlpcpPortList != &AlpcpPortList )
  {
    while ( 1 )
    {
      if ( ObReferenceObjectSafe((int)v9) )
      {
        __dmb(0xBu);
        do
          v10 = __ldrex((unsigned int *)&AlpcpPortListLock);
        while ( __strex(v10 - 1, (unsigned int *)&AlpcpPortListLock) );
        if ( (v10 & 2) != 0 && (v10 & 4) == 0 )
          ExfTryToWakePushLock((unsigned int *)&AlpcpPortListLock);
        KeAbPostRelease((unsigned int)&AlpcpPortListLock);
        if ( v3 )
          ObfDereferenceObject(v3);
        v3 = (int)v9;
        v5 = AlpcpReferenceMessageByWaitingThreadPort(a1, v9);
        if ( v5 )
        {
          v2 = a2;
          v4 = 0;
          goto LABEL_31;
        }
        v11 = KeAbPreAcquire((unsigned int)&AlpcpPortListLock, 0, 0);
        v12 = v11;
        do
          v13 = __ldrex((unsigned __int8 *)&AlpcpPortListLock);
        while ( __strex(v13 | 1, (unsigned __int8 *)&AlpcpPortListLock) );
        __dmb(0xBu);
        if ( (v13 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx(&AlpcpPortListLock, v11, (unsigned int)&AlpcpPortListLock);
        if ( v12 )
          *(_BYTE *)(v12 + 14) |= 1u;
      }
      v9 = (int *)*v9;
      if ( v9 == &AlpcpPortList )
      {
        v2 = a2;
        break;
      }
    }
  }
  __dmb(0xBu);
  do
    v14 = __ldrex((unsigned int *)&AlpcpPortListLock);
  while ( __strex(v14 - 1, (unsigned int *)&AlpcpPortListLock) );
  if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&AlpcpPortListLock);
  KeAbPostRelease((unsigned int)&AlpcpPortListLock);
LABEL_31:
  if ( v3 )
    ObfDereferenceObject(v3);
  *v2 = v5;
  return v4;
}

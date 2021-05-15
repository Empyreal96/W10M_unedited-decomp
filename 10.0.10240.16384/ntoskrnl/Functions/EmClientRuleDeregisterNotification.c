// EmClientRuleDeregisterNotification 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall EmClientRuleDeregisterNotification(unsigned int result)
{
  int *v1; // r4
  int v2; // r0
  int v3; // r5
  unsigned int v4; // r2
  unsigned int v5; // r0
  int v6; // r5
  unsigned int *v7; // r2
  unsigned int v8; // r1
  int v9; // r7
  int v10; // r1 OVERLAPPED
  _DWORD *v11; // r2 OVERLAPPED
  unsigned int v12; // r1

  v1 = (int *)result;
  if ( result )
  {
    v2 = KeAbPreAcquire((unsigned int)&EmpDatabaseLock, 0, 0);
    v3 = v2;
    do
      v4 = __ldrex((unsigned __int8 *)&EmpDatabaseLock);
    while ( __strex(v4 | 1, (unsigned __int8 *)&EmpDatabaseLock) );
    __dmb(0xBu);
    if ( (v4 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&EmpDatabaseLock, v2, (unsigned int)&EmpDatabaseLock);
    if ( v3 )
      *(_BYTE *)(v3 + 14) |= 1u;
    v5 = 0;
    if ( v1[2] )
    {
      v6 = 0;
      do
      {
        __dmb(0xBu);
        v7 = *(unsigned int **)(v6 + v1[1]);
        do
          v8 = __ldrex(v7);
        while ( __strex(v8 - 1, v7) );
        __dmb(0xBu);
        v9 = v1[1] + v6 + 12;
        *(_QWORD *)&v10 = *(_QWORD *)v9;
        if ( *(_DWORD *)(*(_DWORD *)v9 + 4) != v9 || *v11 != v9 )
          __fastfail(3u);
        *v11 = v10;
        *(_DWORD *)(v10 + 4) = v11;
        ++v5;
        v6 += 20;
      }
      while ( v5 < v1[2] );
    }
    if ( *v1 )
      ObfDereferenceObject(*v1);
    ExFreePoolWithTag(v1[1]);
    ExFreePoolWithTag((unsigned int)v1);
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)&EmpDatabaseLock);
    while ( __strex(v12 - 1, (unsigned int *)&EmpDatabaseLock) );
    if ( (v12 & 2) != 0 && (v12 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&EmpDatabaseLock);
    result = KeAbPostRelease((unsigned int)&EmpDatabaseLock);
  }
  return result;
}

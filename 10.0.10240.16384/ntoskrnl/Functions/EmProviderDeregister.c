// EmProviderDeregister 
 
unsigned int __fastcall EmProviderDeregister(unsigned int result)
{
  int *v1; // r4
  int v2; // r0
  int v3; // r5
  unsigned int v4; // r2
  unsigned int v5; // r1
  int v6; // r2
  int v7; // r6
  __int64 v8; // kr00_8
  unsigned int i; // r5
  unsigned int *v10; // r2
  unsigned int v11; // r1
  unsigned int v12; // r1
  _DWORD *j; // r6
  int *v14; // r5
  int v15; // r0
  unsigned int k; // r5
  unsigned int *v17; // r2
  unsigned int v18; // r1
  unsigned int v19; // r1
  _DWORD *l; // r6
  unsigned int v21; // r0
  unsigned int v22; // r1

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
    if ( v1[3] )
    {
      v5 = 0;
      if ( v1[4] )
      {
        v6 = 0;
        do
        {
          v7 = v1[3] + v6 + 8;
          v8 = *(_QWORD *)v7;
          if ( *(_DWORD *)(*(_DWORD *)v7 + 4) != v7 || *(_DWORD *)HIDWORD(v8) != v7 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v8) = v8;
          *(_DWORD *)(v8 + 4) = HIDWORD(v8);
          ++v5;
          v6 += 16;
        }
        while ( v5 < v1[4] );
      }
      ExFreePoolWithTag(v1[3]);
    }
    for ( i = 0; i < v1[2]; ++i )
    {
      __dmb(0xBu);
      v10 = (unsigned int *)(*(_DWORD *)(v1[1] + 4 * i) + 16);
      do
      {
        v11 = __ldrex(v10);
        v12 = v11 - 1;
      }
      while ( __strex(v12, v10) );
      __dmb(0xBu);
      if ( !v12 )
      {
        for ( j = *(_DWORD **)(*(_DWORD *)(v1[1] + 4 * i) + 44); j; j = (_DWORD *)*j )
          EmpQueueRuleUpdateState(*(j - 1), 0);
      }
    }
    v14 = (int *)v1[7];
    while ( v14 != v1 + 7 )
    {
      v15 = (int)(v14 - 5);
      v14 = (int *)*v14;
      EmpProviderDeregisterEntry(v15);
    }
    for ( k = 0; k < v1[6]; ++k )
    {
      __dmb(0xBu);
      v17 = (unsigned int *)(*(_DWORD *)(v1[5] + 4 * k) + 20);
      do
      {
        v18 = __ldrex(v17);
        v19 = v18 - 1;
      }
      while ( __strex(v19, v17) );
      __dmb(0xBu);
      if ( !v19 )
      {
        *(_DWORD *)(*(_DWORD *)(v1[5] + 4 * k) + 16) = 0;
        for ( l = *(_DWORD **)(*(_DWORD *)(v1[5] + 4 * k) + 32); l; l = (_DWORD *)*l )
          EmpQueueRuleUpdateState(*(l - 1), 0);
      }
    }
    if ( *v1 )
      ObfDereferenceObject(*v1);
    v21 = v1[5];
    if ( v21 )
      ExFreePoolWithTag(v21);
    ExFreePoolWithTag((unsigned int)v1);
    __dmb(0xBu);
    do
      v22 = __ldrex((unsigned int *)&EmpDatabaseLock);
    while ( __strex(v22 - 1, (unsigned int *)&EmpDatabaseLock) );
    if ( (v22 & 2) != 0 && (v22 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&EmpDatabaseLock);
    result = KeAbPostRelease((unsigned int)&EmpDatabaseLock);
  }
  return result;
}

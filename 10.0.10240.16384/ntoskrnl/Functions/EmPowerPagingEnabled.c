// EmPowerPagingEnabled 
 
unsigned int __fastcall EmPowerPagingEnabled(int a1)
{
  int v2; // r6
  int v3; // r0
  int v4; // r5
  unsigned int v5; // r2
  unsigned int v6; // r1
  unsigned int result; // r0
  int v8; // r0
  int v9; // r6
  unsigned int v10; // r2
  unsigned int v11; // r1
  char v12[40]; // [sp+8h] [bp-28h] BYREF

  v2 = 0;
  v3 = KeAbPreAcquire((unsigned int)&EmpPagingLock, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex((unsigned __int8 *)&EmpPagingLock);
  while ( __strex(v5 | 1, (unsigned __int8 *)&EmpPagingLock) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&EmpPagingLock, v3, (unsigned int)&EmpPagingLock);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  if ( a1 )
  {
    dword_631F1C |= 0x80000000;
  }
  else
  {
    dword_631F1C &= 0x7FFFFFFFu;
    if ( (dword_631F1C & 0x7FFFFFFF) != 0 )
    {
      KeInitializeEvent((int)v12, 1, 0);
      EmpPagingStatus = (int)v12;
      v2 = 1;
    }
  }
  __dmb(0xBu);
  do
    v6 = __ldrex((unsigned int *)&EmpPagingLock);
  while ( __strex(v6 - 1, (unsigned int *)&EmpPagingLock) );
  if ( (v6 & 2) != 0 && (v6 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&EmpPagingLock);
  result = KeAbPostRelease((unsigned int)&EmpPagingLock);
  if ( v2 )
  {
    KeWaitForSingleObject((unsigned int)v12, 0, 0, 0, 0);
    v8 = KeAbPreAcquire((unsigned int)&EmpPagingLock, 0, 0);
    v9 = v8;
    do
      v10 = __ldrex((unsigned __int8 *)&EmpPagingLock);
    while ( __strex(v10 | 1, (unsigned __int8 *)&EmpPagingLock) );
    __dmb(0xBu);
    if ( (v10 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(&EmpPagingLock, v8, (unsigned int)&EmpPagingLock);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    EmpPagingStatus = 0;
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)&EmpPagingLock);
    while ( __strex(v11 - 1, (unsigned int *)&EmpPagingLock) );
    if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)&EmpPagingLock);
    result = KeAbPostRelease((unsigned int)&EmpPagingLock);
  }
  return result;
}

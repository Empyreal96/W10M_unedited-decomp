// EmClientQueryRuleState 
 
int __fastcall EmClientQueryRuleState(unsigned int a1, _DWORD *a2)
{
  int v2; // r4
  int v6; // r0
  int v7; // r6
  unsigned int v8; // r2
  int *v9; // r0
  int *v10; // r6
  unsigned int *v11; // r0
  unsigned int *v12; // r8
  unsigned int v13; // r2
  unsigned int v14; // r2
  unsigned int v15; // r1

  v2 = 0;
  if ( !a1 || !a2 )
    return -1073741811;
  *a2 = 1;
  if ( !EmpAcquirePagingReference() )
    return sub_6947B0();
  v6 = KeAbPreAcquire((unsigned int)&EmpDatabaseLock, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex((unsigned __int8 *)&EmpDatabaseLock);
  while ( __strex(v8 | 1, (unsigned __int8 *)&EmpDatabaseLock) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&EmpDatabaseLock, v6, (unsigned int)&EmpDatabaseLock);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v9 = EmpSearchRuleDatabase(a1);
  v10 = v9;
  if ( v9 && (v11 = EmpSearchTargetRuleList((int)v9), (v12 = v11) != 0) )
  {
    __dmb(0xBu);
    do
      v13 = __ldrex(v11);
    while ( __strex(v13 + 1, v11) );
    __dmb(0xBu);
    EmpUpdateRuleState(v10);
    __dmb(0xBu);
    do
      v14 = __ldrex(v12);
    while ( __strex(v14 - 1, v12) );
    __dmb(0xBu);
    *a2 = v10[4];
  }
  else
  {
    v2 = -1073741275;
  }
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)&EmpDatabaseLock);
  while ( __strex(v15 - 1, (unsigned int *)&EmpDatabaseLock) );
  if ( (v15 & 2) != 0 && (v15 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&EmpDatabaseLock);
  KeAbPostRelease((unsigned int)&EmpDatabaseLock);
  EmpReleasePagingReference();
  return v2;
}

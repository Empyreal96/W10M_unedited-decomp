// EmClientRuleEvaluate 
 
int __fastcall EmClientRuleEvaluate(unsigned int a1, int a2, int a3, int *a4)
{
  int v9; // r0
  int v10; // r4
  unsigned int v11; // r2
  _DWORD *v12; // r0
  _DWORD *v13; // r4
  _DWORD *v14; // r0
  int v15; // r4
  unsigned int v16; // r1
  unsigned int v17; // r0

  if ( !a1 || !a2 || !a4 || !a3 )
    return -1073741811;
  *a4 = 1;
  if ( !EmpAcquirePagingReference() )
    return sub_694750();
  v9 = KeAbPreAcquire((unsigned int)&EmpDatabaseLock, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex((unsigned __int8 *)&EmpDatabaseLock);
  while ( __strex(v11 | 1, (unsigned __int8 *)&EmpDatabaseLock) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&EmpDatabaseLock, v9, (unsigned int)&EmpDatabaseLock);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  v12 = EmpSearchRuleDatabase(a1);
  v13 = v12;
  if ( v12 && (v14 = EmpSearchTargetRuleList((int)v12)) != 0 )
  {
    if ( a3 == v13[10] )
    {
      *a4 = EmpEvaluateTargetRule(v14, a2, a3);
      v15 = 0;
    }
    else
    {
      v15 = -1073741811;
    }
  }
  else
  {
    v15 = -1073741275;
  }
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)&EmpDatabaseLock);
  while ( __strex(v16 - 1, (unsigned int *)&EmpDatabaseLock) );
  if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&EmpDatabaseLock);
  v17 = KeAbPostRelease((unsigned int)&EmpDatabaseLock);
  EmpReleasePagingReference(v17);
  return v15;
}

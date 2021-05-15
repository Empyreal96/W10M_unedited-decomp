// VfDeadlockBeforeCallDriver 
 
int __fastcall VfDeadlockBeforeCallDriver(int a1)
{
  int v1; // r4
  int v2; // r5
  int v3; // r8
  int v4; // r3
  int v5; // r6
  unsigned int v6; // r9
  int v7; // r0
  int v8; // r3
  unsigned int *v9; // r2
  unsigned int v10; // r1

  v1 = 0;
  v2 = 0;
  if ( (*(_DWORD *)(a1 + 8) & 2) == 0 )
    return 0;
  if ( (unsigned int)KeNumberProcessors_0 > 4 )
    return 0;
  if ( !ViDeadlockGlobals )
    return 0;
  v3 = __mrc(15, 0, 13, 0, 3);
  v4 = ViDeadlockDetectionEnabled;
  __dmb(0xBu);
  if ( v4 )
  {
    a1 = ViDeadlockAllocate(3);
    v2 = a1;
    if ( !a1 )
      return 0;
  }
  v5 = 0;
  v6 = ViRaiseIrqlToDpcLevel(a1);
  while ( 1 )
  {
    ViDeadlockDetectionLock(v5);
    v7 = ViDeadlockSearchThread(v3 & 0xFFFFFFC0);
    if ( v7 )
      break;
    v8 = ViDeadlockDetectionEnabled;
    __dmb(0xBu);
    if ( !v8 )
      goto LABEL_17;
    if ( v5 || (v5 = 1, ViDeadlockDetectionTryConvertSharedToExclusive()) )
    {
      v7 = ViDeadlockAddThread(v3 & 0xFFFFFFC0, v2);
      v2 = 0;
      break;
    }
    ViDeadlockDetectionUnlock(0);
  }
  __dmb(0xBu);
  v9 = (unsigned int *)(v7 + 24);
  do
    v10 = __ldrex(v9);
  while ( __strex(v10 + 1, v9) );
  __dmb(0xBu);
  v1 = 1;
LABEL_17:
  ViDeadlockDetectionUnlock(v5);
  ViLowerIrql(v6);
  if ( v2 )
    ViDeadlockFree(v2, 3);
  return v1;
}

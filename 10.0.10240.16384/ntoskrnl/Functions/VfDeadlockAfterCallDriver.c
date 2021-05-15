// VfDeadlockAfterCallDriver 
 
int __fastcall VfDeadlockAfterCallDriver(int result)
{
  int v1; // r3
  int v2; // r4
  unsigned int v3; // r5
  int v4; // r0
  unsigned int *v5; // r2
  unsigned int v6; // r1

  if ( result )
  {
    v1 = ViDeadlockDetectionEnabled;
    __dmb(0xBu);
    if ( v1 )
    {
      if ( (unsigned int)KeNumberProcessors_0 <= 4 )
      {
        v2 = __mrc(15, 0, 13, 0, 3);
        v3 = ViRaiseIrqlToDpcLevel(result);
        ViDeadlockDetectionLock(0);
        v4 = ViDeadlockSearchThread(v2 & 0xFFFFFFC0);
        if ( v4 )
        {
          __dmb(0xBu);
          v5 = (unsigned int *)(v4 + 24);
          do
            v6 = __ldrex(v5);
          while ( __strex(v6 - 1, v5) );
          __dmb(0xBu);
        }
        ViDeadlockDetectionUnlock(0);
        result = ViLowerIrql(v3);
      }
    }
  }
  return result;
}

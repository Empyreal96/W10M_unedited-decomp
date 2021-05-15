// ViDeadlockDetectionLock 
 
int __fastcall ViDeadlockDetectionLock(int a1)
{
  int result; // r0
  int v2; // r4
  unsigned int v3; // r2
  unsigned int v4; // r1
  unsigned int v5; // r1
  unsigned int v6; // r1

  if ( a1 )
  {
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&ViDeadlockDatabaseLock);
    }
    else
    {
      do
        v5 = __ldrex((unsigned __int8 *)&ViDeadlockDatabaseLock + 3);
      while ( __strex(v5 | 0x80, (unsigned __int8 *)&ViDeadlockDatabaseLock + 3) );
      __dmb(0xBu);
      if ( v5 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&ViDeadlockDatabaseLock);
      while ( 1 )
      {
        result = ViDeadlockDatabaseLock;
        if ( (ViDeadlockDatabaseLock & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (ViDeadlockDatabaseLock & 0x40000000) == 0 )
        {
          do
            v6 = __ldrex((unsigned int *)&ViDeadlockDatabaseLock);
          while ( v6 == result && __strex(result | 0x40000000, (unsigned int *)&ViDeadlockDatabaseLock) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    ViDeadlockDatabaseOwner = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  }
  else
  {
    result = (int)&ViDeadlockDatabaseLock;
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = ExpAcquireSpinLockSharedAtDpcLevelInstrumented((unsigned int *)&ViDeadlockDatabaseLock);
    }
    else
    {
      v2 = ViDeadlockDatabaseLock & 0x7FFFFFFF;
      v3 = (ViDeadlockDatabaseLock & 0x7FFFFFFF) + 1;
      do
        v4 = __ldrex((unsigned int *)&ViDeadlockDatabaseLock);
      while ( v4 == v2 && __strex(v3, (unsigned int *)&ViDeadlockDatabaseLock) );
      __dmb(0xBu);
      if ( v4 != v2 )
        result = ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&ViDeadlockDatabaseLock);
    }
  }
  return result;
}

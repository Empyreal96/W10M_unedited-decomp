// ViDeadlockDetectionUnlock 
 
int *__fastcall ViDeadlockDetectionUnlock(int *result)
{
  unsigned int v1; // r1
  unsigned int v2; // r2
  int v3; // [sp+4h] [bp-4h]

  if ( result )
  {
    ViDeadlockDatabaseOwner = 0;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      result = (int *)ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&ViDeadlockDatabaseLock, v3);
    }
    else
    {
      __dmb(0xBu);
      ViDeadlockDatabaseLock = 0;
    }
  }
  else if ( (dword_682604 & 0x10000) != 0 )
  {
    result = (int *)ExpReleaseSpinLockSharedFromDpcLevelInstrumented((unsigned int *)&ViDeadlockDatabaseLock, v3);
  }
  else
  {
    __dmb(0xBu);
    result = &ViDeadlockDatabaseLock;
    do
      v1 = __ldrex((unsigned int *)&ViDeadlockDatabaseLock);
    while ( __strex(v1 & 0xBFFFFFFF, (unsigned int *)&ViDeadlockDatabaseLock) );
    __dmb(0xBu);
    do
      v2 = __ldrex((unsigned int *)&ViDeadlockDatabaseLock);
    while ( __strex(v2 - 1, (unsigned int *)&ViDeadlockDatabaseLock) );
  }
  return result;
}

// ViDeadlockDetectionTryConvertSharedToExclusive 
 
int ViDeadlockDetectionTryConvertSharedToExclusive()
{
  int result; // r0
  unsigned int v1; // r1
  int v2; // r4
  unsigned int v3; // r1

  if ( (dword_682604 & 0x210000) != 0 )
  {
    result = ExpTryConvertSharedSpinLockExclusiveInstrumented(&ViDeadlockDatabaseLock);
    goto LABEL_13;
  }
  do
    v1 = __ldrex((unsigned __int8 *)&ViDeadlockDatabaseLock + 3);
  while ( __strex(v1 | 0x80, (unsigned __int8 *)&ViDeadlockDatabaseLock + 3) );
  __dmb(0xBu);
  if ( v1 >> 7 )
  {
    result = 0;
LABEL_13:
    if ( !result )
      return result;
    goto LABEL_14;
  }
  while ( 1 )
  {
    v2 = ViDeadlockDatabaseLock;
    if ( (ViDeadlockDatabaseLock & 0xBFFFFFFF) == -2147483647 )
      break;
    if ( (ViDeadlockDatabaseLock & 0x40000000) == 0 )
    {
      do
        v3 = __ldrex((unsigned int *)&ViDeadlockDatabaseLock);
      while ( v3 == v2 && __strex(v2 | 0x40000000, (unsigned int *)&ViDeadlockDatabaseLock) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  result = 1;
LABEL_14:
  ViDeadlockDatabaseOwner = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  return result;
}

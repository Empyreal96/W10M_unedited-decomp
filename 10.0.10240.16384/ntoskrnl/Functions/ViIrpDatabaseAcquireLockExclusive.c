// ViIrpDatabaseAcquireLockExclusive 
 
int __fastcall ViIrpDatabaseAcquireLockExclusive(_BYTE *a1)
{
  char v2; // r7
  int result; // r0
  unsigned int v4; // r1
  unsigned int v5; // r1

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    result = ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&ViIrpDatabaseLock);
  }
  else
  {
    do
      v4 = __ldrex((unsigned __int8 *)&ViIrpDatabaseLock + 3);
    while ( __strex(v4 | 0x80, (unsigned __int8 *)&ViIrpDatabaseLock + 3) );
    __dmb(0xBu);
    if ( v4 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&ViIrpDatabaseLock);
    while ( 1 )
    {
      result = ViIrpDatabaseLock;
      if ( (ViIrpDatabaseLock & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (ViIrpDatabaseLock & 0x40000000) == 0 )
      {
        do
          v5 = __ldrex((unsigned int *)&ViIrpDatabaseLock);
        while ( v5 == result && __strex(result | 0x40000000, (unsigned int *)&ViIrpDatabaseLock) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  *a1 = v2;
  ViIrpDatabaseExclusiveLockOwner = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  return result;
}

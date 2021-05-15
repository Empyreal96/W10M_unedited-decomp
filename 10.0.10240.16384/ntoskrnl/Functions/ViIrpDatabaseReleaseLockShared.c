// ViIrpDatabaseReleaseLockShared 
 
__int64 __fastcall ViIrpDatabaseReleaseLockShared(int a1)
{
  unsigned int v2; // r1
  unsigned int v3; // r2

  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&ViIrpDatabaseLock);
  }
  else
  {
    __dmb(0xBu);
    do
      v2 = __ldrex((unsigned int *)&ViIrpDatabaseLock);
    while ( __strex(v2 & 0xBFFFFFFF, (unsigned int *)&ViIrpDatabaseLock) );
    __dmb(0xBu);
    do
      v3 = __ldrex((unsigned int *)&ViIrpDatabaseLock);
    while ( __strex(v3 - 1, (unsigned int *)&ViIrpDatabaseLock) );
  }
  return KfLowerIrql(a1);
}

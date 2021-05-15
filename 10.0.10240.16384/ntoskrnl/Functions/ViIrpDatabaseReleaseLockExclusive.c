// ViIrpDatabaseReleaseLockExclusive 
 
__int64 __fastcall ViIrpDatabaseReleaseLockExclusive(int a1)
{
  int vars4; // [sp+Ch] [bp+4h]

  ViIrpDatabaseExclusiveLockOwner = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&ViIrpDatabaseLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    ViIrpDatabaseLock = 0;
  }
  return KfLowerIrql(a1);
}

// VfIrpLogLockDatabase 
 
int __fastcall VfIrpLogLockDatabase(int a1)
{
  int v2; // r7
  unsigned int v3; // r2
  int v4; // r5
  int vars4; // [sp+14h] [bp+4h]

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)&ViIrpLogDatabaseLock);
  }
  else
  {
    do
      v3 = __ldrex((unsigned int *)&ViIrpLogDatabaseLock);
    while ( __strex(1u, (unsigned int *)&ViIrpLogDatabaseLock) );
    __dmb(0xBu);
    if ( v3 )
      KxWaitForSpinLockAndAcquire((unsigned int *)&ViIrpLogDatabaseLock);
  }
  if ( *(_DWORD *)(ViIrpLogDatabase + 12 * a1) )
  {
    v4 = -1073741267;
  }
  else
  {
    *(_DWORD *)(ViIrpLogDatabase + 12 * a1) = 1;
    v4 = 0;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&ViIrpLogDatabaseLock, vars4);
  }
  else
  {
    __dmb(0xBu);
    ViIrpLogDatabaseLock = 0;
  }
  KfLowerIrql(v2);
  return v4;
}

// ViIrpDatabaseAcquireLockShared 
 
int *__fastcall ViIrpDatabaseAcquireLockShared(_BYTE *a1)
{
  char v2; // r6
  int *result; // r0
  int v4; // r4
  unsigned int v5; // r2
  unsigned int v6; // r1

  v2 = KfRaiseIrql(2);
  result = &ViIrpDatabaseLock;
  if ( (dword_682604 & 0x210000) != 0 )
  {
    result = (int *)ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&ViIrpDatabaseLock);
  }
  else
  {
    v4 = ViIrpDatabaseLock & 0x7FFFFFFF;
    v5 = (ViIrpDatabaseLock & 0x7FFFFFFF) + 1;
    do
      v6 = __ldrex((unsigned int *)&ViIrpDatabaseLock);
    while ( v6 == v4 && __strex(v5, (unsigned int *)&ViIrpDatabaseLock) );
    __dmb(0xBu);
    if ( v6 != v4 )
      result = (int *)ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&ViIrpDatabaseLock);
  }
  *a1 = v2;
  return result;
}

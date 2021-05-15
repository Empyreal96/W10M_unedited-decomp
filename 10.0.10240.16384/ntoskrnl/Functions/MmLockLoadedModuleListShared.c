// MmLockLoadedModuleListShared 
 
int *__fastcall MmLockLoadedModuleListShared(_BYTE *a1)
{
  unsigned int v2; // r0
  int *result; // r0
  int v4; // r4
  unsigned int v5; // r2
  unsigned int v6; // r1

  v2 = KeGetCurrentIrql(a1);
  *a1 = v2;
  if ( v2 < 0xC )
    KfRaiseIrql(12);
  result = &PsLoadedModuleSpinLock;
  if ( (dword_682604 & 0x210000) != 0 )
    return (int *)ExpAcquireSpinLockSharedAtDpcLevelInstrumented(&PsLoadedModuleSpinLock);
  v4 = PsLoadedModuleSpinLock & 0x7FFFFFFF;
  v5 = (PsLoadedModuleSpinLock & 0x7FFFFFFF) + 1;
  do
    v6 = __ldrex((unsigned int *)&PsLoadedModuleSpinLock);
  while ( v6 == v4 && __strex(v5, (unsigned int *)&PsLoadedModuleSpinLock) );
  __dmb(0xBu);
  if ( v6 != v4 )
    result = (int *)ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&PsLoadedModuleSpinLock);
  return result;
}

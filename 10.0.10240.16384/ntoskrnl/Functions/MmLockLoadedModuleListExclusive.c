// MmLockLoadedModuleListExclusive 
 
int __fastcall MmLockLoadedModuleListExclusive(_BYTE *a1)
{
  unsigned int v2; // r0
  int result; // r0
  unsigned int v4; // r1
  int v5; // r4
  unsigned int v6; // r1

  v2 = KeGetCurrentIrql(a1);
  *a1 = v2;
  if ( v2 < 0xC )
    v2 = KfRaiseIrql(12);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_519190(v2);
  do
    v4 = __ldrex((unsigned __int8 *)&PsLoadedModuleSpinLock + 3);
  while ( __strex(v4 | 0x80, (unsigned __int8 *)&PsLoadedModuleSpinLock + 3) );
  __dmb(0xBu);
  if ( v4 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&PsLoadedModuleSpinLock);
  result = 0x40000000;
  while ( 1 )
  {
    v5 = PsLoadedModuleSpinLock;
    if ( (PsLoadedModuleSpinLock & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (PsLoadedModuleSpinLock & 0x40000000) == 0 )
    {
      do
        v6 = __ldrex((unsigned int *)&PsLoadedModuleSpinLock);
      while ( v6 == v5 && __strex(v5 | 0x40000000, (unsigned int *)&PsLoadedModuleSpinLock) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  return result;
}

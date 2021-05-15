// MmUnlockLoadedModuleListShared 
 
int __fastcall MmUnlockLoadedModuleListShared(int a1)
{
  unsigned int v2; // r1
  unsigned int v3; // r2

  if ( (dword_682604 & 0x10000) != 0 )
    return sub_50EB68();
  __dmb(0xBu);
  do
    v2 = __ldrex((unsigned int *)&PsLoadedModuleSpinLock);
  while ( __strex(v2 & 0xBFFFFFFF, (unsigned int *)&PsLoadedModuleSpinLock) );
  __dmb(0xBu);
  do
    v3 = __ldrex((unsigned int *)&PsLoadedModuleSpinLock);
  while ( __strex(v3 - 1, (unsigned int *)&PsLoadedModuleSpinLock) );
  return KfLowerIrql(a1);
}

// MmUnlockLoadedModuleListExclusive 
 
int __fastcall MmUnlockLoadedModuleListExclusive(int a1)
{
  if ( (dword_682604 & 0x10000) != 0 )
    return sub_519180();
  __dmb(0xBu);
  PsLoadedModuleSpinLock = 0;
  return KfLowerIrql(a1);
}

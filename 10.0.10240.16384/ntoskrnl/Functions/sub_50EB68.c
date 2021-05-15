// sub_50EB68 
 
void sub_50EB68()
{
  ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&PsLoadedModuleSpinLock);
  JUMPOUT(0x4C3D9E);
}

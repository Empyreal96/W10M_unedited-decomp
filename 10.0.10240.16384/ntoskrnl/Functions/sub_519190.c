// sub_519190 
 
void sub_519190()
{
  ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&PsLoadedModuleSpinLock);
  JUMPOUT(0x4DA7DC);
}

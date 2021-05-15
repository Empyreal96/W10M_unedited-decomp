// sub_519180 
 
void __fastcall sub_519180(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&PsLoadedModuleSpinLock, a8);
  JUMPOUT(0x4DA768);
}

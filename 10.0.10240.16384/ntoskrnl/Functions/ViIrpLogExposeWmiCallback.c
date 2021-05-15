// ViIrpLogExposeWmiCallback 
 
unsigned int __fastcall ViIrpLogExposeWmiCallback(unsigned int a1, int a2, int a3, int a4)
{
  VfDdiExposeWmiObjects(a1, a2, a3, a4);
  ViIrpLogDdiLock = 2;
  return ExFreePoolWithTag(a1);
}

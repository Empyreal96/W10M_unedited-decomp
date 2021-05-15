// MiReturnFsDirectPages 
 
int __fastcall MiReturnFsDirectPages(int a1, int a2)
{
  return MiRemovePhysicalMemory(a1, a2, 2);
}

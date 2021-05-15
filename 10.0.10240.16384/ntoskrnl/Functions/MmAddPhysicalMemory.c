// MmAddPhysicalMemory 
 
int __fastcall MmAddPhysicalMemory(int a1, int a2)
{
  return MiAddPhysicalMemoryChunks(a1, a1, a2);
}

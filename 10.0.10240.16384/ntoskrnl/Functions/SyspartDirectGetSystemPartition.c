// SyspartDirectGetSystemPartition 
 
int __fastcall SyspartDirectGetSystemPartition(int a1, int a2, int a3, int a4, int a5, int a6)
{
  return SiGetSystemDeviceName(SiGetSystemPartition, a1, a2, a3, a5, a6);
}

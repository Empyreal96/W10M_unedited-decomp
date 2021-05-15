// SyspartDirectGetSystemDisk 
 
int __fastcall SyspartDirectGetSystemDisk(int a1, unsigned int a2, unsigned __int16 *a3)
{
  return SiGetSystemDeviceName((int (__fastcall *)(int, unsigned __int16 **))SiGetSystemDisk, a1, a2, a3);
}

// VfZwDeviceIoControlFile 
 
int __fastcall VfZwDeviceIoControlFile(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  if ( ViZwShouldCheck(a1, a2) )
  {
    ViZwCheckVirtualAddress(a3);
    ViZwCheckVirtualAddress(a4);
    ViZwCheckVirtualAddress(a5);
    ViZwCheckVirtualAddress(a7);
    ViZwCheckVirtualAddress(a9);
    ((void (__fastcall *)())ViZwCheckApcRequirement)();
  }
  return pXdvZwDeviceIoControlFile(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
}

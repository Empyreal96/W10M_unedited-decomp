// SiGetDefaultSystemDisk 
 
int __fastcall SiGetDefaultSystemDisk(int a1, _DWORD *a2)
{
  if ( a1 == 1 )
    return SiGetBiosSystemDisk(a2);
  if ( a1 == 2 )
    return SiGetEfiSystemDevice(0, (int)a2, a2);
  return -1073741637;
}

// IoAttachDeviceToDeviceStackSafe 
 
int __fastcall IoAttachDeviceToDeviceStackSafe(unsigned int a1, int a2, int *a3)
{
  int result; // r0

  if ( IopAttachDeviceToDeviceStackSafe(a1, a2, a3) )
    result = 0;
  else
    result = -1073741810;
  return result;
}

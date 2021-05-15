// IoAttachDeviceByPointer 
 
int __fastcall IoAttachDeviceByPointer(unsigned int a1, int a2)
{
  int result; // r0

  if ( IopAttachDeviceToDeviceStackSafe(a1, a2, 0) )
    result = 0;
  else
    result = -1073741810;
  return result;
}

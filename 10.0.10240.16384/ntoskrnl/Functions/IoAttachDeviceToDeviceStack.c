// IoAttachDeviceToDeviceStack 
 
int __fastcall IoAttachDeviceToDeviceStack(int a1, int a2)
{
  return IopAttachDeviceToDeviceStackSafe(a1, a2, 0);
}

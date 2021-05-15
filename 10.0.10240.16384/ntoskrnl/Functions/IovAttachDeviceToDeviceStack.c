// IovAttachDeviceToDeviceStack 
 
int __fastcall IovAttachDeviceToDeviceStack(int result, int a2)
{
  int v3; // r3

  v3 = VfIoDisabled;
  __dmb(0xBu);
  if ( !v3 )
  {
    VfXdvDriverCaptureIoCallbacks(*(_DWORD *)(result + 8));
    result = IovUtilFlushStackCache(a2);
  }
  return result;
}

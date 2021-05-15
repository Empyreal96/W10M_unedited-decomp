// IopDecrementDeviceObjectHandleCount 
 
int __fastcall IopDecrementDeviceObjectHandleCount(_DWORD *a1)
{
  return IopDecrementDeviceObjectRef(a1, 0, 0);
}

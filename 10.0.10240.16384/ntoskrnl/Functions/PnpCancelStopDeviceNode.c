// PnpCancelStopDeviceNode 
 
int *__fastcall PnpCancelStopDeviceNode(int *result)
{
  int *v1; // r4
  int v2; // r1

  v1 = result;
  if ( result[43] == 777 )
  {
    if ( (result[114] & 0x20) == 0 )
      KeBugCheckEx(202, 13, (int)result, 32, 0);
    PoFxIdleDevice(result[4]);
    v2 = v1[4];
    v1[114] &= 0xFFFFFFDF;
    IopQueryReconfiguration(6, v2);
    result = (int *)PipRestoreDevNodeState(v1);
    if ( (v1[67] & 0x1000000) != 0 )
    {
      PnpUnlockMountableDevice(v1[4]);
      result = (int *)PipClearDevNodeFlags((int)v1, 0x1000000);
    }
  }
  return result;
}

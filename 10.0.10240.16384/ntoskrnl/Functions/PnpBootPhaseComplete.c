// PnpBootPhaseComplete 
 
int PnpBootPhaseComplete()
{
  int result; // r0
  int v1; // r0

  result = PiPnpRtlInit(2);
  if ( result >= 0 )
  {
    PnpBootMode = 0;
    v1 = PnpRequestDeviceAction(*(int **)(IopRootDeviceNode + 16), 2, 0, 39, 0, 0);
    result = PpDevCfgProcessDevices(v1);
  }
  return result;
}

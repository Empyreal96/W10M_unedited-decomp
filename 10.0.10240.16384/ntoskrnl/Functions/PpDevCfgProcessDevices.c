// PpDevCfgProcessDevices 
 
int PpDevCfgProcessDevices()
{
  int result; // r0

  if ( (PiDevCfgMode & 2) != 0 )
    result = PipForDeviceNodeSubtree(IopRootDeviceNode, (int)PiDevCfgProcessDeviceCallback, 0, (int)&IopRootDeviceNode);
  else
    result = 0;
  return result;
}

// PnpMarkHalDeviceNode 
 
int PnpMarkHalDeviceNode()
{
  int result; // r0
  int v1; // r3

  result = *(_DWORD *)(IopRootDeviceNode + 4);
  if ( result )
  {
    v1 = *(_DWORD *)(result + 172);
    if ( (v1 == 775 || v1 == 776) && (*(_DWORD *)(result + 268) & 0x1000) == 0 )
    {
      IopInitHalDeviceNode = *(_DWORD *)(IopRootDeviceNode + 4);
      result = PipSetDevNodeFlags(result, 4);
    }
    else
    {
      result = sub_970AD4();
    }
  }
  return result;
}

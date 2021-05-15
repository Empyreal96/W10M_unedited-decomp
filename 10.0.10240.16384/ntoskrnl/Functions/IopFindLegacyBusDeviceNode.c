// IopFindLegacyBusDeviceNode 
 
int __fastcall IopFindLegacyBusDeviceNode(unsigned int a1)
{
  int result; // r0

  if ( a1 == 15 || a1 > 0x11 )
    result = IopRootDeviceNode;
  else
    result = sub_80E090();
  return result;
}

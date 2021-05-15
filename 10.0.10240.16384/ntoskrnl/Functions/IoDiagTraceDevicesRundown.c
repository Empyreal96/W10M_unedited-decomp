// IoDiagTraceDevicesRundown 
 
int IoDiagTraceDevicesRundown()
{
  _DWORD *v0; // r3
  _DWORD *v1; // r4
  _DWORD *v2; // r3

  IoControlPnpDeviceActionQueue(1);
  v0 = *(_DWORD **)(IopRootDeviceNode + 4);
  v1 = (_DWORD *)IopRootDeviceNode;
  while ( v0 )
  {
    v1 = v0;
    v0 = (_DWORD *)v0[1];
  }
  while ( v1 != (_DWORD *)IopRootDeviceNode )
  {
    PoDiagTraceDeviceRundown(v1, v1 + 5, v1 + 7, v1[20]);
    v2 = (_DWORD *)*v1;
    if ( *v1 )
    {
      do
      {
        v1 = v2;
        v2 = (_DWORD *)v2[1];
      }
      while ( v2 );
    }
    else
    {
      v1 = (_DWORD *)v1[2];
    }
  }
  return IoControlPnpDeviceActionQueue(0);
}

// PnpStopDeviceSubtree 
 
int __fastcall PnpStopDeviceSubtree(int result)
{
  _DWORD *v1; // r5
  _DWORD *i; // r4

  v1 = (_DWORD *)result;
  for ( i = *(_DWORD **)(result + 4); i; i = (_DWORD *)*i )
    result = PnpStopDeviceSubtree(i);
  if ( v1[43] == 777 )
  {
    IopQueryReconfiguration(4, v1[4]);
    result = PipSetDevNodeState(v1, 778);
  }
  return result;
}

// PnpDeviceObjectToDeviceInstance 
 
int __fastcall PnpDeviceObjectToDeviceInstance(int a1)
{
  if ( !*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) )
    JUMPOUT(0x7CB6CA);
  return sub_7CB6B0();
}

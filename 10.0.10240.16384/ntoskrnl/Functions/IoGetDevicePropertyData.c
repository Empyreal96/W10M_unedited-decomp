// IoGetDevicePropertyData 
 
int __fastcall IoGetDevicePropertyData(int a1)
{
  int v1; // r3

  if ( !a1 )
    JUMPOUT(0x7DF118);
  v1 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  if ( !v1 || (*(_DWORD *)(v1 + 268) & 0x20000) != 0 )
    sub_7DF078();
  return PnpGetDevicePropertyData();
}

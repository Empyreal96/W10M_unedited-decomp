// IopGetLegacyVetoListDeviceNode 
 
int __fastcall IopGetLegacyVetoListDeviceNode(int a1, int a2)
{
  _DWORD *i; // r4

  if ( (*(_DWORD *)(a1 + 368) & 0x8000) != 0 )
    return sub_7BDE64();
  for ( i = *(_DWORD **)(a1 + 4); ; i = (_DWORD *)*i )
  {
    if ( !i )
      return 1;
    if ( !IopGetLegacyVetoListDeviceNode(i, a2) )
      break;
  }
  return 0;
}

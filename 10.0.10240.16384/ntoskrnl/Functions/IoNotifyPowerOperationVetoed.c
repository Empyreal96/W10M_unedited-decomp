// IoNotifyPowerOperationVetoed 
 
int __fastcall IoNotifyPowerOperationVetoed(int a1, int a2, int a3)
{
  if ( !a2 )
    a2 = *(_DWORD *)(IopRootDeviceNode + 16);
  if ( !*(_DWORD *)(*(_DWORD *)(a2 + 176) + 20) )
    return -1073741584;
  if ( *(_DWORD *)(*(_DWORD *)(a3 + 176) + 20) )
    return PnpSetPowerVetoEvent();
  return -1073741583;
}

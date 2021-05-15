// PnpDeleteLockedDeviceNode 
 
int __fastcall PnpDeleteLockedDeviceNode(_DWORD *a1, int a2, int a3, _DWORD *a4, unsigned __int16 *a5)
{
  int v5; // r6

  v5 = 0;
  if ( a2 == 2 )
  {
    PoFxActivateDevice(a1[4]);
    a1[114] |= 0x10u;
    PnpRemoveLockedDeviceNode(a1, a3);
    return v5;
  }
  if ( !a2 )
  {
    PoFxActivateDevice(a1[4]);
    a1[114] |= 4u;
    return PnpQueryRemoveLockedDeviceNode((int)a1, a3, a4, a5);
  }
  if ( a2 != 1 )
  {
    if ( a2 == 3 )
    {
      PoFxActivateDevice(a1[4]);
      a1[114] |= 8u;
      PnpSurpriseRemoveLockedDeviceNode(a1, a3);
    }
    return v5;
  }
  return sub_7E0534();
}

// PiSwDispatch 
 
int __fastcall PiSwDispatch(int a1, int a2)
{
  unsigned __int8 *v3; // r6
  int v4; // r4
  int v5; // r3
  int v6; // r2

  v3 = *(unsigned __int8 **)(a2 + 96);
  v4 = *(_DWORD *)(a2 + 24);
  v5 = *v3;
  if ( v5 != 14 )
  {
    if ( *v3 )
    {
      if ( v5 == 2 )
      {
        if ( *(_DWORD *)(*((_DWORD *)v3 + 7) + 16) )
        {
          PiSwDeviceDereference();
          *(_DWORD *)(*((_DWORD *)v3 + 7) + 16) = 0;
        }
        v4 = 0;
        *(_DWORD *)(a2 + 24) = 0;
      }
      else
      {
        if ( v5 != 18 )
          return v4;
        if ( *(_DWORD *)(*((_DWORD *)v3 + 7) + 16) )
          PiSwIrpCleanup();
        v4 = 0;
        *(_DWORD *)(a2 + 24) = 0;
      }
    }
    else
    {
      *(_DWORD *)(*((_DWORD *)v3 + 7) + 16) = 0;
      if ( PiAuDoesClientHaveAccess(128) )
        v4 = 0;
      else
        v4 = -1073741790;
      *(_DWORD *)(a2 + 24) = v4;
    }
    IofCompleteRequest(a2, 0);
    return v4;
  }
  v6 = *((_DWORD *)v3 + 4);
  switch ( v6 )
  {
    case 4654080:
      return PiSwIrpStartCreate(a2);
    case 4654084:
      return PiSwIrpPropertySet(a2);
    case 4654088:
      return PiSwIrpInterfaceRegister(a2);
    case 4654092:
      return PiSwIrpInterfaceSetState(a2);
    case 4654096:
      return PiSwIrpInterfacePropertySet(a2);
    case 4654100:
      return PiSwIrpSetLifetime(a2);
    case 4654104:
      return PiSwIrpGetLifetime(a2);
  }
  return sub_7E9370(a2);
}

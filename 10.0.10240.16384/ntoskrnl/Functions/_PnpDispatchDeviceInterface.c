// _PnpDispatchDeviceInterface 
 
int __fastcall PnpDispatchDeviceInterface(int a1, unsigned __int16 *a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r0

  switch ( a4 )
  {
    case 1:
      v5 = CmValidateDeviceInterfaceName(a1, a2);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 2:
      v5 = CmOpenDeviceInterfaceRegKey(a1, a2, 48);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 3:
      v5 = CmCreateDeviceInterface(a1, a2, *a5, a5 + 1, a5 + 2, a5[3] & 0xFFFF0000);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 4:
      v5 = CmDeleteDeviceInterface(a1, a2, *a5 & 0xFFFF0000);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 5:
      if ( *a5 )
        return sub_7C6C44();
      v5 = CmGetMatchingDeviceInterfaceList(a1, 0, 0, a5[2], a5[3], a5[4], a5[5] & 0xFFFF0000);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 6:
      v5 = CmGetDeviceInterfaceMappedPropertyKeys(a1, a2, *a5, 0, a5[3], a5[4], a5[5]);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 7:
      v5 = CmGetDeviceInterfaceMappedPropertyLocales(a1, a2, a5, a5[1], a5[2], a5[3], a5[4]);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 8:
      v5 = CmGetDeviceInterfaceMappedProperty(a1, a2, *a5, a5[1], a5[2], a5[3], a5[4], a5[5], a5[6]);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 9:
      v5 = CmSetDeviceInterfaceMappedProperty(a1, a2, *a5, a5[1], a5[2], a5[3], a5[4], a5[5]);
      return PnpMapCmStatusToDispatchStatus(v5);
    default:
      v5 = -1073741811;
      return PnpMapCmStatusToDispatchStatus(v5);
  }
}

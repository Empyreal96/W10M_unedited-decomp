// _PnpDispatchDevice 
 
int __fastcall PnpDispatchDevice(int a1, unsigned __int16 *a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r0

  switch ( a4 )
  {
    case 1:
      v5 = CmValidateDeviceName(a1, a2, a4 - 1, a4);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 2:
      v5 = CmOpenDeviceRegKey(a1, (int)a2, 16, 0, *a5, *((_BYTE *)a5 + 4), a5[2], a5 + 3);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 3:
      v5 = CmCreateDevice(a1, a2, *a5, a5 + 1, a5 + 2, a5[3] & 0xFFFF0000);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 4:
      v5 = CmDeleteDevice(a1, a2, *a5 & 0xFFFF0000);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 5:
      if ( *a5 )
        return sub_7C6A10();
      v5 = CmGetMatchingDeviceList(a1, 0, 0, a5[2], a5[3], a5[4], a5[5] & 0xFFFF0000);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 6:
      v5 = CmGetDeviceMappedPropertyKeys(a1, a2, *a5, 0, a5[3], a5[4], a5[5]);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 7:
      v5 = CmGetDeviceMappedPropertyLocales(a1, a2, a5, a5[1], a5[2], a5[3], a5[4]);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 8:
      v5 = CmGetDeviceMappedProperty(a1, a2, *a5, a5[1], a5[2], a5[3], a5[4], a5[5], a5[6]);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 9:
      v5 = CmSetDeviceMappedProperty(a1, a2, *a5, a5[1], a5[2], a5[3], a5[4], a5[5]);
      return PnpMapCmStatusToDispatchStatus(v5);
    default:
      v5 = -1073741811;
      return PnpMapCmStatusToDispatchStatus(v5);
  }
}

// _PnpDispatchInstallerClass 
 
int __fastcall PnpDispatchInstallerClass(int *a1, unsigned __int16 *a2, int a3, int a4, _DWORD *a5)
{
  int v5; // r0

  switch ( a4 )
  {
    case 1:
      v5 = CmValidateInstallerClassName((int)a1, a2);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 2:
      v5 = CmOpenInstallerClassRegKey(a1, a2, 32, 0, *a5, *((_BYTE *)a5 + 4), a5[2], a5 + 3);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 3:
      v5 = CmCreateInstallerClass(a1, a2, *a5, a5 + 1, a5 + 2, a5[3] & 0xFFFF0000);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 4:
      v5 = CmDeleteInstallerClass(a1, a2, *a5 & 0xFFFF0000);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 5:
      if ( *a5 )
        return sub_7E5568();
      v5 = CmGetMatchingCommonClassList(a1, 2, 0, 0, a5[2], a5[3], a5[4], a5[5] & 0xFFFF0000);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 6:
      v5 = CmGetInstallerClassMappedPropertyKeys(a1, a2, *a5, 0, a5[3], a5[4], a5[5]);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 7:
      v5 = CmGetInstallerClassMappedPropertyLocales(a1, a2, a5, a5[1], a5[2], a5[3], a5[4]);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 8:
      v5 = CmGetInstallerClassMappedProperty(a1, a2, *a5, a5[1], a5[2], a5[3], a5[4], a5[5], a5[6]);
      return PnpMapCmStatusToDispatchStatus(v5);
    case 9:
      v5 = CmSetInstallerClassMappedProperty(a1, a2, *a5, a5[1], a5[2], a5[3], a5[4], a5[5]);
      return PnpMapCmStatusToDispatchStatus(v5);
    default:
      v5 = -1073741811;
      return PnpMapCmStatusToDispatchStatus(v5);
  }
}

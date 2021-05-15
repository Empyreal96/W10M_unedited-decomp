// PiDqConvertObjectTypeToString 
 
int __fastcall PiDqConvertObjectTypeToString(int a1, const __int16 **a2)
{
  int result; // r0
  const __int16 *v4; // r3

  result = 0;
  *a2 = 0;
  switch ( a1 )
  {
    case 0:
      v4 = L"Unknown";
      goto LABEL_3;
    case 1:
      v4 = L"DeviceInterface";
      goto LABEL_3;
    case 2:
      v4 = L"DeviceContainer";
      goto LABEL_3;
    case 3:
      v4 = L"Device";
      goto LABEL_3;
    case 4:
      v4 = L"DeviceInterfaceClass";
      goto LABEL_3;
    case 5:
      v4 = L"AEP";
      goto LABEL_3;
    case 6:
      v4 = L"AEPContainer";
      goto LABEL_3;
    case 7:
      v4 = L"DeviceInstallerClass";
      goto LABEL_3;
    case 8:
      v4 = L"DeviceInterfaceDisplay";
      goto LABEL_3;
    case 9:
      v4 = L"DeviceContainerDisplay";
LABEL_3:
      *a2 = v4;
      break;
    default:
      result = -1073741811;
      break;
  }
  return result;
}

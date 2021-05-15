// _MapCmDevicePropertyToRegValue 
 
const __int16 *__fastcall MapCmDevicePropertyToRegValue(int a1, int a2)
{
  const __int16 *result; // r0

  switch ( a2 )
  {
    case 1:
      result = L"DeviceDesc";
      break;
    case 2:
      result = L"HardwareID";
      break;
    case 3:
      result = L"CompatibleIDs";
      break;
    case 5:
      result = L"Service";
      break;
    case 8:
      result = L"Class";
      break;
    case 9:
      result = L"ClassGUID";
      break;
    case 10:
      result = L"Driver";
      break;
    case 11:
      result = L"ConfigFlags";
      break;
    case 12:
      result = L"Mfg";
      break;
    case 13:
      result = L"FriendlyName";
      break;
    case 14:
      result = L"LocationInformation";
      break;
    case 16:
      result = L"Capabilities";
      break;
    case 17:
      result = L"UINumber";
      break;
    case 18:
      result = L"UpperFilters";
      break;
    case 19:
      result = L"LowerFilters";
      break;
    case 24:
      result = L"Security";
      break;
    case 26:
      result = L"DeviceType";
      break;
    case 27:
      result = L"Exclusive";
      break;
    case 28:
      result = L"DeviceCharacteristics";
      break;
    case 30:
      result = L"UINumberDescFormat";
      break;
    case 34:
      result = L"RemovalPolicy";
      break;
    case 37:
      result = L"ContainerID";
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

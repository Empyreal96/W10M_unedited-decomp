// _MapCmDevicePropertyToRegType 
 
int __fastcall MapCmDevicePropertyToRegType(int a1)
{
  int result; // r0

  switch ( a1 )
  {
    case 1:
    case 5:
    case 8:
    case 9:
    case 10:
    case 12:
    case 13:
    case 14:
    case 15:
    case 30:
    case 37:
      result = 1;
      break;
    case 2:
    case 3:
    case 18:
    case 19:
    case 36:
      result = 7;
      break;
    case 11:
    case 16:
    case 17:
    case 21:
    case 22:
    case 26:
    case 27:
    case 28:
    case 29:
    case 32:
    case 33:
    case 34:
    case 35:
      result = 4;
      break;
    case 20:
    case 24:
    case 31:
      result = 3;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

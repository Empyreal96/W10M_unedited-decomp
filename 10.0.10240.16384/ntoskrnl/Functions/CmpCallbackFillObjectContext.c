// CmpCallbackFillObjectContext 
 
int __fastcall CmpCallbackFillObjectContext(int result, _DWORD *a2, int a3)
{
  switch ( result )
  {
    case 0:
    case 14:
    case 30:
      result = CmpGetCallbackObjectContext(*a2, a3);
      a2[2] = result;
      break;
    case 1:
    case 5:
    case 6:
    case 8:
    case 9:
      result = CmpGetCallbackObjectContext(*a2, a3);
      a2[7] = result;
      break;
    case 2:
    case 4:
    case 34:
      result = CmpGetCallbackObjectContext(*a2, a3);
      a2[3] = result;
      break;
    case 3:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 31:
    case 33:
    case 35:
    case 36:
    case 37:
    case 39:
    case 42:
    case 44:
    case 46:
    case 47:
    case 48:
      result = CmpGetCallbackObjectContext(*a2, a3);
      a2[5] = result;
      break;
    case 7:
      result = CmpGetCallbackObjectContext(*a2, a3);
      a2[6] = result;
      break;
    case 25:
    case 27:
    case 29:
      a2[5] = 0;
      break;
    case 26:
    case 28:
      result = CmpGetCallbackObjectContext(a2[1], a3);
      a2[12] = result;
      break;
    case 32:
      result = CmpGetCallbackObjectContext(*a2, a3);
      a2[9] = result;
      break;
    case 38:
    case 41:
    case 43:
    case 45:
      result = CmpGetCallbackObjectContext(*a2, a3);
      a2[4] = result;
      break;
    default:
      return result;
  }
  return result;
}

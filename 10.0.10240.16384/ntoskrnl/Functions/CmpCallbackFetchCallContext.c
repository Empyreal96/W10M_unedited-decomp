// CmpCallbackFetchCallContext 
 
int __fastcall CmpCallbackFetchCallContext(int result, _DWORD *a2, int a3)
{
  int v3; // r3

  switch ( result )
  {
    case 0:
    case 14:
    case 30:
      *(_DWORD *)(a3 + 16) = a2[1];
      a2[1] = 0;
      break;
    case 1:
    case 5:
    case 6:
    case 8:
    case 9:
      *(_DWORD *)(a3 + 16) = a2[6];
      a2[6] = 0;
      break;
    case 2:
    case 4:
    case 34:
      *(_DWORD *)(a3 + 16) = a2[2];
      a2[2] = 0;
      break;
    case 3:
    case 36:
    case 47:
      *(_DWORD *)(a3 + 16) = a2[4];
      v3 = 0;
      goto LABEL_11;
    case 7:
      *(_DWORD *)(a3 + 16) = a2[5];
      a2[5] = 0;
      break;
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
    case 25:
    case 27:
    case 29:
    case 31:
    case 33:
    case 35:
    case 37:
    case 39:
    case 42:
    case 44:
    case 46:
    case 48:
      v3 = *(_DWORD *)(a3 + 16);
LABEL_11:
      a2[4] = v3;
      break;
    case 26:
    case 28:
      *(_DWORD *)(a3 + 16) = a2[11];
      a2[11] = 0;
      break;
    case 32:
      *(_DWORD *)(a3 + 16) = a2[8];
      a2[8] = 0;
      break;
    case 38:
    case 41:
    case 43:
    case 45:
      *(_DWORD *)(a3 + 16) = a2[3];
      a2[3] = 0;
      break;
    default:
      return result;
  }
  return result;
}

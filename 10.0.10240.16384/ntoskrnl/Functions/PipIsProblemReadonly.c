// PipIsProblemReadonly 
 
int __fastcall PipIsProblemReadonly(int a1, int a2)
{
  int result; // r0

  switch ( a2 )
  {
    case 1:
    case 10:
    case 14:
    case 18:
    case 19:
    case 21:
    case 22:
    case 28:
    case 31:
    case 32:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 43:
    case 44:
    case 48:
    case 51:
    case 52:
    case 53:
      goto LABEL_2;
    case 3:
      if ( (*(_DWORD *)(a1 + 268) & 0x20000) != 0 )
        goto LABEL_5;
LABEL_2:
      result = 0;
      break;
    default:
LABEL_5:
      result = 1;
      break;
  }
  return result;
}

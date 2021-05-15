// IopEfiStatusToNTSTATUS 
 
int __fastcall IopEfiStatusToNTSTATUS(unsigned int a1)
{
  int result; // r0

  if ( a1 > 0x8000000B )
  {
    switch ( a1 )
    {
      case 0x8000000C:
        result = -1073741448;
        break;
      case 0x8000000D:
        result = -2147483620;
        break;
      case 0x8000000E:
        result = -1073741568;
        break;
      case 0x8000000F:
      case 0x8000001A:
        result = -1073741790;
        break;
      case 0x80000010:
      case 0x80000012:
        result = 258;
        break;
      case 0x80000011:
        result = -1073741198;
        break;
      case 0x80000013:
        result = -1073741661;
        break;
      case 0x80000014:
        result = -1073741768;
        break;
      case 0x80000015:
        result = -1073741248;
        break;
      default:
        goto LABEL_36;
    }
  }
  else if ( a1 == -2147483637 )
  {
    result = -1073741697;
  }
  else if ( a1 > 0x80000005 )
  {
    switch ( a1 )
    {
      case 0x80000006:
        result = -1073741275;
        break;
      case 0x80000007:
        result = -1073741435;
        break;
      case 0x80000008:
        result = -1073741662;
        break;
      case 0x80000009:
        result = -1073740716;
        break;
      default:
        result = -1073741774;
        break;
    }
  }
  else if ( a1 == -2147483643 )
  {
    result = -1073741789;
  }
  else if ( a1 )
  {
    switch ( a1 )
    {
      case 0x80000001:
        result = -1073741204;
        break;
      case 0x80000002:
        result = -1073741811;
        break;
      case 0x80000003:
        result = -1073741637;
        break;
      case 0x80000004:
        result = -1073741306;
        break;
      default:
LABEL_36:
        result = -1073741823;
        break;
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

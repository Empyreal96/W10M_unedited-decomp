// _GetBaseTypeSize 
 
int __fastcall GetBaseTypeSize(__int16 a1)
{
  int result; // r0

  switch ( a1 & 0xFFF )
  {
    case 2:
    case 3:
    case 0x11:
    case 0x13:
      result = 1;
      break;
    case 4:
    case 5:
    case 0x12:
    case 0x14:
    case 0x19:
      result = 2;
      break;
    case 6:
    case 7:
    case 0xA:
    case 0x16:
    case 0x17:
    case 0x18:
      result = 4;
      break;
    case 8:
    case 9:
    case 0xB:
    case 0xE:
    case 0xF:
    case 0x10:
      result = 8;
      break;
    case 0xC:
    case 0xD:
      result = 16;
      break;
    case 0x15:
      result = 20;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

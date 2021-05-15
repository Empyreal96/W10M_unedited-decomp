// PiCMConvertDeviceListFilters 
 
int __fastcall PiCMConvertDeviceListFilters(int a1, int *a2)
{
  int v3; // r3
  int result; // r0
  int v5; // r3

  v3 = (unsigned __int16)a1;
  result = 0;
  *a2 = 0;
  if ( v3 > 8 )
  {
    switch ( v3 )
    {
      case 128:
        v5 = 128;
        break;
      case 16:
        v5 = 16;
        break;
      case 32:
        v5 = 32;
        break;
      case 64:
        v5 = 64;
        break;
      default:
        return -1073741811;
    }
    goto LABEL_4;
  }
  if ( v3 == 8 )
  {
    v5 = 8;
LABEL_4:
    *a2 = v5;
    goto LABEL_5;
  }
  if ( v3 )
    return sub_7E92E8(0);
  *a2 = 0;
LABEL_5:
  if ( (a1 & 0xFFFE0000) != 0 )
    return -1073741811;
  if ( (a1 & 0x10000) != 0 )
    *a2 |= 0x100u;
  return result;
}

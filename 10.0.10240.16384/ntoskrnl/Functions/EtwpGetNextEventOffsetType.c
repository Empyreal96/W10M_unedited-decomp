// EtwpGetNextEventOffsetType 
 
int __fastcall EtwpGetNextEventOffsetType(unsigned int *a1, unsigned int a2, unsigned int *a3)
{
  unsigned int v3; // r4
  int v5; // r2
  char *v6; // r5
  int result; // r0
  unsigned int v8; // r3
  bool v9; // cf
  unsigned int v10; // r2

  v3 = *a1;
  *a3 = 0;
  if ( !v3 || a2 < 0x48 || a2 >= v3 - 4 )
    return 0;
  v5 = *(unsigned int *)((char *)a1 + a2);
  v6 = (char *)a1 + a2;
  if ( (v5 & 0xFF000000) == -1879048192 )
  {
    v8 = (unsigned __int16)v5;
    result = 15;
    if ( (unsigned __int16)v5 < 8u )
      return 0;
  }
  else
  {
    if ( (v5 & 0xFF000000) != -1073741824 )
      return 0;
    result = BYTE2(v5);
    switch ( BYTE2(v5) )
    {
      case 1:
      case 2:
        if ( a2 >= v3 - 8 )
          return 0;
        v8 = *((unsigned __int16 *)v6 + 2);
        v9 = v8 >= 0x20;
        break;
      case 3:
      case 4:
        if ( a2 >= v3 - 8 )
          return 0;
        v8 = *((unsigned __int16 *)v6 + 2);
        v9 = v8 >= 0x18;
        break;
      case 0xA:
      case 0xB:
      case 0x14:
      case 0x15:
        v8 = (unsigned __int16)v5;
        v9 = (unsigned __int16)v5 >= 0x30u;
        break;
      case 0xD:
      case 0x12:
      case 0x13:
        v8 = (unsigned __int16)v5;
        v9 = (unsigned __int16)v5 >= 0x50u;
        break;
      case 0x10:
      case 0x11:
        if ( a2 >= v3 - 8 )
          return 0;
        v8 = *((unsigned __int16 *)v6 + 2);
        v9 = v8 >= 0x10;
        break;
      default:
        return 0;
    }
    if ( !v9 )
      return 0;
  }
  v10 = (v8 + 7) & 0xFFFFFFF8;
  if ( v10 >= v3 || v10 + a2 > v3 )
    return 0;
  *a3 = v10;
  return result;
}

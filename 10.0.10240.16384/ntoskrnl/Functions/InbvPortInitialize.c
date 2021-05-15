// InbvPortInitialize 
 
int __fastcall InbvPortInitialize(int a1, int a2, int a3, _DWORD *a4, char a5, char a6, unsigned __int8 a7)
{
  int v11; // r2
  int (*v13)(); // r3
  _DWORD *v14; // r0
  _DWORD *v15; // r0
  int v16; // t1

  if ( a7 )
  {
    v11 = a7 >> 3;
    CpRegisterWidth = v11;
  }
  else
  {
    v11 = CpRegisterWidth;
  }
  if ( a5 )
  {
    a3 = MmMapIoSpace(a3, 0, 6 * v11 + 1, 0);
    if ( !a3 )
      return 0;
    READ_UCHAR = (int (__fastcall *)(_DWORD))MY_READ_REGISTER_UCHAR;
    v13 = MY_WRITE_REGISTER_UCHAR;
  }
  else
  {
    READ_UCHAR = (int (__fastcall *)(_DWORD))MY_READ_PORT_UCHAR;
    v13 = MY_WRITE_PORT_UCHAR;
  }
  WRITE_UCHAR = (int (__fastcall *)(_DWORD, _DWORD))v13;
  if ( !a1 )
    a1 = 19200;
  if ( a2 )
  {
    if ( !a3 )
    {
      switch ( a2 )
      {
        case 1:
          a3 = 1016;
          break;
        case 2:
          a3 = 760;
          break;
        case 3:
          a3 = 1000;
          break;
        default:
          a2 = 4;
          a3 = 744;
          break;
      }
    }
  }
  else
  {
    a3 = 760;
    if ( CpDoesPortExist(760) )
    {
      a2 = 2;
    }
    else
    {
      a3 = 1016;
      if ( !CpDoesPortExist(1016) )
        return 0;
      a2 = 1;
    }
  }
  v14 = &Port[3 * a2];
  v16 = *(v14 - 3);
  v15 = v14 - 3;
  if ( v16 )
    return 0;
  PortInitialize = (int (__fastcall *)(_DWORD, _DWORD, _DWORD))CpInitialize;
  PortGetByte = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD))CpGetByte;
  PortPutByte = CpPutByte;
  PortEnableFifo = (int (__fastcall *)(_DWORD))CpEnableFifo;
  if ( a6 == 3 )
  {
    PortInitialize = (int (__fastcall *)(_DWORD, _DWORD, _DWORD))PL011InitializePort;
    PortGetByte = (int (__fastcall *)(_DWORD, _DWORD, _DWORD, _DWORD))PL011GetByte;
    PortPutByte = PL011PutByte;
    PortEnableFifo = (int (__fastcall *)(_DWORD))PL011EnableFifo;
  }
  PortInitialize(v15, a3, a1);
  *a4 = a2 - 1;
  return 1;
}

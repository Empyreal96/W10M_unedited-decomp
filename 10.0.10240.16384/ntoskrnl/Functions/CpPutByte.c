// CpPutByte 
 
int __fastcall CpPutByte(_DWORD *a1, int a2)
{
  unsigned __int8 v4; // r8
  char v5; // r0

  while ( (a1[2] & 2) != 0 )
  {
    v4 = READ_UCHAR(*a1 + 6 * CpRegisterWidth) & 0xB0;
    if ( v4 == 176 )
      break;
    v5 = CpReadLsr(a1, 0);
    if ( (v4 & 0x80) == 0 && (v5 & 1) != 0 )
      READ_UCHAR(*a1);
  }
  while ( (CpReadLsr(a1, 32) & 0x20) == 0 )
    ;
  return WRITE_UCHAR(*a1, a2);
}

// CpReadLsr 
 
int __fastcall CpReadLsr(int a1, int a2)
{
  int v4; // r6
  char v5; // r0
  char v6; // r1

  v4 = READ_UCHAR(5 * CpRegisterWidth + *(_DWORD *)a1);
  if ( (v4 & a2) == 0 )
  {
    v5 = READ_UCHAR(*(_DWORD *)a1 + 6 * CpRegisterWidth);
    if ( (v5 & 0x40) != 0 )
      v6 = 1;
    if ( (v5 & 0x40) == 0 )
      v6 = 2;
    byte_653588 |= v6;
    if ( byte_653588 == 3 )
      *(_WORD *)(a1 + 8) |= 2u;
  }
  return v4;
}

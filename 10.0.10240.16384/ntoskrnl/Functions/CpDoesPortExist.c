// CpDoesPortExist 
 
int __fastcall CpDoesPortExist(int a1)
{
  int v2; // r4
  int v3; // r8

  v2 = 1;
  v3 = READ_UCHAR(a1 + 4 * CpRegisterWidth);
  WRITE_UCHAR(a1 + 4 * CpRegisterWidth, 16);
  WRITE_UCHAR(a1 + 4 * CpRegisterWidth, 16);
  if ( (READ_UCHAR(a1 + 6 * CpRegisterWidth) & 0xF0) != 0
    || (WRITE_UCHAR(a1 + 4 * CpRegisterWidth, 20), (READ_UCHAR(a1 + 6 * CpRegisterWidth) & 0x40) == 0) )
  {
    v2 = 0;
  }
  WRITE_UCHAR(a1 + 4 * CpRegisterWidth, v3);
  return v2;
}

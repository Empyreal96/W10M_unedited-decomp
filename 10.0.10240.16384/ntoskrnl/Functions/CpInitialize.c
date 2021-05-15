// CpInitialize 
 
int __fastcall CpInitialize(_DWORD *a1, int a2, int a3)
{
  int v4; // r3

  v4 = CpRegisterWidth;
  *a1 = a2;
  a1[1] = a3;
  WRITE_UCHAR(a2 + 4 * v4, 3);
  return WRITE_UCHAR(*a1 + CpRegisterWidth, 0);
}

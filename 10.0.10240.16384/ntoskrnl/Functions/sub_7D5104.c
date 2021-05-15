// sub_7D5104 
 
void sub_7D5104(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int v6; // r5
  unsigned int v7; // r8
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  MiObtainRelocationBits((_BYTE **)va, v7, v7 + v6, 1);
  JUMPOUT(0x6D78D0);
}

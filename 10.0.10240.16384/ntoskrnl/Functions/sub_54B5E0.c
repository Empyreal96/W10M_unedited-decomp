// sub_54B5E0 
 
void sub_54B5E0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, ...)
{
  int v10; // r5
  va_list va; // [sp+18h] [bp+18h] BYREF

  va_start(va, a10);
  SepTokenFromAccessInformation(v10, (int)va);
  JUMPOUT(0x4D3688);
}

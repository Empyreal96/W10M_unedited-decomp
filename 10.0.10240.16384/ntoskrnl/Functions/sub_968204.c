// sub_968204 
 
void sub_968204(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int v6; // r4
  int v7; // r6
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  CmpLoadManufacturingProfileServicesNode(v6, v7, a3, (int *)va);
  JUMPOUT(0x94F0B4);
}

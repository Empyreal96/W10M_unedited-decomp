// sub_7C8D1C 
 
void sub_7C8D1C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, ...)
{
  va_list va; // [sp+10h] [bp+10h] BYREF

  va_start(va, a8);
  PiDmGetCmObjectListFromCache(3, (int)PiPnpRtlInterfaceFilterCallback, (int)va);
  JUMPOUT(0x6CE958);
}

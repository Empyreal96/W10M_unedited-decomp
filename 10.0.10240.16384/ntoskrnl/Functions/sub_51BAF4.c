// sub_51BAF4 
 
void sub_51BAF4(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r6
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  RtlGetNextEntryHashTable(v4, (int)va);
  JUMPOUT(0x4440AA);
}

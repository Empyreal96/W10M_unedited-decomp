// sub_7D6754 
 
void sub_7D6754(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r10
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  RtlGetNextEntryHashTable(v4, (int)va);
  JUMPOUT(0x6DCB4E);
}

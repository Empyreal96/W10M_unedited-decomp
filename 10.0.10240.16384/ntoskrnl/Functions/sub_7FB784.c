// sub_7FB784 
 
void sub_7FB784(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r4
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  if ( memcmp(v4 + 2, (unsigned int)va, 6) )
    JUMPOUT(0x72F2BA);
  JUMPOUT(0x72F2BC);
}

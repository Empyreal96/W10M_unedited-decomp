// sub_81AFC4 
 
void sub_81AFC4(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  if ( a1 == -2147483643 || a1 == -2147483647 && RtlFormatCurrentUserKeyPath((unsigned __int16 *)va) >= 0 )
    JUMPOUT(0x7B9514);
  JUMPOUT(0x7B9528);
}

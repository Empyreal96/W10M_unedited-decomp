// sub_7EFA28 
 
void sub_7EFA28(int a1, int a2, int a3, unsigned __int16 *a4, int a5, int a6, int a7, int a8, ...)
{
  va_list va; // [sp+10h] [bp+10h] BYREF

  va_start(va, a8);
  if ( RtlCreateUnicodeString((int)va, a4) )
    JUMPOUT(0x78425E);
  JUMPOUT(0x784286);
}

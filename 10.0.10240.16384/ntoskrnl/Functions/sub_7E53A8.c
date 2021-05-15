// sub_7E53A8 
 
void sub_7E53A8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, ...)
{
  unsigned __int16 *v13; // r10
  va_list va; // [sp+24h] [bp+24h] BYREF

  va_start(va, a13);
  if ( RtlUnalignedStringCchLengthW(v13, 85, (int *)va) < 0 )
    JUMPOUT(0x77D778);
  JUMPOUT(0x77D758);
}

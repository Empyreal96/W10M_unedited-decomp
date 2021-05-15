// sub_7EFFF4 
 
void sub_7EFFF4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, ...)
{
  unsigned __int16 *v20; // r5
  va_list va; // [sp+40h] [bp+40h] BYREF

  va_start(va, a20);
  if ( RtlUnalignedStringCchLengthW(v20, 85, (int *)va) < 0 )
    JUMPOUT(0x7851EA);
  JUMPOUT(0x785154);
}

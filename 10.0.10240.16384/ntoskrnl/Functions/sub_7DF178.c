// sub_7DF178 
 
void sub_7DF178(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, ...)
{
  int v16; // [sp+0h] [bp-78h]
  _DWORD *v17; // [sp+4h] [bp-74h]
  va_list va; // [sp+A8h] [bp+30h] BYREF

  va_start(va, a16);
  if ( (unsigned int)dword_6174F0 > 5 )
  {
    if ( TlgKeywordOn((int)&dword_6174F0, 0x800000000000i64) )
    {
      TlgCreateSz((int)va, (unsigned int)"Not Found");
      TlgWrite(&dword_6174F0, (unsigned __int8 *)dword_413A14, 0, 0, v16, v17);
    }
  }
  JUMPOUT(0x6EE41E);
}

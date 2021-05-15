// sub_7C73EC 
 
void sub_7C73EC(int a1, unsigned __int16 *a2, int a3, int a4, int a5, int a6, int a7, int a8, ...)
{
  unsigned __int16 *v8; // r5
  int v9; // [sp+10h] [bp+10h] BYREF
  va_list va; // [sp+10h] [bp+10h]
  int v11; // [sp+14h] [bp+14h]
  va_list va1; // [sp+18h] [bp+18h] BYREF

  va_start(va1, a8);
  va_start(va, a8);
  v9 = va_arg(va1, _DWORD);
  v11 = va_arg(va1, _DWORD);
  if ( RtlInitUnicodeStringEx((int)va1, a2) >= 0 && RtlInitUnicodeStringEx((int)va, v8) >= 0 )
  {
    if ( RtlEqualUnicodeString((unsigned __int16 *)va1, (unsigned __int16 *)va, 1) == 1 )
      JUMPOUT(0x6CBF2A);
    JUMPOUT(0x6CBF08);
  }
  JUMPOUT(0x6CBF20);
}

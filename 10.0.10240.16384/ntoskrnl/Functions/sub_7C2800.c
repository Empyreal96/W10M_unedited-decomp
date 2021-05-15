// sub_7C2800 
 
void sub_7C2800(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r6
  int v5; // [sp+0h] [bp+0h] BYREF
  va_list va; // [sp+0h] [bp+0h]
  void *v7; // [sp+4h] [bp+4h] BYREF
  va_list va1; // [sp+4h] [bp+4h]
  va_list va2; // [sp+8h] [bp+8h] BYREF

  va_start(va2, a4);
  va_start(va1, a4);
  va_start(va, a4);
  v5 = va_arg(va1, _DWORD);
  va_copy(va2, va1);
  v7 = va_arg(va2, void *);
  if ( IoQueryFlowHistory(v4 + 704, (int)va2, (int)va1, (int)va) >= 0 )
    JUMPOUT(0x6AFF2C);
  JUMPOUT(0x6AFF08);
}

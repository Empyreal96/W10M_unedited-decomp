// sub_7F3DE0 
 
void sub_7F3DE0(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int *v6; // r5
  int v7; // [sp+8h] [bp+8h] BYREF
  va_list va; // [sp+8h] [bp+8h]
  va_list va1; // [sp+Ch] [bp+Ch] BYREF

  va_start(va1, a6);
  va_start(va, a6);
  v7 = va_arg(va1, _DWORD);
  if ( HvpGenerateLogEntry(v6, (int)va, (int)va1) < 0 )
    JUMPOUT(0x70F22C);
  JUMPOUT(0x70F1AA);
}

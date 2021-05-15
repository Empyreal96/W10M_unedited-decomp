// sub_553130 
 
void sub_553130(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r5
  unsigned int v5; // [sp+0h] [bp+0h] BYREF
  va_list va; // [sp+0h] [bp+0h]
  int v7; // [sp+4h] [bp+4h]
  int v8; // [sp+8h] [bp+8h]
  int v9; // [sp+Ch] [bp+Ch]
  int v10; // [sp+10h] [bp+10h]
  int v11; // [sp+14h] [bp+14h]
  va_list va1; // [sp+18h] [bp+18h] BYREF

  va_start(va1, a4);
  va_start(va, a4);
  v5 = va_arg(va1, _DWORD);
  v7 = va_arg(va1, _DWORD);
  v8 = va_arg(va1, _DWORD);
  v9 = va_arg(va1, _DWORD);
  v10 = va_arg(va1, _DWORD);
  v11 = va_arg(va1, _DWORD);
  RtlStringCbPrintfA((int)va, 0x14u, (int)"%d", a2);
  RtlStringCbPrintfA((int)va1, 0x14u, (int)"%d", v4);
  strcmp((int)va1, (unsigned int *)va);
  JUMPOUT(0x4F30BA);
}

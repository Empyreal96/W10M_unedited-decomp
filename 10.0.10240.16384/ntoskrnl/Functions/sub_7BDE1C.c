// sub_7BDE1C 
 
void sub_7BDE1C(int a1, int a2, int a3, int a4, int a5, int a6, ...)
{
  int v6; // r4
  int v7; // [sp+8h] [bp+8h] BYREF
  va_list va; // [sp+8h] [bp+8h]
  int *v9; // [sp+Ch] [bp+Ch]
  va_list va1; // [sp+10h] [bp+10h] BYREF

  va_start(va1, a6);
  va_start(va, a6);
  v7 = va_arg(va1, _DWORD);
  v9 = va_arg(va1, int *);
  if ( v6 )
  {
    v7 = 0x20000;
    v9 = &dword_8CE900;
    IopAppendLegacyVeto(va1, (int *)va);
  }
  JUMPOUT(0x77E864);
}

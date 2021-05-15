// sub_7E42E4 
 
void sub_7E42E4(int a1, int a2, int a3, int a4, int a5, ...)
{
  int v5; // r6
  int v6; // r7
  unsigned int v7; // [sp+4h] [bp+4h] BYREF
  va_list va; // [sp+4h] [bp+4h]
  int v9; // [sp+8h] [bp+8h]
  int v10; // [sp+Ch] [bp+Ch]
  va_list va1; // [sp+10h] [bp+10h] BYREF

  va_start(va1, a5);
  va_start(va, a5);
  v7 = va_arg(va1, _DWORD);
  v9 = va_arg(va1, _DWORD);
  v10 = va_arg(va1, _DWORD);
  if ( PiDevCfgInitResolveContext(v6, v5, va1) >= 0
    && PiDevCfgQueryResolveValue((int)va1, a5, (int)L"Blocked", (unsigned int *)va) >= 0 )
  {
    ExFreePoolWithTag(v7);
  }
  JUMPOUT(0x77CAEE);
}

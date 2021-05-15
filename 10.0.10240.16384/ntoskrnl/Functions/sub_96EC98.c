// sub_96EC98 
 
void sub_96EC98(int a1, int a2, int a3, int a4, ...)
{
  int v4; // [sp+0h] [bp+0h] BYREF
  va_list va; // [sp+0h] [bp+0h]
  int v6; // [sp+4h] [bp+4h]
  void *v7; // [sp+8h] [bp+8h] BYREF
  va_list va1; // [sp+8h] [bp+8h]
  int v9; // [sp+Ch] [bp+Ch]
  void *v10; // [sp+10h] [bp+10h] BYREF
  va_list va2; // [sp+10h] [bp+10h]
  int v12; // [sp+14h] [bp+14h]
  va_list va3; // [sp+18h] [bp+18h] BYREF

  va_start(va3, a4);
  va_start(va2, a4);
  va_start(va1, a4);
  va_start(va, a4);
  v4 = va_arg(va1, _DWORD);
  v6 = va_arg(va1, _DWORD);
  va_copy(va2, va1);
  v7 = va_arg(va2, void *);
  v9 = va_arg(va2, _DWORD);
  va_copy(va3, va2);
  v10 = va_arg(va3, void *);
  v12 = va_arg(va3, _DWORD);
  PiLastGoodRevertLastKnownDirectory(va1, (int *)va);
  PiLastGoodRevertLastKnownDirectory(va3, va2);
  JUMPOUT(0x9622CC);
}

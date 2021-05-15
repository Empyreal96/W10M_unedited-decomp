// sub_7E4190 
 
void sub_7E4190(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, ...)
{
  int v8; // r5
  int v9; // r6
  int v10; // [sp+0h] [bp-30h]
  _WORD *v11; // [sp+4h] [bp-2Ch]
  int v12; // [sp+40h] [bp+10h] BYREF
  va_list va; // [sp+40h] [bp+10h]
  va_list va1; // [sp+44h] [bp+14h] BYREF

  va_start(va1, a8);
  va_start(va, a8);
  v12 = va_arg(va1, _DWORD);
  if ( a1 == 3 )
    RtlStringCchPrintfExW(v9, v8, va1, (int *)va, v10, v11);
  JUMPOUT(0x77C868);
}

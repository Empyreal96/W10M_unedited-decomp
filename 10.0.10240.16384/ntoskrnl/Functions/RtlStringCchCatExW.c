// RtlStringCchCatExW 
 
int RtlStringCchCatExW(unsigned __int16 *a1, unsigned int a2, ...)
{
  int v4; // r1
  int v5; // r2
  int v6; // r4
  int v7; // r0
  int v8; // r6
  unsigned int v9; // r1
  int var20[9]; // [sp+8h] [bp-20h] BYREF
  int varg_r2; // [sp+38h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+38h] [bp+10h]
  va_list varg_r3; // [sp+3Ch] [bp+14h] BYREF

  va_start(varg_r3, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(varg_r3, _DWORD);
  v6 = sub_43E028((int)a1, a2);
  if ( v6 < 0 )
  {
    v8 = 0;
  }
  else
  {
    v7 = sub_43E3D8(a1, v4, var20);
    v8 = var20[0];
    v6 = v7;
  }
  if ( v6 >= 0 )
  {
    if ( sub_43E2FC((int *)varg_r2a, a2 - v8, v5, 2048) < 0 )
      goto LABEL_10;
    if ( v9 <= 1 )
      return sub_50EED4();
    v6 = sub_43E2B4(&a1[v8], v9, var20, varg_r2);
    if ( v6 < 0 )
LABEL_10:
      JUMPOUT(0x50EEE0);
  }
  return v6;
}

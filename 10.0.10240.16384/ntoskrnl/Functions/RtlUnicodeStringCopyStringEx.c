// RtlUnicodeStringCopyStringEx 
 
int RtlUnicodeStringCopyStringEx(_WORD *a1, ...)
{
  int v1; // r5
  int v2; // r8
  int v3; // r1
  int v4; // r4
  int v5; // r7
  int v6; // r9
  int v7; // r6
  int v8; // r2
  _WORD *v10; // r3
  int v11; // r6
  int v12; // r2
  int v13; // r1
  int v14; // [sp+10h] [bp-38h]
  int v15; // [sp+20h] [bp-28h]
  _WORD *varg_r1; // [sp+54h] [bp+Ch] BYREF
  va_list varg_r1a; // [sp+54h] [bp+Ch]
  int varg_r2; // [sp+58h] [bp+10h]
  int varg_r3; // [sp+5Ch] [bp+14h]
  va_list va1; // [sp+60h] [bp+18h] BYREF

  va_start(va1, a1);
  va_start(varg_r1a, a1);
  varg_r1 = va_arg(va1, _WORD *);
  varg_r2 = va_arg(va1, _DWORD);
  varg_r3 = va_arg(va1, _DWORD);
  v1 = varg_r3;
  v2 = varg_r2;
  v4 = sub_4DBF00();
  if ( v4 >= 0 )
  {
    v5 = 0;
    v6 = v14;
    LOWORD(v7) = v15;
    v4 = sub_43E2FC((_WORD **)varg_r1a, v3, v14, varg_r3);
    if ( v4 < 0 )
      goto LABEL_27;
    if ( (v1 & 0xFFFFE000) != 0 )
      return sub_50B484();
    v10 = varg_r1;
    if ( v15 )
    {
      v4 = 0;
      v11 = v14 - (_DWORD)varg_r1;
      v12 = 0x7FFF;
      v13 = v15;
      do
      {
        if ( !v12 )
          break;
        if ( !*v10 )
          break;
        *(_WORD *)((char *)v10 + v11) = *v10;
        --v13;
        ++v10;
        --v12;
        ++v5;
      }
      while ( v13 );
      if ( !v13 && v12 && *v10 )
        v4 = -2147483643;
      v7 = v15 - v5;
      v6 = v14 + 2 * v5;
      if ( v4 < 0 )
        goto LABEL_27;
      if ( (v1 & 0x200) != 0 && v7 )
        memset((_BYTE *)(v14 + 2 * v5), (unsigned __int8)v1, 2 * v7);
    }
    else if ( *varg_r1 )
    {
      if ( !v8 )
        return sub_50B484();
      v4 = -2147483643;
    }
    if ( v4 >= 0 )
    {
      if ( a1 )
        *a1 = 2 * v5;
      if ( v2 )
      {
        *(_WORD *)v2 = 0;
        *(_WORD *)(v2 + 2) = 2 * v7;
        *(_DWORD *)(v2 + 4) = v6;
      }
      return v4;
    }
LABEL_27:
    JUMPOUT(0x50B486);
  }
  return v4;
}

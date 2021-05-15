// RtlStringCchCopyExW 
 
int RtlStringCchCopyExW(_WORD *a1, int a2, ...)
{
  unsigned int v4; // r1
  int v5; // r4
  _WORD *v6; // r9
  unsigned int v7; // r8
  int v8; // r1
  unsigned int v10; // [sp+Ch] [bp-24h] BYREF
  _DWORD *v11; // [sp+10h] [bp-20h]
  _WORD *varg_r2; // [sp+40h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+40h] [bp+10h]
  _DWORD *varg_r3; // [sp+44h] [bp+14h]
  unsigned int *v15; // [sp+48h] [bp+18h]
  int v16; // [sp+4Ch] [bp+1Ch]
  va_list va1; // [sp+50h] [bp+20h] BYREF

  va_start(va1, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(va1, _WORD *);
  varg_r3 = va_arg(va1, _DWORD *);
  v15 = va_arg(va1, unsigned int *);
  v16 = va_arg(va1, _DWORD);
  v11 = varg_r3;
  v5 = sub_43E31C();
  if ( v5 < 0 )
  {
    if ( a2 )
      *a1 = 0;
    return v5;
  }
  v6 = a1;
  v10 = a2;
  v7 = v4;
  v5 = sub_43E2FC((_WORD **)varg_r2a);
  if ( v5 < 0 )
  {
    if ( a2 )
      *a1 = 0;
  }
  else
  {
    if ( (v16 & 0xFFFFE000) != 0 )
      return sub_50A54C();
    if ( a2 )
    {
      v10 = 0;
      v5 = sub_43E2B4(a1, v8, &v10, varg_r2);
      v6 = &a1[v10];
      v7 -= v10;
      v10 = v7;
      if ( v5 < 0 )
        goto LABEL_24;
      if ( (v16 & 0x200) != 0 && v7 > 1 && 2 * v7 > 2 )
        memset((_BYTE *)v6 + 2, (unsigned __int8)v16, 2 * v7 - 2);
    }
    else if ( *varg_r2 )
    {
      if ( !a1 )
LABEL_24:
        JUMPOUT(0x50A554);
      v5 = -2147483643;
    }
  }
  if ( v5 < 0 )
    goto LABEL_24;
  if ( v11 )
    *v11 = v6;
  if ( v15 )
    *v15 = v7;
  return v5;
}

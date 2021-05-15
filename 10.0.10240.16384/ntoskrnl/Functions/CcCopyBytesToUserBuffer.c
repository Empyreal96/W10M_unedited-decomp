// CcCopyBytesToUserBuffer 
 
__int64 __fastcall CcCopyBytesToUserBuffer(int a1, int a2, unsigned int a3, int a4)
{
  unsigned int v4; // r5
  int v5; // r8
  int i; // r9
  unsigned int v7; // r6
  int varg_r0; // [sp+30h] [bp+8h]
  int varg_r0a; // [sp+30h] [bp+8h]
  int varg_r1; // [sp+34h] [bp+Ch]
  int varg_r1a; // [sp+34h] [bp+Ch]
  unsigned int varg_r2; // [sp+38h] [bp+10h]
  unsigned int varg_r2a; // [sp+38h] [bp+10h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v4 = a3;
  v5 = a2;
  for ( i = a1; ; i += v7 )
  {
    varg_r0a = i;
    varg_r1a = v5;
    varg_r2a = v4;
    if ( !v4 )
      break;
    if ( v4 >= 0x10000 )
      v7 = 0x10000;
    else
      v7 = v4;
    memmove(i, v5, v7);
    v4 -= v7;
    v5 += v7;
  }
  return 0i64;
}

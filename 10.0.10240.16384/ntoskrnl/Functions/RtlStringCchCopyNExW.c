// RtlStringCchCopyNExW 
 
int __fastcall RtlStringCchCopyNExW(_WORD *a1, unsigned int a2, int a3, int a4, _DWORD *a5, unsigned int *a6, int a7)
{
  _WORD *v7; // r6
  unsigned int v8; // r5
  int v9; // r4
  _WORD *v12; // r8
  unsigned int v13; // r7
  unsigned int v14; // r0
  _WORD *v15; // r2
  int v16; // r1
  int v17; // lr
  _WORD *v18; // [sp+8h] [bp-28h]
  unsigned int v19; // [sp+Ch] [bp-24h]

  v7 = a1;
  v8 = a2;
  v9 = 0;
  if ( (a7 & 0x100) != 0 )
    return sub_5187F8(a7, 0x7FFFFFFF, a3, a7 & 0x100);
  if ( !a2 || a2 > 0x7FFFFFFF )
    v9 = -1073741811;
  if ( v9 < 0 )
  {
    if ( a2 )
      *a1 = 0;
    return v9;
  }
  v12 = a1;
  v18 = a1;
  v19 = a2;
  v13 = a2;
  v9 = 0;
  if ( (a7 & 0xFFFFE000) != 0 )
  {
    v9 = -1073741811;
    if ( a2 )
      *a1 = 0;
    goto LABEL_24;
  }
  if ( a2 )
  {
    v14 = a2;
    v15 = v7;
    v16 = 0;
    v17 = a3 - (_DWORD)v7;
    do
    {
      if ( !(a4 - v8 + v14) )
        break;
      if ( !*(_WORD *)((char *)v15 + v17) )
        break;
      *v15 = *(_WORD *)((char *)v15 + v17);
      --v14;
      ++v15;
      ++v16;
    }
    while ( v14 );
    if ( !v14 )
    {
      --v15;
      --v16;
      v9 = -2147483643;
    }
    v12 = &v7[v16];
    v13 = v8 - v16;
    *v15 = 0;
    v18 = v12;
    v19 = v8 - v16;
    if ( v9 >= 0 )
    {
      if ( (a7 & 0x200) != 0 && v13 > 1 && 2 * v13 > 2 )
        memset((_BYTE *)v12 + 2, (unsigned __int8)a7, 2 * v13 - 2);
      goto LABEL_16;
    }
LABEL_24:
    if ( (a7 & 0x1C00) != 0 && v8 )
    {
      sub_568498(v7, 2 * v8);
      v12 = v18;
      v13 = v19;
    }
    if ( v9 != -2147483643 )
      return v9;
  }
LABEL_16:
  if ( a5 )
    *a5 = v12;
  if ( a6 )
    *a6 = v13;
  return v9;
}

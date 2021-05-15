// StringCchPrintfExW 
 
int __fastcall StringCchPrintfExW(_WORD *a1, unsigned int a2, _DWORD *a3, int a4, int a5, __int16 *a6)
{
  unsigned int v6; // r6
  int v7; // r5
  unsigned int *v8; // lr
  _BYTE *v9; // r7
  bool v10; // cc
  __int16 *v11; // r2
  int v12; // r8
  unsigned int v13; // r4
  unsigned int v14; // r4
  int v15; // r0
  _WORD *v18; // [sp+Ch] [bp-2Ch] BYREF
  unsigned int v19; // [sp+10h] [bp-28h] BYREF
  int *v20; // [sp+14h] [bp-24h]
  _WORD *varg_r0; // [sp+40h] [bp+8h]
  unsigned int varg_r1; // [sp+44h] [bp+Ch]
  _DWORD *varg_r2; // [sp+48h] [bp+10h]
  int varg_r3; // [sp+4Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v6 = a2;
  v7 = 0;
  v8 = (unsigned int *)a4;
  v20 = a3;
  v9 = a1;
  if ( (a5 & 0x100) != 0 )
  {
    if ( !a1 && a2 )
      goto LABEL_9;
    v10 = a2 > 0x7FFFFFFF;
  }
  else
  {
    v7 = 0;
    if ( !a2 )
    {
LABEL_9:
      v7 = -2147024809;
      goto LABEL_10;
    }
    v10 = a2 > 0x7FFFFFFF;
  }
  if ( v10 )
    goto LABEL_9;
LABEL_10:
  if ( v7 < 0 )
  {
    if ( a2 )
      *a1 = 0;
    return v7;
  }
  v11 = a6;
  v12 = (int)a1;
  v18 = a1;
  v19 = a2;
  v13 = a2;
  if ( (a5 & 0x100) != 0 && !a6 )
    v11 = &word_5CB8A8;
  v7 = 0;
  if ( (a5 & 0xFFFFE000) != 0 )
  {
    v7 = -2147024809;
    if ( a2 )
      *a1 = 0;
    goto LABEL_17;
  }
  if ( a2 )
  {
    v14 = a2 - 1;
    v7 = 0;
    v15 = vsnwprintf();
    if ( v15 < 0 || v15 > v14 )
    {
      v7 = -2147024774;
    }
    else if ( v15 != v14 )
    {
      v14 = v15;
      goto LABEL_37;
    }
    *(_WORD *)&v9[2 * v14] = 0;
LABEL_37:
    v12 = (int)&v9[2 * v14];
    v13 = v6 - v14;
    v18 = (_WORD *)v12;
    v19 = v13;
    if ( v7 >= 0 )
    {
      if ( (a5 & 0x200) != 0 && v13 > 1 && 2 * v13 > 2 )
        memset((_BYTE *)(v12 + 2), (unsigned __int8)a5, 2 * v13 - 2);
      goto LABEL_21;
    }
    goto LABEL_17;
  }
  if ( !*v11 )
    goto LABEL_22;
  if ( a1 )
    v7 = -2147024774;
  else
    v7 = -2147024809;
LABEL_17:
  if ( (a5 & 0x1C00) != 0 && v6 )
  {
    sub_568498(v9, 2 * v6, (int)v11, &v18, &v19, a5);
    v12 = (int)v18;
    v13 = v19;
  }
  if ( v7 == -2147024774 )
  {
LABEL_21:
    v8 = (unsigned int *)a4;
LABEL_22:
    if ( v20 )
      *v20 = v12;
    if ( v8 )
      *v8 = v13;
  }
  return v7;
}

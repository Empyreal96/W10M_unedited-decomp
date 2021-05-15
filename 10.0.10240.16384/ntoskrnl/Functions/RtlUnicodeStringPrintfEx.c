// RtlUnicodeStringPrintfEx 
 
int __fastcall RtlUnicodeStringPrintfEx(unsigned __int16 *a1, int a2, int a3, __int16 *a4)
{
  int v6; // r0
  unsigned int v7; // r5
  int v8; // r4
  __int16 *v9; // lr
  unsigned int v11; // r7
  unsigned int v12; // r6
  int v13; // r6
  int v14; // r10
  unsigned int v15; // r7
  int v16; // r2
  int v17; // r0
  __int16 v18; // [sp+10h] [bp-38h]
  int v19; // [sp+14h] [bp-34h]
  __int16 v20; // [sp+18h] [bp-30h]
  int v21; // [sp+1Ch] [bp-2Ch]
  _WORD *v22; // [sp+20h] [bp-28h]
  unsigned __int16 *varg_r0; // [sp+50h] [bp+8h]
  int varg_r1; // [sp+54h] [bp+Ch]
  int varg_r2; // [sp+58h] [bp+10h]
  __int16 *varg_r3a; // [sp+5Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v21 = 0;
  v22 = a1;
  v9 = a4;
  if ( !a1 )
    return sub_520204();
  v11 = *a1;
  if ( (v11 & 1) != 0 )
    return -1073741811;
  v12 = a1[1];
  if ( (v12 & 1) != 0 || v11 > v12 || a1[1] == 0xFFFF )
    return -1073741811;
  if ( !*((_DWORD *)a1 + 1) && (*a1 || a1[1]) )
  {
    v8 = -1073741811;
  }
  else
  {
    v6 = *((_DWORD *)a1 + 1);
    v21 = v6;
    v7 = v12 >> 1;
  }
  if ( v8 >= 0 )
  {
    LOWORD(v13) = 0;
    v18 = 0;
    v19 = v6;
    v14 = v6;
    LOWORD(v15) = v7;
    v20 = v7;
    if ( (a3 & 0x100) != 0 && !a4 )
    {
      v9 = &word_5CB8A8;
      varg_r3a = &word_5CB8A8;
    }
    v16 = 1;
    v8 = 0;
    if ( (a3 & 0xFFFFE000) == 0 )
    {
      if ( v7 )
      {
        v17 = vsnwprintf();
        v13 = v17;
        if ( v17 < 0 || v17 > v7 )
        {
          v13 = v7;
          v18 = v7;
          v8 = -2147483643;
        }
        else
        {
          v18 = v17;
        }
        v6 = v21;
        v15 = v7 - v13;
        v20 = v7 - v13;
        v14 = v21 + 2 * v13;
        v19 = v14;
        if ( v8 >= 0 )
        {
          if ( (a3 & 0x200) != 0 && v15 )
            memset((_BYTE *)(v21 + 2 * v13), (unsigned __int8)a3, 2 * v15);
          goto LABEL_18;
        }
LABEL_34:
        if ( (a3 & 0x1C00) != 0 && v7 )
        {
          sub_565FC4(v6, v7, v16);
          v14 = v19;
          LOWORD(v15) = v20;
          LOWORD(v13) = v18;
        }
        goto LABEL_18;
      }
      if ( !*v9 )
      {
LABEL_18:
        if ( v22 )
          *v22 = 2 * v13;
        if ( v8 >= 0 || v8 == -2147483643 )
        {
          if ( a2 )
          {
            *(_WORD *)a2 = 0;
            *(_WORD *)(a2 + 2) = 2 * v15;
            *(_DWORD *)(a2 + 4) = v14;
          }
        }
        return v8;
      }
      if ( v6 )
      {
        v8 = -2147483643;
        goto LABEL_34;
      }
    }
    v8 = -1073741811;
    goto LABEL_34;
  }
  return v8;
}

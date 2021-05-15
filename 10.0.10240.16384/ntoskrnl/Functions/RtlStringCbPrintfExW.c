// RtlStringCbPrintfExW 
 
int RtlStringCbPrintfExW(_WORD *a1, unsigned int a2, _DWORD *a3, _DWORD *a4, int a5, _WORD *a6, ...)
{
  _WORD *v6; // r7
  unsigned int v7; // r6
  int v8; // r4
  _DWORD *v9; // lr
  _WORD *v11; // r8
  unsigned int v12; // r5
  int v13; // r0
  unsigned int v14; // r3
  unsigned int v15; // [sp+8h] [bp-30h]
  _WORD *v17; // [sp+10h] [bp-28h]
  unsigned int v18; // [sp+14h] [bp-24h]

  v6 = a1;
  v7 = a2 >> 1;
  v8 = 0;
  v9 = a4;
  v15 = a2;
  if ( (a5 & 0x100) != 0 )
    return sub_54B640(a5 & 0x100);
  if ( !v7 )
    v8 = -1073741811;
  if ( v8 < 0 )
  {
    if ( v7 )
      *a1 = 0;
    return v8;
  }
  v11 = a1;
  v17 = a1;
  v18 = a2 >> 1;
  v8 = 0;
  if ( (a5 & 0xFFFFE000) != 0 )
  {
    v8 = -1073741811;
    if ( v7 )
      *a1 = 0;
LABEL_26:
    if ( (a5 & 0x1C00) != 0 && a2 )
    {
      sub_568498(v6, a2);
      v11 = v17;
      v7 = v18;
    }
    if ( v8 != -2147483643 )
      return v8;
    goto LABEL_22;
  }
  if ( !v7 )
  {
    if ( !*a6 )
      goto LABEL_15;
    v8 = -1073741811;
    goto LABEL_26;
  }
  v12 = v7 - 1;
  v13 = vsnwprintf(a1, v7 - 1);
  if ( v13 < 0 || v13 > v12 )
  {
    v8 = -2147483643;
  }
  else if ( v13 != v12 )
  {
    v12 = v13;
    goto LABEL_12;
  }
  v6[v12] = 0;
LABEL_12:
  v11 = &v6[v12];
  v7 -= v12;
  a2 = v15;
  v17 = v11;
  v18 = v7;
  if ( v8 < 0 )
    goto LABEL_26;
  if ( (a5 & 0x200) == 0 )
    goto LABEL_14;
  v14 = (v15 & 1) + 2 * v7;
  if ( v14 <= 2 )
    goto LABEL_14;
  memset((_BYTE *)v11 + 2, (unsigned __int8)a5, v14 - 2);
LABEL_22:
  LOBYTE(a2) = v15;
LABEL_14:
  v9 = a4;
LABEL_15:
  if ( a3 )
    *a3 = v11;
  if ( v9 )
    *v9 = (a2 & 1) + 2 * v7;
  return v8;
}

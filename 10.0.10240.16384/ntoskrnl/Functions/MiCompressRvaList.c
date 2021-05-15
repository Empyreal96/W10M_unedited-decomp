// MiCompressRvaList 
 
int __fastcall MiCompressRvaList(unsigned int *a1, int a2, unsigned int a3, unsigned int a4, char a5, unsigned int *a6, int *a7)
{
  char v8; // r0
  unsigned int v10; // r6
  int v11; // r1
  unsigned int v12; // lr
  unsigned int v13; // r9
  _BYTE *v14; // r4
  unsigned int v15; // r8
  unsigned int v16; // r2
  int *v17; // r3
  int v18; // r9
  unsigned int v19; // r2
  unsigned int v20; // t1
  unsigned int v21; // r1
  int v22; // r0
  bool v23; // zf
  int v24; // r2
  char v26; // [sp+0h] [bp-30h]
  unsigned int v27; // [sp+4h] [bp-2Ch]
  int v28; // [sp+8h] [bp-28h]
  unsigned int v30; // [sp+10h] [bp-20h]

  v8 = 1;
  v26 = 1;
  v27 = a3;
  v10 = *a1;
  v11 = 0;
  v12 = a4;
  v13 = a3;
  if ( (a5 & 1) != 0 )
  {
    v8 = 0;
    v26 = 0;
  }
  if ( !v10 || v10 >= a3 )
    return -1073741701;
  if ( a4 > 4 )
  {
    for ( ; ((_BYTE)a1[1] & (unsigned __int8)v8) != 0; --a2 )
    {
      if ( !a2 )
        break;
      a1 = (unsigned int *)((char *)a1 + a4);
    }
    v10 = *a1;
  }
  if ( !a2 )
  {
LABEL_48:
    if ( !a6 )
      *a7 = v11;
    return 0;
  }
  if ( a6 )
  {
    *a6 = v10;
    v14 = a6 + 1;
  }
  else
  {
    v14 = 0;
  }
  v11 = 4;
  v28 = 4;
  v15 = v10;
  while ( 1 )
  {
    if ( v10 != v15 )
      goto LABEL_28;
    v16 = v15;
    a1 = (unsigned int *)((char *)a1 + v12);
    if ( !--a2 )
      goto LABEL_48;
    if ( v12 > 4 )
      break;
LABEL_25:
    if ( !a2 )
      goto LABEL_48;
    v15 = *a1;
    if ( *a1 <= v16 || v15 >= v13 )
    {
      v24 = 13;
      goto LABEL_45;
    }
LABEL_28:
    v17 = &MiCfgCompressionTableScales;
    v18 = 0;
    while ( 1 )
    {
      v20 = *v17++;
      v19 = v20;
      v30 = v20;
      if ( v15 - v10 >= v20 )
        break;
      if ( (unsigned int)++v18 >= 4 )
        goto LABEL_43;
    }
    v21 = v15 - v10;
    if ( !v19 )
      __brkdiv0();
    v22 = v21 / v19;
    if ( v21 / v19 >= 0x3F )
      v22 = 63;
    if ( v14 )
      *v14++ = v22 | ((_BYTE)v18 << 6);
    v12 = a4;
    v10 += v30 * v22;
    v11 = v28 + 1;
    v8 = v26;
    ++v28;
    if ( v10 != v15 )
      goto LABEL_15;
    v8 = v26;
    v12 = a4;
    v23 = v18 == 3;
    v13 = v27;
    if ( !v23 )
    {
      if ( v14 )
        *v14++ = -64;
      ++v11;
      v12 = a4;
      v28 = v11;
LABEL_43:
      v8 = v26;
LABEL_15:
      v13 = v27;
      continue;
    }
  }
  while ( 1 )
  {
    if ( ((_BYTE)a1[1] & (unsigned __int8)v8) == 0 )
      goto LABEL_25;
    if ( !a2 )
      goto LABEL_48;
    if ( *a1 <= v16 || *a1 >= v13 )
      break;
    v16 = *a1;
    a1 = (unsigned int *)((char *)a1 + v12);
    --a2;
  }
  v24 = 14;
LABEL_45:
  dword_632EF0 = v24;
  return -1073741701;
}

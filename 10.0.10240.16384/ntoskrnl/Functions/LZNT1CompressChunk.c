// LZNT1CompressChunk 
 
int __fastcall LZNT1CompressChunk(int (__fastcall *a1)(char *), unsigned int a2, unsigned int a3, _BYTE *a4, unsigned int a5, _DWORD *a6, unsigned int *a7)
{
  unsigned int v8; // r6
  _BYTE *v9; // r10
  unsigned int *v11; // r1
  int v12; // lr
  _BYTE *v13; // r2
  int v14; // r0
  _WORD *v15; // r5
  int v16; // r9
  char *v17; // r7
  _BYTE *v18; // lr
  int *v19; // r2
  int v20; // r0
  char *v21; // r1
  __int16 v22; // r3
  char v23; // r3
  _BYTE *v24; // r3
  unsigned int v25; // r5
  __int16 v26; // r3
  __int16 v28; // r3
  int v29; // [sp+4h] [bp-3Ch]
  _BYTE *v30; // [sp+8h] [bp-38h]
  int v31; // [sp+Ch] [bp-34h]
  _BYTE *v32; // [sp+10h] [bp-30h]
  int v33; // [sp+14h] [bp-2Ch]
  int *v34; // [sp+18h] [bp-28h]

  v8 = a3;
  if ( a2 + 4096 < a3 )
    v8 = a2 + 4096;
  v9 = a4 + 4095;
  if ( (unsigned int)(a4 + 4095) >= a5 )
    v9 = (_BYTE *)a5;
  v11 = a7;
  LOBYTE(v31) = 0;
  v12 = 0;
  v13 = a4 + 2;
  v14 = 0;
  v15 = a4 + 3;
  a7[1] = v8;
  a7[2] = 4098;
  v32 = a4 + 2;
  v33 = 0;
  v16 = 0;
  v17 = (char *)a2;
  v29 = 0;
  *a7 = a2;
  if ( a2 < v8 )
  {
    v18 = a4 + 4;
    v30 = a4 + 4;
    v19 = FormatMaxDisplacement;
    v34 = FormatMaxDisplacement;
    while ( 1 )
    {
      if ( *v19 + a2 < (unsigned int)v17 )
      {
        do
        {
          v11[2] = FormatMaxLength[++v16];
          v34 = &FormatMaxDisplacement[v16];
        }
        while ( *v34 + a2 < (unsigned int)v17 );
        v14 = v29;
      }
      if ( (unsigned int)(v17 + 3) > v8 )
        goto LABEL_32;
      v20 = a1(v17);
      v18 = v30;
      if ( !v20 )
        break;
      if ( v30 >= v9 )
        goto LABEL_38;
      v21 = &v17[-a7[3]];
      v29 = (unsigned __int8)((1 << v31) | v29);
      if ( v16 )
      {
        switch ( v16 )
        {
          case 1:
            v22 = (v20 - 3) & 0x7FF | (((_WORD)v21 - 1) << 11);
            break;
          case 2:
            v22 = (v20 - 3) & 0x3FF | (((_WORD)v21 - 1) << 10);
            break;
          case 3:
            v22 = (v20 - 3) & 0x1FF | (((_WORD)v21 - 1) << 9);
            break;
          case 4:
            v22 = (unsigned __int8)(v20 - 3) | (unsigned __int16)(((_WORD)v21 - 1) << 8);
            break;
          case 5:
            v22 = (v20 - 3) & 0x7F | (((_WORD)v21 - 1) << 7);
            break;
          case 6:
            v22 = (v20 - 3) & 0x3F | (((_WORD)v21 - 1) << 6);
            break;
          case 7:
            v22 = (v20 - 3) & 0x1F | (32 * ((_WORD)v21 - 1));
            break;
          default:
            v22 = (v20 - 3) & 0xF | (16 * ((_WORD)v21 - 1));
            break;
        }
      }
      else
      {
        v22 = (v20 - 3) & 0xFFF | (((_WORD)v21 - 1) << 12);
      }
      v18 = v30 + 2;
      *v15++ = v22;
      v17 += v20;
      v14 = v29;
LABEL_34:
      v30 = v18;
      v31 = ((_BYTE)v31 + 1) & 7;
      if ( !v31 )
      {
        if ( (unsigned int)v17 >= v8 )
          goto LABEL_45;
        v24 = v32;
        ++v18;
        v32 = v15;
        *v24 = v14;
        v14 = 0;
        v29 = 0;
        v30 = v18;
        v15 = (_WORD *)((char *)v15 + 1);
      }
      v11 = a7;
      v19 = v34;
      if ( (unsigned int)v17 >= v8 )
      {
LABEL_38:
        if ( (unsigned int)v17 >= v8 )
        {
LABEL_45:
          v13 = v32;
          v12 = v33;
          goto LABEL_46;
        }
        v25 = v8 - a2;
        if ( (unsigned int)&a4[v8 - a2 + 2] > a5 )
          return -1073741789;
        memmove((int)(a4 + 2), a2, v8 - a2);
        *a6 = v25 + 2;
        v26 = (v25 - 1) & 0xFFF | 0x3000;
        if ( ((unsigned __int8)a4 & 1) != 0 )
        {
          *a4 = v25 - 1;
          a4[1] = HIBYTE(v26);
        }
        else
        {
          *(_WORD *)a4 = v26;
        }
        return 0;
      }
    }
    v14 = v29;
LABEL_32:
    if ( v15 >= (_WORD *)v9 )
      goto LABEL_38;
    ++v18;
    v14 &= ~(1 << v31);
    v23 = *v17;
    v29 = v14;
    *(_BYTE *)v15 = *v17;
    v15 = (_WORD *)((char *)v15 + 1);
    v33 = (unsigned __int8)(v23 | v33);
    ++v17;
    goto LABEL_34;
  }
LABEL_46:
  if ( v13 >= v9 )
    v15 = (_WORD *)((char *)v15 - 1);
  else
    *v13 = v29;
  *a6 = (char *)v15 - a4;
  v28 = ((_WORD)v15 - (_WORD)a4 - 3) & 0xFFF | 0xB000;
  if ( ((unsigned __int8)a4 & 1) != 0 )
  {
    *a4 = (_BYTE)v15 - (_BYTE)a4 - 3;
    a4[1] = HIBYTE(v28);
  }
  else
  {
    *(_WORD *)a4 = v28;
  }
  if ( v12 )
    return 0;
  return 279;
}

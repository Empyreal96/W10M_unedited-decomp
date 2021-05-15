// XpressDoHuffmanPass 
 
_BYTE *__fastcall XpressDoHuffmanPass(int a1, int *a2, unsigned int a3, int a4, int a5)
{
  _WORD *v8; // r9
  unsigned int v9; // r1
  int v10; // r4
  _WORD *v11; // r10
  _BYTE *result; // r0
  int v13; // r3
  int v14; // t1
  int i; // r5
  int v16; // t1
  unsigned int v17; // r7
  int v18; // lr
  unsigned __int8 *v19; // r6
  int v20; // r7
  int v21; // t1
  unsigned int v22; // lr
  int v23; // r9
  unsigned int v24; // r1
  int v25; // lr
  int v26; // r1
  int v27; // r3
  int v28; // r2
  unsigned __int8 v29; // r3
  unsigned int v30; // r4
  unsigned int v31; // r3
  unsigned int v32; // r5
  _WORD *v33; // [sp+0h] [bp-28h]

  memmove(a4, a1 + 18960, 0x100u);
  v8 = (_WORD *)(a4 + 258);
  v9 = 16;
  v10 = 0;
  v11 = (_WORD *)(a4 + 256);
  v33 = (_WORD *)(a4 + 258);
  result = (_BYTE *)(a4 + 260);
  while ( 1 )
  {
    __pld(a2 + 12);
    __pld(a2 + 16);
    v14 = *a2++;
    v13 = v14;
    if ( v14 < 0 )
      break;
    for ( i = 2 * v13 + 1; ; i *= 2 )
    {
      v16 = *(unsigned __int8 *)a2;
      a2 = (int *)((char *)a2 + 1);
      v17 = *(unsigned __int16 *)(a1 + 4 * v16);
      v18 = a1 + 4 * v16;
      if ( v9 < v17 )
      {
        v33 = result;
        *v11 = ((_WORD)v10 << v9) | (*(unsigned __int16 *)(v18 + 2) >> (v17 - v9));
        v11 = v8;
        v8 = result;
        v10 = *(unsigned __int16 *)(v18 + 2);
        result += 2;
        v9 = v9 - v17 + 16;
      }
      else
      {
        v9 -= v17;
        v10 = (unsigned __int16)(*(_WORD *)(v18 + 2) | ((_WORD)v10 << v17));
      }
LABEL_8:
      if ( i < 0 )
        break;
    }
    i *= 2;
    if ( i )
      goto LABEL_10;
  }
  i = 2 * v13 + 1;
LABEL_10:
  if ( (unsigned int)a2 < a3 )
  {
    v21 = *(unsigned __int8 *)a2;
    v19 = (unsigned __int8 *)a2 + 1;
    v20 = v21;
    v22 = *(unsigned __int16 *)(a1 + 4 * (v21 + 256));
    v23 = a1 + 4 * (v21 + 256);
    if ( v9 < v22 )
    {
      *v11 = ((_WORD)v10 << v9) | (*(unsigned __int16 *)(v23 + 2) >> (v22 - v9));
      v11 = v33;
      v33 = result;
      v26 = v9 - v22;
      v25 = *(unsigned __int16 *)(v23 + 2);
      result += 2;
      v24 = v26 + 16;
    }
    else
    {
      v24 = v9 - v22;
      v25 = (unsigned __int16)(*(_WORD *)(v23 + 2) | ((_WORD)v10 << v22));
    }
    if ( v20 - 16 * (v20 >> 4) == 15 )
    {
      v27 = *v19++;
      *result++ = v27;
      if ( v27 == 255 )
      {
        v28 = *(unsigned __int16 *)v19;
        *result = *v19;
        v29 = v19[1];
        v19 += 2;
        result[1] = v29;
        result += 2;
        if ( !v28 )
        {
          *result = *v19;
          result[1] = v19[1];
          result[2] = v19[2];
          result[3] = v19[3];
          result += 4;
          v19 += 4;
        }
      }
    }
    v30 = (unsigned int)v20 >> 4;
    if ( v24 < (unsigned int)v20 >> 4 )
    {
      v8 = result;
      *v11 = (v25 << v24) | (*(unsigned __int16 *)v19 >> (v30 - v24));
      v11 = v33;
      v33 = result;
      result += 2;
      v31 = v24 - v30;
      v10 = *(unsigned __int16 *)v19;
      v9 = v31 + 16;
    }
    else
    {
      v9 = v24 - v30;
      v8 = v33;
      v10 = (unsigned __int16)(*(_WORD *)v19 | ((_WORD)v25 << v30));
    }
    a2 = (int *)(v19 + 2);
    goto LABEL_8;
  }
  if ( a5 )
  {
    v32 = *(unsigned __int16 *)(a1 + 1024);
    if ( v9 < v32 )
    {
      *v11 = ((_WORD)v10 << v9) | (*(unsigned __int16 *)(a1 + 1026) >> (v32 - v9));
      v11 = v8;
      v8 = result;
      v10 = *(unsigned __int16 *)(a1 + 1026);
      result += 2;
      LOBYTE(v9) = v9 - v32 + 16;
    }
    else
    {
      LOBYTE(v9) = v9 - v32;
      v10 = (unsigned __int16)(*(_WORD *)(a1 + 1026) | ((_WORD)v10 << v32));
    }
  }
  *v11 = v10 << v9;
  *v8 = 0;
  return result;
}

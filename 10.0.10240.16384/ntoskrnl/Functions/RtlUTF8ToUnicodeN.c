// RtlUTF8ToUnicodeN 
 
int __fastcall RtlUTF8ToUnicodeN(_WORD *a1, unsigned int a2, _DWORD *a3, unsigned int a4, int a5)
{
  char *v5; // r5
  _WORD *v6; // lr
  _WORD *v7; // r4
  unsigned int v8; // r8
  unsigned int v9; // r1
  int result; // r0
  unsigned int v11; // r10
  unsigned int v13; // t1
  char v14; // r2
  char v15; // t1
  unsigned int v16; // r2
  unsigned int v17; // r3
  unsigned int v18; // t1
  _WORD *i; // r6
  unsigned int v20; // r2
  unsigned int v21; // t1
  unsigned int v22; // r1
  char v23; // r1
  char v24; // t1
  int v25; // r1
  int v26; // r3
  bool v27; // zf
  char v28; // r2
  unsigned int v29; // r1
  int v30; // r3
  char v31; // r2
  int v32; // r1
  unsigned int v33; // r2
  __int16 v34; // r3

  v5 = (char *)a4;
  v6 = a1;
  v7 = a1;
  v8 = (unsigned int)&a1[a2 >> 1];
  v9 = 0;
  result = 0;
  v11 = a4 + a5;
  if ( !a4 )
    return -1073741582;
  if ( !v6 )
  {
    if ( a3 )
      result = CountUTF8ToUnicode(a4, a5, a3);
    else
      result = -1073741811;
    return result;
  }
  while ( 1 )
  {
    while ( 1 )
    {
      while ( 1 )
      {
LABEL_7:
        if ( (unsigned int)v5 >= v11 )
          goto LABEL_74;
        if ( v9 )
          break;
        v13 = *v5++;
        LOWORD(v9) = v13;
        if ( v13 <= 0x7F )
          goto LABEL_24;
LABEL_30:
        if ( (v9 & 0x40) == 0 )
          goto LABEL_36;
        if ( (v9 & 0x20) != 0 )
        {
          if ( (v9 & 0x10) != 0 )
          {
            if ( (v9 & 0xF) > 4 )
              goto LABEL_36;
            v9 = v9 & 0xF | 0x504D0C00;
          }
          else
          {
            v9 = v9 & 0xF | 0x48228000;
          }
        }
        else
        {
          if ( (v9 & 0x1F) <= 1 )
            goto LABEL_36;
          v9 = v9 & 0x1F | 0x800000;
        }
      }
      v15 = *v5++;
      v14 = v15;
      if ( (v15 & 0xC0) != 128 )
      {
        --v5;
LABEL_36:
        result = 263;
        LOWORD(v9) = -3;
        goto LABEL_24;
      }
      v9 = v14 & 0x3F | (v9 << 6);
      if ( (v9 & 0x20000000) != 0 )
        break;
      if ( (v9 & 0x10000000) != 0 )
      {
        if ( (v9 & 0x800000) == 0 && (v9 & 0x1F0) - 16 > 0xF0 )
          goto LABEL_36;
      }
      else if ( (v9 & 0x3E0) == 0 || (v9 & 0x3E0) == 864 )
      {
        goto LABEL_36;
      }
    }
    if ( (v9 & 0x101F0000) > 0x10000000 )
    {
      if ( (unsigned int)v7 >= v8 )
        goto LABEL_77;
      *v7++ = ((v9 >> 10) & 0x7FF) - 10304;
      LOWORD(v9) = (v9 & 0x3FF) - 9216;
    }
LABEL_24:
    if ( (unsigned int)v7 >= v8 )
    {
LABEL_77:
      if ( a3 )
        *a3 = 2 * (v7 - v6);
      return -1073741789;
    }
    *v7++ = v9;
    v16 = (int)(v8 - (_DWORD)v7) >> 1;
    v17 = v11 - (_DWORD)v5;
    if ( v11 - (unsigned int)v5 > 0xD )
    {
      if ( v17 >= v16 )
        v17 = (int)(v8 - (_DWORD)v7) >> 1;
      for ( i = &v7[v17 - 7]; ; --i )
      {
        while ( 2 )
        {
          if ( v7 >= i )
            goto LABEL_71;
          v21 = *v5++;
          LOWORD(v20) = v21;
          if ( v21 <= 0x7F )
          {
            *v7++ = v20;
            if ( ((unsigned __int8)v5 & 1) != 0 )
            {
              v20 = *v5++;
              if ( v20 > 0x7F )
                break;
              *v7++ = v20;
            }
            if ( ((unsigned __int8)v5 & 2) == 0 )
              goto LABEL_49;
            v20 = *(unsigned __int16 *)v5;
            if ( (v20 & 0x8080) == 0 )
            {
              *v7 = *(_WORD *)v5 & 0x7F;
              v7[1] = (v20 >> 8) & 0x7F;
              v5 += 2;
LABEL_49:
              for ( v7 += 2; v7 < i; v7 += 8 )
              {
                v22 = *((_DWORD *)v5 + 1);
                v20 = *(_DWORD *)v5;
                if ( ((v22 | *(_DWORD *)v5) & 0x80808080) != 0 )
                  goto LABEL_52;
                *v7 = v20 & 0x7F;
                v7[1] = (v20 >> 8) & 0x7F;
                v7[2] = BYTE2(v20) & 0x7F;
                v7[3] = HIBYTE(v20) & 0x7F;
                v7[4] = v22 & 0x7F;
                v7[5] = (v22 >> 8) & 0x7F;
                v7[6] = BYTE2(v22) & 0x7F;
                v7[7] = HIBYTE(v22) & 0x7F;
                v5 += 8;
              }
              goto LABEL_71;
            }
LABEL_52:
            ++v5;
            if ( (unsigned __int8)v20 <= 0x7Fu )
            {
              *v7++ = (unsigned __int8)v20;
              continue;
            }
          }
          break;
        }
        v24 = *v5++;
        v23 = v24;
        if ( (v20 & 0x40) == 0 || (v23 & 0xC0) != 128 )
        {
LABEL_72:
          v5 -= 2;
          v9 = 0;
          goto LABEL_7;
        }
        v25 = v23 & 0x3F;
        if ( (v20 & 0x20) != 0 )
        {
          v26 = v20 & 0xF;
          v27 = (v20 & 0x10) == 0;
          v28 = *v5;
          v29 = v25 | (v26 << 6);
          if ( v27 )
          {
            if ( (v29 & 0x3E0) == 0 || (v29 & 0x3E0) == 864 || (v28 & 0xC0) != 128 )
              goto LABEL_72;
            v34 = v28 & 0x3F | ((_WORD)v29 << 6);
            ++v5;
          }
          else
          {
            if ( (v29 >> 4) - 1 > 0xF )
              goto LABEL_72;
            if ( (v28 & 0xC0) != 128 )
              goto LABEL_72;
            v30 = v28 & 0x3F;
            v31 = v5[1];
            v32 = v30 | (v29 << 6);
            if ( (v31 & 0xC0) != 128 )
              goto LABEL_72;
            v33 = v31 & 0x3F | (v32 << 6);
            *v7 = ((v33 >> 10) & 0x7FF) - 10304;
            v5 += 2;
            ++v7;
            v34 = (v33 & 0x3FF) - 9216;
          }
          --i;
        }
        else
        {
          if ( (v20 & 0x1F) <= 1 )
            goto LABEL_72;
          v34 = v25 | ((v20 & 0x1F) << 6);
        }
        *v7++ = v34;
      }
    }
    if ( v16 >= v17 )
      break;
LABEL_71:
    v9 = 0;
  }
  while ( (unsigned int)v5 < v11 )
  {
    v18 = *v5++;
    LOWORD(v9) = v18;
    if ( v18 > 0x7F )
      goto LABEL_30;
    *v7++ = v9;
  }
  v9 = 0;
LABEL_74:
  if ( v9 )
  {
    result = 263;
    if ( (unsigned int)v7 < v8 )
      *v7++ = -3;
    else
      result = -1073741789;
  }
  if ( a3 )
    *a3 = 2 * (v7 - v6);
  return result;
}

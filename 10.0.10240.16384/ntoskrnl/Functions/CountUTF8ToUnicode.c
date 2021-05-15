// CountUTF8ToUnicode 
 
int __fastcall CountUTF8ToUnicode(unsigned int a1, int a2, _DWORD *a3)
{
  int v4; // r5
  unsigned int v5; // lr
  int v6; // r7
  int v7; // r4
  unsigned int v8; // r4
  unsigned int v9; // t1
  char v10; // r2
  char v11; // t1
  unsigned int v12; // t1
  unsigned int v13; // r6
  unsigned int v14; // r1
  unsigned int v15; // t1
  __int64 v16; // r2
  char v17; // r4
  char v18; // t1
  unsigned int v19; // r3
  int v20; // r3

  v4 = a2;
  v5 = a1 + a2;
  v6 = 0;
LABEL_2:
  v7 = 0;
  while ( a1 < v5 )
  {
    if ( v7 )
    {
      v11 = *(_BYTE *)a1++;
      v10 = v11;
      if ( (v11 & 0xC0) != 128 )
      {
        --a1;
        v4 += v7 >> 30;
        goto LABEL_8;
      }
      v7 = v10 & 0x3F | (v7 << 6);
      if ( (v7 & 0x20000000) != 0 )
        goto LABEL_17;
      if ( (v7 & 0x10000000) != 0 )
      {
        if ( (v7 & 0x800000) == 0 && (v7 & 0x1F0u) - 16 > 0xF0 )
          goto LABEL_8;
      }
      else if ( (v7 & 0x3E0) == 0 || (v7 & 0x3E0) == 864 )
      {
        goto LABEL_8;
      }
    }
    else
    {
      v9 = *(char *)a1++;
      v8 = v9;
LABEL_20:
      if ( v8 <= 0x7F )
      {
LABEL_17:
        if ( v5 - a1 <= 0xD )
        {
          while ( a1 < v5 )
          {
            v12 = *(char *)a1++;
            v8 = v12;
            if ( v12 > 0x7F )
              goto LABEL_20;
          }
          v7 = 0;
          break;
        }
        v13 = v5 - 7;
        if ( a1 >= v5 - 7 )
          goto LABEL_2;
        while ( 1 )
        {
          v15 = *(char *)a1++;
          LOBYTE(v14) = v15;
          if ( v15 > 0x7F )
            goto LABEL_43;
          if ( (a1 & 1) != 0 )
          {
            v14 = *(char *)a1++;
            if ( v14 > 0x7F )
              goto LABEL_43;
          }
          if ( (a1 & 2) == 0 )
            goto LABEL_37;
          LOWORD(v16) = *(_WORD *)a1;
          if ( (*(_WORD *)a1 & 0x8080) == 0 )
          {
LABEL_37:
            for ( a1 += 2; a1 < v13; a1 += 8 )
            {
              v16 = *(_QWORD *)a1;
              if ( ((HIDWORD(v16) | (unsigned int)v16) & 0x80808080) != 0 )
                goto LABEL_42;
              a1 += 8;
              if ( a1 >= v13 )
                break;
              v16 = *(_QWORD *)a1;
              if ( ((HIDWORD(v16) | (unsigned int)v16) & 0x80808080) != 0 )
                goto LABEL_42;
            }
            goto LABEL_2;
          }
LABEL_42:
          LOBYTE(v14) = v16;
          ++a1;
          if ( (unsigned __int8)v16 > 0x7Fu )
          {
LABEL_43:
            v18 = *(_BYTE *)a1++;
            v17 = v18;
            if ( (v14 & 0x40) == 0 || (v17 & 0xC0) != 128 )
            {
LABEL_60:
              a1 -= 2;
              goto LABEL_2;
            }
            if ( (v14 & 0x20) != 0 )
            {
              v19 = v17 & 0x3F | ((v14 & 0xF) << 6);
              if ( (v14 & 0x10) != 0 )
              {
                if ( (v19 >> 4) - 1 > 0xF || (*(_BYTE *)a1 & 0xC0) != 128 || (*(_BYTE *)(a1 + 1) & 0xC0) != 128 )
                  goto LABEL_60;
                a1 += 2;
              }
              else
              {
                v20 = v19 & 0x3E0;
                if ( !v20 || v20 == 864 || (*(_BYTE *)a1 & 0xC0) != 128 )
                  goto LABEL_60;
                ++a1;
              }
              --v4;
            }
            else if ( (v14 & 0x1E) == 0 )
            {
              goto LABEL_60;
            }
            --v4;
          }
          if ( a1 >= v13 )
            goto LABEL_2;
        }
      }
      --v4;
      if ( (v8 & 0x40) == 0 )
        goto LABEL_8;
      if ( (v8 & 0x20) != 0 )
      {
        if ( (v8 & 0x10) != 0 )
        {
          if ( (v8 & 0xF) <= 4 )
          {
            v7 = v8 & 0xF | 0x504D0C00;
            goto LABEL_27;
          }
LABEL_8:
          ++v4;
          v7 = 0;
          v6 = 263;
        }
        else
        {
          v7 = v8 & 0xF | 0x48228000;
LABEL_27:
          --v4;
        }
      }
      else
      {
        if ( (v8 & 0x1F) <= 1 )
          goto LABEL_8;
        v7 = v8 & 0x1F | 0x800000;
      }
    }
  }
  if ( v7 )
  {
    v4 += (v7 >> 30) + 1;
    v6 = 263;
  }
  *a3 = 2 * v4;
  return v6;
}

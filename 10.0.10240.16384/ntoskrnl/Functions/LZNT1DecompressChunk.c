// LZNT1DecompressChunk 
 
int __fastcall LZNT1DecompressChunk(unsigned int a1, unsigned int a2, unsigned __int8 *a3, unsigned int a4, char **a5, int a6, int a7)
{
  char v8; // r3
  int v10; // r10
  int v11; // r6
  char *v12; // r4
  _BYTE *v13; // r5
  unsigned __int8 *v14; // r7
  int *v15; // r2
  int v16; // t1
  char v17; // t1
  char v18; // r3
  int v19; // r3
  int v20; // r2
  int v21; // r1
  int v22; // r2
  int v23; // r3
  char *v24; // r1
  char v25; // t1
  char *v26; // r2
  int result; // r0
  unsigned __int16 v28; // [sp+0h] [bp-28h]
  char v29; // [sp+4h] [bp-24h]

  v8 = 0;
  v10 = *a3;
  v11 = 0;
  v12 = (char *)(a3 + 1);
  v29 = 0;
  v13 = (_BYTE *)a1;
  if ( a1 < a2 )
  {
    v14 = a3 + 2;
    do
    {
      if ( (unsigned int)v12 >= a4 )
        break;
      if ( FormatMaxDisplacement[v11] + a1 < (unsigned int)v13 )
      {
        v15 = &FormatMaxDisplacement[v11];
        do
        {
          v16 = v15[1];
          ++v15;
          ++v11;
        }
        while ( v16 + a1 < (unsigned int)v13 );
        v8 = v29;
      }
      if ( ((1 << v8) & v10) == 0 )
      {
        v17 = *v12++;
        *v13++ = v17;
        ++v14;
        goto LABEL_36;
      }
      if ( (unsigned int)v14 >= a4 )
        goto LABEL_41;
      v14 += 2;
      LOBYTE(v28) = *v12;
      v18 = v12[1];
      v12 += 2;
      HIBYTE(v28) = v18;
      if ( v11 )
      {
        switch ( v11 )
        {
          case 1:
            v19 = v28 >> 11;
            v20 = v28 & 0x7FF;
            break;
          case 2:
            v19 = v28 >> 10;
            v20 = v28 & 0x3FF;
            break;
          case 3:
            v19 = v28 >> 9;
            v20 = v28 & 0x1FF;
            break;
          default:
            switch ( v11 )
            {
              case 4:
                v21 = HIBYTE(v28) + 1;
                v23 = (unsigned __int8)v28;
                break;
              case 5:
                v21 = (v28 >> 7) + 1;
                v23 = v28 & 0x7F;
                break;
              case 6:
                v21 = (v28 >> 6) + 1;
                v23 = v28 & 0x3F;
                break;
              case 7:
                v21 = (v28 >> 5) + 1;
                v23 = v28 & 0x1F;
                break;
              default:
                v21 = (v28 >> 4) + 1;
                v23 = v28 & 0xF;
                break;
            }
            v22 = v23 + 3;
            goto LABEL_30;
        }
      }
      else
      {
        v19 = v28 >> 12;
        v20 = v28 & 0xFFF;
      }
      v21 = v19 + 1;
      v22 = v20 + 3;
LABEL_30:
      if ( v21 > (int)&v13[-a1] )
      {
LABEL_41:
        result = -1073741246;
        *a5 = v12;
        return result;
      }
      if ( (unsigned int)&v13[v22] >= a2 )
        v22 = a2 - (_DWORD)v13;
      if ( v22 > 0 )
      {
        v24 = &v13[-v21];
        do
        {
          v25 = *v24++;
          --v22;
          *v13++ = v25;
        }
        while ( v22 > 0 );
      }
LABEL_36:
      v8 = (v29 + 1) & 7;
      v29 = v8;
      if ( !v8 )
      {
        if ( (unsigned int)v12 >= a4 )
          break;
        v10 = (unsigned __int8)*v12++;
        ++v14;
      }
    }
    while ( (unsigned int)v13 < a2 );
  }
  v26 = &v13[-a1];
  result = 0;
  *a5 = v26;
  return result;
}

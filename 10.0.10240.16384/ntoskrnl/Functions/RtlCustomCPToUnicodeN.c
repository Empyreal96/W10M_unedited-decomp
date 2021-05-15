// RtlCustomCPToUnicodeN 
 
int __fastcall RtlCustomCPToUnicodeN(int a1, char *a2, unsigned int a3, _DWORD *a4, unsigned __int8 *a5, unsigned int a6)
{
  unsigned int v6; // r7
  unsigned int v7; // r5
  unsigned int v9; // r4
  int v10; // r0
  unsigned __int8 *v11; // r2
  int v12; // r8
  char *v13; // r9
  unsigned __int8 *v14; // r4
  int v15; // r2
  int v16; // t1
  int v17; // lr
  int v18; // r3
  int result; // r0

  v6 = a3 >> 1;
  v7 = a6;
  if ( !*(_WORD *)(a1 + 12) )
  {
    v9 = a3 >> 1;
    if ( v6 >= a6 )
      v9 = a6;
    if ( a4 )
      *a4 = 2 * v9;
    v10 = *(_DWORD *)(a1 + 28);
    v11 = a5;
    while ( 1 )
    {
      switch ( v9 )
      {
        case 0u:
          goto LABEL_24;
        case 1u:
          goto LABEL_23;
        case 2u:
          goto LABEL_22;
        case 3u:
          goto LABEL_21;
        case 4u:
          goto LABEL_20;
        case 5u:
          goto LABEL_19;
        case 6u:
          goto LABEL_18;
        case 7u:
          goto LABEL_17;
        case 8u:
          goto LABEL_16;
        case 9u:
          goto LABEL_15;
        case 0xAu:
          goto LABEL_14;
        case 0xBu:
          goto LABEL_13;
        case 0xCu:
          goto LABEL_12;
        case 0xDu:
          goto LABEL_11;
        case 0xEu:
          goto LABEL_10;
        case 0xFu:
          goto LABEL_9;
        default:
          *((_WORD *)a2 + 15) = *(_WORD *)(v10 + 2 * v11[15]);
LABEL_9:
          *((_WORD *)a2 + 14) = *(_WORD *)(v10 + 2 * v11[14]);
LABEL_10:
          *((_WORD *)a2 + 13) = *(_WORD *)(v10 + 2 * v11[13]);
LABEL_11:
          *((_WORD *)a2 + 12) = *(_WORD *)(v10 + 2 * v11[12]);
LABEL_12:
          *((_WORD *)a2 + 11) = *(_WORD *)(v10 + 2 * v11[11]);
LABEL_13:
          *((_WORD *)a2 + 10) = *(_WORD *)(v10 + 2 * v11[10]);
LABEL_14:
          *((_WORD *)a2 + 9) = *(_WORD *)(v10 + 2 * v11[9]);
LABEL_15:
          *((_WORD *)a2 + 8) = *(_WORD *)(v10 + 2 * v11[8]);
LABEL_16:
          *((_WORD *)a2 + 7) = *(_WORD *)(v10 + 2 * v11[7]);
LABEL_17:
          *((_WORD *)a2 + 6) = *(_WORD *)(v10 + 2 * v11[6]);
LABEL_18:
          *((_WORD *)a2 + 5) = *(_WORD *)(v10 + 2 * v11[5]);
LABEL_19:
          *((_WORD *)a2 + 4) = *(_WORD *)(v10 + 2 * v11[4]);
LABEL_20:
          *((_WORD *)a2 + 3) = *(_WORD *)(v10 + 2 * v11[3]);
LABEL_21:
          *((_WORD *)a2 + 2) = *(_WORD *)(v10 + 2 * v11[2]);
LABEL_22:
          *((_WORD *)a2 + 1) = *(_WORD *)(v10 + 2 * v11[1]);
LABEL_23:
          *(_WORD *)a2 = *(_WORD *)(v10 + 2 * *v11);
LABEL_24:
          if ( v9 <= 0x10 )
            goto LABEL_38;
          v9 -= 16;
          v11 += 16;
          a2 += 32;
          break;
      }
    }
  }
  v12 = *(_DWORD *)(a1 + 40);
  v13 = a2;
  if ( v6 )
  {
    v14 = a5;
    while ( v7 )
    {
      v16 = *v14++;
      v15 = v16;
      --v6;
      --v7;
      v17 = *(unsigned __int16 *)(v12 + 2 * v16);
      if ( *(_WORD *)(v12 + 2 * v16) )
      {
        if ( !v7 )
        {
          *(_WORD *)a2 = 0;
          a2 += 2;
          break;
        }
        v18 = *v14++;
        *(_WORD *)a2 = *(_WORD *)(v12 + 2 * (v18 + v17));
        a2 += 2;
        --v7;
      }
      else
      {
        *(_WORD *)a2 = *(_WORD *)(*(_DWORD *)(a1 + 28) + 2 * v15);
        a2 += 2;
      }
      if ( !v6 )
        break;
    }
  }
  if ( a4 )
    *a4 = a2 - v13;
LABEL_38:
  if ( v7 > v6 )
    result = -2147483643;
  else
    result = 0;
  return result;
}

// RtlOemToUnicodeN 
 
int __fastcall RtlOemToUnicodeN(char *a1, unsigned int a2, _DWORD *a3, unsigned __int8 *a4, unsigned int a5)
{
  unsigned int v5; // r6
  unsigned int v6; // r5
  unsigned __int8 *v7; // r4
  unsigned int v8; // r1
  int v9; // r2
  int result; // r0
  char *v11; // lr
  int v12; // r9
  int v13; // r8
  int v14; // r3
  int v15; // t1
  int v16; // r7
  int v17; // r3

  v5 = a2 >> 1;
  v6 = a5;
  v7 = a4;
  if ( NlsMbOemCodePageTag )
  {
    v11 = a1;
    v12 = NlsMbOemCodePageTables;
    if ( v5 )
    {
      v13 = NlsOemToUnicodeData;
      while ( v6 )
      {
        v15 = *v7++;
        v14 = v15;
        --v5;
        --v6;
        v16 = (unsigned __int16)NlsOemLeadByteInfoTable[v15];
        if ( NlsOemLeadByteInfoTable[v15] )
        {
          if ( !v6 )
          {
            *(_WORD *)a1 = 0;
            a1 += 2;
            break;
          }
          v17 = *v7++;
          *(_WORD *)a1 = *(_WORD *)(v12 + 2 * (v17 + v16));
          a1 += 2;
          --v6;
        }
        else
        {
          *(_WORD *)a1 = *(_WORD *)(v13 + 2 * v14);
          a1 += 2;
        }
        if ( !v5 )
          break;
      }
    }
    if ( a3 )
      *a3 = a1 - v11;
LABEL_21:
    if ( v6 > v5 )
      result = -2147483643;
    else
      result = 0;
  }
  else
  {
    if ( v5 < a5 )
      v8 = a2 >> 1;
    else
      v8 = a5;
    if ( a3 )
      *a3 = 2 * v8;
    v9 = NlsOemToUnicodeData;
    switch ( v8 )
    {
      case 0u:
        goto LABEL_19;
      case 1u:
        goto LABEL_18;
      case 2u:
        goto LABEL_17;
      case 3u:
        goto LABEL_16;
      case 4u:
        goto LABEL_15;
      case 5u:
        goto LABEL_14;
      case 6u:
        goto LABEL_13;
      case 7u:
        goto LABEL_12;
      case 8u:
        goto LABEL_11;
      case 9u:
        goto LABEL_10;
      case 0xAu:
        goto LABEL_9;
      case 0xBu:
        goto LABEL_8;
      case 0xCu:
        goto LABEL_7;
      case 0xDu:
        goto LABEL_26;
      case 0xEu:
        goto LABEL_25;
      case 0xFu:
        goto LABEL_24;
      default:
        *((_WORD *)a1 + 15) = *(_WORD *)(NlsOemToUnicodeData + 2 * a4[15]);
LABEL_24:
        *((_WORD *)a1 + 14) = *(_WORD *)(v9 + 2 * a4[14]);
LABEL_25:
        *((_WORD *)a1 + 13) = *(_WORD *)(v9 + 2 * a4[13]);
LABEL_26:
        *((_WORD *)a1 + 12) = *(_WORD *)(v9 + 2 * a4[12]);
LABEL_7:
        *((_WORD *)a1 + 11) = *(_WORD *)(v9 + 2 * a4[11]);
LABEL_8:
        *((_WORD *)a1 + 10) = *(_WORD *)(v9 + 2 * a4[10]);
LABEL_9:
        *((_WORD *)a1 + 9) = *(_WORD *)(v9 + 2 * a4[9]);
LABEL_10:
        *((_WORD *)a1 + 8) = *(_WORD *)(v9 + 2 * a4[8]);
LABEL_11:
        *((_WORD *)a1 + 7) = *(_WORD *)(v9 + 2 * a4[7]);
LABEL_12:
        *((_WORD *)a1 + 6) = *(_WORD *)(v9 + 2 * a4[6]);
LABEL_13:
        *((_WORD *)a1 + 5) = *(_WORD *)(v9 + 2 * a4[5]);
LABEL_14:
        *((_WORD *)a1 + 4) = *(_WORD *)(v9 + 2 * a4[4]);
LABEL_15:
        *((_WORD *)a1 + 3) = *(_WORD *)(v9 + 2 * a4[3]);
LABEL_16:
        *((_WORD *)a1 + 2) = *(_WORD *)(v9 + 2 * a4[2]);
LABEL_17:
        *((_WORD *)a1 + 1) = *(_WORD *)(v9 + 2 * a4[1]);
LABEL_18:
        *(_WORD *)a1 = *(_WORD *)(v9 + 2 * *a4);
LABEL_19:
        if ( v8 <= 0x10 )
          goto LABEL_21;
        result = sub_7E5CAC(a1);
        break;
    }
  }
  return result;
}

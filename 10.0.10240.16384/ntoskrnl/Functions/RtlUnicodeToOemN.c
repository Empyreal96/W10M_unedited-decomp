// RtlUnicodeToOemN 
 
int __fastcall RtlUnicodeToOemN(int a1, unsigned int a2, unsigned int *a3, int a4, unsigned int a5)
{
  unsigned int v5; // r6
  unsigned int v6; // lr
  int result; // r0
  unsigned int v9; // r4
  int v10; // r7
  int v11; // r2
  int v12; // r0
  int v13; // r1

  v5 = a2;
  v6 = a5 >> 1;
  if ( NlsMbOemCodePageTag )
    return sub_7DD2F8();
  if ( v6 < a2 )
    v9 = a5 >> 1;
  else
    v9 = a2;
  if ( a3 )
    *a3 = v9;
  v10 = v9 & 0xF;
  v11 = a4 + 2 * v10;
  v12 = NlsUnicodeToOemData;
  v13 = v10 + a1;
  while ( 2 )
  {
    switch ( v10 )
    {
      case 0:
        goto LABEL_21;
      case 1:
        goto LABEL_20;
      case 2:
        goto LABEL_19;
      case 3:
        goto LABEL_18;
      case 4:
        goto LABEL_17;
      case 5:
        goto LABEL_16;
      case 6:
        goto LABEL_15;
      case 7:
        goto LABEL_14;
      case 8:
        goto LABEL_13;
      case 9:
        goto LABEL_12;
      case 10:
        goto LABEL_11;
      case 11:
        goto LABEL_10;
      case 12:
        goto LABEL_9;
      case 13:
        goto LABEL_27;
      case 14:
        goto LABEL_26;
      case 15:
        goto LABEL_25;
      default:
        v11 += 32;
        v13 += 16;
        *(_BYTE *)(v13 - 16) = *(_BYTE *)(*(unsigned __int16 *)(v11 - 32) + v12);
LABEL_25:
        *(_BYTE *)(v13 - 15) = *(_BYTE *)(*(unsigned __int16 *)(v11 - 30) + v12);
LABEL_26:
        *(_BYTE *)(v13 - 14) = *(_BYTE *)(*(unsigned __int16 *)(v11 - 28) + v12);
LABEL_27:
        *(_BYTE *)(v13 - 13) = *(_BYTE *)(*(unsigned __int16 *)(v11 - 26) + v12);
LABEL_9:
        *(_BYTE *)(v13 - 12) = *(_BYTE *)(*(unsigned __int16 *)(v11 - 24) + v12);
LABEL_10:
        *(_BYTE *)(v13 - 11) = *(_BYTE *)(*(unsigned __int16 *)(v11 - 22) + v12);
LABEL_11:
        *(_BYTE *)(v13 - 10) = *(_BYTE *)(*(unsigned __int16 *)(v11 - 20) + v12);
LABEL_12:
        *(_BYTE *)(v13 - 9) = *(_BYTE *)(*(unsigned __int16 *)(v11 - 18) + v12);
LABEL_13:
        *(_BYTE *)(v13 - 8) = *(_BYTE *)(*(unsigned __int16 *)(v11 - 16) + v12);
LABEL_14:
        *(_BYTE *)(v13 - 7) = *(_BYTE *)(*(unsigned __int16 *)(v11 - 14) + v12);
LABEL_15:
        *(_BYTE *)(v13 - 6) = *(_BYTE *)(*(unsigned __int16 *)(v11 - 12) + v12);
LABEL_16:
        *(_BYTE *)(v13 - 5) = *(_BYTE *)(*(unsigned __int16 *)(v11 - 10) + v12);
LABEL_17:
        *(_BYTE *)(v13 - 4) = *(_BYTE *)(*(unsigned __int16 *)(v11 - 8) + v12);
LABEL_18:
        *(_BYTE *)(v13 - 3) = *(_BYTE *)(*(unsigned __int16 *)(v11 - 6) + v12);
LABEL_19:
        *(_BYTE *)(v13 - 2) = *(_BYTE *)(*(unsigned __int16 *)(v11 - 4) + v12);
LABEL_20:
        *(_BYTE *)(v13 - 1) = *(_BYTE *)(*(unsigned __int16 *)(v11 - 2) + v12);
LABEL_21:
        v9 -= v10;
        v10 = 16;
        if ( v9 )
          continue;
        if ( v6 > v5 )
          result = -2147483643;
        else
          result = 0;
        break;
    }
    return result;
  }
}

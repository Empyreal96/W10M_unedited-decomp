// RtlUnicodeToCustomCPN 
 
int __fastcall RtlUnicodeToCustomCPN(int a1, _BYTE *a2, unsigned int a3, unsigned int *a4, unsigned __int16 *a5, unsigned int a6)
{
  unsigned int v6; // r5
  unsigned int v7; // r7
  unsigned int v8; // r4
  int v9; // r0
  int v10; // r6
  unsigned __int16 *v11; // r2
  _BYTE *v12; // r1
  int v13; // lr
  _BYTE *v14; // r2
  unsigned __int16 *v15; // r4
  int v16; // t1
  unsigned int v17; // r0
  int result; // r0

  v6 = a3;
  v7 = a6 >> 1;
  if ( !*(_WORD *)(a1 + 12) )
  {
    v8 = a6 >> 1;
    if ( v7 >= a3 )
      v8 = a3;
    if ( a4 )
      *a4 = v8;
    v9 = *(_DWORD *)(a1 + 32);
    v10 = v8 & 0xF;
    v11 = &a5[v10];
    v12 = &a2[v10];
    while ( 2 )
    {
      switch ( v10 )
      {
        case 0:
          goto LABEL_24;
        case 1:
          goto LABEL_23;
        case 2:
          goto LABEL_22;
        case 3:
          goto LABEL_21;
        case 4:
          goto LABEL_20;
        case 5:
          goto LABEL_19;
        case 6:
          goto LABEL_18;
        case 7:
          goto LABEL_17;
        case 8:
          goto LABEL_16;
        case 9:
          goto LABEL_15;
        case 10:
          goto LABEL_14;
        case 11:
          goto LABEL_13;
        case 12:
          goto LABEL_12;
        case 13:
          goto LABEL_11;
        case 14:
          goto LABEL_10;
        case 15:
          goto LABEL_9;
        default:
          v11 += 16;
          v12 += 16;
          *(v12 - 16) = *(_BYTE *)(*(v11 - 16) + v9);
LABEL_9:
          *(v12 - 15) = *(_BYTE *)(*(v11 - 15) + v9);
LABEL_10:
          *(v12 - 14) = *(_BYTE *)(*(v11 - 14) + v9);
LABEL_11:
          *(v12 - 13) = *(_BYTE *)(*(v11 - 13) + v9);
LABEL_12:
          *(v12 - 12) = *(_BYTE *)(*(v11 - 12) + v9);
LABEL_13:
          *(v12 - 11) = *(_BYTE *)(*(v11 - 11) + v9);
LABEL_14:
          *(v12 - 10) = *(_BYTE *)(*(v11 - 10) + v9);
LABEL_15:
          *(v12 - 9) = *(_BYTE *)(*(v11 - 9) + v9);
LABEL_16:
          *(v12 - 8) = *(_BYTE *)(*(v11 - 8) + v9);
LABEL_17:
          *(v12 - 7) = *(_BYTE *)(*(v11 - 7) + v9);
LABEL_18:
          *(v12 - 6) = *(_BYTE *)(*(v11 - 6) + v9);
LABEL_19:
          *(v12 - 5) = *(_BYTE *)(*(v11 - 5) + v9);
LABEL_20:
          *(v12 - 4) = *(_BYTE *)(*(v11 - 4) + v9);
LABEL_21:
          *(v12 - 3) = *(_BYTE *)(*(v11 - 3) + v9);
LABEL_22:
          *(v12 - 2) = *(_BYTE *)(*(v11 - 2) + v9);
LABEL_23:
          *(v12 - 1) = *(_BYTE *)(*(v11 - 1) + v9);
LABEL_24:
          v8 -= v10;
          v10 = 16;
          if ( !v8 )
            goto LABEL_36;
          continue;
      }
    }
  }
  v13 = *(_DWORD *)(a1 + 32);
  v14 = a2;
  if ( v7 )
  {
    v15 = a5;
    do
    {
      if ( !v6 )
        break;
      v16 = *v15++;
      v17 = *(unsigned __int16 *)(v13 + 2 * v16);
      if ( v17 >> 8 )
      {
        if ( v6-- < 2 )
          break;
        *a2++ = BYTE1(v17);
      }
      --v6;
      --v7;
      *a2++ = v17;
    }
    while ( v7 );
  }
  if ( a4 )
    *a4 = a2 - v14;
LABEL_36:
  if ( v7 > v6 )
    result = -2147483643;
  else
    result = 0;
  return result;
}

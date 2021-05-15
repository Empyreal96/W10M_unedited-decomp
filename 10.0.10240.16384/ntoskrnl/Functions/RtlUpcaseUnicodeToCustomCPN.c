// RtlUpcaseUnicodeToCustomCPN 
 
int __fastcall RtlUpcaseUnicodeToCustomCPN(int a1, _BYTE *a2, unsigned int a3, unsigned int *a4, unsigned __int16 *a5, unsigned int a6)
{
  unsigned int v8; // r2
  _BYTE *v9; // r5
  unsigned int v10; // lr
  int v11; // r8
  int v12; // r1
  unsigned __int16 *v13; // r6
  _BYTE *v14; // r0
  int v15; // r5
  unsigned int v16; // r4
  unsigned int v17; // r4
  unsigned int v18; // r4
  unsigned int v19; // r4
  unsigned int v20; // r4
  unsigned int v21; // r4
  unsigned int v22; // r4
  unsigned int v23; // r4
  unsigned int v24; // r4
  unsigned int v25; // r4
  unsigned int v26; // r4
  unsigned int v27; // r4
  unsigned int v28; // r4
  unsigned int v29; // r4
  unsigned int v30; // r4
  unsigned int v31; // r4
  int v32; // r0
  int v33; // r4
  unsigned __int16 *v35; // r8
  int v36; // r9
  int v37; // t1
  unsigned int v38; // r2
  unsigned int v39; // r1
  unsigned int v40; // r2
  int result; // r0
  unsigned int v43; // [sp+0h] [bp-20h]

  v8 = a6 >> 1;
  v9 = a2;
  v43 = a6 >> 1;
  if ( !*(_WORD *)(a1 + 12) )
  {
    v10 = a6 >> 1;
    if ( v8 >= a3 )
      v10 = a3;
    if ( a4 )
      *a4 = v10;
    v11 = v10 & 0xF;
    v12 = *(_DWORD *)(a1 + 32);
    v13 = &a5[v11];
    v14 = &v9[v11];
    v15 = Nls844UnicodeUpcaseTable;
    while ( 2 )
    {
      switch ( v11 )
      {
        case 0:
          goto LABEL_88;
        case 1:
          goto LABEL_83;
        case 2:
          goto LABEL_78;
        case 3:
          goto LABEL_73;
        case 4:
          goto LABEL_68;
        case 5:
          goto LABEL_63;
        case 6:
          goto LABEL_58;
        case 7:
          goto LABEL_53;
        case 8:
          goto LABEL_48;
        case 9:
          goto LABEL_43;
        case 10:
          goto LABEL_38;
        case 11:
          goto LABEL_33;
        case 12:
          goto LABEL_28;
        case 13:
          goto LABEL_23;
        case 14:
          goto LABEL_18;
        case 15:
          goto LABEL_13;
        default:
          v13 += 16;
          v14 += 16;
          v16 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * *(unsigned __int8 *)(*(v13 - 16) + v12));
          if ( v16 >= 0x61 )
          {
            if ( v16 > 0x7A )
              LOWORD(v16) = *(_WORD *)(v15
                                     + 2
                                     * ((v16 & 0xF)
                                      + *(unsigned __int16 *)(v15
                                                            + 2
                                                            * (((unsigned __int8)v16 >> 4)
                                                             + *(unsigned __int16 *)(v15 + 2 * (v16 >> 8))))))
                          + v16;
            else
              LOWORD(v16) = v16 - 32;
          }
          *(v14 - 16) = *(_BYTE *)((unsigned __int16)v16 + v12);
LABEL_13:
          v17 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * *(unsigned __int8 *)(*(v13 - 15) + v12));
          if ( v17 >= 0x61 )
          {
            if ( v17 > 0x7A )
              LOWORD(v17) = *(_WORD *)(v15
                                     + 2
                                     * ((v17 & 0xF)
                                      + *(unsigned __int16 *)(v15
                                                            + 2
                                                            * (((unsigned __int8)v17 >> 4)
                                                             + *(unsigned __int16 *)(v15 + 2 * (v17 >> 8))))))
                          + v17;
            else
              LOWORD(v17) = v17 - 32;
          }
          *(v14 - 15) = *(_BYTE *)((unsigned __int16)v17 + v12);
LABEL_18:
          v18 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * *(unsigned __int8 *)(*(v13 - 14) + v12));
          if ( v18 >= 0x61 )
          {
            if ( v18 > 0x7A )
              LOWORD(v18) = *(_WORD *)(v15
                                     + 2
                                     * ((v18 & 0xF)
                                      + *(unsigned __int16 *)(v15
                                                            + 2
                                                            * (((unsigned __int8)v18 >> 4)
                                                             + *(unsigned __int16 *)(v15 + 2 * (v18 >> 8))))))
                          + v18;
            else
              LOWORD(v18) = v18 - 32;
          }
          *(v14 - 14) = *(_BYTE *)((unsigned __int16)v18 + v12);
LABEL_23:
          v19 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * *(unsigned __int8 *)(*(v13 - 13) + v12));
          if ( v19 >= 0x61 )
          {
            if ( v19 > 0x7A )
              LOWORD(v19) = *(_WORD *)(v15
                                     + 2
                                     * ((v19 & 0xF)
                                      + *(unsigned __int16 *)(v15
                                                            + 2
                                                            * (((unsigned __int8)v19 >> 4)
                                                             + *(unsigned __int16 *)(v15 + 2 * (v19 >> 8))))))
                          + v19;
            else
              LOWORD(v19) = v19 - 32;
          }
          *(v14 - 13) = *(_BYTE *)((unsigned __int16)v19 + v12);
LABEL_28:
          v20 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * *(unsigned __int8 *)(*(v13 - 12) + v12));
          if ( v20 >= 0x61 )
          {
            if ( v20 > 0x7A )
              LOWORD(v20) = *(_WORD *)(v15
                                     + 2
                                     * ((v20 & 0xF)
                                      + *(unsigned __int16 *)(v15
                                                            + 2
                                                            * (((unsigned __int8)v20 >> 4)
                                                             + *(unsigned __int16 *)(v15 + 2 * (v20 >> 8))))))
                          + v20;
            else
              LOWORD(v20) = v20 - 32;
          }
          *(v14 - 12) = *(_BYTE *)((unsigned __int16)v20 + v12);
LABEL_33:
          v21 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * *(unsigned __int8 *)(*(v13 - 11) + v12));
          if ( v21 >= 0x61 )
          {
            if ( v21 > 0x7A )
              LOWORD(v21) = *(_WORD *)(v15
                                     + 2
                                     * ((v21 & 0xF)
                                      + *(unsigned __int16 *)(v15
                                                            + 2
                                                            * (((unsigned __int8)v21 >> 4)
                                                             + *(unsigned __int16 *)(v15 + 2 * (v21 >> 8))))))
                          + v21;
            else
              LOWORD(v21) = v21 - 32;
          }
          *(v14 - 11) = *(_BYTE *)((unsigned __int16)v21 + v12);
LABEL_38:
          v22 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * *(unsigned __int8 *)(*(v13 - 10) + v12));
          if ( v22 >= 0x61 )
          {
            if ( v22 > 0x7A )
              LOWORD(v22) = *(_WORD *)(v15
                                     + 2
                                     * ((v22 & 0xF)
                                      + *(unsigned __int16 *)(v15
                                                            + 2
                                                            * (((unsigned __int8)v22 >> 4)
                                                             + *(unsigned __int16 *)(v15 + 2 * (v22 >> 8))))))
                          + v22;
            else
              LOWORD(v22) = v22 - 32;
          }
          *(v14 - 10) = *(_BYTE *)((unsigned __int16)v22 + v12);
LABEL_43:
          v23 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * *(unsigned __int8 *)(*(v13 - 9) + v12));
          if ( v23 >= 0x61 )
          {
            if ( v23 > 0x7A )
              LOWORD(v23) = *(_WORD *)(v15
                                     + 2
                                     * ((v23 & 0xF)
                                      + *(unsigned __int16 *)(v15
                                                            + 2
                                                            * (((unsigned __int8)v23 >> 4)
                                                             + *(unsigned __int16 *)(v15 + 2 * (v23 >> 8))))))
                          + v23;
            else
              LOWORD(v23) = v23 - 32;
          }
          *(v14 - 9) = *(_BYTE *)((unsigned __int16)v23 + v12);
LABEL_48:
          v24 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * *(unsigned __int8 *)(*(v13 - 8) + v12));
          if ( v24 >= 0x61 )
          {
            if ( v24 > 0x7A )
              LOWORD(v24) = *(_WORD *)(v15
                                     + 2
                                     * ((v24 & 0xF)
                                      + *(unsigned __int16 *)(v15
                                                            + 2
                                                            * (((unsigned __int8)v24 >> 4)
                                                             + *(unsigned __int16 *)(v15 + 2 * (v24 >> 8))))))
                          + v24;
            else
              LOWORD(v24) = v24 - 32;
          }
          *(v14 - 8) = *(_BYTE *)((unsigned __int16)v24 + v12);
LABEL_53:
          v25 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * *(unsigned __int8 *)(*(v13 - 7) + v12));
          if ( v25 >= 0x61 )
          {
            if ( v25 > 0x7A )
              LOWORD(v25) = *(_WORD *)(v15
                                     + 2
                                     * ((v25 & 0xF)
                                      + *(unsigned __int16 *)(v15
                                                            + 2
                                                            * (((unsigned __int8)v25 >> 4)
                                                             + *(unsigned __int16 *)(v15 + 2 * (v25 >> 8))))))
                          + v25;
            else
              LOWORD(v25) = v25 - 32;
          }
          *(v14 - 7) = *(_BYTE *)((unsigned __int16)v25 + v12);
LABEL_58:
          v26 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * *(unsigned __int8 *)(*(v13 - 6) + v12));
          if ( v26 >= 0x61 )
          {
            if ( v26 > 0x7A )
              LOWORD(v26) = *(_WORD *)(v15
                                     + 2
                                     * ((v26 & 0xF)
                                      + *(unsigned __int16 *)(v15
                                                            + 2
                                                            * (((unsigned __int8)v26 >> 4)
                                                             + *(unsigned __int16 *)(v15 + 2 * (v26 >> 8))))))
                          + v26;
            else
              LOWORD(v26) = v26 - 32;
          }
          *(v14 - 6) = *(_BYTE *)((unsigned __int16)v26 + v12);
LABEL_63:
          v27 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * *(unsigned __int8 *)(*(v13 - 5) + v12));
          if ( v27 >= 0x61 )
          {
            if ( v27 > 0x7A )
              LOWORD(v27) = *(_WORD *)(v15
                                     + 2
                                     * ((v27 & 0xF)
                                      + *(unsigned __int16 *)(v15
                                                            + 2
                                                            * (((unsigned __int8)v27 >> 4)
                                                             + *(unsigned __int16 *)(v15 + 2 * (v27 >> 8))))))
                          + v27;
            else
              LOWORD(v27) = v27 - 32;
          }
          *(v14 - 5) = *(_BYTE *)((unsigned __int16)v27 + v12);
LABEL_68:
          v28 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * *(unsigned __int8 *)(*(v13 - 4) + v12));
          if ( v28 >= 0x61 )
          {
            if ( v28 > 0x7A )
              LOWORD(v28) = *(_WORD *)(v15
                                     + 2
                                     * ((v28 & 0xF)
                                      + *(unsigned __int16 *)(v15
                                                            + 2
                                                            * (((unsigned __int8)v28 >> 4)
                                                             + *(unsigned __int16 *)(v15 + 2 * (v28 >> 8))))))
                          + v28;
            else
              LOWORD(v28) = v28 - 32;
          }
          *(v14 - 4) = *(_BYTE *)((unsigned __int16)v28 + v12);
LABEL_73:
          v29 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * *(unsigned __int8 *)(*(v13 - 3) + v12));
          if ( v29 >= 0x61 )
          {
            if ( v29 > 0x7A )
              LOWORD(v29) = *(_WORD *)(v15
                                     + 2
                                     * ((v29 & 0xF)
                                      + *(unsigned __int16 *)(v15
                                                            + 2
                                                            * (((unsigned __int8)v29 >> 4)
                                                             + *(unsigned __int16 *)(v15 + 2 * (v29 >> 8))))))
                          + v29;
            else
              LOWORD(v29) = v29 - 32;
          }
          *(v14 - 3) = *(_BYTE *)((unsigned __int16)v29 + v12);
LABEL_78:
          v30 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * *(unsigned __int8 *)(*(v13 - 2) + v12));
          if ( v30 >= 0x61 )
          {
            if ( v30 > 0x7A )
              LOWORD(v30) = *(_WORD *)(v15
                                     + 2
                                     * ((v30 & 0xF)
                                      + *(unsigned __int16 *)(v15
                                                            + 2
                                                            * (((unsigned __int8)v30 >> 4)
                                                             + *(unsigned __int16 *)(v15 + 2 * (v30 >> 8))))))
                          + v30;
            else
              LOWORD(v30) = v30 - 32;
          }
          *(v14 - 2) = *(_BYTE *)((unsigned __int16)v30 + v12);
LABEL_83:
          v31 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * *(unsigned __int8 *)(*(v13 - 1) + v12));
          if ( v31 >= 0x61 )
          {
            if ( v31 > 0x7A )
              LOWORD(v31) = *(_WORD *)(v15
                                     + 2
                                     * ((v31 & 0xF)
                                      + *(unsigned __int16 *)(v15
                                                            + 2
                                                            * (((unsigned __int8)v31 >> 4)
                                                             + *(unsigned __int16 *)(v15 + 2 * (v31 >> 8))))))
                          + v31;
            else
              LOWORD(v31) = v31 - 32;
          }
          *(v14 - 1) = *(_BYTE *)((unsigned __int16)v31 + v12);
LABEL_88:
          v10 -= v11;
          v11 = 16;
          if ( !v10 )
            goto LABEL_107;
          continue;
      }
    }
  }
  v32 = *(_DWORD *)(a1 + 40);
  v33 = *(_DWORD *)(a1 + 32);
  if ( v8 )
  {
    v35 = a5;
    v36 = Nls844UnicodeUpcaseTable;
    do
    {
      if ( !a3 )
        break;
      v37 = *v35++;
      v38 = *(unsigned __int16 *)(v33 + 2 * v37);
      if ( *(_WORD *)(v32 + 2 * (v38 >> 8)) )
        v39 = *(unsigned __int16 *)(v32 + 2 * (*(unsigned __int16 *)(v32 + 2 * (v38 >> 8)) + (unsigned __int8)v38));
      else
        v39 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 28) + 2 * (unsigned __int8)v38);
      if ( v39 >= 0x61 )
      {
        if ( v39 > 0x7A )
          LOWORD(v39) = *(_WORD *)(v36
                                 + 2
                                 * ((v39 & 0xF)
                                  + *(unsigned __int16 *)(v36
                                                        + 2
                                                        * (((unsigned __int8)v39 >> 4)
                                                         + *(unsigned __int16 *)(v36 + 2 * (v39 >> 8))))))
                      + v39;
        else
          LOWORD(v39) = v39 - 32;
      }
      v40 = *(unsigned __int16 *)(v33 + 2 * (unsigned __int16)v39);
      if ( v40 >> 8 )
      {
        if ( a3-- < 2 )
          break;
        *v9++ = BYTE1(v40);
      }
      *v9++ = v40;
      --a3;
      --v43;
    }
    while ( v43 );
  }
  if ( a4 )
    *a4 = v9 - a2;
LABEL_107:
  if ( v43 > a3 )
    result = -2147483643;
  else
    result = 0;
  return result;
}

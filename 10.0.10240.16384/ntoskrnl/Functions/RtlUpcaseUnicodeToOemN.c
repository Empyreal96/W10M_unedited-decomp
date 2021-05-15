// RtlUpcaseUnicodeToOemN 
 
int __fastcall RtlUpcaseUnicodeToOemN(_BYTE *a1, unsigned int a2, unsigned int *a3, unsigned __int16 *a4, unsigned int a5)
{
  unsigned int v6; // r2
  unsigned __int16 *v7; // r6
  unsigned int v8; // r8
  unsigned int v9; // lr
  int v10; // r7
  unsigned __int16 *v11; // r4
  int v12; // r1
  int v13; // r5
  int v14; // r9
  _BYTE *v15; // r0
  unsigned int v16; // r6
  unsigned int v17; // r6
  unsigned int v18; // r6
  unsigned int v19; // r6
  unsigned int v20; // r6
  unsigned int v21; // r6
  unsigned int v22; // r6
  unsigned int v23; // r6
  unsigned int v24; // r6
  unsigned int v25; // r6
  unsigned int v26; // r6
  unsigned int v27; // r6
  unsigned int v28; // r6
  unsigned int v29; // r6
  unsigned int v30; // r6
  unsigned int v31; // r6
  int result; // r0
  _BYTE *v33; // r7
  int v34; // r8
  int v35; // r10
  int v36; // lr
  int v37; // r9
  int v38; // t1
  unsigned int v39; // r1
  unsigned int v40; // r1
  unsigned int v41; // r2
  bool v43; // zf
  unsigned int v44; // [sp+0h] [bp-28h]
  unsigned int v45; // [sp+4h] [bp-24h]

  v6 = a2;
  v44 = a2;
  v7 = a4;
  v8 = a5 >> 1;
  v45 = a5 >> 1;
  if ( NlsMbOemCodePageTag )
  {
    v33 = a1;
    if ( v8 )
    {
      v34 = NlsOemToUnicodeData;
      v35 = Nls844UnicodeUpcaseTable;
      v36 = NlsUnicodeToMbOemData;
      v37 = NlsMbOemCodePageTables;
      while ( v6 )
      {
        v38 = *v7++;
        v39 = *(unsigned __int16 *)(v36 + 2 * v38);
        if ( NlsOemLeadByteInfoTable[v39 >> 8] )
          v40 = *(unsigned __int16 *)(v37
                                    + 2 * ((unsigned __int16)NlsOemLeadByteInfoTable[v39 >> 8] + (unsigned __int8)v39));
        else
          v40 = *(unsigned __int16 *)(v34 + 2 * (unsigned __int8)v39);
        if ( v40 >= 0x61 )
        {
          if ( v40 > 0x7A )
            LOWORD(v40) = *(_WORD *)(v35
                                   + 2
                                   * ((v40 & 0xF)
                                    + *(unsigned __int16 *)(v35
                                                          + 2
                                                          * (((unsigned __int8)v40 >> 4)
                                                           + *(unsigned __int16 *)(v35 + 2 * (v40 >> 8))))))
                        + v40;
          else
            LOWORD(v40) = v40 - 32;
        }
        v41 = *(unsigned __int16 *)(v36 + 2 * (unsigned __int16)v40);
        if ( v41 >> 8 )
        {
          if ( v44-- < 2 )
          {
            v6 = v44;
            break;
          }
          *a1++ = BYTE1(v41);
        }
        *a1++ = v41;
        v6 = v44 - 1;
        v43 = v45 == 1;
        --v44;
        --v45;
        if ( v43 )
          break;
      }
      v8 = v45;
    }
    if ( a3 )
      *a3 = a1 - v33;
  }
  else
  {
    if ( v8 < a2 )
      v9 = a5 >> 1;
    else
      v9 = a2;
    if ( a3 )
      *a3 = v9;
    v10 = v9 & 0xF;
    v11 = &a4[v10];
    v12 = NlsUnicodeToOemData;
    v13 = NlsOemToUnicodeData;
    v14 = Nls844UnicodeUpcaseTable;
    v15 = &a1[v10];
    while ( 2 )
    {
      switch ( v10 )
      {
        case 0:
          goto LABEL_40;
        case 1:
          goto LABEL_38;
        case 2:
          goto LABEL_36;
        case 3:
          goto LABEL_34;
        case 4:
          goto LABEL_32;
        case 5:
          goto LABEL_30;
        case 6:
          goto LABEL_28;
        case 7:
          goto LABEL_26;
        case 8:
          goto LABEL_24;
        case 9:
          goto LABEL_22;
        case 10:
          goto LABEL_20;
        case 11:
          goto LABEL_18;
        case 12:
          goto LABEL_16;
        case 13:
          goto LABEL_14;
        case 14:
          goto LABEL_12;
        case 15:
          goto LABEL_10;
        default:
          v11 += 16;
          v15 += 16;
          v16 = *(unsigned __int16 *)(v13 + 2 * *(unsigned __int8 *)(*(v11 - 16) + v12));
          if ( v16 < 0x61 )
            goto LABEL_9;
          if ( v16 > 0x7A )
            return sub_7DD01C(v15);
          LOWORD(v16) = v16 - 32;
LABEL_9:
          *(v15 - 16) = *(_BYTE *)((unsigned __int16)v16 + v12);
LABEL_10:
          v17 = *(unsigned __int16 *)(v13 + 2 * *(unsigned __int8 *)(*(v11 - 15) + v12));
          if ( v17 >= 0x61 )
          {
            if ( v17 > 0x7A )
              LOWORD(v17) = *(_WORD *)(v14
                                     + 2
                                     * ((v17 & 0xF)
                                      + *(unsigned __int16 *)(v14
                                                            + 2
                                                            * (((unsigned __int8)v17 >> 4)
                                                             + *(unsigned __int16 *)(v14 + 2 * (v17 >> 8))))))
                          + v17;
            else
              LOWORD(v17) = v17 - 32;
          }
          *(v15 - 15) = *(_BYTE *)((unsigned __int16)v17 + v12);
LABEL_12:
          v18 = *(unsigned __int16 *)(v13 + 2 * *(unsigned __int8 *)(*(v11 - 14) + v12));
          if ( v18 >= 0x61 )
          {
            if ( v18 > 0x7A )
              LOWORD(v18) = *(_WORD *)(v14
                                     + 2
                                     * ((v18 & 0xF)
                                      + *(unsigned __int16 *)(v14
                                                            + 2
                                                            * (((unsigned __int8)v18 >> 4)
                                                             + *(unsigned __int16 *)(v14 + 2 * (v18 >> 8))))))
                          + v18;
            else
              LOWORD(v18) = v18 - 32;
          }
          *(v15 - 14) = *(_BYTE *)((unsigned __int16)v18 + v12);
LABEL_14:
          v19 = *(unsigned __int16 *)(v13 + 2 * *(unsigned __int8 *)(*(v11 - 13) + v12));
          if ( v19 >= 0x61 )
          {
            if ( v19 > 0x7A )
              LOWORD(v19) = *(_WORD *)(v14
                                     + 2
                                     * ((v19 & 0xF)
                                      + *(unsigned __int16 *)(v14
                                                            + 2
                                                            * (((unsigned __int8)v19 >> 4)
                                                             + *(unsigned __int16 *)(v14 + 2 * (v19 >> 8))))))
                          + v19;
            else
              LOWORD(v19) = v19 - 32;
          }
          *(v15 - 13) = *(_BYTE *)((unsigned __int16)v19 + v12);
LABEL_16:
          v20 = *(unsigned __int16 *)(v13 + 2 * *(unsigned __int8 *)(*(v11 - 12) + v12));
          if ( v20 >= 0x61 )
          {
            if ( v20 > 0x7A )
              LOWORD(v20) = *(_WORD *)(v14
                                     + 2
                                     * ((v20 & 0xF)
                                      + *(unsigned __int16 *)(v14
                                                            + 2
                                                            * (((unsigned __int8)v20 >> 4)
                                                             + *(unsigned __int16 *)(v14 + 2 * (v20 >> 8))))))
                          + v20;
            else
              LOWORD(v20) = v20 - 32;
          }
          *(v15 - 12) = *(_BYTE *)((unsigned __int16)v20 + v12);
LABEL_18:
          v21 = *(unsigned __int16 *)(v13 + 2 * *(unsigned __int8 *)(*(v11 - 11) + v12));
          if ( v21 >= 0x61 )
          {
            if ( v21 > 0x7A )
              LOWORD(v21) = *(_WORD *)(v14
                                     + 2
                                     * ((v21 & 0xF)
                                      + *(unsigned __int16 *)(v14
                                                            + 2
                                                            * (((unsigned __int8)v21 >> 4)
                                                             + *(unsigned __int16 *)(v14 + 2 * (v21 >> 8))))))
                          + v21;
            else
              LOWORD(v21) = v21 - 32;
          }
          *(v15 - 11) = *(_BYTE *)((unsigned __int16)v21 + v12);
LABEL_20:
          v22 = *(unsigned __int16 *)(v13 + 2 * *(unsigned __int8 *)(*(v11 - 10) + v12));
          if ( v22 >= 0x61 )
          {
            if ( v22 > 0x7A )
              LOWORD(v22) = *(_WORD *)(v14
                                     + 2
                                     * ((v22 & 0xF)
                                      + *(unsigned __int16 *)(v14
                                                            + 2
                                                            * (((unsigned __int8)v22 >> 4)
                                                             + *(unsigned __int16 *)(v14 + 2 * (v22 >> 8))))))
                          + v22;
            else
              LOWORD(v22) = v22 - 32;
          }
          *(v15 - 10) = *(_BYTE *)((unsigned __int16)v22 + v12);
LABEL_22:
          v23 = *(unsigned __int16 *)(v13 + 2 * *(unsigned __int8 *)(*(v11 - 9) + v12));
          if ( v23 >= 0x61 )
          {
            if ( v23 > 0x7A )
              LOWORD(v23) = *(_WORD *)(v14
                                     + 2
                                     * ((v23 & 0xF)
                                      + *(unsigned __int16 *)(v14
                                                            + 2
                                                            * (((unsigned __int8)v23 >> 4)
                                                             + *(unsigned __int16 *)(v14 + 2 * (v23 >> 8))))))
                          + v23;
            else
              LOWORD(v23) = v23 - 32;
          }
          *(v15 - 9) = *(_BYTE *)((unsigned __int16)v23 + v12);
LABEL_24:
          v24 = *(unsigned __int16 *)(v13 + 2 * *(unsigned __int8 *)(*(v11 - 8) + v12));
          if ( v24 >= 0x61 )
          {
            if ( v24 > 0x7A )
              LOWORD(v24) = *(_WORD *)(v14
                                     + 2
                                     * ((v24 & 0xF)
                                      + *(unsigned __int16 *)(v14
                                                            + 2
                                                            * (((unsigned __int8)v24 >> 4)
                                                             + *(unsigned __int16 *)(v14 + 2 * (v24 >> 8))))))
                          + v24;
            else
              LOWORD(v24) = v24 - 32;
          }
          *(v15 - 8) = *(_BYTE *)((unsigned __int16)v24 + v12);
LABEL_26:
          v25 = *(unsigned __int16 *)(v13 + 2 * *(unsigned __int8 *)(*(v11 - 7) + v12));
          if ( v25 >= 0x61 )
          {
            if ( v25 > 0x7A )
              LOWORD(v25) = *(_WORD *)(v14
                                     + 2
                                     * ((v25 & 0xF)
                                      + *(unsigned __int16 *)(v14
                                                            + 2
                                                            * (((unsigned __int8)v25 >> 4)
                                                             + *(unsigned __int16 *)(v14 + 2 * (v25 >> 8))))))
                          + v25;
            else
              LOWORD(v25) = v25 - 32;
          }
          *(v15 - 7) = *(_BYTE *)((unsigned __int16)v25 + v12);
LABEL_28:
          v26 = *(unsigned __int16 *)(v13 + 2 * *(unsigned __int8 *)(*(v11 - 6) + v12));
          if ( v26 >= 0x61 )
          {
            if ( v26 > 0x7A )
              LOWORD(v26) = *(_WORD *)(v14
                                     + 2
                                     * ((v26 & 0xF)
                                      + *(unsigned __int16 *)(v14
                                                            + 2
                                                            * (((unsigned __int8)v26 >> 4)
                                                             + *(unsigned __int16 *)(v14 + 2 * (v26 >> 8))))))
                          + v26;
            else
              LOWORD(v26) = v26 - 32;
          }
          *(v15 - 6) = *(_BYTE *)((unsigned __int16)v26 + v12);
LABEL_30:
          v27 = *(unsigned __int16 *)(v13 + 2 * *(unsigned __int8 *)(*(v11 - 5) + v12));
          if ( v27 >= 0x61 )
          {
            if ( v27 > 0x7A )
              LOWORD(v27) = *(_WORD *)(v14
                                     + 2
                                     * ((v27 & 0xF)
                                      + *(unsigned __int16 *)(v14
                                                            + 2
                                                            * (((unsigned __int8)v27 >> 4)
                                                             + *(unsigned __int16 *)(v14 + 2 * (v27 >> 8))))))
                          + v27;
            else
              LOWORD(v27) = v27 - 32;
          }
          *(v15 - 5) = *(_BYTE *)((unsigned __int16)v27 + v12);
LABEL_32:
          v28 = *(unsigned __int16 *)(v13 + 2 * *(unsigned __int8 *)(*(v11 - 4) + v12));
          if ( v28 >= 0x61 )
          {
            if ( v28 > 0x7A )
              LOWORD(v28) = *(_WORD *)(v14
                                     + 2
                                     * ((v28 & 0xF)
                                      + *(unsigned __int16 *)(v14
                                                            + 2
                                                            * (((unsigned __int8)v28 >> 4)
                                                             + *(unsigned __int16 *)(v14 + 2 * (v28 >> 8))))))
                          + v28;
            else
              LOWORD(v28) = v28 - 32;
          }
          *(v15 - 4) = *(_BYTE *)((unsigned __int16)v28 + v12);
LABEL_34:
          v29 = *(unsigned __int16 *)(v13 + 2 * *(unsigned __int8 *)(*(v11 - 3) + v12));
          if ( v29 >= 0x61 )
          {
            if ( v29 > 0x7A )
              LOWORD(v29) = *(_WORD *)(v14
                                     + 2
                                     * ((v29 & 0xF)
                                      + *(unsigned __int16 *)(v14
                                                            + 2
                                                            * (((unsigned __int8)v29 >> 4)
                                                             + *(unsigned __int16 *)(v14 + 2 * (v29 >> 8))))))
                          + v29;
            else
              LOWORD(v29) = v29 - 32;
          }
          *(v15 - 3) = *(_BYTE *)((unsigned __int16)v29 + v12);
LABEL_36:
          v30 = *(unsigned __int16 *)(v13 + 2 * *(unsigned __int8 *)(*(v11 - 2) + v12));
          if ( v30 >= 0x61 )
          {
            if ( v30 > 0x7A )
              LOWORD(v30) = *(_WORD *)(v14
                                     + 2
                                     * ((v30 & 0xF)
                                      + *(unsigned __int16 *)(v14
                                                            + 2
                                                            * (((unsigned __int8)v30 >> 4)
                                                             + *(unsigned __int16 *)(v14 + 2 * (v30 >> 8))))))
                          + v30;
            else
              LOWORD(v30) = v30 - 32;
          }
          *(v15 - 2) = *(_BYTE *)((unsigned __int16)v30 + v12);
LABEL_38:
          v31 = *(unsigned __int16 *)(v13 + 2 * *(unsigned __int8 *)(*(v11 - 1) + v12));
          if ( v31 >= 0x61 )
          {
            if ( v31 > 0x7A )
              LOWORD(v31) = *(_WORD *)(v14
                                     + 2
                                     * ((v31 & 0xF)
                                      + *(unsigned __int16 *)(v14
                                                            + 2
                                                            * (((unsigned __int8)v31 >> 4)
                                                             + *(unsigned __int16 *)(v14 + 2 * (v31 >> 8))))))
                          + v31;
            else
              LOWORD(v31) = v31 - 32;
          }
          *(v15 - 1) = *(_BYTE *)((unsigned __int16)v31 + v12);
LABEL_40:
          v9 -= v10;
          v10 = 16;
          if ( v9 )
            continue;
          v6 = v44;
          break;
      }
      break;
    }
  }
  if ( v8 > v6 )
    result = -2147483643;
  else
    result = 0;
  return result;
}

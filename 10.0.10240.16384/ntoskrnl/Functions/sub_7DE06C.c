// sub_7DE06C 
 
void sub_7DE06C()
{
  int v0; // r4
  int v1; // r7
  int v2; // r8
  int v3; // r9
  int v4; // r10
  int v5; // lr
  unsigned int v6; // r1
  unsigned int v7; // r1
  unsigned int v8; // r1
  unsigned int v9; // r1
  unsigned int v10; // r1
  unsigned int v11; // r1
  unsigned int v12; // r1
  unsigned int v13; // r1
  unsigned int v14; // r1
  unsigned int v15; // r1
  unsigned int v16; // r1
  unsigned int v17; // r1
  unsigned int v18; // r1
  unsigned int v19; // r1
  unsigned int v20; // r1

  switch ( v0 )
  {
    case 0:
      JUMPOUT(0x6EDBEA);
    case 2:
      goto LABEL_72;
    case 3:
      goto LABEL_67;
    case 4:
      goto LABEL_62;
    case 5:
      goto LABEL_57;
    case 6:
      goto LABEL_52;
    case 7:
      goto LABEL_47;
    case 8:
      goto LABEL_42;
    case 9:
      goto LABEL_37;
    case 10:
      goto LABEL_32;
    case 11:
      goto LABEL_27;
    case 12:
      goto LABEL_22;
    case 13:
      goto LABEL_17;
    case 14:
      goto LABEL_12;
    case 15:
      goto LABEL_7;
    default:
      v2 += 32;
      v5 += 16;
      v6 = *(unsigned __int16 *)(v3 + 2 * *(unsigned __int8 *)(*(unsigned __int16 *)(v2 - 32) + v1));
      if ( v6 >= 0x61 )
      {
        if ( v6 > 0x7A )
          LOWORD(v6) = *(_WORD *)(v4
                                + 2
                                * ((v6 & 0xF)
                                 + *(unsigned __int16 *)(v4
                                                       + 2
                                                       * (((unsigned __int8)v6 >> 4)
                                                        + *(unsigned __int16 *)(v4 + 2 * (v6 >> 8))))))
                     + v6;
        else
          LOWORD(v6) = v6 - 32;
      }
      *(_BYTE *)(v5 - 16) = *(_BYTE *)((unsigned __int16)v6 + v1);
LABEL_7:
      v7 = *(unsigned __int16 *)(v3 + 2 * *(unsigned __int8 *)(*(unsigned __int16 *)(v2 - 30) + v1));
      if ( v7 >= 0x61 )
      {
        if ( v7 > 0x7A )
          LOWORD(v7) = *(_WORD *)(v4
                                + 2
                                * ((v7 & 0xF)
                                 + *(unsigned __int16 *)(v4
                                                       + 2
                                                       * (((unsigned __int8)v7 >> 4)
                                                        + *(unsigned __int16 *)(v4 + 2 * (v7 >> 8))))))
                     + v7;
        else
          LOWORD(v7) = v7 - 32;
      }
      *(_BYTE *)(v5 - 15) = *(_BYTE *)((unsigned __int16)v7 + v1);
LABEL_12:
      v8 = *(unsigned __int16 *)(v3 + 2 * *(unsigned __int8 *)(*(unsigned __int16 *)(v2 - 28) + v1));
      if ( v8 >= 0x61 )
      {
        if ( v8 > 0x7A )
          LOWORD(v8) = *(_WORD *)(v4
                                + 2
                                * ((v8 & 0xF)
                                 + *(unsigned __int16 *)(v4
                                                       + 2
                                                       * (((unsigned __int8)v8 >> 4)
                                                        + *(unsigned __int16 *)(v4 + 2 * (v8 >> 8))))))
                     + v8;
        else
          LOWORD(v8) = v8 - 32;
      }
      *(_BYTE *)(v5 - 14) = *(_BYTE *)((unsigned __int16)v8 + v1);
LABEL_17:
      v9 = *(unsigned __int16 *)(v3 + 2 * *(unsigned __int8 *)(*(unsigned __int16 *)(v2 - 26) + v1));
      if ( v9 >= 0x61 )
      {
        if ( v9 > 0x7A )
          LOWORD(v9) = *(_WORD *)(v4
                                + 2
                                * ((v9 & 0xF)
                                 + *(unsigned __int16 *)(v4
                                                       + 2
                                                       * (((unsigned __int8)v9 >> 4)
                                                        + *(unsigned __int16 *)(v4 + 2 * (v9 >> 8))))))
                     + v9;
        else
          LOWORD(v9) = v9 - 32;
      }
      *(_BYTE *)(v5 - 13) = *(_BYTE *)((unsigned __int16)v9 + v1);
LABEL_22:
      v10 = *(unsigned __int16 *)(v3 + 2 * *(unsigned __int8 *)(*(unsigned __int16 *)(v2 - 24) + v1));
      if ( v10 >= 0x61 )
      {
        if ( v10 > 0x7A )
          LOWORD(v10) = *(_WORD *)(v4
                                 + 2
                                 * ((v10 & 0xF)
                                  + *(unsigned __int16 *)(v4
                                                        + 2
                                                        * (((unsigned __int8)v10 >> 4)
                                                         + *(unsigned __int16 *)(v4 + 2 * (v10 >> 8))))))
                      + v10;
        else
          LOWORD(v10) = v10 - 32;
      }
      *(_BYTE *)(v5 - 12) = *(_BYTE *)((unsigned __int16)v10 + v1);
LABEL_27:
      v11 = *(unsigned __int16 *)(v3 + 2 * *(unsigned __int8 *)(*(unsigned __int16 *)(v2 - 22) + v1));
      if ( v11 >= 0x61 )
      {
        if ( v11 > 0x7A )
          LOWORD(v11) = *(_WORD *)(v4
                                 + 2
                                 * ((v11 & 0xF)
                                  + *(unsigned __int16 *)(v4
                                                        + 2
                                                        * (((unsigned __int8)v11 >> 4)
                                                         + *(unsigned __int16 *)(v4 + 2 * (v11 >> 8))))))
                      + v11;
        else
          LOWORD(v11) = v11 - 32;
      }
      *(_BYTE *)(v5 - 11) = *(_BYTE *)((unsigned __int16)v11 + v1);
LABEL_32:
      v12 = *(unsigned __int16 *)(v3 + 2 * *(unsigned __int8 *)(*(unsigned __int16 *)(v2 - 20) + v1));
      if ( v12 >= 0x61 )
      {
        if ( v12 > 0x7A )
          LOWORD(v12) = *(_WORD *)(v4
                                 + 2
                                 * ((v12 & 0xF)
                                  + *(unsigned __int16 *)(v4
                                                        + 2
                                                        * (((unsigned __int8)v12 >> 4)
                                                         + *(unsigned __int16 *)(v4 + 2 * (v12 >> 8))))))
                      + v12;
        else
          LOWORD(v12) = v12 - 32;
      }
      *(_BYTE *)(v5 - 10) = *(_BYTE *)((unsigned __int16)v12 + v1);
LABEL_37:
      v13 = *(unsigned __int16 *)(v3 + 2 * *(unsigned __int8 *)(*(unsigned __int16 *)(v2 - 18) + v1));
      if ( v13 >= 0x61 )
      {
        if ( v13 > 0x7A )
          LOWORD(v13) = *(_WORD *)(v4
                                 + 2
                                 * ((v13 & 0xF)
                                  + *(unsigned __int16 *)(v4
                                                        + 2
                                                        * (((unsigned __int8)v13 >> 4)
                                                         + *(unsigned __int16 *)(v4 + 2 * (v13 >> 8))))))
                      + v13;
        else
          LOWORD(v13) = v13 - 32;
      }
      *(_BYTE *)(v5 - 9) = *(_BYTE *)((unsigned __int16)v13 + v1);
LABEL_42:
      v14 = *(unsigned __int16 *)(v3 + 2 * *(unsigned __int8 *)(*(unsigned __int16 *)(v2 - 16) + v1));
      if ( v14 >= 0x61 )
      {
        if ( v14 > 0x7A )
          LOWORD(v14) = *(_WORD *)(v4
                                 + 2
                                 * ((v14 & 0xF)
                                  + *(unsigned __int16 *)(v4
                                                        + 2
                                                        * (((unsigned __int8)v14 >> 4)
                                                         + *(unsigned __int16 *)(v4 + 2 * (v14 >> 8))))))
                      + v14;
        else
          LOWORD(v14) = v14 - 32;
      }
      *(_BYTE *)(v5 - 8) = *(_BYTE *)((unsigned __int16)v14 + v1);
LABEL_47:
      v15 = *(unsigned __int16 *)(v3 + 2 * *(unsigned __int8 *)(*(unsigned __int16 *)(v2 - 14) + v1));
      if ( v15 >= 0x61 )
      {
        if ( v15 > 0x7A )
          LOWORD(v15) = *(_WORD *)(v4
                                 + 2
                                 * ((v15 & 0xF)
                                  + *(unsigned __int16 *)(v4
                                                        + 2
                                                        * (((unsigned __int8)v15 >> 4)
                                                         + *(unsigned __int16 *)(v4 + 2 * (v15 >> 8))))))
                      + v15;
        else
          LOWORD(v15) = v15 - 32;
      }
      *(_BYTE *)(v5 - 7) = *(_BYTE *)((unsigned __int16)v15 + v1);
LABEL_52:
      v16 = *(unsigned __int16 *)(v3 + 2 * *(unsigned __int8 *)(*(unsigned __int16 *)(v2 - 12) + v1));
      if ( v16 >= 0x61 )
      {
        if ( v16 > 0x7A )
          LOWORD(v16) = *(_WORD *)(v4
                                 + 2
                                 * ((v16 & 0xF)
                                  + *(unsigned __int16 *)(v4
                                                        + 2
                                                        * (((unsigned __int8)v16 >> 4)
                                                         + *(unsigned __int16 *)(v4 + 2 * (v16 >> 8))))))
                      + v16;
        else
          LOWORD(v16) = v16 - 32;
      }
      *(_BYTE *)(v5 - 6) = *(_BYTE *)((unsigned __int16)v16 + v1);
LABEL_57:
      v17 = *(unsigned __int16 *)(v3 + 2 * *(unsigned __int8 *)(*(unsigned __int16 *)(v2 - 10) + v1));
      if ( v17 >= 0x61 )
      {
        if ( v17 > 0x7A )
          LOWORD(v17) = *(_WORD *)(v4
                                 + 2
                                 * ((v17 & 0xF)
                                  + *(unsigned __int16 *)(v4
                                                        + 2
                                                        * (((unsigned __int8)v17 >> 4)
                                                         + *(unsigned __int16 *)(v4 + 2 * (v17 >> 8))))))
                      + v17;
        else
          LOWORD(v17) = v17 - 32;
      }
      *(_BYTE *)(v5 - 5) = *(_BYTE *)((unsigned __int16)v17 + v1);
LABEL_62:
      v18 = *(unsigned __int16 *)(v3 + 2 * *(unsigned __int8 *)(*(unsigned __int16 *)(v2 - 8) + v1));
      if ( v18 >= 0x61 )
      {
        if ( v18 > 0x7A )
          LOWORD(v18) = *(_WORD *)(v4
                                 + 2
                                 * ((v18 & 0xF)
                                  + *(unsigned __int16 *)(v4
                                                        + 2
                                                        * (((unsigned __int8)v18 >> 4)
                                                         + *(unsigned __int16 *)(v4 + 2 * (v18 >> 8))))))
                      + v18;
        else
          LOWORD(v18) = v18 - 32;
      }
      *(_BYTE *)(v5 - 4) = *(_BYTE *)((unsigned __int16)v18 + v1);
LABEL_67:
      v19 = *(unsigned __int16 *)(v3 + 2 * *(unsigned __int8 *)(*(unsigned __int16 *)(v2 - 6) + v1));
      if ( v19 >= 0x61 )
      {
        if ( v19 > 0x7A )
          LOWORD(v19) = *(_WORD *)(v4
                                 + 2
                                 * ((v19 & 0xF)
                                  + *(unsigned __int16 *)(v4
                                                        + 2
                                                        * (((unsigned __int8)v19 >> 4)
                                                         + *(unsigned __int16 *)(v4 + 2 * (v19 >> 8))))))
                      + v19;
        else
          LOWORD(v19) = v19 - 32;
      }
      *(_BYTE *)(v5 - 3) = *(_BYTE *)((unsigned __int16)v19 + v1);
LABEL_72:
      v20 = *(unsigned __int16 *)(v3 + 2 * *(unsigned __int8 *)(*(unsigned __int16 *)(v2 - 4) + v1));
      if ( v20 >= 0x61 )
      {
        if ( v20 > 0x7A )
          LOWORD(v20) = *(_WORD *)(v4
                                 + 2
                                 * ((v20 & 0xF)
                                  + *(unsigned __int16 *)(v4
                                                        + 2
                                                        * (((unsigned __int8)v20 >> 4)
                                                         + *(unsigned __int16 *)(v4 + 2 * (v20 >> 8))))))
                      + v20;
        else
          LOWORD(v20) = v20 - 32;
      }
      *(_BYTE *)(v5 - 2) = *(_BYTE *)((unsigned __int16)v20 + v1);
      JUMPOUT(0x6EDBD4);
  }
}

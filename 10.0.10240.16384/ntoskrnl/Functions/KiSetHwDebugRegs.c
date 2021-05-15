// KiSetHwDebugRegs 
 
int __fastcall KiSetHwDebugRegs(int a1, unsigned int *a2, unsigned int *a3, int a4, unsigned int *a5, unsigned int *a6)
{
  int result; // r0

  if ( a1 != 6 )
    return sub_51B4B8();
  __mcr(14, 0, a2[5], 0, 5, 4);
  __mcr(14, 0, a3[5], 0, 5, 5);
  __mcr(14, 0, a2[4], 0, 4, 4);
  __mcr(14, 0, a3[4], 0, 4, 5);
  __mcr(14, 0, a2[3], 0, 3, 4);
  __mcr(14, 0, a3[3], 0, 3, 5);
  __mcr(14, 0, a2[2], 0, 2, 4);
  __mcr(14, 0, a3[2], 0, 2, 5);
  __mcr(14, 0, a2[1], 0, 1, 4);
  __mcr(14, 0, a3[1], 0, 1, 5);
  __mcr(14, 0, *a2, 0, 0, 4);
  __mcr(14, 0, *a3, 0, 0, 5);
  result = (int)a5;
  switch ( a4 )
  {
    case 1:
      goto LABEL_7;
    case 2:
      goto LABEL_6;
    case 3:
      goto LABEL_5;
    case 4:
      goto LABEL_4;
    case 5:
      goto LABEL_20;
    case 6:
      goto LABEL_19;
    case 7:
      goto LABEL_18;
    case 8:
      goto LABEL_17;
    case 9:
      goto LABEL_16;
    case 10:
      goto LABEL_15;
    case 11:
      goto LABEL_14;
    case 12:
      goto LABEL_13;
    case 13:
      goto LABEL_12;
    case 14:
      goto LABEL_11;
    case 15:
      goto LABEL_10;
    case 16:
      __mcr(14, 0, a5[15], 0, 15, 6);
      __mcr(14, 0, a6[15], 0, 15, 7);
LABEL_10:
      __mcr(14, 0, a5[14], 0, 14, 6);
      __mcr(14, 0, a6[14], 0, 14, 7);
LABEL_11:
      __mcr(14, 0, a5[13], 0, 13, 6);
      __mcr(14, 0, a6[13], 0, 13, 7);
LABEL_12:
      __mcr(14, 0, a5[12], 0, 12, 6);
      __mcr(14, 0, a6[12], 0, 12, 7);
LABEL_13:
      __mcr(14, 0, a5[11], 0, 11, 6);
      __mcr(14, 0, a6[11], 0, 11, 7);
LABEL_14:
      __mcr(14, 0, a5[10], 0, 10, 6);
      __mcr(14, 0, a6[10], 0, 10, 7);
LABEL_15:
      __mcr(14, 0, a5[9], 0, 9, 6);
      __mcr(14, 0, a6[9], 0, 9, 7);
LABEL_16:
      __mcr(14, 0, a5[8], 0, 8, 6);
      __mcr(14, 0, a6[8], 0, 8, 7);
LABEL_17:
      __mcr(14, 0, a5[7], 0, 7, 6);
      __mcr(14, 0, a6[7], 0, 7, 7);
LABEL_18:
      __mcr(14, 0, a5[6], 0, 6, 6);
      __mcr(14, 0, a6[6], 0, 6, 7);
LABEL_19:
      __mcr(14, 0, a5[5], 0, 5, 6);
      __mcr(14, 0, a6[5], 0, 5, 7);
LABEL_20:
      __mcr(14, 0, a5[4], 0, 4, 6);
      __mcr(14, 0, a6[4], 0, 4, 7);
LABEL_4:
      __mcr(14, 0, a5[3], 0, 3, 6);
      __mcr(14, 0, a6[3], 0, 3, 7);
LABEL_5:
      __mcr(14, 0, a5[2], 0, 2, 6);
      __mcr(14, 0, a6[2], 0, 2, 7);
LABEL_6:
      __mcr(14, 0, a5[1], 0, 1, 6);
      __mcr(14, 0, a6[1], 0, 1, 7);
LABEL_7:
      __mcr(14, 0, *a5, 0, 0, 6);
      __mcr(14, 0, *a6, 0, 0, 7);
      break;
    default:
      break;
  }
  __dsb(0xFu);
  return result;
}

// sub_51B4B8 
 
void __fastcall sub_51B4B8(int a1, unsigned int *a2, unsigned int *a3)
{
  switch ( a1 )
  {
    case 1:
      JUMPOUT(0x442F4C);
    case 2:
      JUMPOUT(0x442F40);
    case 3:
      JUMPOUT(0x442F34);
    case 4:
      JUMPOUT(0x442F28);
    case 5:
      JUMPOUT(0x442F1C);
    case 7:
      goto LABEL_11;
    case 8:
      goto LABEL_10;
    case 9:
      goto LABEL_9;
    case 10:
      goto LABEL_8;
    case 11:
      goto LABEL_7;
    case 12:
      goto LABEL_6;
    case 13:
      goto LABEL_5;
    case 14:
      goto LABEL_4;
    case 15:
      goto LABEL_3;
    case 16:
      __mcr(14, 0, a2[15], 0, 15, 4);
      __mcr(14, 0, a3[15], 0, 15, 5);
LABEL_3:
      __mcr(14, 0, a2[14], 0, 14, 4);
      __mcr(14, 0, a3[14], 0, 14, 5);
LABEL_4:
      __mcr(14, 0, a2[13], 0, 13, 4);
      __mcr(14, 0, a3[13], 0, 13, 5);
LABEL_5:
      __mcr(14, 0, a2[12], 0, 12, 4);
      __mcr(14, 0, a3[12], 0, 12, 5);
LABEL_6:
      __mcr(14, 0, a2[11], 0, 11, 4);
      __mcr(14, 0, a3[11], 0, 11, 5);
LABEL_7:
      __mcr(14, 0, a2[10], 0, 10, 4);
      __mcr(14, 0, a3[10], 0, 10, 5);
LABEL_8:
      __mcr(14, 0, a2[9], 0, 9, 4);
      __mcr(14, 0, a3[9], 0, 9, 5);
LABEL_9:
      __mcr(14, 0, a2[8], 0, 8, 4);
      __mcr(14, 0, a3[8], 0, 8, 5);
LABEL_10:
      __mcr(14, 0, a2[7], 0, 7, 4);
      __mcr(14, 0, a3[7], 0, 7, 5);
LABEL_11:
      __mcr(14, 0, a2[6], 0, 6, 4);
      __mcr(14, 0, a3[6], 0, 6, 5);
      JUMPOUT(0x442F10);
    default:
      JUMPOUT(0x442F58);
  }
}

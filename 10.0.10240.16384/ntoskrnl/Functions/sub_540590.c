// sub_540590 
 
void __fastcall sub_540590(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, char *a9, int a10, int a11, int a12, char *a13, int a14, int a15, int a16, int *a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, char *a25, int a26, int a27, int a28, char *a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40, int a41, int a42, char a43, char a44, char a45, char a46)
{
  unsigned int v46; // r4
  int v47; // r5
  int v48; // r6
  int v49; // r7
  char v50; // r3
  unsigned int v51; // r2

  if ( v46 )
  {
    if ( v46 >= 0x20 || (v51 = KiProcessorIndexToNumberMappingTable[v46]) == 0 )
    {
LABEL_7:
      a9 = &a43;
      a10 = 0;
      a11 = 4;
      a12 = 0;
      a13 = &a44;
      a14 = 0;
      a15 = 4;
      a16 = 0;
      a17 = &a7;
      a18 = 0;
      a19 = 2;
      a20 = 0;
      a21 = (int)&a7 + 2;
      a22 = 0;
      a23 = 1;
      a24 = 0;
      a25 = &a45;
      a26 = 0;
      a27 = 4;
      a28 = 0;
      a29 = &a46;
      a30 = 0;
      a31 = 4;
      a32 = 0;
      EtwWrite(v49, v48, v47, 0);
      JUMPOUT(0x4ACA64);
    }
    HIBYTE(a7) = 0;
    LOWORD(a7) = v51 >> 6;
    v50 = v51 & 0x3F;
  }
  else
  {
    v50 = 0;
    HIBYTE(a7) = 0;
    LOWORD(a7) = 0;
  }
  BYTE2(a7) = v50;
  goto LABEL_7;
}

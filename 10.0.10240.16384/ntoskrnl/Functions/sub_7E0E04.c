// sub_7E0E04 
 
void __fastcall sub_7E0E04(int a1, int a2, int a3, int a4, int a5, int a6, __int16 a7, int a8, char *a9, int a10, int a11, int a12, char *a13, int a14, int a15, int a16, __int16 *a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int *a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, char a37, char a38)
{
  int v38; // r5
  int v39; // r6
  unsigned __int16 *v40; // r7
  int v41; // r4
  int v42; // r3

  v41 = *v40;
  a7 = *v40 >> 1;
  a9 = &a37;
  a10 = 0;
  a11 = 4;
  a12 = 0;
  a13 = &a38;
  a14 = 0;
  a15 = 4;
  a16 = 0;
  a17 = &a7;
  a18 = 0;
  a19 = 2;
  a20 = 0;
  v42 = *((_DWORD *)v40 + 1);
  a23 = v41;
  a21 = v42;
  a22 = 0;
  a24 = 0;
  a25 = &a8;
  a26 = 0;
  a27 = 4;
  a28 = 0;
  EtwWrite(v39, v38, (int)POP_ETW_EVENT_DEVICE_PREPARATION, 0);
  JUMPOUT(0x7781E0);
}

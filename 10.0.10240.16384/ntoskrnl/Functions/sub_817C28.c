// sub_817C28 
 
void __fastcall sub_817C28(int a1, int a2, int a3, int a4, int a5, int a6, BOOL a7, int a8, char *a9, int a10, int a11, int a12, unsigned int a13, int a14, char *a15, int a16, BOOL *a17, int a18, int a19, int a20, char *a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int *a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40, int a41, int a42, int a43, int a44, char a45, int a46, int a47, char a48, int a49, int a50, int a51)
{
  int v51; // r4
  int v52; // r5
  int v53; // r6
  unsigned int v54; // r7
  char *v55; // r0
  const __int16 *v56; // r2

  a7 = a51 != 0;
  v55 = strlen(v54);
  a9 = &a45;
  a10 = 0;
  a11 = 1;
  a12 = 0;
  a13 = v54;
  a14 = 0;
  a15 = v55 + 1;
  a16 = 0;
  a17 = &a7;
  a18 = 0;
  a19 = 4;
  a20 = 0;
  a21 = &a48;
  a22 = 0;
  a23 = 1;
  a24 = 0;
  a26 = 0;
  a27 = 16;
  a28 = 0;
  a29 = &a50;
  a30 = 0;
  a31 = 4;
  a32 = 0;
  a33 = a49;
  a34 = 0;
  a35 = a50;
  a36 = 0;
  if ( v53 )
    v56 = (const __int16 *)PPM_ETW_PROCESSOR_PROFILE_SETTING_RUNDOWN;
  else
    v56 = L"i";
  EtwWrite(v52, v51, (int)v56, 0);
  JUMPOUT(0x7B0D7A);
}

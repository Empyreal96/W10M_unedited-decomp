// sub_818330 
 
void __fastcall sub_818330(int a1, int a2, unsigned int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26, int a27, int a28, int a29, int a30, int a31, int a32, int a33, int a34, int a35, int a36, int a37, int a38, int a39, int a40, int a41, int a42, int a43, int a44, int a45, int a46, int a47, int a48, int a49, int a50, int a51, int a52, int a53)
{
  char v53; // cf
  char v54; // zf
  int v55; // r4
  int v56; // r3

  if ( !v54 & v53 && a3 > 5 && a3 == 6 )
  {
    v56 = a53;
    if ( !a53 )
    {
      v56 = 0;
      v55 = 0;
    }
    a7 = v56;
    if ( WmipGetSMBiosEventlog(v55, &a7) >= 0 )
      JUMPOUT(0x7B2458);
  }
  JUMPOUT(0x7B245A);
}

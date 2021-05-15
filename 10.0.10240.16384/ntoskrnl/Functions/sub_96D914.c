// sub_96D914 
 
void __fastcall sub_96D914(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20)
{
  _DWORD *v20; // r4
  int v21; // r7
  int v22; // r3
  int v23; // r10

  if ( v21 )
  {
    v23 = v20[7];
    a14 = v20[8];
    a17 = v23;
    a18 = a14;
    a15 = v20[9];
    a19 = a15;
    a13 = v20[10];
    a20 = a13;
    if ( !BapdpIsTime1MoreRecentThanTime2(&a17, &a9) )
      goto LABEL_6;
    a9 = v23;
    a10 = a14;
    a11 = a15;
    v22 = a13;
  }
  else
  {
    a9 = v20[7];
    a10 = v20[8];
    a11 = v20[9];
    v22 = v20[10];
  }
  a12 = v22;
LABEL_6:
  JUMPOUT(0x95EAB6);
}

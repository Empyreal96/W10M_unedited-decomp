// sub_80E5A4 
 
void __fastcall sub_80E5A4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, unsigned __int64 *a23, __int64 a24, __int64 a25, __int64 a26, __int64 a27, __int64 a28, __int64 a29, __int64 a30, __int64 a31)
{
  unsigned __int64 v31; // r6
  unsigned int v32; // r9
  unsigned int v33; // r10
  unsigned __int64 v34; // r4
  __int64 v35; // r2

  v34 = *a23 - __PAIR64__(v33, v32);
  if ( v34 <= *a23 )
  {
    if ( !a31 )
      __brkdiv0();
    _rt_udiv64(a31, v34);
    if ( v34 - v35 >= v31 )
      JUMPOUT(0x7971A8);
  }
  JUMPOUT(0x7971D8);
}

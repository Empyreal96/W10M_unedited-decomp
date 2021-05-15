// sub_50BB84 
 
void __fastcall sub_50BB84(__int64 a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, unsigned int a18, int a19)
{
  unsigned int v19; // r7
  unsigned int v20; // r8
  unsigned int v21; // r9
  unsigned int v22; // r10
  __int64 v23; // r0
  unsigned __int64 v24; // r2
  int v25; // r4
  unsigned __int64 v26; // r2

  if ( !a1 )
    __brkdiv0();
  LODWORD(v23) = _rt_udiv64(a1, __PAIR64__(v19, v20));
  v24 = __PAIR64__(v19, v20) - v23 * __PAIR64__(v21, v22);
  v25 = HIDWORD(v24) * a18 + v24 * a19;
  v26 = (unsigned int)v24 * (unsigned __int64)a18;
  HIDWORD(v26) += v25;
  if ( !v22 && !v21 )
    __brkdiv0();
  _rt_udiv64(__SPAIR64__(v21, v22), v26);
  JUMPOUT(0x4666F6);
}

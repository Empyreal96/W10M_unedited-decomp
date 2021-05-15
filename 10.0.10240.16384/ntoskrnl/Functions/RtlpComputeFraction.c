// RtlpComputeFraction 
 
int __fastcall RtlpComputeFraction(unsigned int a1, unsigned int a2, _BYTE *a3)
{
  char v5; // r0
  char v6; // r8
  unsigned __int64 v7; // r2
  int v8; // r10
  unsigned int v9; // r3
  unsigned int v10; // r6
  unsigned int v11; // r2
  unsigned int v12; // r5
  unsigned int v13; // r1
  unsigned int v14; // r4
  unsigned int v15; // r0
  int result; // r0
  char v17; // r7
  unsigned __int64 v18; // kr08_8
  unsigned int v19; // r2
  unsigned int v20; // r2
  unsigned int v21; // kr00_4

  *a3 = 0;
  v5 = ((int (*)(void))RtlpCountLeadingZeroes32)();
  v6 = v5 + 32;
  if ( !a2 )
    __brkdiv0();
  LODWORD(v7) = a1 << (v5 + 32);
  HIDWORD(v7) = (a1 << v5) | (a1 >> -v5);
  v8 = _rt_udiv64(a2, v7);
  v10 = v9;
  v12 = v11;
  v14 = v13;
  v15 = RtlpCountLeadingZeroes32(v13);
  if ( v15 >= 0x20 )
    return sub_554ED4();
  v17 = v15;
  v18 = (unsigned int)_rt_udiv64(a2, __PAIR64__(v10, v12) << a2) + (__PAIR64__(v14, v8) << v15);
  result = v18;
  v21 = v19;
  v20 = 2 * v19;
  if ( (!is_mul_ok(2u, v21) || v20 > a2) && v18 + 1 > v18 )
    result = v18 + 1;
  *a3 = 64 - v17 - v6;
  return result;
}

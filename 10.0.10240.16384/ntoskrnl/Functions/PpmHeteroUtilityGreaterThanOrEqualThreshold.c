// PpmHeteroUtilityGreaterThanOrEqualThreshold 
 
BOOL __fastcall PpmHeteroUtilityGreaterThanOrEqualThreshold(__int64 a1, unsigned int a2, int a3, unsigned __int64 a4, unsigned int a5)
{
  int v5; // r4
  int v6; // r3
  unsigned int v7; // r5
  unsigned int v8; // r6

  v5 = HIDWORD(a1) * a2 + a1 * a3;
  v6 = ((unsigned int)a1 * (unsigned __int64)a2) >> 32;
  v7 = a1 * a2;
  v8 = v5 + v6;
  if ( __PAIR64__(v5 + v6, (unsigned int)a1 * a2) <= a4 )
  {
    v8 = HIDWORD(a4);
    v7 = a4;
  }
  return 100 * __PAIR64__(v8, v7) >= __PAIR64__(
                                       PpmHeteroMinRelativePerformance * a5 / 0x8DB8BAC8,
                                       (__int64)(10000
                                               * (unsigned int)PpmHeteroMinRelativePerformance
                                               * (unsigned __int64)a5) >> 16)
                                   * a1
      && a1;
}

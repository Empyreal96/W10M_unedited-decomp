// KiEndCounterAccumulation 
 
int __fastcall KiEndCounterAccumulation(int result)
{
  int v1; // r4
  __int64 v2; // kr00_8
  int v3; // r5
  int v4; // r6
  unsigned int v5; // r1
  unsigned int v6; // r7
  unsigned int *v7; // r9
  int v8; // r3
  unsigned int v9; // r2
  int v10; // r3

  v1 = *(_DWORD *)(result + 236);
  v2 = *(_QWORD *)(v1 + 32);
  if ( v2 )
  {
    v3 = 1;
    v4 = 0;
    v5 = KiHwCountersCount;
    v6 = 0;
    if ( KiHwCountersCount )
    {
      v7 = (unsigned int *)&KiHwCounters;
      do
      {
        if ( v4 & HIDWORD(v2) | v3 & (unsigned int)v2 )
        {
          __mcr(15, 0, *v7, 9, 12, 5);
          result = __mrc(15, 0, 9, 13, 2);
          v8 = *(_DWORD *)(v1 + 48);
          v9 = *(_DWORD *)(v1 + 60);
          *(_DWORD *)(v1 + 48) = result;
          *(_QWORD *)(v1 + 56) = __PAIR64__(v9, *(_DWORD *)(v1 + 56)) + (unsigned int)(result - v8);
          v5 = KiHwCountersCount;
          *(_DWORD *)(v1 + 52) = 0;
        }
        ++v6;
        v10 = (unsigned __int64)(unsigned int)v3 >> 31;
        v3 *= 2;
        v1 += 24;
        v4 = v10 | (2 * v4);
        ++v7;
      }
      while ( v6 < v5 );
    }
  }
  return result;
}

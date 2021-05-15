// KiBeginCounterAccumulation 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiBeginCounterAccumulation(int result, int a2)
{
  int v2; // r4
  int v3; // r5 OVERLAPPED
  int v4; // r6 OVERLAPPED
  int v5; // r7
  int v6; // r10
  unsigned int v7; // r8
  unsigned int *v8; // r9
  int v9; // lr
  unsigned int v10; // r0
  int v11; // r3
  char v12; // r2
  int v13; // r3
  int v14; // [sp+4h] [bp-24h]

  v2 = *(_DWORD *)(result + 236);
  v14 = result;
  *(_QWORD *)&v3 = *(_QWORD *)(v2 + 32);
  if ( *(_QWORD *)&v3 )
  {
    v5 = 1;
    v6 = 0;
    v7 = KiHwCountersCount;
    if ( KiHwCountersCount )
    {
      v8 = (unsigned int *)&KiHwCounters;
      v9 = *(_DWORD *)(result + 236);
      v10 = 0;
      do
      {
        if ( v6 & v4 | v5 & v3 )
        {
          __mcr(15, 0, *v8, 9, 12, 5);
          *(_DWORD *)(v9 + 48) = __mrc(15, 0, 9, 13, 2);
          v7 = KiHwCountersCount;
          *(_DWORD *)(v9 + 52) = 0;
        }
        ++v10;
        v11 = (unsigned __int64)(unsigned int)v5 >> 31;
        v5 *= 2;
        v6 = v11 | (2 * v6);
        ++v8;
        v9 += 24;
      }
      while ( v10 < v7 );
      result = v14;
    }
  }
  if ( (*(_DWORD *)(v2 + 12) & 1) != 0 )
  {
    if ( a2 )
    {
      ++*(_DWORD *)(v2 + 16);
      v12 = *(_BYTE *)(result + 395);
      v13 = *(_DWORD *)(v2 + 4);
      *(_DWORD *)v2 |= 1 << v12;
      *(_DWORD *)(v2 + 4) = v13 | (1 << (v12 - 32));
    }
  }
  return result;
}

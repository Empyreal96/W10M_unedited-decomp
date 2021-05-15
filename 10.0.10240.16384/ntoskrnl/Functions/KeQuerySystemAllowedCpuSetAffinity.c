// KeQuerySystemAllowedCpuSetAffinity 
 
void KeQuerySystemAllowedCpuSetAffinity()
{
  __int64 v0; // kr00_8
  int v1; // r1
  int v2; // r0
  int *v3; // r3
  unsigned int v4; // r5
  unsigned int v5; // t1
  int v6; // lr
  unsigned int v7; // r2

  do
  {
    v0 = KiCpuSetSequence;
    __dmb(0xBu);
    if ( (v0 & 1) != 0 )
    {
      sub_540F54();
      return;
    }
    if ( KiCachedSystemAllowedCpuSetVersion == v0 )
      return;
    KiCachedSystemAllowedCpuSet = 1;
    word_61DB72 = 1;
    dword_61DB74 = 0;
    v1 = 0;
    dword_61DB78 = 0;
    if ( KiRestrictedSystemCpuSetsActive )
    {
      v2 = (unsigned __int16)KiActiveGroups;
      if ( KiActiveGroups )
      {
        v3 = KiSystemAllowedCpuSets;
        do
        {
          v5 = *v3++;
          v4 = v5;
          v6 = 0;
          if ( v5 )
          {
            do
            {
              v7 = __clz(__rbit(v4));
              v6 |= *(_DWORD *)(KiCpuSetAffinities + 4 * v7);
              v4 &= ~(1 << v7);
            }
            while ( v4 );
            if ( v6 )
            {
              v1 |= v6;
              dword_61DB78 = v1;
            }
          }
          --v2;
        }
        while ( v2 );
      }
    }
    else
    {
      v1 = *(_DWORD *)&KeActiveProcessors;
      *(_DWORD *)&KiCachedSystemAllowedCpuSet = *(_DWORD *)&KeActiveProcessors;
      dword_61DB74 = dword_681D74;
      dword_61DB78 = dword_681D78[0];
    }
  }
  while ( !RtlTryEndReadTickLock(&KiCpuSetSequence, v1, v0, HIDWORD(v0)) );
  KiCachedSystemAllowedCpuSetVersion = v0;
}

// MiAbortCombineScan 
 
int __fastcall MiAbortCombineScan(int result)
{
  int v1; // r10
  int v2; // r4
  unsigned int v3; // r1
  unsigned int v4; // r0
  int *i; // r4
  unsigned int v6; // r1
  int v7; // r7
  int v8; // r0

  v1 = result;
  if ( dword_634304 )
  {
    if ( (dword_682604 & 0x210000) != 0 )
    {
      result = sub_53AC50();
    }
    else
    {
      v2 = dword_634300 & 0x7FFFFFFF;
      v3 = (dword_634300 & 0x7FFFFFFF) + 1;
      do
        v4 = __ldrex((unsigned int *)&dword_634300);
      while ( v4 == v2 && __strex(v3, (unsigned int *)&dword_634300) );
      __dmb(0xBu);
      if ( v4 != v2 )
        ExpWaitForSpinLockSharedAndAcquire((unsigned int *)&dword_634300);
      for ( i = (int *)dword_6403D4; i != &dword_6403D4; i = (int *)*i )
      {
        if ( i[6] == v1 )
        {
          v7 = i[7];
          if ( (*(_DWORD *)v7 & 2) != 0 )
          {
            if ( (unsigned int)(v7 + 0x40000000) > 0x3FFFFF )
            {
              *(_DWORD *)v7 = 0;
            }
            else
            {
              __dmb(0xBu);
              *(_DWORD *)v7 = 0;
              if ( (unsigned int)(v7 + 1070596096) <= 0xFFF )
              {
                v8 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v8, v8 + 4 * (v7 & 0xFFF), 0);
              }
            }
            KeFlushSingleTb(v7 << 10, 1);
          }
        }
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        result = ExpReleaseSpinLockSharedFromDpcLevelInstrumented(&dword_634300);
      }
      else
      {
        __dmb(0xBu);
        do
          result = __ldrex((unsigned int *)&dword_634300);
        while ( __strex(result & 0xBFFFFFFF, (unsigned int *)&dword_634300) );
        __dmb(0xBu);
        do
          v6 = __ldrex((unsigned int *)&dword_634300);
        while ( __strex(v6 - 1, (unsigned int *)&dword_634300) );
      }
    }
  }
  return result;
}

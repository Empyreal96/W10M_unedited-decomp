// KeQueryHardwareCounterConfiguration 
 
int __fastcall KeQueryHardwareCounterConfiguration(_DWORD *a1, unsigned int a2, unsigned int *a3)
{
  unsigned int v4; // r3
  unsigned int v6; // r2
  int *v7; // r1
  int v8; // t1

  v4 = KiHwCountersCount;
  *a3 = KiHwCountersCount;
  if ( v4 > a2 )
    return -1073741789;
  v6 = 0;
  if ( v4 )
  {
    v7 = &KiHwCounters;
    do
    {
      v8 = *v7++;
      *a1 = 0;
      a1[1] = 0;
      a1[2] = v8;
      a1[3] = 0;
      ++v6;
      a1 += 4;
    }
    while ( v6 < *a3 );
  }
  return 0;
}

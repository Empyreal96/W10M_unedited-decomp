// KeSetHardwareCounterConfiguration 
 
int __fastcall KeSetHardwareCounterConfiguration(int a1, unsigned int a2)
{
  int *v4; // r0
  unsigned int v5; // r4
  int v6; // r3

  if ( a2 > 0x10 )
    return -1073741811;
  if ( a2 )
  {
    if ( KiHwCountersCount )
      return -1073741053;
    v4 = &KiHwCounters;
    v5 = a2;
    do
    {
      v6 = *(_DWORD *)(a1 + 8);
      a1 += 16;
      --v5;
      *v4++ = v6;
    }
    while ( v5 );
  }
  KiHwCountersCount = a2;
  return 0;
}

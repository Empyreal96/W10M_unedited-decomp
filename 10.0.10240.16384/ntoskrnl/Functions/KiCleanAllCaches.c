// KiCleanAllCaches 
 
int KiCleanAllCaches()
{
  unsigned int v0; // r4
  int v1; // r0
  unsigned int v2; // r5
  unsigned int i; // r1
  unsigned int v4; // r6
  unsigned int v5; // r0
  char v6; // r2
  unsigned int j; // r3
  char v8; // r7
  int v9; // r2
  int v11[6]; // [sp+8h] [bp-18h] BYREF

  v0 = KfRaiseIrql(12);
  v11[0] = KeNumberProcessors_0 - 1;
  if ( KeNumberProcessors_0 != 1 )
    KiIpiSendPacket(1, 0, (int)KiCleanAllCachesTarget, (int)v11, 0, 0);
  while ( v11[0] )
  {
    __dmb(0xAu);
    __yield();
  }
  v1 = v0;
  if ( v0 < 2 )
    v1 = 2;
  KfLowerIrql(v1);
  v2 = ((unsigned int)__mrc(15, 1, 0, 0, 1) >> 24) & 7;
  for ( i = 0; i < v2; ++i )
  {
    __mcr(15, 2, 2 * (i & 7), 0, 0, 0);
    __isb(0xFu);
    v4 = __mrc(15, 1, 0, 0, 0);
    v5 = ((v4 >> 3) & 0x3FF) + 1;
    v6 = 0;
    for ( j = v5 >> 1; j; j >>= 1 )
      ++v6;
    if ( ((v4 >> 3) & 0x3FF & (((v4 >> 3) & 0x3FF) + 1)) != 0 )
      ++v6;
    v8 = 32 - v6;
    do
    {
      --v5;
      v9 = ((v4 >> 13) & 0x7FFF) + 1;
      do
        __mcr(15, 0, (--v9 << ((v4 & 7) + 4)) | (2 * i) | (v5 << v8), 7, 10, 2);
      while ( v9 );
    }
    while ( v5 );
  }
  __dsb(0xFu);
  KfLowerIrql(v0);
  return off_617A84(0);
}

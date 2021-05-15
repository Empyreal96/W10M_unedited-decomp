// PiDqObjectManagerUnlockData 
 
unsigned int __fastcall PiDqObjectManagerUnlockData(unsigned int *a1)
{
  unsigned int *v1; // r4
  unsigned int v2; // r5
  unsigned int v3; // r1

  v1 = a1 + 14;
  v2 = a1[21];
  a1[15] = 0;
  __dmb(0xBu);
  do
    v3 = __ldrex(v1);
  while ( !v3 && __strex(1u, v1) );
  if ( v3 )
    ExpReleaseFastMutexContended(a1 + 14, v3);
  KfLowerIrql((unsigned __int8)v2);
  return KeAbPostRelease((unsigned int)v1);
}

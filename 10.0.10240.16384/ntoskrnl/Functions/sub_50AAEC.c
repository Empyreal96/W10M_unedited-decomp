// sub_50AAEC 
 
unsigned int __fastcall sub_50AAEC(int a1, unsigned int a2)
{
  unsigned int *v2; // r4

  ExpReleaseFastMutexContended(v2, a2);
  return KeAbPostRelease((unsigned int)v2);
}

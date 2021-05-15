// FsRtlReleaseHeaderMutex 
 
int __fastcall FsRtlReleaseHeaderMutex(int a1)
{
  unsigned int *v1; // r4
  unsigned int v2; // r5
  unsigned int v3; // r1

  v1 = *(unsigned int **)(*(_DWORD *)(a1 + 12) + 40);
  v2 = v1[7];
  v1[1] = 0;
  __dmb(0xBu);
  do
    v3 = __ldrex(v1);
  while ( !v3 && __strex(1u, v1) );
  if ( v3 )
    ExpReleaseFastMutexContended(v1, v3, 1);
  KfLowerIrql((unsigned __int8)v2);
  return KeAbPostRelease(v1);
}

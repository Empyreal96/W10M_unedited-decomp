// sub_7C8108 
 
unsigned int sub_7C8108()
{
  unsigned int *v0; // r4
  int v1; // r5
  int *v2; // r6
  int v3; // r7
  unsigned int v4; // r8
  int v5; // r2
  int **v6; // r1
  unsigned int v7; // r5
  unsigned int v8; // r1

  ExpAcquireFastMutexContended((int)v0, v1);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  v0[1] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v0[7] = v4;
  v5 = *v2;
  if ( *v2 )
  {
    v6 = (int **)v2[1];
    if ( *(int **)(v5 + 4) != v2 || *v6 != v2 )
      __fastfail(3u);
    *v6 = (int *)v5;
    *(_DWORD *)(v5 + 4) = v6;
    --*(_DWORD *)(v3 + 120);
    PiDqQueryRelease((unsigned int)v2);
  }
  v7 = v0[7];
  v0[1] = 0;
  __dmb(0xBu);
  do
    v8 = __ldrex(v0);
  while ( !v8 && __strex(1u, v0) );
  if ( v8 )
    ExpReleaseFastMutexContended(v0, v8);
  KfLowerIrql((unsigned __int8)v7);
  return KeAbPostRelease((unsigned int)v0);
}

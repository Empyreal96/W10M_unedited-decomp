// sub_80D9A0 
 
void sub_80D9A0()
{
  unsigned int v0; // r5
  unsigned int v1; // r9
  int *v2; // r10
  int *v3; // r7
  int v4; // r3
  int v5; // t1
  int v6; // r4
  int v7; // r6
  int v8; // r8
  unsigned int v9; // r2
  unsigned int v10; // r0
  unsigned int v11; // r0
  int v12; // r4
  unsigned int v13; // r1

  v3 = v2;
  while ( (unsigned int)v3 < v1 )
  {
    v5 = *v3;
    v3 += 10;
    v4 = v5;
    if ( v5 )
      v6 = *(_DWORD *)(*(_DWORD *)(v4 + 176) + 20);
    else
      v6 = 0;
    v7 = KeAbPreAcquire(v0, 0, 0);
    v8 = KfRaiseIrql(1);
    do
      v9 = __ldrex((unsigned __int8 *)v0);
    while ( __strex(v9 & 0xFE, (unsigned __int8 *)v0) );
    __dmb(0xBu);
    if ( (v9 & 1) == 0 )
      ExpAcquireFastMutexContended(v0, v7);
    if ( v7 )
      *(_BYTE *)(v7 + 14) |= 1u;
    *(_DWORD *)(v0 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v0 + 28) = v8;
    v10 = *(_DWORD *)(v6 + 284);
    if ( v10 )
    {
      ExFreePoolWithTag(v10);
      *(_DWORD *)(v6 + 284) = 0;
    }
    v11 = *(_DWORD *)(v6 + 288);
    if ( v11 )
    {
      ExFreePoolWithTag(v11);
      *(_DWORD *)(v6 + 288) = 0;
    }
    *(_DWORD *)(v0 + 4) = 0;
    v12 = *(_DWORD *)(v0 + 28);
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)v0);
    while ( !v13 && __strex(1u, (unsigned int *)v0) );
    if ( v13 )
      ExpReleaseFastMutexContended((unsigned int *)v0, v13);
    KfLowerIrql((unsigned __int8)v12);
    KeAbPostRelease(v0);
  }
  JUMPOUT(0x7950A6);
}

// sub_522F9C 
 
void sub_522F9C()
{
  int v0; // r4
  _DWORD *v1; // r5
  int v2; // r0
  _DWORD *v3; // r4
  unsigned __int8 *v4; // r7
  int v5; // r6
  int v6; // r9
  unsigned int v7; // r2

  v2 = KeAcquireQueuedSpinLock(5);
  v3 = *(_DWORD **)(v0 + 4);
  if ( !v3 )
  {
    KeReleaseQueuedSpinLock(5, v2);
    *v1 = -1;
    v1[1] = 0x7FFFFFFF;
    JUMPOUT(0x45903E);
  }
  ++v3[1];
  KeReleaseQueuedSpinLock(5, v2);
  v4 = (unsigned __int8 *)(v3 + 45);
  v5 = KeAbPreAcquire((unsigned int)(v3 + 45), 0, 0);
  v6 = KfRaiseIrql(1);
  do
    v7 = __ldrex(v4);
  while ( __strex(v7 & 0xFE, v4) );
  __dmb(0xBu);
  if ( (v7 & 1) == 0 )
    ExpAcquireFastMutexContended((int)(v3 + 45), v5);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v3[46] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3[52] = v6;
  JUMPOUT(0x45902A);
}

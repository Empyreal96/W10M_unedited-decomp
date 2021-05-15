// sub_7C9AF8 
 
void sub_7C9AF8()
{
  int v0; // r0
  unsigned int v1; // r1
  int v2; // r3
  int v3; // r4
  int v4; // r5
  unsigned int *v5; // r6
  int v6; // r7
  unsigned int v7; // r9
  unsigned int v8; // r4
  unsigned int v9; // r1

  ExpAcquireFastMutexContended((int)v5, v6);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  __mrc(15, 0, 13, 0, 3);
  v5[7] = v7;
  *(_DWORD *)(v4 + 296) = v3;
  v5[1] = 0;
  v8 = v5[7];
  __dmb(0xBu);
  do
    v9 = __ldrex(v5);
  while ( !v9 && __strex(1u, v5) );
  if ( v9 )
    ExpReleaseFastMutexContended(v5, v9);
  KfLowerIrql((unsigned __int8)v8);
  KeAbPostRelease((unsigned int)v5);
  PipSetDevNodeFlags(v4, 512);
  v0 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = (__int16)(*(_WORD *)(v1 + 0x134) + 1);
  *(_WORD *)(v1 + 308) = v2;
  if ( !v2 && *(_DWORD *)(v1 + 100) != v1 + 100 && !*(_WORD *)(v1 + 310) )
  {
    KiCheckForKernelApcDelivery(v0);
    JUMPOUT(0x7690A8);
  }
  JUMPOUT(0x769006);
}

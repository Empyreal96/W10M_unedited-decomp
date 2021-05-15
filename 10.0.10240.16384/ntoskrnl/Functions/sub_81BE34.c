// sub_81BE34 
 
void sub_81BE34()
{
  unsigned int *v0; // r5
  unsigned int v1; // r6
  int v2; // r0
  int v3; // r4
  unsigned int v4; // r2
  int i; // r4
  char v6; // r0
  unsigned int v7; // r2
  int v8; // r0
  int v9; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 310);
  v2 = KeAbPreAcquire((unsigned int)v0, 0, 0);
  v3 = v2;
  do
    v4 = __ldrex(v0);
  while ( !v4 && __strex(0x11u, v0) );
  __dmb(0xBu);
  if ( v4 )
    ExfAcquirePushLockSharedEx(v0, v2, (unsigned int)v0);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  for ( i = PsActiveProcessHead; (int *)i != &PsActiveProcessHead; i = *(_DWORD *)i )
  {
    v6 = PspComputeQuantum(i - 180, *(unsigned __int8 *)(i + 426));
    KeSetQuantumProcess(i - 180, v6);
  }
  __dmb(0xBu);
  do
    v7 = __ldrex(v0);
  while ( v7 == 17 && __strex(0, v0) );
  if ( v7 != 17 )
    ExfReleasePushLockShared(v0);
  v8 = KeAbPostRelease((unsigned int)v0);
  v9 = (__int16)(*(_WORD *)(v1 + 310) + 1);
  *(_WORD *)(v1 + 310) = v9;
  if ( !v9 && *(_DWORD *)(v1 + 100) != v1 + 100 )
    KiCheckForKernelApcDelivery(v8);
  JUMPOUT(0x7BC38C);
}

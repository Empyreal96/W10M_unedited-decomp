// sub_7F4B78 
 
void sub_7F4B78()
{
  int v0; // r6
  int v1; // r7
  _BYTE *v2; // r9
  int v3; // r10
  int v4; // r4
  int v5; // r8
  unsigned int v6; // r2
  unsigned int *v7; // r4
  unsigned int v8; // r1
  unsigned __int8 *v9; // r5
  int v10; // r8
  int v11; // r6
  int v12; // r10
  unsigned int v13; // r2
  unsigned int v14; // r6
  unsigned int v15; // r1

  v4 = KeAbPreAcquire((unsigned int)&DbgkpProcessDebugPortMutex, 0, 0);
  v5 = KfRaiseIrql(1);
  do
    v6 = __ldrex((unsigned __int8 *)&DbgkpProcessDebugPortMutex);
  while ( __strex(v6 & 0xFE, (unsigned __int8 *)&DbgkpProcessDebugPortMutex) );
  __dmb(0xBu);
  if ( (v6 & v3) == 0 )
    ExpAcquireFastMutexContended((int)&DbgkpProcessDebugPortMutex, v4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= v3;
  dword_631F64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_631F7C = v5;
  v7 = *(unsigned int **)(v0 + 340);
  if ( v7 )
  {
    if ( (*(_DWORD *)(v0 + 192) & 2) != 0 )
    {
      v7 = 0;
    }
    else
    {
      ObfReferenceObject(*(_DWORD *)(v0 + 340));
      LOBYTE(v5) = dword_631F7C;
    }
  }
  dword_631F64 = 0;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&DbgkpProcessDebugPortMutex);
  while ( !v8 && __strex(1u, (unsigned int *)&DbgkpProcessDebugPortMutex) );
  if ( v8 )
    ExpReleaseFastMutexContended((unsigned int *)&DbgkpProcessDebugPortMutex, v8);
  KfLowerIrql((unsigned __int8)v5);
  KeAbPostRelease((unsigned int)&DbgkpProcessDebugPortMutex);
  if ( v7 )
  {
    if ( PspCheckForInvalidAccessByProtection(
           *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A),
           *(_BYTE *)(v0 + 734),
           *(_BYTE *)(v1 + 734)) )
    {
      ObfDereferenceObject((int)v7);
      JUMPOUT(0x715110);
    }
    v9 = (unsigned __int8 *)(v7 + 4);
    v10 = 0;
    v11 = KeAbPreAcquire((unsigned int)(v7 + 4), 0, 0);
    v12 = KfRaiseIrql(1);
    do
      v13 = __ldrex(v9);
    while ( __strex(v13 & 0xFE, v9) );
    __dmb(0xBu);
    if ( (v13 & 1) == 0 )
      ExpAcquireFastMutexContended((int)(v7 + 4), v11);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    v7[5] = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v7[11] = v12;
    if ( (v7[14] & 1) != 0 )
      v10 = 1;
    else
      *(_DWORD *)(v1 + 340) = v7;
    v14 = v7[11];
    v7[5] = 0;
    __dmb(0xBu);
    do
      v15 = __ldrex((unsigned int *)v9);
    while ( !v15 && __strex(1u, (unsigned int *)v9) );
    if ( v15 )
      ExpReleaseFastMutexContended(v7 + 4, v15);
    KfLowerIrql((unsigned __int8)v14);
    KeAbPostRelease((unsigned int)(v7 + 4));
    if ( v10 )
    {
      ObfDereferenceObject((int)v7);
      v7 = 0;
    }
    if ( v7 )
    {
      DbgkpMarkProcessPeb(v1);
      *v2 = 1;
      JUMPOUT(0x71510E);
    }
    JUMPOUT(0x71510A);
  }
  JUMPOUT(0x715106);
}

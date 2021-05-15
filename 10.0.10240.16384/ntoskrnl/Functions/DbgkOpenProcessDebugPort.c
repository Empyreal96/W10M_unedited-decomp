// DbgkOpenProcessDebugPort 
 
int __fastcall DbgkOpenProcessDebugPort(int a1, char a2, _DWORD *a3)
{
  int v3; // r7
  int v4; // r8
  int v6; // r6
  int v7; // r10
  unsigned int v8; // r4
  int v9; // r4
  unsigned int v10; // r1
  int v11; // r1

  v3 = -1073740973;
  v4 = a2;
  if ( *(_DWORD *)(a1 + 340) )
  {
    v6 = KeAbPreAcquire((unsigned int)&DbgkpProcessDebugPortMutex, 0, 0);
    v7 = KfRaiseIrql(1);
    do
      v8 = __ldrex((unsigned __int8 *)&DbgkpProcessDebugPortMutex);
    while ( __strex(v8 & 0xFE, (unsigned __int8 *)&DbgkpProcessDebugPortMutex) );
    __dmb(0xBu);
    if ( (v8 & 1) == 0 )
      ExpAcquireFastMutexContended((int)&DbgkpProcessDebugPortMutex, v6);
    if ( v6 )
      *(_BYTE *)(v6 + 14) |= 1u;
    dword_631F64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    dword_631F7C = v7;
    v9 = *(_DWORD *)(a1 + 340);
    if ( v9 )
    {
      ObfReferenceObject(*(_DWORD *)(a1 + 340));
      LOBYTE(v7) = dword_631F7C;
    }
    dword_631F64 = 0;
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)&DbgkpProcessDebugPortMutex);
    while ( !v10 && __strex(1u, (unsigned int *)&DbgkpProcessDebugPortMutex) );
    if ( v10 )
      ExpReleaseFastMutexContended((unsigned int *)&DbgkpProcessDebugPortMutex, v10);
    KfLowerIrql((unsigned __int8)v7);
    KeAbPostRelease((unsigned int)&DbgkpProcessDebugPortMutex);
    if ( v9 )
    {
      if ( PspCheckForInvalidAccessByProtection(
             v4,
             *(_BYTE *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 734),
             *(_BYTE *)(a1 + 734)) )
      {
        v3 = -1073740014;
LABEL_22:
        ObfDereferenceObject(v9);
        return v3;
      }
      if ( v4 )
        v11 = 0;
      else
        v11 = 512;
      v3 = ObOpenObjectByPointer(v9, v11, 0, 0x2000000, DbgkDebugObjectType, v4, a3);
      if ( v3 < 0 )
        goto LABEL_22;
    }
  }
  return v3;
}

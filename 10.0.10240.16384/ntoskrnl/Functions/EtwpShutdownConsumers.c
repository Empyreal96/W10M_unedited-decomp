// EtwpShutdownConsumers 
 
unsigned int __fastcall EtwpShutdownConsumers(_DWORD *a1)
{
  unsigned __int8 *v2; // r5
  int v3; // r0
  unsigned int v4; // r2
  unsigned int *v6; // r0
  int v7; // r3
  int v8; // r1
  unsigned int v9; // r0
  unsigned int v10; // r2
  int v11; // r4
  unsigned int v12; // r1

  EtwpRealtimeDisconnectAllConsumers(a1);
  v2 = (unsigned __int8 *)(a1 + 126);
  v3 = KeAbPreAcquire((unsigned int)(a1 + 126), 0, 0);
  do
    v4 = __ldrex(v2);
  while ( __strex(v4 | 1, v2) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_7EEEFC(v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v6 = a1 + 153;
  a1[152] |= 0x200u;
  v7 = a1[153];
  __dmb(0xBu);
  if ( (v7 & 0x20) != 0 )
  {
    v11 = a1[67];
    a1[67] = 0;
    a1[10] = 0;
    __dmb(0xBu);
    do
      v12 = __ldrex(v6);
    while ( __strex(v12 & 0xFFFFFFDF, v6) );
    __dmb(0xBu);
    KeSetEvent((int)(a1 + 89), 0, 0);
    KeSetEvent(*(_DWORD *)(v11 + 24), 0, 0);
    ObfDereferenceObject(v11);
  }
  __pld(v2);
  v8 = *(_DWORD *)v2;
  if ( (*(_DWORD *)v2 & 0xFFFFFFF0) > 0x10 )
    v9 = v8 - 16;
  else
    v9 = 0;
  if ( (v8 & 2) != 0 )
    goto LABEL_17;
  __dmb(0xBu);
  do
    v10 = __ldrex((unsigned int *)v2);
  while ( v10 == v8 && __strex(v9, (unsigned int *)v2) );
  if ( v10 != v8 )
LABEL_17:
    ExfReleasePushLock(a1 + 126, v8);
  return KeAbPostRelease((unsigned int)(a1 + 126));
}

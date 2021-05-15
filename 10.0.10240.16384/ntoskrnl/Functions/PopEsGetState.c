// PopEsGetState 
 
int PopEsGetState()
{
  unsigned int v0; // r2
  int v1; // r0
  unsigned int v2; // r2
  int v4; // r5
  int v5; // r1
  unsigned int v6; // r0
  unsigned int v7; // r2
  int v8; // r0
  unsigned int v9; // r1
  __int16 v10; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&PopEsLock, 0, 0);
  do
    v2 = __ldrex((unsigned __int8 *)&PopEsLock);
  while ( __strex(v2 | 1, (unsigned __int8 *)&PopEsLock) );
  __dmb(0xBu);
  if ( (v2 & 1) != 0 )
    return sub_81B660(v1);
  if ( v1 )
    *(_BYTE *)(v1 + 14) |= 1u;
  __mrc(15, 0, 13, 0, 3);
  v4 = PopEsState;
  dword_61DED4 = 0;
  __pld(&PopEsLock);
  v5 = PopEsLock;
  if ( (PopEsLock & 0xFFFFFFF0) > 0x10 )
    v6 = PopEsLock - 16;
  else
    v6 = 0;
  if ( (PopEsLock & 2) != 0 )
    goto LABEL_20;
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&PopEsLock);
  while ( v7 == v5 && __strex(v6, (unsigned int *)&PopEsLock) );
  if ( v7 != v5 )
LABEL_20:
    ExfReleasePushLock(&PopEsLock, v5);
  v8 = KeAbPostRelease((unsigned int)&PopEsLock);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = *(_WORD *)(v9 + 0x134) + 1;
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v8);
  return v4;
}

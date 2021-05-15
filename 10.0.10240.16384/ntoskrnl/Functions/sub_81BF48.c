// sub_81BF48 
 
void sub_81BF48()
{
  int *v0; // r6
  unsigned int v1; // r2
  int v2; // r0
  int v3; // r5
  unsigned int v4; // r2
  int v5; // r1
  unsigned int v6; // r0
  unsigned int v7; // r2
  int v8; // r0
  unsigned int v9; // r1
  int v10; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v1 + 308);
  v2 = KeAbPreAcquire((unsigned int)&PopEsLock, 0, 0);
  v3 = v2;
  do
    v4 = __ldrex((unsigned __int8 *)&PopEsLock);
  while ( __strex(v4 | 1, (unsigned __int8 *)&PopEsLock) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&PopEsLock, v2, (unsigned int)&PopEsLock);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  dword_61DED4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_61EC50 = *v0;
  if ( (unsigned int)dword_61EC50 > 0x64 )
    dword_61EC50 = 100;
  dword_61DED4 = 0;
  __pld(&PopEsLock);
  v5 = PopEsLock;
  if ( (PopEsLock & 0xFFFFFFF0) <= 0x10 )
    v6 = 0;
  else
    v6 = PopEsLock - 16;
  if ( (PopEsLock & 2) != 0 )
    goto LABEL_17;
  __dmb(0xBu);
  do
    v7 = __ldrex((unsigned int *)&PopEsLock);
  while ( v7 == v5 && __strex(v6, (unsigned int *)&PopEsLock) );
  if ( v7 != v5 )
LABEL_17:
    ExfReleasePushLock(&PopEsLock, v5);
  v8 = KeAbPostRelease((unsigned int)&PopEsLock);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = (__int16)(*(_WORD *)(v9 + 0x134) + 1);
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v8);
  JUMPOUT(0x7BC4B2);
}

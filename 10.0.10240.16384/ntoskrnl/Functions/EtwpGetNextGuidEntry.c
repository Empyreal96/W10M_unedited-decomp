// EtwpGetNextGuidEntry 
 
int __fastcall EtwpGetNextGuidEntry(_DWORD *a1, int a2)
{
  _DWORD *v2; // r4
  char *v3; // r8
  char *v4; // r3
  char *v5; // r7
  char *v6; // r10
  unsigned int *v7; // r6
  unsigned int v8; // r2
  int v9; // r0
  unsigned int v10; // r2
  char *i; // r5
  int v13; // r5
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  int v18; // [sp+0h] [bp-20h]

  v2 = a1;
  v18 = 0;
  v3 = 0;
  if ( a1 )
    v4 = (char *)&EtwpGuidHashTable + 28 * ((a1[3] ^ a1[6] ^ a1[5] ^ a1[4]) & 0x3F);
  else
    v4 = (char *)&EtwpGuidHashTable;
  v5 = &v4[8 * a2];
  v6 = v5;
  v7 = (unsigned int *)(v4 + 24);
  while ( 1 )
  {
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v8 + 308);
    v9 = KeAbPreAcquire((unsigned int)v7, 0, 0);
    do
      v10 = __ldrex(v7);
    while ( !v10 && __strex(0x11u, v7) );
    __dmb(0xBu);
    if ( v10 )
      return sub_7EE254(v9, 17);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    for ( i = (char *)(v2 ? *v2 : *(_DWORD *)v5); i != v5; i = *(char **)i )
    {
      v3 = i;
      if ( EtwpReferenceGuidEntry((int)i) )
      {
        v13 = 1;
        v18 = 1;
        goto LABEL_16;
      }
    }
    v13 = v18;
LABEL_16:
    __dmb(0xBu);
    do
      v14 = __ldrex(v7);
    while ( v14 == 17 && __strex(0, v7) );
    if ( v14 != 17 )
      ExfReleasePushLockShared(v7);
    v15 = KeAbPostRelease((unsigned int)v7);
    v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v17 = *(_WORD *)(v16 + 0x134) + 1;
    *(_WORD *)(v16 + 308) = v17;
    if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
      KiCheckForKernelApcDelivery(v15);
    if ( v2 )
      EtwpUnreferenceGuidEntry((int)v2);
    if ( v13 )
      return (int)v3;
    v7 += 7;
    v6 += 28;
    if ( v7 - 6 == (unsigned int *)&EtwpReplyListHead )
      return 0;
    v2 = 0;
    v5 = v6;
  }
}

// EtwpAddGuidEntry 
 
int __fastcall EtwpAddGuidEntry(unsigned int a1, int a2)
{
  _DWORD *v4; // r5
  int v6; // r8
  char *v7; // r1
  char *v8; // r7
  unsigned int v9; // r2
  unsigned __int8 *v10; // r6
  int v11; // r0
  int v12; // r4
  unsigned int v13; // r2
  char *i; // r4
  char *v15; // r2
  unsigned int v16; // r1
  int v17; // r0
  unsigned int v18; // r1
  __int16 v19; // r3
  unsigned int v20; // r1
  int v21; // r0
  unsigned int v22; // r1
  __int16 v23; // r3
  unsigned int *v24; // r2
  unsigned int v25; // r1

  v4 = (_DWORD *)EtwpAllocGuidEntry();
  if ( !v4 )
    return sub_8080A4();
  v6 = PsGetCurrentServerSilo();
  v7 = (char *)&EtwpGuidHashTable
     + 28
     * (((unsigned __int8)*(_DWORD *)a1 ^ (unsigned __int8)(*(_DWORD *)(a1 + 12) ^ *(_QWORD *)(a1 + 8) ^ *(_DWORD *)(a1 + 4))) & 0x3F);
  v8 = &v7[8 * a2];
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  v10 = (unsigned __int8 *)(v7 + 24);
  v11 = KeAbPreAcquire((unsigned int)(v7 + 24), 0, 0);
  v12 = v11;
  do
    v13 = __ldrex(v10);
  while ( __strex(v13 | 1, v10) );
  __dmb(0xBu);
  if ( (v13 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v10, v11, (unsigned int)v10);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  for ( i = *(char **)v8; i != v8; i = *(char **)i )
  {
    if ( !memcmp(a1, (unsigned int)(i + 12), 16) && v6 == *((_DWORD *)i + 87) && EtwpReferenceGuidEntry((int)i) )
    {
      __dmb(0xBu);
      do
        v20 = __ldrex((unsigned int *)v10);
      while ( __strex(v20 - 1, (unsigned int *)v10) );
      if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)v10);
      v21 = KeAbPostRelease((unsigned int)v10);
      v22 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v23 = *(_WORD *)(v22 + 0x134) + 1;
      *(_WORD *)(v22 + 308) = v23;
      if ( !v23 && *(_DWORD *)(v22 + 100) != v22 + 100 && !*(_WORD *)(v22 + 310) )
        KiCheckForKernelApcDelivery(v21);
      __dmb(0xBu);
      v24 = v4 + 2;
      do
        v25 = __ldrex(v24);
      while ( __strex(v25 - 1, v24) );
      __dmb(0xBu);
      EtwpFreeGuidEntry(v4);
      goto LABEL_21;
    }
  }
  v4[87] = v6;
  if ( v6 )
    PspReferenceSiloObject(v6);
  v15 = *(char **)v8;
  *v4 = *(_DWORD *)v8;
  v4[1] = v8;
  if ( *((char **)v15 + 1) != v8 )
    __fastfail(3u);
  *((_DWORD *)v15 + 1) = v4;
  *(_DWORD *)v8 = v4;
  i = (char *)v4;
  __dmb(0xBu);
  do
    v16 = __ldrex((unsigned int *)v10);
  while ( __strex(v16 - 1, (unsigned int *)v10) );
  if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v10);
  v17 = KeAbPostRelease((unsigned int)v10);
  v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v19 = *(_WORD *)(v18 + 0x134) + 1;
  *(_WORD *)(v18 + 308) = v19;
  if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
    KiCheckForKernelApcDelivery(v17);
LABEL_21:
  if ( v6 )
    PspDereferenceSiloObject(v6);
  return (int)i;
}

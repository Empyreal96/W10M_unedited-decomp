// EtwpFindGuidEntryByGuid 
 
int __fastcall EtwpFindGuidEntryByGuid(unsigned int a1, int a2)
{
  int v4; // r8
  char *v5; // r7
  char *v6; // r4
  char *v7; // r5
  unsigned int v8; // r2
  unsigned int *v9; // r9
  int v10; // r0
  int v11; // r4
  unsigned int v12; // r2
  char *v13; // r4
  unsigned int v14; // r2
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  int result; // r0

  v4 = PsGetCurrentServerSilo();
  v5 = 0;
  v6 = (char *)&EtwpGuidHashTable
     + 28
     * (((unsigned __int8)*(_DWORD *)a1 ^ (unsigned __int8)(*(_DWORD *)(a1 + 4) ^ *(_QWORD *)(a1 + 8) ^ *(_DWORD *)(a1 + 12))) & 0x3F);
  v7 = &v6[8 * a2];
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = (unsigned int *)(v6 + 24);
  v10 = KeAbPreAcquire((unsigned int)(v6 + 24), 0, 0);
  v11 = v10;
  do
    v12 = __ldrex(v9);
  while ( !v12 && __strex(0x11u, v9) );
  __dmb(0xBu);
  if ( v12 )
    ExfAcquirePushLockSharedEx(v9, v10, (unsigned int)v9);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  v13 = *(char **)v7;
  if ( *(char **)v7 != v7 )
  {
    while ( memcmp(a1, (unsigned int)(v13 + 12), 16) || v4 != *((_DWORD *)v13 + 87) || !EtwpReferenceGuidEntry(v13) )
    {
      v13 = *(char **)v13;
      if ( v13 == v7 )
        goto LABEL_15;
    }
    v5 = v13;
  }
LABEL_15:
  __dmb(0xBu);
  do
    v14 = __ldrex(v9);
  while ( v14 == 17 && __strex(0, v9) );
  if ( v14 != 17 )
    ExfReleasePushLockShared(v9);
  v15 = KeAbPostRelease((unsigned int)v9);
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = *(_WORD *)(v16 + 0x134) + 1;
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    v15 = KiCheckForKernelApcDelivery(v15);
  if ( v4 )
    result = sub_7C4FF8(v15);
  else
    result = (int)v5;
  return result;
}

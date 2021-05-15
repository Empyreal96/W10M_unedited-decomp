// CmpParseCacheLookup 
 
int __fastcall CmpParseCacheLookup(int a1, unsigned __int16 *a2, int a3, int a4, int a5)
{
  unsigned int v6; // r4
  _WORD *v7; // r5
  __int16 v8; // r6
  _WORD *v10; // r4
  unsigned int v11; // r8
  char *v12; // r7
  int v13; // r0
  int v14; // r5
  unsigned int v15; // r2
  int v16; // r3
  unsigned int v17; // r0
  unsigned int v18; // r2
  unsigned int v19; // r1
  int v20; // r7
  int v21; // r5
  int v22; // r1
  unsigned int v23; // r0
  unsigned int v24; // r2
  int v25; // r0
  unsigned int v26; // r4
  unsigned int v27; // r1
  unsigned int v28; // r1
  int v29; // r3
  int v31; // r0
  unsigned int v32; // r1
  __int16 v33; // r3
  __int16 v34; // [sp+10h] [bp-48h] BYREF
  __int16 v35; // [sp+12h] [bp-46h]
  _WORD *v36; // [sp+14h] [bp-44h]
  int v37; // [sp+18h] [bp-40h]
  int v38; // [sp+1Ch] [bp-3Ch]
  int v39; // [sp+20h] [bp-38h]
  char v40[48]; // [sp+28h] [bp-30h] BYREF

  v6 = *a2;
  v7 = (_WORD *)*((_DWORD *)a2 + 1);
  v38 = a3;
  v39 = a5;
  v8 = 0;
  v34 = 0;
  v35 = 0;
  v36 = v7;
  v37 = a1;
  v10 = &v7[v6 >> 1];
  v11 = 0;
  v12 = v40;
  do
  {
    if ( v7 >= v10 )
      break;
    do
    {
      if ( *v7 != 92 )
        break;
      ++v7;
      v8 += 2;
    }
    while ( v7 < v10 );
    if ( v7 == v10 )
      return sub_7D2A6C();
    for ( ; v7 < v10; v8 += 2 )
    {
      if ( *v7 == 92 )
        break;
      ++v7;
    }
    v34 = v8;
    v35 = v8;
    ++v11;
    *(_DWORD *)v12 = CmpParseCacheComputeRegHashKey(&v34);
    v12 += 4;
  }
  while ( v11 < 3 );
  v13 = KeAbPreAcquire((unsigned int)&CmpParseCacheLock, 0, 0);
  v14 = v13;
  do
    v15 = __ldrex((unsigned int *)&CmpParseCacheLock);
  while ( !v15 && __strex(0x11u, (unsigned int *)&CmpParseCacheLock) );
  __dmb(0xBu);
  if ( v15 )
    ExfAcquirePushLockSharedEx(&CmpParseCacheLock, v13, (unsigned int)&CmpParseCacheLock);
  if ( v14 )
    *(_BYTE *)(v14 + 14) |= 1u;
  v16 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v16 & 0xFFFFFFC0) + 0x134);
  __pld(&CmpShutdownRundown);
  v17 = CmpShutdownRundown & 0xFFFFFFFE;
  v18 = (CmpShutdownRundown & 0xFFFFFFFE) + 2;
  do
    v19 = __ldrex((unsigned int *)&CmpShutdownRundown);
  while ( v19 == v17 && __strex(v18, (unsigned int *)&CmpShutdownRundown) );
  __dmb(0xBu);
  if ( v19 == v17 )
  {
    v20 = 1;
  }
  else
  {
    v31 = ExfAcquireRundownProtection(&CmpShutdownRundown);
    v20 = v31;
    if ( !v31 )
    {
      v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v33 = *(_WORD *)(v32 + 0x134) + 1;
      *(_WORD *)(v32 + 308) = v33;
      if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 && !*(_WORD *)(v32 + 310) )
        KiCheckForKernelApcDelivery(0);
      v21 = -1073741431;
      goto LABEL_22;
    }
  }
  v21 = CmpParseCacheLookupByHash(CmpParseCacheTable, v37, a2, v40, v11, v38, a4, v39);
LABEL_22:
  __pld(&CmpParseCacheLock);
  v22 = CmpParseCacheLock;
  if ( (CmpParseCacheLock & 0xFFFFFFF0) > 0x10 )
    v23 = CmpParseCacheLock - 16;
  else
    v23 = 0;
  if ( (CmpParseCacheLock & 2) != 0 )
    goto LABEL_40;
  __dmb(0xBu);
  do
    v24 = __ldrex((unsigned int *)&CmpParseCacheLock);
  while ( v24 == v22 && __strex(v23, (unsigned int *)&CmpParseCacheLock) );
  if ( v24 != v22 )
LABEL_40:
    ExfReleasePushLock(&CmpParseCacheLock, v22);
  v25 = KeAbPostRelease((unsigned int)&CmpParseCacheLock);
  if ( v20 )
  {
    __pld(&CmpShutdownRundown);
    v26 = CmpShutdownRundown & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v27 = __ldrex((unsigned int *)&CmpShutdownRundown);
    while ( v27 == v26 && __strex(v26 - 2, (unsigned int *)&CmpShutdownRundown) );
    if ( v27 != v26 )
      v25 = (int)ExfReleaseRundownProtection((unsigned __int8 *)&CmpShutdownRundown);
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v29 = (__int16)(*(_WORD *)(v28 + 0x134) + 1);
    *(_WORD *)(v28 + 308) = v29;
    if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
      KiCheckForKernelApcDelivery(v25);
  }
  return v21;
}

// PspSetProcessAffinityUpdateMode 
 
int __fastcall PspSetProcessAffinityUpdateMode(unsigned int *a1, _DWORD *a2)
{
  unsigned int *v2; // r4
  int v3; // r6
  int v4; // r5
  unsigned int *v5; // r9
  unsigned int v6; // r7
  unsigned int v7; // r1
  int v8; // r3
  int v9; // r5
  int *v10; // r0
  int v12; // r0
  int v13; // r7
  unsigned int v14; // r2
  unsigned int v15; // r2
  __int16 v16; // r3

  v2 = a1;
  v3 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v4 = 0;
  if ( (*a2 & 2) != 0 )
    v4 = 0x40000;
  if ( (*a2 & 1) != 0 )
    v4 |= 0x80000u;
  v5 = (unsigned int *)(v3 + 188);
  v6 = *(_DWORD *)(v3 + 188);
  __dmb(0xBu);
  do
  {
    if ( (v6 & 0xC0000) == v4 )
      break;
    if ( (v6 & 0x40000) != 0 )
      return -1073741823;
    a1 = (unsigned int *)v6;
    __dmb(0xBu);
    do
      v7 = __ldrex(v5);
    while ( v7 == v6 && __strex(v6 & 0xFFF3FFFF | v4, v5) );
    v6 = v7;
    __dmb(0xBu);
  }
  while ( (unsigned int *)v7 != a1 );
  if ( v4 == 0x40000 )
  {
    --*((_WORD *)v2 + 154);
    __dmb(0xFu);
    v8 = *(_DWORD *)(v3 + 168);
    __dmb(0xBu);
    if ( (v8 & 1) == 0 )
      goto LABEL_37;
    v9 = KeAbPreAcquire(v3 + 168, 0, 0);
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v3 + 168), v9, v3 + 168);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    a1 = ExfReleasePushLockExclusive((unsigned int *)(v3 + 168));
    if ( !v9 )
      goto LABEL_37;
    v10 = (int *)(v3 + 168);
LABEL_36:
    a1 = (unsigned int *)KeAbPostRelease((unsigned int)v10);
LABEL_37:
    v16 = *((_WORD *)v2 + 154) + 1;
    *((_WORD *)v2 + 154) = v16;
    if ( !v16 && (unsigned int *)v2[25] != v2 + 25 && !*((_WORD *)v2 + 155) )
      KiCheckForKernelApcDelivery((int)a1);
    return 0;
  }
  if ( (v4 & 0x80000) != 0 && KeDynamicPartitioningSupported )
  {
    --*((_WORD *)v2 + 154);
    v12 = KeAbPreAcquire((unsigned int)&PspAffinityUpdateLock, 0, 0);
    v13 = v12;
    do
      v14 = __ldrex((unsigned int *)&PspAffinityUpdateLock);
    while ( !v14 && __strex(0x11u, (unsigned int *)&PspAffinityUpdateLock) );
    __dmb(0xBu);
    if ( v14 )
      ExfAcquirePushLockSharedEx(&PspAffinityUpdateLock, v12, (unsigned int)&PspAffinityUpdateLock);
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    if ( dword_6182F0 )
      PspUpdateSingleProcessAffinity(v2, v3, &PspLastUpdateAffinityMask);
    __dmb(0xBu);
    do
      v15 = __ldrex((unsigned int *)&PspAffinityUpdateLock);
    while ( v15 == 17 && __strex(0, (unsigned int *)&PspAffinityUpdateLock) );
    if ( v15 != 17 )
      ExfReleasePushLockShared(&PspAffinityUpdateLock);
    v10 = &PspAffinityUpdateLock;
    goto LABEL_36;
  }
  return 0;
}

// SepRmReferenceCapTable 
 
int SepRmReferenceCapTable()
{
  unsigned int v0; // r2
  int v1; // r0
  int v2; // r4
  unsigned int v3; // r2
  int v4; // r4
  unsigned int *v5; // r2
  unsigned int v6; // r1
  signed int v7; // r1
  unsigned int v8; // r2
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)&SepRmCapTableLock, 0, 0);
  v2 = v1;
  do
    v3 = __ldrex((unsigned int *)&SepRmCapTableLock);
  while ( !v3 && __strex(0x11u, (unsigned int *)&SepRmCapTableLock) );
  __dmb(0xBu);
  if ( v3 )
    ExfAcquirePushLockSharedEx(&SepRmCapTableLock, v1, (unsigned int)&SepRmCapTableLock);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  v4 = SepRmCapTable;
  __dmb(0xBu);
  if ( v4 )
  {
    v5 = (unsigned int *)(v4 + 36);
    do
    {
      v6 = __ldrex(v5);
      v7 = v6 + 1;
    }
    while ( __strex(v7, v5) );
    if ( v7 <= 1 )
      __fastfail(0xEu);
  }
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&SepRmCapTableLock);
  while ( v8 == 17 && __strex(0, (unsigned int *)&SepRmCapTableLock) );
  if ( v8 != 17 )
    ExfReleasePushLockShared(&SepRmCapTableLock);
  v9 = KeAbPostRelease((unsigned int)&SepRmCapTableLock);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v9);
  return v4;
}

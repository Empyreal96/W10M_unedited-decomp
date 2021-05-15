// SepReferenceLuidToIndexEntry 
 
int __fastcall SepReferenceLuidToIndexEntry(int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r3
  unsigned int *v6; // r7
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  int v10; // r0
  unsigned int *v11; // r2
  unsigned int v12; // r1
  signed int v13; // r1
  unsigned int *v14; // r4
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  int v20[6]; // [sp+0h] [bp-18h] BYREF

  v20[1] = a4;
  v20[0] = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v6 = (unsigned int *)SeLuidToIndexMapping;
  v7 = KeAbPreAcquire(SeLuidToIndexMapping, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex(v6);
  while ( !v9 && __strex(0x11u, v6) );
  __dmb(0xBu);
  if ( v9 )
    ExfAcquirePushLockSharedEx(v6, v7, v6);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v10 = SepFindMatchingLuidEntry(*((_DWORD *)SeLuidToIndexMapping + 1), a1, v20);
  if ( v20[0] )
  {
    v11 = (unsigned int *)(v20[0] + 12);
    do
    {
      v12 = __ldrex(v11);
      v13 = v12 + 1;
    }
    while ( __strex(v13, v11) );
    if ( v13 <= 1 )
      sub_517F80(v10);
  }
  v14 = (unsigned int *)SeLuidToIndexMapping;
  __dmb(0xBu);
  do
    v15 = __ldrex(v14);
  while ( v15 == 17 && __strex(0, v14) );
  if ( v15 != 17 )
    ExfReleasePushLockShared(v14, 0);
  v16 = KeAbPostRelease(v14);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( v18 )
    return 0;
  if ( *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v16);
  return 0;
}

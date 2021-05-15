// SepDereferenceLowBoxHandlesEntry 
 
int __fastcall SepDereferenceLowBoxHandlesEntry(int a1, int a2)
{
  unsigned __int8 *v3; // r4
  unsigned int v4; // r2
  int v5; // r0
  int v6; // r6
  unsigned int v7; // r2
  unsigned int *v8; // r2
  unsigned int v9; // r1
  signed int v10; // r1
  unsigned int v11; // r1
  int v12; // r0
  unsigned int v13; // r1
  __int16 v14; // r3

  v3 = (unsigned __int8 *)(a1 + 52);
  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v4 + 308);
  v5 = KeAbPreAcquire(a1 + 52, 0, 0);
  v6 = v5;
  do
    v7 = __ldrex(v3);
  while ( __strex(v7 | 1, v3) );
  __dmb(0xBu);
  if ( (v7 & 1) != 0 )
    v5 = ExfAcquirePushLockExclusiveEx(v3, v5, (unsigned int)v3);
  if ( v6 )
    *(_BYTE *)(v6 + 14) |= 1u;
  __dmb(0xBu);
  v8 = (unsigned int *)(a2 + 12);
  do
  {
    v9 = __ldrex(v8);
    v10 = v9 - 1;
  }
  while ( __strex(v10, v8) );
  if ( v10 <= 0 )
    return sub_7BFF90(v5);
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)v3);
  while ( __strex(v11 - 1, (unsigned int *)v3) );
  if ( (v11 & 2) != 0 && (v11 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v3);
  v12 = KeAbPostRelease((unsigned int)v3);
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *(_WORD *)(v13 + 0x134) + 1;
  *(_WORD *)(v13 + 308) = v14;
  if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
    KiCheckForKernelApcDelivery(v12);
  return 0;
}

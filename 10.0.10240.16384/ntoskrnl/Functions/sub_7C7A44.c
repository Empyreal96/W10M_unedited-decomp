// sub_7C7A44 
 
void __fastcall sub_7C7A44(int a1, int a2, int a3, int a4, int a5, int a6, unsigned __int8 a7, int a8, int a9, int a10, int a11)
{
  int v11; // r7
  int v12; // r9
  int v13; // r10
  unsigned int v14; // r2
  unsigned __int8 *v15; // r4
  int v16; // r0
  int v17; // r5
  unsigned int v18; // r2
  int v19; // r1
  unsigned int v20; // r0
  unsigned int v21; // r2
  int v22; // r0
  unsigned int v23; // r1
  int v24; // r3

  a9 = PiDqSameUserHive(v12 + 16, v13 + 16, &a7);
  if ( a9 >= 0 )
  {
    a11 = a7;
    JUMPOUT(0x6CD188);
  }
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v14 + 308);
  v15 = (unsigned __int8 *)(v12 + 32);
  v16 = KeAbPreAcquire(v12 + 32, 0, 0);
  v17 = v16;
  do
    v18 = __ldrex(v15);
  while ( __strex(v18 | 1, v15) );
  __dmb(0xBu);
  if ( (v18 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v12 + 32), v16, v12 + 32);
  if ( v17 )
    *(_BYTE *)(v17 + 14) |= 1u;
  *(_DWORD *)(v12 + 116) |= 1u;
  PiDqQueryFreeActiveData(v12);
  __pld(v15);
  v19 = *(_DWORD *)v15;
  if ( (*(_DWORD *)v15 & 0xFFFFFFF0) <= 0x10 )
    v20 = 0;
  else
    v20 = v19 - 16;
  if ( (v19 & v11) != 0 )
    goto LABEL_17;
  __dmb(0xBu);
  do
    v21 = __ldrex((unsigned int *)v15);
  while ( v21 == v19 && __strex(v20, (unsigned int *)v15) );
  if ( v21 != v19 )
LABEL_17:
    ExfReleasePushLock((_DWORD *)(v12 + 32), v19);
  v22 = KeAbPostRelease(v12 + 32);
  v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v24 = (__int16)(*(_WORD *)(v23 + 0x134) + 1);
  *(_WORD *)(v23 + 308) = v24;
  if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
    KiCheckForKernelApcDelivery(v22);
  JUMPOUT(0x6CD26A);
}

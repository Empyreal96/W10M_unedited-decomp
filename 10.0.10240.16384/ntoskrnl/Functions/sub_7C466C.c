// sub_7C466C 
 
void sub_7C466C(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r5
  int v5; // r7
  int v6; // r8
  unsigned int v7; // r2
  unsigned __int8 *v8; // r4
  int v9; // r0
  int v10; // r6
  unsigned int v11; // r2
  unsigned int *v12; // r2
  unsigned int v13; // r1
  unsigned int v14; // r1
  int v15; // r1
  unsigned int v16; // r0
  unsigned int v17; // r2
  int v18; // r0
  unsigned int v19; // r1
  int v20; // r3
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v7 + 308);
  v8 = (unsigned __int8 *)(v4 + 8);
  v9 = KeAbPreAcquire(v4 + 8, 0, 0);
  v10 = v9;
  do
    v11 = __ldrex(v8);
  while ( __strex(v11 | 1, v8) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v4 + 8), v9, v4 + 8);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  __dmb(0xBu);
  v12 = (unsigned int *)(v4 + 4);
  do
  {
    v13 = __ldrex(v12);
    v14 = v13 - 1;
  }
  while ( __strex(v14, v12) );
  __dmb(0xBu);
  if ( !v14 && (*(_BYTE *)(v4 + 15) & 8) != 0 )
    *(_DWORD *)(v4 - ObpInfoMaskToOffset[*(_BYTE *)(v4 + 14) & 0x1F]) = 0;
  if ( (*(_BYTE *)(v5 + 42) & 0x10) != 0 )
    ObpReleaseHandleInfo(v4, v6, (int *)va);
  __pld(v8);
  v15 = *(_DWORD *)v8;
  if ( (*(_DWORD *)v8 & 0xFFFFFFF0) <= 0x10 )
    v16 = 0;
  else
    v16 = v15 - 16;
  if ( (v15 & 2) != 0 )
    goto LABEL_22;
  __dmb(0xBu);
  do
    v17 = __ldrex((unsigned int *)v8);
  while ( v17 == v15 && __strex(v16, (unsigned int *)v8) );
  if ( v17 != v15 )
LABEL_22:
    ExfReleasePushLock((_DWORD *)(v4 + 8), v15);
  v18 = KeAbPostRelease(v4 + 8);
  v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v20 = (__int16)(*(_WORD *)(v19 + 0x134) + 1);
  *(_WORD *)(v19 + 308) = v20;
  if ( !v20 && *(_DWORD *)(v19 + 100) != v19 + 100 && !*(_WORD *)(v19 + 310) )
    KiCheckForKernelApcDelivery(v18);
  JUMPOUT(0x6BCB44);
}

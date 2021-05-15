// WdipSemAllocatePool 
 
int __fastcall WdipSemAllocatePool(int a1)
{
  unsigned int v1; // r7
  int v2; // r6
  unsigned int v3; // r2
  int v4; // r5
  int v5; // r1
  int v6; // r2
  int *v7; // r0
  int **v8; // r2
  int v9; // r0
  unsigned int v10; // r5
  int v11; // r0
  unsigned int v12; // r1
  __int16 v13; // r3

  v1 = (a1 + 7) & 0xFFFFFFF8;
  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)&dword_61CAD0, 0, 0);
  do
    v5 = __ldrex((unsigned __int8 *)&dword_61CAD0);
  while ( __strex(v5 | 1, (unsigned __int8 *)&dword_61CAD0) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_61CAD0, v4, (unsigned int)&dword_61CAD0);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  v6 = dword_61CAC8;
  if ( v1 <= dword_61CAC8 )
  {
    v2 = dword_61CACC;
  }
  else
  {
    v7 = (int *)ExAllocatePoolWithTag(1, 4096, 1934181463);
    if ( !v7 )
      goto LABEL_14;
    v8 = (int **)dword_61CAC4;
    *v7 = (int)&WdipSemPool;
    v7[1] = (int)v8;
    if ( *v8 != &WdipSemPool )
      __fastfail(3u);
    *v8 = v7;
    dword_61CAC4 = (int)v7;
    v6 = 4088;
    v2 = (int)(v7 + 2);
  }
  dword_61CACC = v2 + v1;
  dword_61CAC8 = v6 - v1;
LABEL_14:
  __pld(&dword_61CAD0);
  v9 = dword_61CAD0;
  v10 = dword_61CAD0 - 16;
  if ( (dword_61CAD0 & 0xFFFFFFF0) <= 0x10 )
    v10 = 0;
  if ( (dword_61CAD0 & 2) != 0 )
    goto LABEL_21;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&dword_61CAD0);
  while ( v5 == v9 && __strex(v10, (unsigned int *)&dword_61CAD0) );
  if ( v5 != v9 )
LABEL_21:
    ExfReleasePushLock(&dword_61CAD0, v5);
  v11 = KeAbPostRelease((unsigned int)&dword_61CAD0);
  v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *(_WORD *)(v12 + 0x134) + 1;
  *(_WORD *)(v12 + 308) = v13;
  if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
    KiCheckForKernelApcDelivery(v11);
  return v2;
}

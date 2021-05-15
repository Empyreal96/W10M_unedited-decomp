// WdipSemDeleteTransitionalInstance 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall WdipSemDeleteTransitionalInstance(int a1)
{
  unsigned int v2; // r2
  int v3; // r5
  unsigned int v4; // r1
  int v5; // r1 OVERLAPPED
  int *v6; // r2 OVERLAPPED
  int v7; // r0
  unsigned int v8; // r5
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v2 + 308);
  v3 = KeAbPreAcquire((unsigned int)&dword_61B74C, 0, 0);
  do
    v4 = __ldrex((unsigned __int8 *)&dword_61B74C);
  while ( __strex(v4 | 1, (unsigned __int8 *)&dword_61B74C) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_61B74C, v3, (unsigned int)&dword_61B74C);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  *(_QWORD *)&v5 = *(_QWORD *)a1;
  if ( *(_DWORD *)(*(_DWORD *)a1 + 4) != a1 || *v6 != a1 )
    __fastfail(3u);
  *v6 = v5;
  *(_DWORD *)(v5 + 4) = v6;
  --dword_61B748;
  __pld(&dword_61B74C);
  v7 = dword_61B74C;
  v8 = dword_61B74C - 16;
  if ( (dword_61B74C & 0xFFFFFFF0) <= 0x10 )
    v8 = 0;
  if ( (dword_61B74C & 2) != 0 )
    goto LABEL_16;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&dword_61B74C);
  while ( v5 == v7 && __strex(v8, (unsigned int *)&dword_61B74C) );
  if ( v5 != v7 )
LABEL_16:
    ExfReleasePushLock(&dword_61B74C, v5);
  v9 = KeAbPostRelease((unsigned int)&dword_61B74C);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v9);
  return WdipSemFastFree(3, a1);
}

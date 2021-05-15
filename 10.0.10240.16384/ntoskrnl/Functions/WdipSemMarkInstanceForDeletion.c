// WdipSemMarkInstanceForDeletion 
 
int __fastcall WdipSemMarkInstanceForDeletion(int a1)
{
  int v2; // r5
  unsigned int v3; // r2
  int v4; // r6
  int v5; // r1
  int v6; // r0
  int v7; // r0
  unsigned int v8; // r6
  int v9; // r0
  unsigned int v10; // r1
  __int16 v11; // r3

  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)&dword_61B74C, 0, 0);
  do
    v5 = __ldrex((unsigned __int8 *)&dword_61B74C);
  while ( __strex(v5 | 1, (unsigned __int8 *)&dword_61B74C) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_61B74C, v4, (unsigned int)&dword_61B74C);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  if ( a1 )
  {
    v6 = WdipSemQueryEnabledInstanceTable(a1);
    v2 = v6;
    if ( v6 )
    {
      if ( *(_DWORD *)(v6 + 32) )
        v2 = 0;
      else
        *(_DWORD *)(v6 + 32) = 1;
    }
  }
  __pld(&dword_61B74C);
  v7 = dword_61B74C;
  v8 = dword_61B74C - 16;
  if ( (dword_61B74C & 0xFFFFFFF0) <= 0x10 )
    v8 = 0;
  if ( (dword_61B74C & 2) != 0 )
    goto LABEL_19;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&dword_61B74C);
  while ( v5 == v7 && __strex(v8, (unsigned int *)&dword_61B74C) );
  if ( v5 != v7 )
LABEL_19:
    ExfReleasePushLock(&dword_61B74C, v5);
  v9 = KeAbPostRelease((unsigned int)&dword_61B74C);
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v11 = *(_WORD *)(v10 + 0x134) + 1;
  *(_WORD *)(v10 + 308) = v11;
  if ( !v11 && *(_DWORD *)(v10 + 100) != v10 + 100 && !*(_WORD *)(v10 + 310) )
    KiCheckForKernelApcDelivery(v9);
  return v2;
}

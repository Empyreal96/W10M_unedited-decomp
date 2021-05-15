// WdipSemMarkNextTimedOutInstanceForDeletion 
 
_DWORD *__fastcall WdipSemMarkNextTimedOutInstanceForDeletion(unsigned int *a1)
{
  _DWORD *v2; // r7
  unsigned int v3; // r2
  int v4; // r5
  unsigned int v5; // r1
  _DWORD *v6; // r2
  unsigned int v7; // r3
  int v8; // r0
  unsigned int v9; // r5
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3

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
    v5 = *a1;
    while ( (int *)v5 != &WdipSemEnabledInstanceTable )
    {
      v6 = (_DWORD *)v5;
      v7 = *(_DWORD *)(v5 + 28);
      v5 = *(_DWORD *)v5;
      v6[7] = ++v7;
      if ( v7 >= 0xA && *(_BYTE *)(v6[6] + 616) && !v6[8] )
      {
        v6[8] = 1;
        v2 = v6;
        break;
      }
    }
  }
  __pld(&dword_61B74C);
  v8 = dword_61B74C;
  v9 = dword_61B74C - 16;
  if ( (dword_61B74C & 0xFFFFFFF0) <= 0x10 )
    v9 = 0;
  if ( (dword_61B74C & 2) != 0 )
    goto LABEL_22;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&dword_61B74C);
  while ( v5 == v8 && __strex(v9, (unsigned int *)&dword_61B74C) );
  if ( v5 != v8 )
LABEL_22:
    ExfReleasePushLock(&dword_61B74C, v5);
  v10 = KeAbPostRelease((unsigned int)&dword_61B74C);
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
    KiCheckForKernelApcDelivery(v10);
  return v2;
}

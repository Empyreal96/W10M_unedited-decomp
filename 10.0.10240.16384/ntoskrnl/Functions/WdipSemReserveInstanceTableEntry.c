// WdipSemReserveInstanceTableEntry 
 
int *__fastcall WdipSemReserveInstanceTableEntry(int a1, _DWORD *a2)
{
  int *v4; // r6
  unsigned int v5; // r2
  int v6; // r1
  int v7; // r7
  unsigned int v8; // r4
  int *v9; // r0
  int **v10; // r2
  int v11; // r0
  unsigned int v12; // r4
  int v13; // r0
  unsigned int v14; // r1
  __int16 v15; // r3

  v4 = 0;
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v5 + 308);
  v7 = KeAbPreAcquire((unsigned int)&dword_61B74C, 0, 0);
  do
    v8 = __ldrex((unsigned __int8 *)&dword_61B74C);
  while ( __strex(v8 | 1, (unsigned __int8 *)&dword_61B74C) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_61B74C, v7, (unsigned int)&dword_61B74C);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  if ( a1 && a2 )
  {
    if ( (unsigned int)dword_61B748 < 0x80 )
    {
      if ( WdipSemQueryEnabledInstanceTable((unsigned int)a2) )
      {
        v4 = 0;
      }
      else
      {
        v9 = WdipSemBuildScenarioInstance(a1, a2);
        v4 = v9;
        if ( v9 )
        {
          v10 = (int **)dword_61B744;
          *v9 = (int)&WdipSemEnabledInstanceTable;
          v9[1] = (int)v10;
          if ( *v10 != &WdipSemEnabledInstanceTable )
            __fastfail(3u);
          *v10 = v9;
          dword_61B744 = (int)v9;
          ++dword_61B748;
        }
      }
    }
    else
    {
      WdipSemLogInflightLimitExceededInformation(a1, *(unsigned __int16 *)(a1 + 16), (int)a2);
    }
  }
  __pld(&dword_61B74C);
  v11 = dword_61B74C;
  v12 = dword_61B74C - 16;
  if ( (dword_61B74C & 0xFFFFFFF0) <= 0x10 )
    v12 = 0;
  if ( (dword_61B74C & 2) != 0 )
    goto LABEL_24;
  __dmb(0xBu);
  do
    v6 = __ldrex((unsigned int *)&dword_61B74C);
  while ( v6 == v11 && __strex(v12, (unsigned int *)&dword_61B74C) );
  if ( v6 != v11 )
LABEL_24:
    ExfReleasePushLock(&dword_61B74C, v6);
  v13 = KeAbPostRelease((unsigned int)&dword_61B74C);
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v15 = *(_WORD *)(v14 + 0x134) + 1;
  *(_WORD *)(v14 + 308) = v15;
  if ( !v15 && *(_DWORD *)(v14 + 100) != v14 + 100 && !*(_WORD *)(v14 + 310) )
    KiCheckForKernelApcDelivery(v13);
  return v4;
}

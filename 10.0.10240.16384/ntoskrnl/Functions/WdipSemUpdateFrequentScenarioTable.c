// WdipSemUpdateFrequentScenarioTable 
 
int __fastcall WdipSemUpdateFrequentScenarioTable(int *a1)
{
  int v2; // r7
  unsigned int v3; // r2
  int v4; // r4
  int v5; // r1
  _DWORD *v6; // lr
  int v7; // r0
  int v8; // r2
  int v9; // r3
  _DWORD *v10; // r8
  int v11; // r3
  int v12; // r0
  unsigned int v13; // r4
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3

  v2 = 0;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v3 + 308);
  v4 = KeAbPreAcquire((unsigned int)&dword_61CAA4, 0, 0);
  do
    v5 = __ldrex((unsigned __int8 *)&dword_61CAA4);
  while ( __strex(v5 | 1, (unsigned __int8 *)&dword_61CAA4) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&dword_61CAA4, v4, (unsigned int)&dword_61CAA4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  if ( a1 )
  {
    if ( (unsigned int)dword_61CAA0 < 0x80 )
    {
      v6 = (_DWORD *)WdipSemFastAllocate(5, 24);
      if ( v6 )
      {
        v7 = *a1;
        v5 = a1[1];
        v8 = a1[2];
        v9 = a1[3];
        v10 = a1 + 4;
        *v6 = v7;
        v6[1] = v5;
        v6[2] = v8;
        v6[3] = v9;
        v11 = v10[1];
        v6[4] = *v10;
        v6[5] = v11;
        WdipSemFrequentScenarioTable[dword_61CAA0++] = (int)v6;
      }
      else
      {
        v2 = -1073741670;
      }
    }
    else
    {
      v2 = -1073741823;
    }
  }
  else
  {
    v2 = -1073741811;
  }
  __pld(&dword_61CAA4);
  v12 = dword_61CAA4;
  v13 = dword_61CAA4 - 16;
  if ( (dword_61CAA4 & 0xFFFFFFF0) <= 0x10 )
    v13 = 0;
  if ( (dword_61CAA4 & 2) != 0 )
    goto LABEL_21;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&dword_61CAA4);
  while ( v5 == v12 && __strex(v13, (unsigned int *)&dword_61CAA4) );
  if ( v5 != v12 )
LABEL_21:
    ExfReleasePushLock(&dword_61CAA4, v5);
  v14 = KeAbPostRelease((unsigned int)&dword_61CAA4);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v16 = *(_WORD *)(v15 + 0x134) + 1;
  *(_WORD *)(v15 + 308) = v16;
  if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
    KiCheckForKernelApcDelivery(v14);
  return v2;
}

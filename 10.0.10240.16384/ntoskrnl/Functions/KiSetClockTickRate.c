// KiSetClockTickRate 
 
int __fastcall KiSetClockTickRate(unsigned int a1)
{
  int v2; // r5
  int v3; // r0
  int result; // r0
  unsigned int v5; // r6
  unsigned int v6; // lr
  _DWORD *v7; // r4
  int v8; // r3
  unsigned int v9; // [sp+8h] [bp-28h] BYREF
  int v10; // [sp+Ch] [bp-24h]
  int v11[8]; // [sp+10h] [bp-20h] BYREF

  v2 = KiClockState;
  KiLastRequestedTimeIncrement = a1;
  v9 = a1;
  v10 = 0;
  off_617AF0(0);
  v3 = KiSetPendingTick(1);
  if ( v2 == 2 )
    return sub_552B10(v3);
  KiEventClockStateChange(0, v2, v11, &v9);
  KeTimeIncrement = v11[0];
  while ( 1 )
  {
    v5 = MEMORY[0xFFFF900C];
    __dmb(0xBu);
    v6 = MEMORY[0xFFFF9008];
    __dmb(0xBu);
    if ( v5 == MEMORY[0xFFFF9010] )
      break;
    __dmb(0xAu);
    __yield();
  }
  KiClockTimerNextTickTime = __PAIR64__(v5, KeTimeIncrement) + v6;
  if ( KeTimeIncrement < (unsigned int)dword_624FD4 )
    dword_624FD4 = KeTimeIncrement;
  if ( KeTimeIncrement > (unsigned int)dword_624FD0 )
    dword_624FD0 = KeTimeIncrement;
  if ( a1 < dword_624FDC )
    dword_624FDC = a1;
  if ( a1 > dword_624FD8 )
    dword_624FD8 = a1;
  v7 = (_DWORD *)((char *)&KiClockIncrementTrace + 24 * KiClockIncrementTraceCount);
  KiClockIncrementTraceCount = ((_BYTE)KiClockIncrementTraceCount + 1) & 0xF;
  v8 = KiLastRequestedTimeIncrement;
  *v7 = KeTimeIncrement;
  v7[1] = v8;
  v7[2] = v6;
  v7[3] = v5;
  KeQueryPerformanceCounter(&v9, 0);
  result = KeTimeIncrement;
  v7[4] = v9;
  v7[5] = v10;
  return result;
}

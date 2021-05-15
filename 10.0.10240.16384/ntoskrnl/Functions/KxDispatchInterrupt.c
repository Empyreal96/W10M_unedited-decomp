// KxDispatchInterrupt 
 
int KxDispatchInterrupt()
{
  int v0; // r4
  unsigned int v1; // r5
  unsigned __int64 *v2; // r2
  unsigned __int64 v3; // kr00_8
  unsigned __int64 v4; // r0
  __int64 v5; // r2
  __int64 v6; // r0
  unsigned __int64 *v7; // r7
  unsigned __int64 v8; // r2
  int *v9; // r7
  int v10; // r2
  unsigned int v11; // r1
  int v12; // r6

  v0 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  v1 = *(_DWORD *)(v0 + 4);
  __disable_irq();
  ++*(_BYTE *)(v0 + 16);
  v2 = (unsigned __int64 *)(v0 + 2416);
  do
  {
    v3 = __ldrexd(v2);
    v4 = __PAIR64__(HIDWORD(v3), __mrc(15, 0, 9, 13, 0));
    if ( ((v3 ^ v4) & 0x80000000) != 0i64 )
      HIDWORD(v4) = HIDWORD(v3) + ((unsigned int)v3 >> 31);
  }
  while ( __strexd(v4, v2) );
  v5 = *(_QWORD *)(v0 + 2376);
  *(_QWORD *)(v0 + 2376) = v4;
  v6 = v4 - v5;
  v7 = (unsigned __int64 *)(v1 + 48);
  do
    v8 = __ldrexd(v7);
  while ( __strexd(v8 + v6, v7) == 1 );
  v9 = (int *)(v1 + 56);
  if ( HIDWORD(v6) || (v10 = *v9 + v6, __CFADD__(*v9, (_DWORD)v6)) )
    v10 = -1;
  *v9 = v10;
  if ( (*(_BYTE *)(v1 + 2) & 0x3E) != 0 )
    KiEndThreadAccountingPeriod(v0, v1, v6, HIDWORD(v6));
  __enable_irq();
  KiAbProcessContextSwitch(v1, 0);
  __dmb(0xFu);
  while ( 1 )
  {
    do
      v11 = __ldrex((unsigned int *)v0);
    while ( __strex(1u, (unsigned int *)(v0 + 24)) == 1 );
    if ( !v11 )
      break;
    __yield();
  }
  __dmb(0xFu);
  v12 = *(_DWORD *)(v0 + 8);
  *(_DWORD *)(v0 + 8) = 0;
  *(_DWORD *)(v0 + 4) = v12;
  *(_BYTE *)(v12 + 132) = 2;
  *(_BYTE *)(v1 + 395) = 31;
  KiQueueReadyThread(v0, v1);
  return SwapContext(v1, v12, 1, v0);
}

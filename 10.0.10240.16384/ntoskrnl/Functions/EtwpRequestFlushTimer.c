// EtwpRequestFlushTimer 
 
int __fastcall EtwpRequestFlushTimer(int a1, int a2)
{
  int v2; // r3
  BOOL v4; // r0
  unsigned __int8 *v6; // r3
  unsigned int v7; // r1
  __int64 v8; // r0
  unsigned int v9; // r3
  unsigned __int8 *v10; // r3
  unsigned int v11; // r1

  v2 = *(_DWORD *)(a1 + 612);
  __dmb(0xBu);
  if ( (v2 & 0x400) == 0 )
  {
    if ( a2 )
      goto LABEL_16;
    v4 = KeAreInterruptsEnabled();
    if ( !v4 )
      return sub_54CB48();
    if ( (unsigned int)KeGetCurrentIrql(v4) > 2 )
    {
LABEL_16:
      __dmb(0xBu);
      v10 = (unsigned __int8 *)(a1 + 613);
      do
        v11 = __ldrex(v10);
      while ( __strex(v11 | 2, v10) );
      __dmb(0xBu);
      if ( !((unsigned __int8)(v11 & 2) >> 1) )
      {
        *(_WORD *)(a1 + 442) = KiClockTimerOwner + 32;
        KiInsertQueueDpc(a1 + 440, 0, 0, 0, 0);
      }
      return 1;
    }
    __dmb(0xBu);
    v6 = (unsigned __int8 *)(a1 + 613);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 | 4, v6) );
    __dmb(0xBu);
    if ( !((unsigned __int8)(v7 & 4) >> 2) )
    {
      HIDWORD(v8) = *(_DWORD *)(a1 + 132);
      if ( (*(_DWORD *)(a1 + 12) & 0x10) == 0 )
        HIDWORD(v8) *= 1000;
      v9 = HIDWORD(v8) >> 2;
      if ( HIDWORD(v8) >> 2 >= 0x1F4 )
        v9 = 500;
      LODWORD(v8) = a1 + 392;
      KeSetCoalescableTimer(v8, *(_QWORD *)EtwpOneMs * HIDWORD(v8), 0, v9, 0);
      return 1;
    }
  }
  return 0;
}

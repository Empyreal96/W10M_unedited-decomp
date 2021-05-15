// KeFlushTb 
 
int __fastcall KeFlushTb(int result, int a2)
{
  int v2; // r6
  int v3; // r1
  int v4; // r8
  unsigned int v5; // lr
  void **v6; // r4
  int v7; // r2
  int v8; // r1
  int v9; // t1
  int v10; // r4

  v2 = result;
  if ( result != 3 && result && result == 1 )
  {
    __dsb(0xFu);
    if ( KiTbDisableProcessByAsidBroadcast )
      return sub_50DB2C();
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v3 = 0;
    }
    else
    {
      __disable_irq();
      v3 = 1;
    }
    __mcr(15, 0, (unsigned __int8)__mrc(15, 0, 13, 0, 1), 8, 3, 2);
    if ( v3 )
      __enable_irq();
    __dsb(0xFu);
    __isb(0xFu);
    if ( KiTbSendIpiForBroadcastFlushes )
    {
      __mcr(15, 0, 0, 8, 3, 1);
      __dsb(0xFu);
      result = KfRaiseIrql(12);
      v4 = result;
      v5 = (unsigned int)KeGetPcr() & 0xFFFFF000;
      v6 = &KeNodeBlock;
      if ( !KeNodeBlock )
        goto LABEL_23;
      v7 = (unsigned __int16)KeNumberNodes;
      v8 = 0;
      if ( KeNumberNodes )
      {
        do
        {
          v9 = (int)*v6++;
          v8 |= *(_DWORD *)(v9 + 128);
          --v7;
        }
        while ( v7 );
      }
      if ( (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v5 + 1412) + 116) + 96) & ~v8) != 0 )
      {
LABEL_23:
        KiIpiSendRequestEx(v5 + 1408);
        result = KfLowerIrql(v4);
      }
    }
  }
  else
  {
    result = KxFlushEntireTb(a2);
  }
  if ( VmTbFlushEnabled )
    result = VmFlushTb(0, 0);
  if ( ExTbFlushActive )
  {
    v10 = KfRaiseIrql(15);
    ExFlushTb(0, 0, v2);
    result = KfLowerIrql(v10);
  }
  return result;
}

// KeFlushSingleTb 
 
int __fastcall KeFlushSingleTb(int result, int a2)
{
  int v3; // r6
  int v4; // r1
  unsigned int v5; // r2
  unsigned int v6; // r2
  unsigned int v7; // r2
  int v8; // r1
  int v9; // r8
  unsigned int v10; // lr
  int v11; // r2
  int v12; // r3
  void **v13; // r2
  int v14; // r1
  int v15; // t1
  int v16; // r2
  int v17; // r4
  int v18[2]; // [sp+Ch] [bp-30h] BYREF
  int v19; // [sp+14h] [bp-28h]
  int v20; // [sp+18h] [bp-24h]
  int v21; // [sp+1Ch] [bp-20h]

  v3 = result;
  __dsb(0xFu);
  if ( a2 )
  {
    __mcr(15, 0, result & 0xFFFFF000, 8, 3, 3);
    if ( (result & 0xFFFFF000) >= 0xC0000000 && (result & 0xFFFFF000) <= 0xC03FFFFF )
      return sub_509D7C();
  }
  else if ( KiTbDisableSingleByAsidBroadcast )
  {
    __mcr(15, 0, result & 0xFFFFF000, 8, 3, 3);
    if ( (result & 0xFFFFF000) + 0x40000000 <= 0x3FFFFF )
    {
      v7 = (result & 0xFFFFF000) << 10;
      v8 = 4;
      do
      {
        __mcr(15, 0, v7, 8, 3, 3);
        v7 += 0x100000;
        --v8;
      }
      while ( v8 );
    }
  }
  else
  {
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v4 = 0;
    }
    else
    {
      __disable_irq();
      v4 = 1;
    }
    result = (unsigned __int8)__mrc(15, 0, 13, 0, 1);
    v5 = v3 & 0xFFFFF000 | result;
    __mcr(15, 0, v5, 8, 3, 1);
    if ( v5 >= 0xC0000000 && v5 <= 0xC03FFFFF )
    {
      v6 = result | ((v5 & 0xFFFFF000) << 10);
      result = 4;
      do
      {
        __mcr(15, 0, v6, 8, 3, 1);
        v6 += 0x100000;
        --result;
      }
      while ( result );
    }
    if ( v4 )
      __enable_irq();
  }
  __dsb(0xFu);
  __isb(0xFu);
  if ( KiTbSendIpiForBroadcastFlushes )
  {
    __mcr(15, 0, 0, 8, 3, 1);
    __dsb(0xFu);
    v9 = KfRaiseIrql(12);
    v10 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    if ( a2 )
    {
      v19 = *(_DWORD *)&KeActiveProcessors;
      v20 = dword_681D74;
      v21 = dword_681D78;
    }
    else
    {
      v11 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v10 + 1412) + 116) + 92);
      v12 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v10 + 1412) + 116) + 96);
      v19 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v10 + 1412) + 116) + 88);
      v20 = v11;
      v21 = v12;
    }
    v13 = &KeNodeBlock;
    if ( KeNodeBlock )
    {
      v14 = (unsigned __int16)KeNumberNodes;
      result = 0;
      if ( KeNumberNodes )
      {
        do
        {
          v15 = (int)*v13++;
          result |= *(_DWORD *)(v15 + 128);
          --v14;
        }
        while ( v14 );
      }
      v16 = v21 & ~result;
      v19 = 65537;
      v20 = 0;
      if ( !v16 )
        goto LABEL_4;
    }
    else
    {
      v16 = v21;
    }
    v21 = v16 & ~(1 << *(_DWORD *)(v10 + 1428));
    KiIpiSendRequestEx(v10 + 1408);
    result = KfLowerIrql(v9);
  }
LABEL_4:
  if ( VmTbFlushEnabled )
  {
    v18[0] = v3 & 0xFFFFF000 | 1;
    result = VmFlushTb(1, v18);
  }
  if ( ExTbFlushActive )
  {
    v18[0] = v3 & 0xFFFFF000 | 1;
    v17 = KfRaiseIrql(15);
    ExFlushTb(1, v18, 0);
    result = KfLowerIrql(v17);
  }
  return result;
}

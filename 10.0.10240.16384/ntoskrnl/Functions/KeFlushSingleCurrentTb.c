// KeFlushSingleCurrentTb 
 
int __fastcall KeFlushSingleCurrentTb(int result, int a2, int a3, unsigned int a4)
{
  unsigned int v4; // r3
  int v5; // r2
  int v6; // r4
  unsigned int v7; // [sp+0h] [bp-8h] BYREF

  v7 = a4;
  __dsb(0xFu);
  __mcr(15, 0, result & 0xFFFFF000, 8, 7, 3);
  if ( (result & 0xFFFFF000) + 0x40000000 <= 0x3FFFFF )
  {
    v4 = (result & 0xFFFFF000) << 10;
    v5 = 4;
    do
    {
      __mcr(15, 0, v4, 8, 7, 3);
      v4 += 0x100000;
      --v5;
    }
    while ( v5 );
  }
  __dsb(0xFu);
  __isb(0xFu);
  if ( VmTbFlushEnabled )
    return sub_5210D4();
  if ( ExTbFlushActive )
  {
    v7 = result & 0xFFFFF000 | 1;
    v6 = KfRaiseIrql(15);
    ExFlushTb(1, &v7, 0);
    result = KfLowerIrql(v6);
  }
  return result;
}

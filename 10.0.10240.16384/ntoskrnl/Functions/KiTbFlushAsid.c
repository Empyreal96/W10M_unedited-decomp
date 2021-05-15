// KiTbFlushAsid 
 
unsigned int __fastcall KiTbFlushAsid(unsigned int result)
{
  unsigned int v1; // r7
  unsigned int v2; // r6
  void **v3; // r4
  int v4; // r2
  int v5; // r1
  int v6; // t1

  __dsb(0xFu);
  if ( KiTbDisableProcessByAsidBroadcast )
    return sub_50A02C();
  __mcr(15, 0, result, 8, 3, 2);
  __dsb(0xFu);
  __isb(0xFu);
  if ( KiTbSendIpiForBroadcastFlushes )
  {
    __mcr(15, 0, 0, 8, 3, 1);
    __dsb(0xFu);
    result = KfRaiseIrql(12);
    v1 = result;
    v2 = (unsigned int)KeGetPcr() & 0xFFFFF000;
    v3 = &KeNodeBlock;
    if ( !KeNodeBlock )
      goto LABEL_9;
    v4 = (unsigned __int16)KeNumberNodes;
    v5 = 0;
    if ( KeNumberNodes )
    {
      do
      {
        v6 = (int)*v3++;
        v5 |= *(_DWORD *)(v6 + 128);
        --v4;
      }
      while ( v4 );
    }
    if ( (dword_681D78 & ~v5) != 0 )
    {
LABEL_9:
      KiIpiSendRequestEx(v2 + 1408);
      result = KfLowerIrql(v1);
    }
  }
  return result;
}

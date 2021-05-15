// KiTbInitialize 
 
unsigned int *__fastcall KiTbInitialize(int a1, int a2)
{
  unsigned int v4; // r2
  unsigned int v5; // r4
  int v6; // r1

  if ( a1 )
    return KiAsidInitialize(a1, a2);
  v4 = __mrc(15, 0, 0, 0, 0);
  v5 = HIBYTE(v4);
  if ( HIBYTE(v4) != 81 )
  {
    v6 = (unsigned __int16)v4 >> 4;
    if ( v6 == 3081 && v5 == 65 && (v4 & 0xF00000) < 0x200000 )
    {
      KiTbDisableSingleByAsidBroadcast = 1;
      KiTbDisableProcessByAsidBroadcast = 1;
    }
    if ( v6 == 3087 && v5 == 65 && (v4 & 0xF00000) < 0x400000 )
    {
      KiTbIpiTypeToSendForBroadcast = 8;
      KiTbSendIpiForBroadcastFlushes = 1;
    }
    return KiAsidInitialize(a1, a2);
  }
  return (unsigned int *)sub_69417C();
}

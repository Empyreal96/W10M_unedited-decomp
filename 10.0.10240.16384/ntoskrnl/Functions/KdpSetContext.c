// KdpSetContext 
 
int __fastcall KdpSetContext(int a1, int a2, int *a3)
{
  unsigned int v4; // r3
  unsigned __int16 v7; // r0
  int v8; // r2
  _BYTE *v9; // r1
  int v10; // r4

  v4 = *(unsigned __int16 *)(a1 + 6);
  if ( v4 < 0x20 && *(&KiProcessorBlock + v4) && KdpContextSent )
  {
    *(_DWORD *)(a1 + 8) = 0;
    v7 = KeGetCurrentProcessorNumberEx(0);
    v8 = *(unsigned __int16 *)(a1 + 6);
    if ( v8 != v7 )
      a3 = (int *)*((_DWORD *)*(&KiProcessorBlock + v8) + 326);
    v9 = *(_BYTE **)(a2 + 4);
    v10 = *(_DWORD *)v9 & 0x20000F;
    KdpQuickMoveMemory((int)a3, v9, 416);
    *a3 = v10;
  }
  else
  {
    *(_DWORD *)(a1 + 8) = -1073741823;
  }
  return KdSendPacket_0();
}

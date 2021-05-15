// KdpWriteCustomBreakpoint 
 
int __fastcall KdpWriteCustomBreakpoint(int a1, int a2)
{
  int v3; // r0
  int v4; // r3

  v3 = KdpAddBreakpoint(
         *(_DWORD *)(a1 + 16),
         a2,
         *(_DWORD *)(a1 + 24),
         *(_DWORD *)(a1 + 28),
         *(unsigned __int8 *)(a1 + 36),
         *(unsigned __int8 *)(a1 + 37),
         56,
         a1);
  *(_DWORD *)(a1 + 32) = v3;
  if ( v3 )
    v4 = 0;
  else
    v4 = -1073741823;
  *(_DWORD *)(a1 + 8) = v4;
  return KdSendPacket_0();
}

// KdpWriteBreakpoint 
 
int __fastcall KdpWriteBreakpoint(_DWORD *a1, int a2)
{
  int v3; // r0
  int v4; // r3

  v3 = KdpAddBreakpoint(a1[4], a2, 57086, 0, 2, 1, 56, a1);
  a1[6] = v3;
  if ( v3 )
    v4 = 0;
  else
    v4 = -1073741823;
  a1[2] = v4;
  return KdSendPacket_0();
}

// KdpReadControlSpace 
 
int __fastcall KdpReadControlSpace(int a1, int a2)
{
  int v4; // r2
  int v5; // r0
  int v6; // r3
  int v8; // [sp+10h] [bp-18h] BYREF
  __int16 v9; // [sp+18h] [bp-10h]
  int v10; // [sp+1Ch] [bp-Ch]

  v9 = 56;
  v10 = a1;
  v4 = KdTransportMaxPacketSize - 56;
  if ( *(_DWORD *)(a1 + 24) > (unsigned int)(KdTransportMaxPacketSize - 56) )
  {
    v8 = KdTransportMaxPacketSize - 56;
  }
  else
  {
    v4 = *(_DWORD *)(a1 + 24);
    v8 = v4;
  }
  v5 = KdpSysReadControlSpace(
         *(unsigned __int16 *)(a1 + 6),
         a2,
         *(_DWORD *)(a1 + 16),
         *(_DWORD *)(a1 + 20),
         *(_DWORD *)(a2 + 4),
         v4,
         &v8);
  v6 = v8;
  *(_DWORD *)(a1 + 8) = v5;
  *(_WORD *)a2 = v6;
  *(_DWORD *)(a1 + 28) = v6;
  return KdSendPacket_0();
}

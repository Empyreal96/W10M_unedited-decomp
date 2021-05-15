// KdpReadVirtualMemory 
 
int __fastcall KdpReadVirtualMemory(_DWORD *a1, int a2)
{
  unsigned int v3; // r4
  int v5; // r0
  int v6; // r3
  int v8; // [sp+10h] [bp-20h] BYREF
  __int16 v9; // [sp+18h] [bp-18h]
  _DWORD *v10; // [sp+1Ch] [bp-14h]

  v3 = a1[6];
  v8 = v3;
  if ( v3 > KdTransportMaxPacketSize - 56 )
  {
    v3 = KdTransportMaxPacketSize - 56;
    v8 = KdTransportMaxPacketSize - 56;
  }
  if ( v3 > *(unsigned __int16 *)(a2 + 2) )
  {
    v3 = *(unsigned __int16 *)(a2 + 2);
    v8 = v3;
  }
  v5 = KdpCopyMemoryChunks(a1[4], a1[5], *(_DWORD *)(a2 + 4), v3, 0, 4, &v8);
  v6 = v8;
  a1[2] = v5;
  *(_WORD *)a2 = v6;
  a1[7] = v6;
  v9 = 56;
  v10 = a1;
  return KdSendPacket_0();
}

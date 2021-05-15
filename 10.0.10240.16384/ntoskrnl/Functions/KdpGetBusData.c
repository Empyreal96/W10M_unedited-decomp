// KdpGetBusData 
 
int __fastcall KdpGetBusData(_DWORD *a1, int a2)
{
  int v4; // r2
  int v5; // r0
  int v6; // r3
  int v8; // [sp+10h] [bp-18h] BYREF
  __int16 v9; // [sp+18h] [bp-10h]
  _DWORD *v10; // [sp+1Ch] [bp-Ch]

  v9 = 56;
  v10 = a1;
  v4 = KdTransportMaxPacketSize - 56;
  if ( a1[8] <= (unsigned int)(KdTransportMaxPacketSize - 56) )
  {
    v4 = a1[8];
    v8 = v4;
  }
  else
  {
    v8 = KdTransportMaxPacketSize - 56;
  }
  v5 = KdpSysReadBusData(a1[4], a1[5], a1[6], a1[7], *(_DWORD *)(a2 + 4), v4, &v8);
  v6 = v8;
  a1[2] = v5;
  a1[8] = v6;
  *(_WORD *)a2 = v6;
  return KdSendPacket_0();
}

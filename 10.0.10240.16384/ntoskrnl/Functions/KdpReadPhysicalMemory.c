// KdpReadPhysicalMemory 
 
int __fastcall KdpReadPhysicalMemory(_DWORD *a1, int a2)
{
  unsigned int v4; // r4
  unsigned int v5; // r2
  int v6; // r3
  char v7; // r1
  unsigned int v8; // r0
  int v10; // r0
  unsigned int v11; // r4
  int v12; // [sp+10h] [bp-28h] BYREF
  __int16 v13; // [sp+18h] [bp-20h]
  _DWORD *v14; // [sp+1Ch] [bp-1Ch]

  v4 = KdTransportMaxPacketSize - 56;
  v5 = a1[6];
  v13 = 56;
  v14 = a1;
  if ( v5 > KdTransportMaxPacketSize - 56 )
  {
    v12 = KdTransportMaxPacketSize - 56;
  }
  else
  {
    v4 = v5;
    v12 = v5;
  }
  v6 = a1[7];
  v7 = 6;
  switch ( v6 )
  {
    case 1:
      v7 = 14;
      break;
    case 2:
      v7 = 22;
      break;
    case 3:
      v7 = 38;
      break;
  }
  v8 = a1[4];
  if ( *a1 == 12642 )
    return sub_903FB4(v8);
  v10 = KdpCopyMemoryChunks(v8, a1[5], *(_DWORD *)(a2 + 4), v4, 0, v7, &v12);
  v11 = v12;
  a1[2] = v10;
  a1[7] = v11;
  if ( *a1 == 12642 )
  {
    if ( RunLengthEncode(*(_DWORD **)(a2 + 4), v11) )
    {
      a1[7] = (v11 >> 2) | 0x40000000;
      LOWORD(v11) = 4;
    }
  }
  *(_WORD *)a2 = v11;
  return KdSendPacket_0();
}

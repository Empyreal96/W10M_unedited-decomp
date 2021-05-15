// KdpWritePhysicalMemory 
 
int __fastcall KdpWritePhysicalMemory(_DWORD *a1, int a2)
{
  int v2; // r3
  char v3; // r2

  v2 = a1[7];
  v3 = 7;
  switch ( v2 )
  {
    case 1:
      v3 = 15;
      break;
    case 2:
      v3 = 23;
      break;
    case 3:
      v3 = 39;
      break;
  }
  a1[2] = KdpCopyMemoryChunks(a1[4], a1[5], *(_DWORD *)(a2 + 4), a1[6], 0, v3, a1 + 7);
  return KdSendPacket_0();
}

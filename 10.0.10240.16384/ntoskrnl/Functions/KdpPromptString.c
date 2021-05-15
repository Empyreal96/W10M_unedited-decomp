// KdpPromptString 
 
int __fastcall KdpPromptString(unsigned __int16 *a1, int a2)
{
  __int16 v3; // r0
  int v4; // r3
  int v5; // r0
  unsigned int v6; // r3
  int result; // r0
  int v8[2]; // [sp+10h] [bp-40h] BYREF
  __int16 v9; // [sp+18h] [bp-38h]
  __int16 v10; // [sp+1Ah] [bp-36h]
  void *v11; // [sp+1Ch] [bp-34h]
  __int16 v12; // [sp+20h] [bp-30h]
  __int16 v13; // [sp+22h] [bp-2Eh]
  int *v14; // [sp+24h] [bp-2Ch]
  int v15; // [sp+28h] [bp-28h] BYREF
  __int16 v16; // [sp+2Ch] [bp-24h]
  __int16 v17; // [sp+2Eh] [bp-22h]
  int v18; // [sp+30h] [bp-20h]
  int v19; // [sp+34h] [bp-1Ch]

  KdpCopyMemoryChunks(*((_DWORD *)a1 + 1), 0, (int)&KdpMessageBuffer, *a1, 0, 4, v8);
  if ( v8[0] + 16 > (unsigned int)KdTransportMaxPacketSize )
    v8[0] = KdTransportMaxPacketSize - 16;
  v15 = 12849;
  v16 = KeProcessorLevel;
  v3 = KeGetCurrentProcessorNumberEx(0);
  v4 = *(unsigned __int16 *)(a2 + 2);
  v18 = v8[0];
  v19 = v4;
  v12 = 16;
  v14 = &v15;
  v17 = v3;
  v9 = v8[0];
  v11 = &KdpMessageBuffer;
  KdSendPacket_0();
  v13 = 16;
  v10 = 4096;
  do
  {
    v5 = KdReceivePacket_0();
    if ( v5 == 2 )
      return 1;
  }
  while ( v5 );
  v6 = v8[0];
  if ( v8[0] > (unsigned int)*(unsigned __int16 *)(a2 + 2) )
  {
    v6 = *(unsigned __int16 *)(a2 + 2);
    v8[0] = v6;
  }
  KdpCopyMemoryChunks(*(_DWORD *)(a2 + 4), 0, (int)&KdpMessageBuffer, v6, 0, 5, v8);
  result = 0;
  *(_WORD *)a2 = v8[0];
  return result;
}

// KdpPrintString 
 
int __fastcall KdpPrintString(unsigned __int16 *a1)
{
  int v1; // r4
  __int16 v2; // r0
  int v4; // [sp+10h] [bp-38h] BYREF
  __int16 v5; // [sp+18h] [bp-30h]
  void *v6; // [sp+1Ch] [bp-2Ch]
  __int16 v7; // [sp+20h] [bp-28h]
  int *v8; // [sp+24h] [bp-24h]
  int v9; // [sp+28h] [bp-20h] BYREF
  __int16 v10; // [sp+2Ch] [bp-1Ch]
  __int16 v11; // [sp+2Eh] [bp-1Ah]
  int v12; // [sp+30h] [bp-18h]

  KdpCopyMemoryChunks(*((_DWORD *)a1 + 1), 0, &KdpMessageBuffer, *a1, 0, 4, &v4);
  v1 = v4;
  if ( v4 + 16 > (unsigned int)KdTransportMaxPacketSize )
    v1 = KdTransportMaxPacketSize - 16;
  v9 = 12848;
  v10 = KeProcessorLevel;
  v2 = KeGetCurrentProcessorNumberEx(0);
  v7 = 16;
  v8 = &v9;
  v11 = v2;
  v12 = v1;
  v5 = v1;
  v6 = &KdpMessageBuffer;
  KdSendPacket_0();
  return KdpPollBreakInWithPortLock();
}

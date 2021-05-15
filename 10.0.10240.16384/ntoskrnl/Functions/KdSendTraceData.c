// KdSendTraceData 
 
int __fastcall KdSendTraceData(int result, int a2, __int64 a3)
{
  int v3; // r4
  unsigned int v4; // r6
  int v5; // r5
  int v6; // r9
  char *i; // r7
  int v8; // r3
  int v9; // r1
  int v10; // r2
  int v11; // r3

  v3 = a2;
  v4 = 0;
  v5 = result;
  if ( a2 )
  {
    LODWORD(a3) = result;
    do
    {
      HIDWORD(a3) = *(_DWORD *)(a3 + 4);
      LODWORD(a3) = a3 + 8;
      v4 += HIDWORD(a3);
      --a2;
    }
    while ( a2 );
  }
  if ( v4 <= KdTransportMaxPacketSize - 64 )
  {
    HIDWORD(a3) = KdTransportMaxPacketSize - 64;
    v6 = KdEnterDebugger(0, 0, a3);
    for ( i = (char *)&KdpMessageBuffer; v3; --v3 )
    {
      memmove((int)i, *(_DWORD *)v5, *(_DWORD *)(v5 + 4));
      v8 = *(_DWORD *)(v5 + 4);
      v5 += 8;
      i += v8;
    }
    KdSendPacket_0();
    result = KdExitDebugger(v6, v9, v10, v11);
  }
  return result;
}

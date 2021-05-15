// EtwpSendBufferToDebugger 
 
int __fastcall EtwpSendBufferToDebugger(unsigned int *a1)
{
  unsigned int v2; // r2
  int v3; // r4
  int result; // r0
  unsigned int v5; // r6
  unsigned int v6; // r4
  int v7; // r7
  int v8; // r8
  unsigned int v9[2]; // [sp+0h] [bp-78h] BYREF
  unsigned int *v10; // [sp+8h] [bp-70h] BYREF
  unsigned int v11; // [sp+Ch] [bp-6Ch]
  int v12; // [sp+10h] [bp-68h]
  int v13; // [sp+14h] [bp-64h]
  _DWORD v14[24]; // [sp+18h] [bp-60h] BYREF

  v2 = a1[12];
  v3 = KdTransportMaxPacketSize - 64;
  if ( v2 > KdTransportMaxPacketSize - 64 )
  {
    memmove((int)v14, (int)a1, 0x48u);
    v10 = v14;
    v5 = 72;
    v11 = 72;
    v6 = v3 - 72;
    do
    {
      v12 = (int)a1 + v5;
      v7 = 0;
      result = EtwpGetNextEventOffsetType(a1, v5, v9);
      v8 = result;
      if ( !result )
        break;
      while ( v9[0] + v7 <= v6 )
      {
        v5 += v9[0];
        v7 += v9[0];
        result = EtwpGetNextEventOffsetType(a1, v5, v9);
        v8 = result;
        if ( !result )
          goto LABEL_10;
      }
      if ( v9[0] > v6 )
        v5 += v9[0];
LABEL_10:
      if ( v7 )
      {
        v14[12] = v7 + 72;
        v13 = v7;
        v14[0] = v7 + 72;
        result = KdSendTraceData(&v10, 2);
      }
    }
    while ( v8 );
  }
  else
  {
    v10 = a1;
    v11 = v2;
    result = KdSendTraceData(&v10, 1);
  }
  return result;
}

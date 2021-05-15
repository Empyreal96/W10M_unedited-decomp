// EtwpRealtimeDisconnectConsumerByHandle 
 
int __fastcall EtwpRealtimeDisconnectConsumerByHandle(int a1, int a2, int a3, int a4)
{
  char v4; // r3
  int v5; // r4
  int v7; // [sp+8h] [bp-8h] BYREF

  v7 = a4;
  v4 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v5 = ObReferenceObjectByHandle(a1, 1024, EtwpRealTimeConnectionObjectType, v4, (int)&v7, 0);
  if ( v5 >= 0 )
  {
    EtwpRealtimeDisconnectConsumer(v7);
    ObfDereferenceObject(v7);
  }
  return v5;
}

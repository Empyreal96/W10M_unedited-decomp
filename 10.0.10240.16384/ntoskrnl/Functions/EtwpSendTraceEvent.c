// EtwpSendTraceEvent 
 
int __fastcall EtwpSendTraceEvent(int a1, int a2)
{
  int v2; // r3
  BOOL v5; // r0
  unsigned int v6; // r0
  unsigned int v7; // r6
  unsigned int *v8; // r4
  int result; // r0
  int v10; // r7
  int v11; // r5
  int v12; // [sp+0h] [bp-70h] BYREF
  int v13[4]; // [sp+8h] [bp-68h] BYREF
  int v14[22]; // [sp+18h] [bp-58h] BYREF

  v2 = *(_DWORD *)(a1 + 612);
  __dmb(0xBu);
  if ( (v2 & 0x800) != 0 )
  {
    v5 = KeAreInterruptsEnabled();
    v6 = v5 ? KeGetCurrentIrql(v5) : 15;
    if ( v6 < 2 )
      EtwpSendDbgId(a1);
  }
  v7 = *(_DWORD *)(a2 + 8);
  v8 = *(unsigned int **)a2;
  result = EtwpGetNextEventOffsetType(*(unsigned int **)a2, v7, (unsigned int *)&v12);
  if ( result )
  {
    v10 = v12;
    v11 = v12 + 72;
    if ( v12 + 72 <= (unsigned int)(KdTransportMaxPacketSize - 64) )
    {
      memmove((int)v14, (int)v8, 0x48u);
      v13[0] = (int)v14;
      v13[1] = 72;
      v13[2] = (int)v8 + v7;
      v13[3] = v10;
      v14[0] = v11;
      v14[12] = v11;
      result = KdSendTraceData(v13, 2);
    }
  }
  return result;
}

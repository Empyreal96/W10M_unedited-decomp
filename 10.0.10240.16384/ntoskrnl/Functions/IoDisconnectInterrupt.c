// IoDisconnectInterrupt 
 
int __fastcall IoDisconnectInterrupt(int a1)
{
  int v1; // r5
  unsigned __int8 v2; // r6
  __int64 v3; // r0
  char v4; // r2
  char v6[56]; // [sp+8h] [bp-38h] BYREF

  v1 = a1 - 88;
  KeRemoveQueueDpc(a1 + 196);
  IopInitializeActiveConnectBlock(v1 + 8, v6);
  v2 = *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~*(_DWORD *)(v1 + 4) >> 16))
     + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~*(_DWORD *)(v1 + 4) >> 24))
     + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~*(_WORD *)(v1 + 4) >> 8))
     + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~*(_BYTE *)(v1 + 4));
  IopAcquireActiveConnectLock(v6);
  KeDisconnectInterrupt(v1 + 316, v2, v1 + 8);
  LODWORD(v3) = IopReleaseActiveConnectLock(v6);
  if ( *(_BYTE *)(v1 + 264) )
    v3 = IopDestroyPassiveInterruptBlock(*(_DWORD *)(v1 + 20));
  return sub_7BF24C(v3, SHIDWORD(v3), v4);
}

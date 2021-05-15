// KeFlushProcessWriteBuffers 
 
int __fastcall KeFlushProcessWriteBuffers(int a1)
{
  int v2; // r8
  int v3; // r7
  _DWORD *v4; // r6
  int v5; // r3
  _DWORD *v6; // r1
  int v7; // r3
  int v8; // r3
  int v10; // r2
  int v11; // r3
  _DWORD v12[2]; // [sp+8h] [bp-28h] BYREF
  int v13; // [sp+10h] [bp-20h]

  v2 = KfRaiseIrql(12);
  v3 = 0;
  v4 = (_DWORD *)((unsigned int)KeGetPcr() & 0xFFFFF000);
  if ( a1 )
  {
    v3 = 1;
    v5 = KeNumberProcessors_0 - 1;
    v6 = 0;
  }
  else
  {
    v10 = *(_DWORD *)(*(_DWORD *)(v4[353] + 116) + 92);
    v11 = *(_DWORD *)(*(_DWORD *)(v4[353] + 116) + 96);
    v12[0] = *(_DWORD *)(*(_DWORD *)(v4[353] + 116) + 88);
    v12[1] = v10;
    v13 = v11;
    v13 = v11 & ~(1 << v4[357]);
    v5 = (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~v13 >> 16))
                         + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~v13 >> 24))
                         + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v13 >> 8))
                         + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v13));
    v6 = v12;
  }
  if ( v5 )
  {
    KiIpiSendPacket(v3, v6, KiFlushWriteBuffersTarget, 0, 0, 0);
    v7 = v4[736];
    __dmb(0xBu);
    if ( v7 )
    {
      do
      {
        __dmb(0xAu);
        __yield();
        v8 = v4[736];
        __dmb(0xBu);
      }
      while ( v8 );
    }
  }
  return KfLowerIrql(v2);
}

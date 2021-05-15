// PpmCheckSnapAllUtility 
 
int PpmCheckSnapAllUtility()
{
  unsigned int v0; // r5
  unsigned int v1; // r4
  unsigned int v2; // r2
  unsigned __int8 v4; // r1
  unsigned int v5; // r2
  int v6; // r4
  unsigned int *v7; // r2
  unsigned int v8; // r0
  char v9; // [sp+8h] [bp-30h]

  PpmParkSnapNodeStatistics();
  v0 = dword_6174B8;
  v1 = dword_6174B8;
  while ( v1 )
  {
    v2 = __clz(__rbit(v1));
    v1 &= ~(1 << v2);
    v9 = v2;
    if ( v2 >= KeNumberProcessors_0 )
      return sub_54140C();
    if ( PpmPerfSnapUtility(*(&KiProcessorBlock + v2)) )
      v0 &= ~(1 << v9);
  }
  v4 = *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)(~v0 >> 16))
     + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~(_WORD)v0 >> 8))
     + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~(_BYTE)v0)
     + *((_BYTE *)RtlpBitsClearTotal + (~v0 >> 24));
  PpmCheckCount = v4;
  if ( !v4 )
    return 1;
  while ( v0 )
  {
    v5 = __clz(__rbit(v0));
    v0 &= ~(1 << v5);
    if ( v5 >= KeNumberProcessors_0 )
      v6 = 0;
    else
      v6 = (int)*(&KiProcessorBlock + v5);
    __dmb(0xBu);
    v7 = (unsigned int *)(v6 + 3192);
    do
      v8 = __ldrex(v7);
    while ( __strex(v8 | 1, v7) );
    __dmb(0xBu);
    if ( !v8 )
      KiInsertQueueDpc(v6 + 3160, 0, 0, 0, 0);
  }
  return 0;
}

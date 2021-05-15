// KeQueryMaximumProcessorCountEx 
 
int __fastcall KeQueryMaximumProcessorCountEx(unsigned int a1, int a2)
{
  unsigned int v3; // r2

  if ( KeDynamicPartitioningSupported )
    return sub_50A314(a1, a2, &KeNumberProcessors_0, 0xFFFF);
  if ( a1 == 0xFFFF )
    return KeNumberProcessors_0;
  if ( a1 >= (unsigned __int16)KiActiveGroups )
    return 0;
  v3 = ~dword_681D78[a1];
  return (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + BYTE2(v3))
                         + *((_BYTE *)RtlpBitsClearTotal + HIBYTE(v3))
                         + *((_BYTE *)RtlpBitsClearTotal + BYTE1(v3))
                         + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)v3));
}

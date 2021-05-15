// KeQueryActiveProcessorCountEx 
 
int __fastcall KeQueryActiveProcessorCountEx(unsigned int a1)
{
  unsigned int v2; // r2

  if ( a1 == 0xFFFF )
    return KeNumberProcessors_0;
  if ( a1 >= (unsigned __int16)KiActiveGroups )
    return 0;
  v2 = ~dword_681D78[a1];
  return (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + BYTE2(v2))
                         + *((_BYTE *)RtlpBitsClearTotal + HIBYTE(v2))
                         + *((_BYTE *)RtlpBitsClearTotal + BYTE1(v2))
                         + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)v2));
}

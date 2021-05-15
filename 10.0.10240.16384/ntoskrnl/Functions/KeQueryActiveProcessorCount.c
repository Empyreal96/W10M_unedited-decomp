// KeQueryActiveProcessorCount 
 
int __fastcall KeQueryActiveProcessorCount(int a1)
{
  if ( a1 )
    return sub_554FAC();
  if ( KiActiveGroups )
    return (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~dword_681D78[0] >> 16))
                           + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~dword_681D78[0] >> 24))
                           + *((_BYTE *)RtlpBitsClearTotal
                             + (unsigned __int8)((unsigned __int16)~LOWORD(dword_681D78[0]) >> 8))
                           + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~LOBYTE(dword_681D78[0])));
  return 0;
}

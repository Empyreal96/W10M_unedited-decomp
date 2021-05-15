// IopMaskInterrupt 
 
int __fastcall IopMaskInterrupt(int a1)
{
  return KeMaskInterrupt(
           a1 + 228,
           (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~*(_DWORD *)(a1 - 84) >> 16))
                           + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~*(_DWORD *)(a1 - 84) >> 24))
                           + *((_BYTE *)RtlpBitsClearTotal
                             + (unsigned __int8)((unsigned __int16)~*(_WORD *)(a1 - 84) >> 8))
                           + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~*(_BYTE *)(a1 - 84))));
}

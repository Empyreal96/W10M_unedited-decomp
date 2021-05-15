// KeCountSetBitsAffinityEx 
 
int __fastcall KeCountSetBitsAffinityEx(int a1)
{
  return (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~*(_DWORD *)(a1 + 8) >> 24))
                         + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~*(_DWORD *)(a1 + 8) >> 16))
                         + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~*(_WORD *)(a1 + 8) >> 8))
                         + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~*(_BYTE *)(a1 + 8)));
}

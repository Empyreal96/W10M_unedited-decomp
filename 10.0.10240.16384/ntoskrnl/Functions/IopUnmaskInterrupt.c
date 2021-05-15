// IopUnmaskInterrupt 
 
int __fastcall IopUnmaskInterrupt(int a1)
{
  unsigned int v1; // r2

  v1 = ~*(_DWORD *)(a1 - 84);
  return KeUnmaskInterrupt(
           a1 + 228,
           (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + BYTE2(v1))
                           + *((_BYTE *)RtlpBitsClearTotal + HIBYTE(v1))
                           + *((_BYTE *)RtlpBitsClearTotal + BYTE1(v1))
                           + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)v1)),
           a1 - 80);
}

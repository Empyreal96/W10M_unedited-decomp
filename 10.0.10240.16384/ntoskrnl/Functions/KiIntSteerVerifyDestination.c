// KiIntSteerVerifyDestination 
 
int __fastcall KiIntSteerVerifyDestination(int a1, int a2)
{
  int result; // r0

  if ( *(unsigned __int16 *)(a1 + 48) == *(unsigned __int16 *)(a2 + 4)
    && (unsigned __int8)(*((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned int)~*(_DWORD *)a2 >> 16))
                       + *((_BYTE *)RtlpBitsClearTotal + ((unsigned int)~*(_DWORD *)a2 >> 24))
                       + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)((unsigned __int16)~*(_WORD *)a2 >> 8))
                       + *((_BYTE *)RtlpBitsClearTotal + (unsigned __int8)~*(_BYTE *)a2)) == 1
    && (*(_DWORD *)(a1 + 44) | *(_DWORD *)a2) == *(_DWORD *)(a1 + 44) )
  {
    result = 0;
  }
  else
  {
    result = -1073741811;
  }
  return result;
}

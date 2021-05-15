// RtlClearAllBits 
 
_BYTE *__fastcall RtlClearAllBits(int a1)
{
  return memset(*(_BYTE **)(a1 + 4), 0, 4 * (((*(_DWORD *)a1 & 0x1F) != 0) + (*(_DWORD *)a1 >> 5)));
}

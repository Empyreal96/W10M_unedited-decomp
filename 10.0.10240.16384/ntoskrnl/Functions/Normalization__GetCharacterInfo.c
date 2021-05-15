// Normalization__GetCharacterInfo 
 
int __fastcall Normalization__GetCharacterInfo(int a1, int a2, _BYTE *a3, _BYTE *a4)
{
  int result; // r0

  result = *(unsigned __int8 *)(*(_DWORD *)(a1 + 24)
                              + (a2 & 0x7F)
                              + (*(unsigned __int8 *)((a2 >> 7) + *(_DWORD *)(a1 + 20)) << 7)
                              - 128);
  *a4 = result & 0xC0;
  *a3 = result & 0x3F;
  return result;
}

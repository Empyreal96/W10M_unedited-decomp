// Normalization__TableLookup 
 
int __fastcall Normalization__TableLookup(int a1, char a2, int a3)
{
  return *(unsigned __int8 *)(*(_DWORD *)(a1 + 24) + (a2 & 0x7F) + (a3 << 7) - 128);
}

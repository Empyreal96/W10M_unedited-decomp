// Normalization__PageLookup 
 
int __fastcall Normalization__PageLookup(int a1, int a2)
{
  return *(unsigned __int8 *)((a2 >> 7) + *(_DWORD *)(a1 + 20));
}

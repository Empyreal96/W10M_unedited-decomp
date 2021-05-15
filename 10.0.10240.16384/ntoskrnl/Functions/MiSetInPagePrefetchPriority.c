// MiSetInPagePrefetchPriority 
 
int __fastcall MiSetInPagePrefetchPriority(int a1, int a2)
{
  unsigned int v3; // r1

  if ( (*(_DWORD *)(a1 + 40) & 0x40) != 0 )
    v3 = 5;
  else
    v3 = 0;
  return MiSetInPagePriority(a2, v3, *(_DWORD *)(a1 + 40) & 7);
}

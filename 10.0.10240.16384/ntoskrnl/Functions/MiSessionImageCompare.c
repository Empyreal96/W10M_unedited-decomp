// MiSessionImageCompare 
 
int __fastcall MiSessionImageCompare(unsigned int a1, int a2)
{
  if ( a1 > *(_DWORD *)(a2 + 24) )
    return 1;
  if ( a1 < (*(_DWORD *)(a2 + 20) & 0xFFFFFFFC) )
    return -1;
  return 0;
}

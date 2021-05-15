// MI_IS_PFN 
 
int __fastcall MI_IS_PFN(unsigned int a1)
{
  if ( a1 > dword_633850 )
    return 0;
  if ( dword_634C9C )
    return (*(_DWORD *)(dword_634C9C + 4 * (a1 >> 5)) >> (a1 & 0x1F)) & 1;
  return 1;
}

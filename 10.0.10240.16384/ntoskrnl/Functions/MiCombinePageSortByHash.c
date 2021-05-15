// MiCombinePageSortByHash 
 
int __fastcall MiCombinePageSortByHash(unsigned __int64 *a1, unsigned __int64 *a2)
{
  unsigned __int64 v2; // kr00_8
  unsigned __int64 v3; // kr08_8

  v2 = *a1;
  v3 = *a2;
  if ( *((_DWORD *)a1 + 1) > *((_DWORD *)a2 + 1) )
    return 1;
  if ( HIDWORD(v2) < HIDWORD(v3) || (unsigned int)v2 < (unsigned int)v3 )
    return -1;
  return v2 > v3;
}

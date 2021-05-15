// SdbpFindMatcher 
 
int __fastcall SdbpFindMatcher(_DWORD *a1, int a2, int a3, int a4)
{
  int v7; // r0
  int result; // r0
  unsigned int v9; // r2

  v7 = SdbGetTagFromTagID(a3, a4, a3, a4);
  if ( !a4 )
    return 0;
  v9 = 0;
  while ( v7 != *(_DWORD *)(a2 + 12 * v9 + 424) )
  {
    v9 = (unsigned __int16)(v9 + 1);
    if ( v9 >= 0x10 )
      return 0;
  }
  result = *(_DWORD *)(a2 + 12 * v9 + 428);
  *a1 = *(_DWORD *)(a2 + 12 * v9 + 432);
  return result;
}

// MiUnlinkNodeLargePageHelper 
 
int __fastcall MiUnlinkNodeLargePageHelper(int a1, int a2, int a3, int a4)
{
  __int64 v4; // r4
  BOOL v5; // r1
  unsigned int v6; // r4
  int result; // r0
  unsigned int v8; // r0

  v4 = 715827883i64 * (a2 - MmPfnDatabase);
  *(_DWORD *)(a2 + 4) = 0;
  --*(_DWORD *)(a1 + 4 * a3);
  v5 = (unsigned int)((SHIDWORD(v4) >> 2) + (HIDWORD(v4) >> 31)) < 0x100000;
  --*(_DWORD *)(a1 + 4 * (a3 + 2 * (v5 + 5) + a4));
  if ( a3 )
  {
    do
      v6 = __ldrex((unsigned int *)&dword_63FC00);
    while ( __strex(v6 - 1024, (unsigned int *)&dword_63FC00) );
  }
  else
  {
    do
      v8 = __ldrex((unsigned int *)&dword_63FB80);
    while ( __strex(v8 - 1024, (unsigned int *)&dword_63FB80) );
  }
  result = MiDecreaseAvailablePages((int)MiSystemPartition, 1024);
  if ( dword_634380 == 1 )
    result = sub_5501C4(result);
  return result;
}

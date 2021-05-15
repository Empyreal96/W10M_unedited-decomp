// KiSelectLowestRankedThread 
 
int __fastcall KiSelectLowestRankedThread(int a1)
{
  int v2; // r4
  int result; // r0

  v2 = *(_DWORD *)(a1 + 1980);
  result = 0;
  while ( v2 )
  {
    result = KiSelectThreadFromSchedulingGroup(a1, v2 - 80, 0);
    if ( result )
      break;
    v2 = *(_DWORD *)(v2 + 152);
  }
  return result;
}

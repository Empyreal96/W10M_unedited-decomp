// ExpValidateFastCacheSize 
 
int __fastcall ExpValidateFastCacheSize(int a1, unsigned int a2, _DWORD *a3)
{
  if ( a1 != 4 )
    return sub_811D84();
  if ( a2 > ExpPackagesTableMaximumSize )
    return -1073700220;
  if ( a3 )
    *a3 = ExpPackagesTableMaximumSize;
  return 0;
}

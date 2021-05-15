// MiCombineCompareVm 
 
int __fastcall MiCombineCompareVm(unsigned int a1, int a2)
{
  if ( a1 > a2 + 16 )
    return 1;
  if ( a1 >= a2 + 16 )
    return 0;
  return -1;
}

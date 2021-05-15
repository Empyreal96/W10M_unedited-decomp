// MiSystemViewCompareVa 
 
int __fastcall MiSystemViewCompareVa(unsigned int a1, int a2)
{
  unsigned int v2; // r2

  v2 = *(_DWORD *)(a2 + 48) & 0xFFFFF000;
  if ( a1 >= *(_DWORD *)(a2 + 24) + v2 )
    return 1;
  if ( a1 >= v2 )
    return 0;
  return -1;
}

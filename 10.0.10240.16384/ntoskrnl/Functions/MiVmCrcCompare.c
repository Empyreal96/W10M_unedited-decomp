// MiVmCrcCompare 
 
int __fastcall MiVmCrcCompare(unsigned int a1, int a2)
{
  unsigned int v2; // r3

  v2 = *(_DWORD *)(a2 + 16);
  if ( a1 > v2 )
    return 1;
  if ( a1 >= v2 )
    return 0;
  return -1;
}

// MiVadCompareVpn 
 
int __fastcall MiVadCompareVpn(unsigned int a1, int a2)
{
  if ( a1 > *(_DWORD *)(a2 + 16) )
    return 1;
  if ( a1 >= *(_DWORD *)(a2 + 12) )
    return 0;
  return -1;
}

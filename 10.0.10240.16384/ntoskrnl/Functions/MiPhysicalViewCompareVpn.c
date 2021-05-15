// MiPhysicalViewCompareVpn 
 
int __fastcall MiPhysicalViewCompareVpn(unsigned int a1, int a2)
{
  return MiVadCompareVpn(a1, *(_DWORD *)(a2 + 12));
}

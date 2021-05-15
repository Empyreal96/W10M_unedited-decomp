// PnpFindRebalanceCandidates 
 
int __fastcall PnpFindRebalanceCandidates(int a1, int a2, int a3, int a4)
{
  int v6; // r4
  int result; // r0

  v6 = a2;
  if ( a1 || !a2 )
    return PnpQueryRebalance(IopRootDeviceNode, a3, a4);
  result = *(_DWORD *)(a2 + 172);
  if ( result != 776 )
    v6 = *(_DWORD *)(a2 + 8);
  for ( ; v6; v6 = *(_DWORD *)(v6 + 8) )
  {
    result = PnpQueryRebalance(v6, a3, a4);
    if ( result != 281 )
      break;
  }
  return result;
}

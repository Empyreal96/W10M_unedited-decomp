// PnpQueryRebalance 
 
int __fastcall PnpQueryRebalance(int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // r5
  int v5; // r4

  v4 = *(_DWORD **)(a1 + 4);
  v5 = 0;
  if ( !v4 )
    return PnpQueryRebalanceWorker(a1, a2, a3, a4);
  do
  {
    if ( PnpQueryRebalance(v4, a2, a3) < 0 )
      v5 = -1073741823;
    v4 = (_DWORD *)*v4;
  }
  while ( v4 );
  if ( v5 >= 0 )
    return PnpQueryRebalanceWorker(a1, a2, a3, a4);
  return v5;
}

// IopPowerDispatch 
 
int __fastcall IopPowerDispatch(int a1, int a2)
{
  int v3; // r2
  int v5; // r3
  int v6; // r4

  v3 = *(_DWORD *)(a2 + 96);
  if ( *(_BYTE *)(v3 + 1) != 2 )
    return sub_520444();
  v5 = *(_DWORD *)(v3 + 12);
  if ( v5 )
  {
    if ( v5 != 1 )
    {
      v6 = *(_DWORD *)(a2 + 24);
      goto LABEL_7;
    }
    PoSetPowerState(a1, 1, *(_DWORD *)(v3 + 16));
  }
  v6 = 0;
  *(_DWORD *)(a2 + 24) = 0;
LABEL_7:
  pIofCompleteRequest(a2, 0);
  return v6;
}

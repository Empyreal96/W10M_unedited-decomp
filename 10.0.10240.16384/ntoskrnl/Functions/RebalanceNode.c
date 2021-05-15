// RebalanceNode 
 
int __fastcall RebalanceNode(int a1)
{
  int v1; // r6
  int v3; // r4
  int v4; // r3
  int v5; // r7
  int v6; // r0
  int v7; // r0
  int v8; // r0
  int v9; // r2

  v1 = *(char *)(a1 + 12);
  if ( v1 == 1 )
    v3 = *(_DWORD *)(a1 + 8);
  else
    v3 = *(_DWORD *)(a1 + 4);
  v4 = *(char *)(v3 + 12);
  if ( v4 == v1 )
  {
    PromoteNode(v3);
    *(_BYTE *)(v3 + 12) = 0;
    *(_BYTE *)(a1 + 12) = 0;
    return 0;
  }
  v5 = -v1;
  if ( v4 == -v1 )
  {
    if ( v1 == 1 )
      v6 = *(_DWORD *)(v3 + 4);
    else
      v6 = *(_DWORD *)(v3 + 8);
    v7 = PromoteNode(v6);
    v8 = PromoteNode(v7);
    *(_BYTE *)(a1 + 12) = 0;
    *(_BYTE *)(v3 + 12) = 0;
    v9 = *(char *)(v8 + 12);
    if ( v9 == v1 )
    {
      *(_BYTE *)(a1 + 12) = v5;
    }
    else if ( v9 == v5 )
    {
      *(_BYTE *)(v3 + 12) = v1;
    }
    *(_BYTE *)(v8 + 12) = 0;
    return 0;
  }
  PromoteNode(v3);
  *(_BYTE *)(v3 + 12) = v5;
  return 1;
}

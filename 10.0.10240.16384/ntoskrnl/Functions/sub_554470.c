// sub_554470 
 
void __fastcall sub_554470(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  unsigned int i; // r1
  int v6; // r4
  int v7; // r1
  int v8; // r4
  int v9; // r0
  int v10; // r2

  if ( a4 )
  {
    for ( i = 0; i < *(_DWORD *)(a1 + 40); ++i )
    {
      v6 = *(_DWORD *)(*(_DWORD *)(a1 + 44) + 4 * i);
      if ( v6 != v4 )
        *(_DWORD *)(v6 + 24) = *(_DWORD *)(v6 + 28);
    }
  }
  else
  {
    v7 = a2 - 1;
    v8 = *(_DWORD *)(*(_DWORD *)(a1 + 44) + 4 * v7);
    if ( v7 )
      v9 = EmpEvaluatePermuteRuleEntries(a1, v7);
    else
      v9 = 1;
    if ( v8 != v4 )
    {
      if ( !v9 )
        goto LABEL_18;
      v10 = **(_DWORD **)(v8 + 24);
      if ( v10 != v8 + 28 )
      {
        *(_DWORD *)(v8 + 24) = v10;
        goto LABEL_18;
      }
      *(_DWORD *)(v8 + 24) = *(_DWORD *)(v8 + 28);
    }
    if ( v9 )
      JUMPOUT(0x4F539C);
  }
LABEL_18:
  JUMPOUT(0x4F539E);
}

// PsIsThreadInSilo 
 
int __fastcall PsIsThreadInSilo(int a1, int a2)
{
  int v3; // r0

  if ( !a2 )
    return 1;
  v3 = *(_DWORD *)(a1 + 1096);
  if ( v3 == -3 )
    return PsIsProcessInSilo(*(_DWORD *)(a1 + 336), a2);
  return v3 == a2 || PsIsSiloInSilo(v3, a2);
}

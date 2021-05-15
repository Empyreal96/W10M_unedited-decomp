// PnpDiagnosticCompletionRoutine 
 
int __fastcall PnpDiagnosticCompletionRoutine(int a1, int a2, int a3)
{
  int v3; // r3

  v3 = *(_DWORD *)(a2 + 24);
  *(_DWORD *)(a3 + 20) = v3;
  if ( v3 < 0 )
    return sub_528DF8();
  pIoFreeIrp(a2);
  KeSetEvent(a3 + 4, 0, 0);
  return -1073741802;
}

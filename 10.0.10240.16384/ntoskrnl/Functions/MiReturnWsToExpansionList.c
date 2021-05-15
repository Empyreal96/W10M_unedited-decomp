// MiReturnWsToExpansionList 
 
int __fastcall MiReturnWsToExpansionList(int *a1, int a2)
{
  bool v2; // zf
  int *v3; // r1
  int **v4; // r5
  int result; // r0
  int v6; // r5

  v2 = a2 == 0;
  v3 = a1 + 3;
  if ( v2 )
  {
    v4 = (int **)dword_6404C0;
    *v3 = (int)&dword_6404BC;
    a1[4] = (int)v4;
    if ( *v4 != &dword_6404BC )
      __fastfail(3u);
    *v4 = v3;
    dword_6404C0 = (int)(a1 + 3);
  }
  else
  {
    v6 = dword_6404BC;
    *v3 = dword_6404BC;
    a1[4] = (int)&dword_6404BC;
    if ( *(int **)(v6 + 4) != &dword_6404BC )
      sub_50BC3C();
    *(_DWORD *)(v6 + 4) = v3;
    dword_6404BC = (int)(a1 + 3);
  }
  result = a1[1];
  if ( result )
    result = KeSignalGate(result, 1);
  return result;
}

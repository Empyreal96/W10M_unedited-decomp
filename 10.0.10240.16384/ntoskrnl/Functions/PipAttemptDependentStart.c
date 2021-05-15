// PipAttemptDependentStart 
 
int __fastcall PipAttemptDependentStart(int *a1, int a2, int a3)
{
  int v4; // r4
  int v5; // r1
  int v6; // r2
  int v7; // r3

  if ( a1 )
    v4 = *(_DWORD *)(a1[44] + 20);
  else
    v4 = 0;
  if ( !v4
    || (*(_DWORD *)(v4 + 268) & 0x2000) == 0
    || *(_DWORD *)(v4 + 276) != 51
    || PipCheckForUnsatisfiedDependencies(v4, 3, a3, 51) )
  {
    return -1073741823;
  }
  PipClearDevNodeProblem(v4, v5, v6, v7);
  return PnpRequestDeviceAction(a1, 16, 1, 0, 0, 0);
}

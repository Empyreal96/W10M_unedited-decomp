// PopSessionInputChange 
 
int __fastcall PopSessionInputChange(int a1, unsigned __int8 *a2, int a3)
{
  int v3; // r7
  int v4; // r8
  BOOL v7; // r5
  int *v8; // r0
  int v9; // r0

  v3 = *a2;
  v4 = *((_DWORD *)a2 + 1);
  PopPrintEx(3);
  v7 = PopConsoleContext == a1 && a1 != -1;
  if ( v3 )
    v8 = POP_ETW_ADPM_ACTIVE_INPUT;
  else
    v8 = POP_ETW_ADPM_PASSIVE_INPUT;
  PopDiagTraceSessionStates(v8, a1, v7);
  PopAcquireAdaptiveLock(1);
  if ( v3 )
  {
    if ( v7 )
      v9 = PopConsoleSessionActiveInput(a1, v4, a3);
    else
      v9 = PopRemoteSessionActiveInput(a1);
    return PopReleaseAdaptiveLock(v9);
  }
  if ( v7 )
  {
    v9 = PopConsoleSessionPassiveInput(a1, v4, a3);
    return PopReleaseAdaptiveLock(v9);
  }
  return sub_7BF2A4(a1);
}

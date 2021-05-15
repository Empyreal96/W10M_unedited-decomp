// PpmParkSnapNodeIdleTime 
 
int __fastcall PpmParkSnapNodeIdleTime(int a1, _DWORD *a2, _DWORD *a3)
{
  unsigned int v6; // r2
  int v7; // r0

  *a2 = 0;
  a2[1] = 0;
  *a3 = 0;
  a3[1] = 0;
  PpmAcquireLock(&PpmPerfPolicyLock);
  v6 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 2360) + 266);
  if ( v6 <= PpmParkNumNodes )
  {
    v7 = *(_DWORD *)(PpmParkNodes + 88 * v6 + 28);
    if ( v7 )
      PpmIdleSnapConcurrencyIdleTime(v7, a2, a3);
  }
  return PpmReleaseLock(&PpmPerfPolicyLock);
}

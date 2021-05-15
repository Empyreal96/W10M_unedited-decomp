// PpmParkSnapNodeIdleTime 
 
int __fastcall PpmParkSnapNodeIdleTime(int a1, _DWORD *a2, _DWORD *a3)
{
  unsigned int v6; // r2
  unsigned __int64 v7; // r2
  int v8; // r0

  *a2 = 0;
  a2[1] = 0;
  *a3 = 0;
  a3[1] = 0;
  PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
  v6 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 2360) + 266);
  if ( v6 <= PpmParkNumNodes )
  {
    HIDWORD(v7) = PpmParkNodes + 88 * v6;
    v8 = *(_DWORD *)(HIDWORD(v7) + 28);
    if ( v8 )
    {
      LODWORD(v7) = a3;
      PpmIdleSnapConcurrencyIdleTime(v8, a2, v7);
    }
  }
  return PpmReleaseLock(&PpmPerfPolicyLock);
}

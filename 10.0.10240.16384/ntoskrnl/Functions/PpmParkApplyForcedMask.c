// PpmParkApplyForcedMask 
 
int __fastcall PpmParkApplyForcedMask(int *a1)
{
  unsigned int v2; // r5
  int v3; // r7
  int v4; // r1
  int v5; // r2
  unsigned int v6; // r0
  unsigned __int16 v7; // r4
  int v8; // r6
  int v9; // r2
  int v10; // r4

  v2 = *((unsigned __int16 *)a1 + 2);
  v3 = *a1;
  PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
  if ( v2 > 1 )
    goto LABEL_12;
  if ( *((_WORD *)a1 + 3) )
    goto LABEL_12;
  if ( *((_WORD *)a1 + 4) )
    goto LABEL_12;
  if ( *((_WORD *)a1 + 5) )
    goto LABEL_12;
  v4 = 0;
  v5 = 0;
  v6 = PpmParkNumNodes;
  if ( !PpmParkNumNodes )
    goto LABEL_12;
  v7 = 0;
  v8 = PpmParkNodes;
  do
  {
    v9 = v8 + 88 * v5;
    if ( *(unsigned __int16 *)(v9 + 4) == v2 )
    {
      *(_DWORD *)(v9 + 20) = *(_DWORD *)(v9 + 8) & v3;
      v4 = 1;
      *(_BYTE *)(v9 + 82) |= 1u;
    }
    v5 = ++v7;
  }
  while ( v7 < v6 );
  if ( !v4 )
  {
LABEL_12:
    v10 = -1073741811;
    PpmReleaseLock(&PpmPerfPolicyLock);
  }
  else
  {
    PpmParkApplyPolicy();
    PpmParkParkingAvailable();
    PpmCheckApplyParkConstraints();
    v10 = 0;
  }
  return v10;
}

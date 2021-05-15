// PpmParkClearForcedMask 
 
int __fastcall PpmParkClearForcedMask(_WORD *a1)
{
  int v2; // r4
  int v4; // r1
  int v5; // r2
  unsigned int v6; // r5
  unsigned __int16 v7; // r6
  int v8; // r7
  int v9; // r0

  PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
  if ( *a1 )
  {
    v2 = -1073741811;
  }
  else
  {
    v4 = 0;
    v5 = 0;
    v6 = PpmParkNumNodes;
    if ( PpmParkNumNodes )
    {
      v7 = 0;
      v8 = PpmParkNodes;
      do
      {
        v9 = v8 + 88 * v5;
        if ( *(unsigned __int16 *)(v9 + 4) == (unsigned __int16)*a1 && (*(_BYTE *)(v9 + 82) & 1) != 0 )
        {
          *(_BYTE *)(v9 + 82) &= 0xFEu;
          v4 = 1;
        }
        v5 = ++v7;
      }
      while ( v7 < v6 );
    }
    v2 = 0;
    if ( v4 )
    {
      PpmParkApplyPolicy();
      PpmParkParkingAvailable();
      PpmCheckApplyParkConstraints();
      return v2;
    }
  }
  PpmReleaseLock(&PpmPerfPolicyLock);
  return v2;
}

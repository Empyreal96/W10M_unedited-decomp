// PpmParkSetLpiCap 
 
int __fastcall PpmParkSetLpiCap(int a1, int a2, unsigned int *a3)
{
  unsigned int v6; // r4
  unsigned int v7; // r1
  unsigned int v8; // r5
  int v9; // r8
  int v10; // r7
  unsigned int v11; // r2
  int v12; // r1
  int v13; // r0
  unsigned int v14; // r3
  unsigned int v15; // r1
  unsigned int v16; // r2
  unsigned int v17; // r3
  int v18; // r2
  int v19; // r0

  PpmAcquireLock((unsigned int *)&PpmPerfPolicyLock);
  v6 = (unsigned __int8)PpmParkGranularity + a1 - 1;
  if ( !PpmParkGranularity )
    __brkdiv0();
  v7 = v6 % (unsigned __int8)PpmParkGranularity;
  v8 = v6 - v7;
  v9 = PpmParkNodes;
  v10 = PpmParkNumNodes;
  if ( v6 != v7 )
  {
    v11 = 0;
    if ( PpmParkNumNodes )
    {
      v12 = PpmParkNodes;
      v13 = PpmParkNumNodes;
      do
      {
        v14 = *(unsigned __int8 *)(v12 + 6);
        if ( v14 > (unsigned __int8)PpmParkGranularity )
          v11 += v14 - (unsigned __int8)PpmParkGranularity;
        v12 += 88;
        --v13;
      }
      while ( v13 );
    }
    if ( v8 > v11 )
      v8 = v11;
  }
  if ( !PpmParkGranularity )
    __brkdiv0();
  v15 = (unsigned __int8)PpmParkGranularity
      + a2
      - 1
      - ((unsigned int)(unsigned __int8)PpmParkGranularity + a2 - 1) % (unsigned __int8)PpmParkGranularity;
  if ( v15 )
  {
    v16 = 0;
    if ( PpmParkNumNodes )
    {
      do
      {
        v17 = *(unsigned __int8 *)(v9 + 6);
        if ( v17 > (unsigned __int8)PpmParkGranularity )
          v16 += v17 - (unsigned __int8)PpmParkGranularity;
        v9 += 88;
        --v10;
      }
      while ( v10 );
    }
    if ( v15 > v16 )
      v15 = v16;
  }
  v18 = 0;
  if ( v8 != PpmParkLpiCap )
  {
    v18 = 1;
    PpmParkLpiCap = v8;
    PpmParkLpiCapChanged = 1;
  }
  if ( v15 != PpmParkThermalCap )
  {
    PpmParkThermalCap = v15;
    v18 = 1;
  }
  if ( v18 )
  {
    PpmParkApplyPolicy();
    PpmCheckReInit(v19);
    PpmCheckCustomRun(4);
  }
  else
  {
    PpmReleaseLock(&PpmPerfPolicyLock);
  }
  *a3 = v8;
  return 0;
}

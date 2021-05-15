// PopSetupHighPerfPowerRequest 
 
int __fastcall PopSetupHighPerfPowerRequest(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int *v5; // r2
  int v6; // r3
  int v7; // r4
  int v9; // r1
  int v10[4]; // [sp+8h] [bp-10h] BYREF

  v10[0] = a3;
  v10[1] = a4;
  v4 = 3;
  v5 = PpmHighPerfDuration;
  do
  {
    v6 = *v5;
    if ( (unsigned int)*v5 >= 0x493E0 )
      v6 = 300000;
    *v5++ = v6;
    --v4;
  }
  while ( v4 );
  v7 = PoCaptureReasonContext(0, 0, 0, 1, 0, v10);
  if ( v7 >= 0 )
  {
    v7 = PopCreateKernelPowerRequest(&PopTransitionHighPerfRequest, v10[0]);
    if ( v7 < 0 )
      return sub_7F1508();
    if ( PpmHighPerfDuration[0] )
    {
      v7 = PpmBeginHighPerfRequest();
      if ( v7 >= 0 )
        v7 = PpmEndHighPerfRequest(0, v9);
    }
  }
  return v7;
}

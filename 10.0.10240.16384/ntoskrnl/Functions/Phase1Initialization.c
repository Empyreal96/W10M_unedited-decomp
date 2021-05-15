// Phase1Initialization 
 
int __fastcall Phase1Initialization(int a1)
{
  int v2; // r5
  int v3; // r0

  v2 = Phase1InitializationDiscard();
  InbvSetProgressBarSubset();
  if ( !IoInitSystem(a1) )
    sub_80BF68();
  v3 = Phase1InitializationIoReady(a1, v2);
  return MmFreeBootDriverInitializationCode(v3);
}

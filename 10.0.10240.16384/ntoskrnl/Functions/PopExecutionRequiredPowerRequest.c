// PopExecutionRequiredPowerRequest 
 
int __fastcall PopExecutionRequiredPowerRequest(int a1, int a2, int a3)
{
  int v4; // r0

  v4 = PopAoacExecutionRequiredPowerRequest(a1, a2, a3);
  if ( !byte_61EA54 && v4 == 259 )
    PopSystemRequiredCallback(a1, 2);
  return 0;
}

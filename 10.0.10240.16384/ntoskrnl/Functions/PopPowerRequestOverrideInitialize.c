// PopPowerRequestOverrideInitialize 
 
int PopPowerRequestOverrideInitialize()
{
  int v0; // r0
  int v1; // r1
  int v2; // r2
  int v3; // r3
  int *i; // r4

  v0 = PopAcquirePowerRequestPushLock(0);
  for ( i = (int *)PopPowerRequestObjectList; i != &PopPowerRequestObjectList; i = (int *)*i )
    v0 = PopUmpoSendPowerRequestOverrideQuery((int)i, v1, v2, v3);
  return sub_81C718(v0);
}

// PopUmpoProcessPowerMessage 
 
int __fastcall PopUmpoProcessPowerMessage(int *a1, int a2, int a3)
{
  int v3; // r3
  int v4; // r4

  v3 = *a1;
  if ( *a1 == 4 )
  {
    v4 = PopSetNewPolicyValue(a1 + 1);
    if ( v4 < 0 )
    {
      if ( (PoDebug & 1) != 0 )
        DbgPrint("%s: PopSetNewPolicyValue() 0x%x\n", "PopUmpoProcessPowerMessage", v4);
      return v4;
    }
    return 0;
  }
  switch ( v3 )
  {
    case 9:
      PopProcessPowerRequestOverrideQueryResponse(a1 + 1, a2, a3, 9);
      return 0;
    case 8:
      if ( ExAllocatePoolWithTag(512, 28, 1869638997) )
        JUMPOUT(0x7C3C7E);
      return -1073741670;
    case 11:
      PopPowerRequestOverrideInitialize();
      return 0;
  }
  return sub_7C3C60();
}

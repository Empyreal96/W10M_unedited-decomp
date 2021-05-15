// sub_8186E0 
 
void __fastcall sub_8186E0(int a1, int a2, int a3, int a4, int a5, _DWORD *a6)
{
  unsigned int v6; // r5
  int *v7; // r1
  unsigned int v8; // r2
  unsigned int v9; // r2

  *a6 = 0;
  if ( !memcmp((unsigned int)PPM_PERFSTATE_CHANGE_GUID, v6, 16) )
  {
    v7 = &WmiPerfStateEventEnabled;
  }
  else if ( !memcmp((unsigned int)PPM_PERFSTATE_DOMAIN_CHANGE_GUID, v6, 16) )
  {
    v7 = &WmiPerfStateDomainEventEnabled;
  }
  else if ( !memcmp((unsigned int)PPM_IDLESTATE_CHANGE_GUID, v6, 16) )
  {
    v7 = (int *)&WmiIdleStateEventEnabled;
  }
  else if ( !memcmp((unsigned int)PPM_IDLE_ACCOUNTING_EX_GUID, v6, 16) )
  {
    v7 = (int *)&WmiIdleAccntEventEnabled;
  }
  else if ( !memcmp((unsigned int)PPM_THERMALCONSTRAINT_GUID, v6, 16) )
  {
    v7 = &WmiThermalEventEnabled;
  }
  else
  {
    if ( memcmp((unsigned int)PPM_THERMAL_POLICY_CHANGE_GUID, v6, 16) )
      JUMPOUT(0x7B2C9C);
    v7 = &WmiThermalPolicyEventEnabled;
  }
  __dmb(0xBu);
  do
  {
    v8 = __ldrex((unsigned int *)v7);
    v9 = v8 + 1;
  }
  while ( __strex(v9, (unsigned int *)v7) );
  __dmb(0xBu);
  if ( v9 == 1 && v7 == (int *)&WmiIdleAccntEventEnabled )
    KiSetTimerEx((int)&PpmWmiIdleAccountingTimer, 0x2710u, 0i64, 10000, 0, (int)&PpmWmiIdleAccountingDpc);
  JUMPOUT(0x7B2CB2);
}

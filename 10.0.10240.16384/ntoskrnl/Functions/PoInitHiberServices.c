// PoInitHiberServices 
 
int __fastcall PoInitHiberServices(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  BOOL v5; // r5
  int v7; // r0
  int v8; // [sp+0h] [bp-18h]
  _DWORD v10[3]; // [sp+Ch] [bp-Ch] BYREF

  v10[0] = a4;
  v4 = 0;
  v5 = PopHiberEnabledReg == 0;
  EmClientQueryRuleState((unsigned int)&GUID_EM_REMOVE_BAD_S3_PAGE_RULE, v10);
  if ( BcdOpenSystemStore(v10) >= 0 )
    return sub_7F1110();
  if ( ZwQuerySystemInformation() == -1073741789 )
  {
    v4 = ExAllocatePoolWithTag(512, a3, 1919052136);
    if ( v4 )
    {
      if ( ZwQuerySystemInformation() >= 0 && *(_BYTE *)v4 && *(_DWORD *)(v4 + 4) <= (unsigned int)(a3 - 2) )
      {
        v5 = 1;
        PoDisableSleepStates(2, 8, v10);
      }
    }
  }
  KeWaitForSingleObject((unsigned int)&PopTransitionLock, 7, 0, 0, 0);
  PopAcquirePolicyLock();
  PopEnableHiberFile(!v5, 0);
  PopReleasePolicyLock();
  v7 = KeSetEvent((int)&PopTransitionLock, 0, 0);
  if ( dword_61EAAC )
    dword_61EAAC(v7);
  if ( v4 )
    ExFreePoolWithTag(v4);
  return v8;
}

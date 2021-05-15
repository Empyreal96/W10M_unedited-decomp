// PopFilterCapabilities 
 
int __fastcall PopFilterCapabilities(int a1, _BYTE *a2, int a3, int a4)
{
  int v6; // [sp+0h] [bp-20h] BYREF
  _BYTE *v7; // [sp+4h] [bp-1Ch] BYREF
  int v8[6]; // [sp+8h] [bp-18h] BYREF

  v6 = a1;
  v7 = a2;
  v8[0] = a3;
  v8[1] = a4;
  memmove((int)a2, a1, 0x4Cu);
  if ( IoGetLegacyVetoList(&v6, &v7) >= 0 )
  {
    if ( v7 )
      return sub_7BDD60();
    if ( v6 )
      ExFreePoolWithTag(v6);
  }
  PopRemoveReasonRecordByReasonCode(4);
  v8[0] = 1;
  EmClientQueryRuleState((unsigned int)EM_RULE_DISABLE_FASTS4_GUID, v8);
  if ( v8[0] == 2 )
    PopLogSleepDisabled(7, 16, 0, 0);
  else
    PopRemoveReasonRecordByReasonCode(7);
  if ( byte_61EC1D )
    PopLogSleepDisabled(14, 7, 0, 0);
  else
    PopRemoveReasonRecordByReasonCode(14);
  PopLogDisabledSleepReason();
  if ( PopCheckDisabledState(0) )
    a2[3] = 0;
  if ( PopCheckDisabledState(1) )
    a2[4] = 0;
  if ( PopCheckDisabledState(2) )
    a2[5] = 0;
  if ( PopCheckDisabledState(3) )
    a2[6] = 0;
  if ( PopCheckDisabledState(6) )
    a2[17] = 0;
  if ( !a2[5] || !a2[6] )
    a2[17] = 0;
  if ( !a2[6] )
    a2[18] = 0;
  return v6;
}

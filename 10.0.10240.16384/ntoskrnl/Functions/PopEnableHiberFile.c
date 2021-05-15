// PopEnableHiberFile 
 
int __fastcall PopEnableHiberFile(int a1)
{
  PopRemoveReasonRecordByReasonCode();
  PopRemoveReasonRecordByReasonCode();
  PopLogSleepDisabled(3, 8, 0, 0);
  if ( PopCheckDisabledReason(16) )
    return -1073741637;
  if ( a1 )
    JUMPOUT(0x7F11E2);
  if ( PopHiberEnabled )
    return sub_7F1140();
  PopDeleteHiberFile(0);
  return 0;
}

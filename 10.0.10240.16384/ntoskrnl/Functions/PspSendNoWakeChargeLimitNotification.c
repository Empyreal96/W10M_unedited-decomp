// PspSendNoWakeChargeLimitNotification 
 
int __fastcall PspSendNoWakeChargeLimitNotification(int result)
{
  int v1; // r3
  int v2; // [sp+10h] [bp-18h] BYREF
  int v3; // [sp+18h] [bp-10h]
  int v4; // [sp+1Ch] [bp-Ch]

  if ( !result )
  {
    v3 = -1;
    v1 = 0;
LABEL_6:
    v4 = v1;
    return ZwUpdateWnfStateData();
  }
  if ( !PspNoWakeChargeReferencedProcess )
  {
    v2 = 0;
    result = PspEnumJobsAndProcessesInJobHierarchy(result, 0, 0, (int)PspGetProcessInJobHierarchyCallback, (int)&v2, 0);
    if ( v2 )
    {
      v3 = 1;
      v1 = *(_DWORD *)(v2 + 176);
      PspNoWakeChargeReferencedProcess = v2;
      goto LABEL_6;
    }
  }
  return result;
}

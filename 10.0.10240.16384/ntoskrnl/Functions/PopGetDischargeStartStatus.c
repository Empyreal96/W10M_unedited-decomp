// PopGetDischargeStartStatus 
 
int PopGetDischargeStartStatus()
{
  int v0; // r0
  __int64 v2; // [sp+10h] [bp-10h]

  v0 = ZwQueryWnfStateData();
  if ( v0 == -1073741670 || v0 == -1073741431 )
    return 0;
  if ( v0 )
    return 1;
  if ( v2 )
    return 3;
  return 2;
}

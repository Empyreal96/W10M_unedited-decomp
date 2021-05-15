// KiTriggerForegroundBoostDpc 
 
int KiTriggerForegroundBoostDpc()
{
  _DWORD v1[6]; // [sp+10h] [bp-18h] BYREF

  v1[0] = 0;
  v1[1] = 0;
  v1[2] = -1;
  v1[3] = -1;
  return KeSetTimer2(KiForegroundState, -300000i64, 0i64, (int)v1);
}

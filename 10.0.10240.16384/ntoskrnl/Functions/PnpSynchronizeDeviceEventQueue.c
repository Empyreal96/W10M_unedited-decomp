// PnpSynchronizeDeviceEventQueue 
 
int PnpSynchronizeDeviceEventQueue()
{
  _DWORD *v0; // r6
  int result; // r0
  char v2; // [sp+8h] [bp-28h] BYREF
  char v3[32]; // [sp+10h] [bp-20h] BYREF

  v0 = PnpCreateDeviceEventEntry(132);
  if ( !v0 )
    return -1073741801;
  KeInitializeEvent((int)v3, 0, 0);
  v0[3] = v3;
  v0[16] = -885374960;
  v0[17] = 298862320;
  v0[18] = 1610649520;
  v0[19] = 1057297303;
  v0[20] = 1;
  v0[21] = &v2;
  v0[23] = 68;
  result = PnpInsertEventInQueue(v0);
  if ( result >= 0 )
    result = KeWaitForSingleObject((unsigned int)v3, 0, 0, 0, 0);
  return result;
}

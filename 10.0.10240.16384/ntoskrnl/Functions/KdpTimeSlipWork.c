// KdpTimeSlipWork 
 
int KdpTimeSlipWork()
{
  int v1; // [sp+0h] [bp-20h]

  if ( ExAcquireTimeRefreshLock(0) )
    return sub_903B04();
  KiSetTimerEx((int)&KdpTimeSlipTimer, (unsigned int)&KdpTimeSlipDpc, -1800000000i64, 0, 0, (int)&KdpTimeSlipDpc);
  return v1;
}

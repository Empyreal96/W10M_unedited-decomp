// EtwpSpinLockConfigRunDown 
 
int __fastcall EtwpSpinLockConfigRunDown(int a1, int a2)
{
  int v2; // r3
  int v4[4]; // [sp+8h] [bp-28h] BYREF
  int v5[6]; // [sp+18h] [bp-18h] BYREF

  v2 = 3916;
  if ( a2 )
    v2 = 3915;
  v4[0] = EtwpSpinLockSpinThreshold;
  v4[2] = EtwpSpinLockAcquireSampleRate;
  v4[1] = EtwpSpinLockContentionSampleRate;
  v4[3] = EtwpSpinLockHoldThreshold;
  v5[0] = (int)v4;
  v5[1] = 0;
  v5[2] = 16;
  v5[3] = 0;
  return EtwpLogKernelEvent(v5, a1, 1, v2, 5249283);
}

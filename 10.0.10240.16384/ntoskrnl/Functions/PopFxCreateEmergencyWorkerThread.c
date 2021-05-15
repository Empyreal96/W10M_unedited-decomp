// PopFxCreateEmergencyWorkerThread 
 
int PopFxCreateEmergencyWorkerThread()
{
  int v0; // r4
  int v2; // [sp+10h] [bp-28h] BYREF
  int v3[8]; // [sp+18h] [bp-20h] BYREF

  v3[0] = 24;
  v3[1] = 0;
  v3[3] = 512;
  v3[2] = 0;
  v3[4] = 0;
  v3[5] = 0;
  v0 = PsCreateSystemThread((int)&v2, 0x1FFFFF, (int)v3);
  if ( v0 >= 0 )
    ZwClose();
  return v0;
}

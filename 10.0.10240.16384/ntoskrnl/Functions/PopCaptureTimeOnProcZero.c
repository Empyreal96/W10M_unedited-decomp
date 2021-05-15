// PopCaptureTimeOnProcZero 
 
__int64 PopCaptureTimeOnProcZero()
{
  __int64 v1; // [sp+8h] [bp-40h]
  char v2[16]; // [sp+10h] [bp-38h] BYREF
  char v3[2]; // [sp+20h] [bp-28h] BYREF
  __int16 v4; // [sp+22h] [bp-26h]

  KeInitializeEvent((int)v2, 1, 0);
  KeInitializeDpc((int)v3, (int)PopTimestampTargetProcessor, 0);
  v3[1] = 2;
  v4 = 32;
  KeInsertQueueDpc((int)v3);
  KeWaitForSingleObject((unsigned int)v2, 0, 0, 0, 0);
  return v1;
}

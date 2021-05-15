// FsRtlInitializeWorkerThread 
 
int FsRtlInitializeWorkerThread()
{
  unsigned int v0; // r5
  char *v1; // r6
  int v2; // r4
  int v4; // [sp+10h] [bp-38h] BYREF
  int v5[12]; // [sp+18h] [bp-30h] BYREF

  v5[0] = 24;
  v0 = 0;
  v1 = (char *)&FsRtlWorkerQueues;
  v5[1] = 0;
  v5[2] = 0;
  v5[3] = 0;
  v5[4] = 0;
  v5[5] = 0;
  while ( 1 )
  {
    KeInitializeQueue((int)v1, 0);
    v2 = PsCreateSystemThread((int)&v4, 0x1FFFFF, (int)v5);
    if ( v2 < 0 )
      break;
    ZwClose();
    ++v0;
    v1 += 40;
    if ( v0 >= 2 )
    {
      StackOverflowFallbackSerialEvent = 1;
      byte_631DD1 = 0;
      byte_631DD2 = 4;
      dword_631DD4 = 1;
      dword_631DDC = (int)&dword_631DD8;
      dword_631DD8 = (int)&dword_631DD8;
      return v2;
    }
  }
  return v2;
}

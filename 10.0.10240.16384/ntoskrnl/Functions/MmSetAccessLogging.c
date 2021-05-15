// MmSetAccessLogging 
 
int __fastcall MmSetAccessLogging(int a1, int a2)
{
  int result; // r0
  char v5[24]; // [sp+8h] [bp-18h] BYREF

  KeAcquireInStackQueuedSpinLock((unsigned int *)&dword_634500, (unsigned int)v5);
  dword_634484 = a1;
  dword_634498 = a2;
  if ( a1 )
  {
    result = KeReleaseInStackQueuedSpinLock((int)v5);
    if ( !dword_6346A0 )
      result = KiInsertQueueDpc((int)&byte_6346A4, 0, 0, 0, 0);
  }
  else
  {
    if ( dword_634494 )
    {
      if ( dword_634494 == 2 )
        dword_634494 = 3;
    }
    else
    {
      dword_634490 = (int)MiEmptyAccessLogs;
      dword_634494 = 1;
      dword_634488 = 0;
      ExQueueWorkItem(&dword_634488, 1);
    }
    result = KeReleaseInStackQueuedSpinLock((int)v5);
  }
  return result;
}

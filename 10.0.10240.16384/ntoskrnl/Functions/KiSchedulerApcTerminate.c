// KiSchedulerApcTerminate 
 
int KiSchedulerApcTerminate()
{
  int v1; // r0

  if ( KiIsCommitFailTerminationRequested(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
    return sub_7E9050();
  v1 = PspExitThread(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3D8));
  return ExEnableRaiseUMExceptionOnInvalidHandleClose(v1);
}

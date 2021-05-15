// InbvRotateGuiBootDisplay 
 
int __fastcall InbvRotateGuiBootDisplay(int a1, int a2, int a3, unsigned int a4)
{
  unsigned int v5[4]; // [sp+0h] [bp-10h] BYREF

  v5[2] = a4;
  v5[0] = -800000;
  v5[1] = -1;
  do
  {
    KeDelayExecutionThread(0, 0, v5);
    InbvAcquireLock();
    if ( !InbvGetDisplayState() && RotBarSelection == 1 )
      RotBarUpdate();
    InbvReleaseLock();
  }
  while ( InbvCheckDisplayOwnership() );
  InbvReleaseResources();
  return PsTerminateSystemThread(0);
}

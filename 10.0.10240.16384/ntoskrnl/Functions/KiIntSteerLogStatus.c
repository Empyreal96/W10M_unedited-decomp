// KiIntSteerLogStatus 
 
void __fastcall KiIntSteerLogStatus(int a1)
{
  int v2; // r0
  int *i; // r6
  int *j; // r8

  KiIntSteerLogMask();
  v2 = KiIntSteerLogProc(a1);
  if ( a1 )
  {
    sub_541008(v2);
  }
  else if ( KiIntSteerEtwHandle )
  {
    if ( EtwEventEnabled(KiIntSteerEtwHandle, HIDWORD(KiIntSteerEtwHandle), PPM_ETW_INTERRUPT_STEERING_STATE_RETARGET) )
    {
      for ( i = (int *)KiIntTrackRootList; i != &KiIntTrackRootList; i = (int *)*i )
      {
        if ( i[33] != i[30] )
        {
          for ( j = (int *)i[2]; j != i + 2; j = (int *)*j )
            KiIntSteerLogState((int)j, (int)PPM_ETW_INTERRUPT_STEERING_STATE_RETARGET);
        }
      }
    }
  }
}

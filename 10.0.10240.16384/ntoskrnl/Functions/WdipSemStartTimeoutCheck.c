// WdipSemStartTimeoutCheck 
 
int WdipSemStartTimeoutCheck()
{
  if ( !WdipTimeoutWorkEnabled )
  {
    WdipTimeoutWorkEnabled = 1;
    WdipSemSqmInit();
    KeInitializeTimerEx(WdipTimeoutTimer, 1);
    KeInitializeDpc((int)&WdipTimeoutDpc, (int)WdipTimeoutDpcRoutine, 0);
    dword_61B6F8 = (int)WdipTimeoutCheckRoutine;
    dword_61B6FC = 0;
    WdipTimeoutWorkItem = 0;
    ExQueueWorkItem(&WdipTimeoutWorkItem, 1);
  }
  return 0;
}

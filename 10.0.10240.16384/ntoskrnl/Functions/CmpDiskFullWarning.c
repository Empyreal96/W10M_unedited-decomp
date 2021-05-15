// CmpDiskFullWarning 
 
void CmpDiskFullWarning()
{
  _DWORD *v0; // r0

  if ( !CmpDiskFullWorkerPopupDisplayed && CmpCannotWriteConfiguration && ExReadyForErrors && CmpProfileLoaded )
  {
    v0 = (_DWORD *)ExAllocatePoolWithTag(512, 16, 538987843);
    if ( v0 )
    {
      CmpDiskFullWorkerPopupDisplayed = 1;
      v0[2] = CmpDiskFullWarningWorker;
      v0[3] = v0;
      *v0 = 0;
      ExQueueWorkItem(v0, 1);
    }
  }
}

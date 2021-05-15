// SepScheduleImageVerificationCallbacks 
 
int __fastcall SepScheduleImageVerificationCallbacks(int a1, int a2)
{
  _DWORD *v4; // r0

  v4 = (_DWORD *)ExAllocatePoolWithTag(512, a2 + 24, 1668499779);
  if ( !v4 )
    return -1073741801;
  v4[2] = SepImageVerificationCallbackWorker;
  v4[3] = v4;
  *v4 = 0;
  v4[4] = a1;
  v4[5] = a2;
  ExQueueWorkItem(v4, 1);
  return 0;
}

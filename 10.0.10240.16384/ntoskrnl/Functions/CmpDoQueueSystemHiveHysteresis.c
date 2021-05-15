// CmpDoQueueSystemHiveHysteresis 
 
int __fastcall CmpDoQueueSystemHiveHysteresis(int a1)
{
  _DWORD *v2; // r0

  v2 = (_DWORD *)ExAllocatePoolWithTag(512, 16, 538987843);
  if ( !v2 )
    return 0;
  v2[3] = v2;
  CmpSystemHiveHysteresisHitRatio = a1;
  v2[2] = CmpSystemHiveHysteresisWorker;
  *v2 = 0;
  ExQueueWorkItem(v2, 1);
  return 1;
}

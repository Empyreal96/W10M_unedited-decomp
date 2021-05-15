// PspSetJobLimitsProcessCallback 
 
int __fastcall PspSetJobLimitsProcessCallback(int a1, _DWORD *a2, int a3)
{
  int v3; // r3
  int v6; // r2

  v3 = *(_DWORD *)(a1 + 188);
  if ( (v3 & 1) == 0 )
  {
    PspApplyJobLimitsToProcess(a1, a2[1], a3, v3);
    if ( (a2[1] & 1) == 0 )
    {
      v6 = *(_DWORD *)(a1 + 288);
      __dmb(0xBu);
      if ( *a2 != v6 )
        PspAddProcessToWorkingSetChangeList((void **)a1);
    }
  }
  return 0;
}

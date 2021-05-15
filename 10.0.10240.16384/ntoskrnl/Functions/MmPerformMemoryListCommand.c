// MmPerformMemoryListCommand 
 
int __fastcall MmPerformMemoryListCommand(int a1, int a2, int a3, int a4)
{
  int v5; // r0
  int v6; // r1

  if ( !a1 )
  {
    v6 = 0;
    goto LABEL_15;
  }
  if ( a1 == 1 )
  {
    v6 = 1;
LABEL_15:
    MiCaptureAllWorkingSetAccessBits(a1, v6);
    return 0;
  }
  if ( a1 == 2 )
  {
    MmEmptyAllWorkingSets();
  }
  else if ( a1 == 3 )
  {
    MmFlushAllPages();
  }
  else
  {
    if ( a1 == 4 )
    {
      v5 = 8;
    }
    else
    {
      if ( a1 != 5 )
        return -1073741637;
      v5 = 1;
    }
    MiPurgeTransitionList(v5, a2, a3, a4);
  }
  return 0;
}

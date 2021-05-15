// MiIncreaseCommitLimits 
 
int __fastcall MiIncreaseCommitLimits(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int v9; // r8
  int v10; // r0
  unsigned int *v12; // r2
  unsigned int v13; // r4
  int v14; // r2
  _DWORD v15[10]; // [sp+0h] [bp-28h] BYREF

  v15[0] = a2;
  v15[1] = a3;
  v15[2] = a4;
  v9 = 1;
  v10 = KeAcquireInStackQueuedSpinLock(a1 + 806, (unsigned int)v15);
  if ( (unsigned int)(a1[801] + a3) < a1[801] )
  {
    v9 = 0;
  }
  else
  {
    if ( a2 )
    {
      if ( a4 )
        return sub_54E7EC(v10);
      a1[1029] += a2;
    }
    if ( a3 )
      a1[801] += a3;
    MiComputeCommitThresholds(a1);
    if ( a5 )
    {
      MiUpdatePageFileList(a5, 1);
      v12 = a1 + 961;
      do
        v13 = __ldrex(v12);
      while ( __strex(v13 + 2, v12) );
      v14 = a1[899];
      __dmb(0xBu);
      a1[v14 + 900] = a5;
      __dmb(0xBu);
      a1[899] = v14 + 1;
    }
  }
  KeReleaseInStackQueuedSpinLock((int)v15);
  return v9;
}

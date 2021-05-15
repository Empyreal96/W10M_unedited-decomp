// KeSetSchedulingGroupWeights 
 
void __fastcall KeSetSchedulingGroupWeights(int a1, int a2, _DWORD *a3, int a4)
{
  _DWORD *v6; // r5
  int v7; // r4
  int v8; // r3
  _DWORD *v9; // t1
  int v10; // r3
  _DWORD v11[8]; // [sp+0h] [bp-20h] BYREF

  v11[0] = a2;
  v11[1] = a3;
  v11[2] = a4;
  v6 = a3;
  KeAcquireInStackQueuedSpinLock(KiSchedulingGroupLock, (unsigned int)v11);
  if ( a1 )
  {
    v7 = a2;
    while ( 1 )
    {
      v8 = *(_DWORD *)(*(_DWORD *)v7 + 4);
      if ( (v8 & 1) != 0 )
      {
        *(_DWORD *)(*(_DWORD *)v7 + 4) = v8 & 0xFFFFFFFE;
        if ( KiUpdateMinimumWeight(1, 0, *(_DWORD **)(*(_DWORD *)v7 + 60)) )
          break;
      }
      v9 = *(_DWORD **)v7;
      v7 += 4;
      *v9 = *v6;
      v10 = v6[1];
      v6 += 2;
      --a1;
      v9[1] = v10;
      if ( !a1 )
        goto LABEL_7;
    }
    sub_50FEB0();
  }
  else
  {
LABEL_7:
    KiUpdateMinimumWeight(0, 1, *(_DWORD **)(*(_DWORD *)a2 + 60));
    KiAssignSchedulingGroupWeights(0, 1, *(_DWORD *)(*(_DWORD *)a2 + 60));
    KeReleaseInStackQueuedSpinLock((int)v11);
  }
}

// KiEnableGroupScheduling 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall KiEnableGroupScheduling(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int v5; // r1
  int v6; // r0
  int v8; // kr00_4
  int v9; // r0
  unsigned __int64 v10; // kr08_8
  void **v11; // r1
  int v12; // t1
  int v13; // r3
  _DWORD v14[6]; // [sp+0h] [bp-18h] BYREF

  v14[0] = a2;
  v14[1] = a3;
  v14[2] = a4;
  v4 = KeAcquireInStackQueuedSpinLock(KiSchedulingGroupLock, (unsigned int)v14);
  if ( !KiGroupSchedulingEnabled )
  {
    KiSchedulingGroupList = (int)&KiSchedulingGroupList;
    dword_624D9C = (int)&KiSchedulingGroupList;
    KeUpdateGroupSchedulingConstants(v4);
    v5 = dword_690384;
    __dmb(0xBu);
    v6 = KeTickCount;
    __dmb(0xBu);
    if ( v5 != dword_690388 )
      return sub_555000(v6, v5, &KeTickCount);
    v8 = v6;
    v9 = KeNumberProcessors_0;
    v10 = __PAIR64__(v5, KiGenerationTicks) + (unsigned int)v8;
    KiGenerationEndTick = v10;
    if ( KeNumberProcessors_0 )
    {
      v11 = &KiProcessorBlock;
      do
      {
        v12 = (int)*v11++;
        *(_DWORD *)(v12 + 1984) = v12 + 1984;
        *(_DWORD *)(v12 + 1988) = v12 + 1984;
        v13 = *(_DWORD *)(v12 + 20);
        *(_QWORD *)(v12 + 2408) = v10;
        *(_DWORD *)(v12 + 2352) = 248 * v13 + 128;
        --v9;
      }
      while ( v9 );
    }
    KiGroupSchedulingEnabled = 1;
  }
  return KeReleaseInStackQueuedSpinLock((int)v14);
}

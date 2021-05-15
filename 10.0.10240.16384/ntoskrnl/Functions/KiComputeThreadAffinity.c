// KiComputeThreadAffinity 
 
int __fastcall KiComputeThreadAffinity(int a1)
{
  int v2; // r9
  int v3; // r5
  int v4; // r7
  int v5; // r1
  int v6; // r2
  int result; // r0
  int v8; // r0
  int v9; // lr
  __int16 v10; // r3
  int v11; // r0
  int v12; // [sp+8h] [bp-28h] BYREF
  int v13; // [sp+Ch] [bp-24h]
  int v14; // [sp+10h] [bp-20h]

  v2 = 0;
  if ( (*(_DWORD *)(a1 + 76) & 8) != 0 )
  {
    v3 = RtlBeginReadTickLock(&KiCpuSetSequence);
LABEL_12:
    *(_DWORD *)(a1 + 352) = v3;
    result = v2;
  }
  else
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v4 = unk_681FE4;
        v3 = KiCpuSetSequence;
        __dmb(0xBu);
        if ( (v3 & 1) == 0 )
          break;
        __dmb(0xAu);
        __yield();
      }
      v5 = *(_DWORD *)(a1 + 340);
      if ( ((v5 - 1) & v5) != 0 )
      {
        v6 = *(_DWORD *)(a1 + 336);
        if ( *(_DWORD *)(v6 + 880) | KiSystemAllowedCpuSets[0] )
        {
          if ( *(_DWORD *)(a1 + 1092) || *(_DWORD *)(v6 + 884) || KiRestrictedSystemCpuSetsActive )
            break;
        }
      }
      if ( *(_DWORD *)(a1 + 356) != v5 )
      {
        v8 = *(_DWORD *)(a1 + 124);
        *(_DWORD *)(a1 + 356) = v5;
        v9 = (int)*(&KiProcessorBlock + v8);
        if ( *(unsigned __int8 *)(v9 + 1052) != *(unsigned __int16 *)(a1 + 360) || (v5 & *(_DWORD *)(v9 + 1048)) == 0 )
        {
          v12 = 0;
          v13 = 0;
          v14 = 0;
          v10 = *(_WORD *)(a1 + 360);
          v12 = v5;
          LOWORD(v13) = v10;
          v11 = KeSelectNodeForAffinity(&v12, v5);
          v8 = KeSelectIdealProcessor(v11, &v12, 0);
        }
        *(_DWORD *)(a1 + 364) = v8;
        KiUpdateSharedReadyQueueAffinityThread(*(&KiProcessorBlock + v8), a1);
        KiUpdateNodeAffinitizedFlag(a1);
        v2 = 1;
      }
      __dmb(0xBu);
      if ( KiCpuSetSequence == v3 && unk_681FE4 == v4 )
        goto LABEL_12;
    }
    result = sub_50A884();
  }
  return result;
}

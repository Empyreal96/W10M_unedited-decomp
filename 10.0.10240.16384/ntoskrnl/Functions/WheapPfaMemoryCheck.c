// WheapPfaMemoryCheck 
 
// local variable allocation has failed, the output may be wrong!
void __fastcall WheapPfaMemoryCheck(int a1, int a2)
{
  int v2; // r9
  int v3; // r0
  unsigned int v4; // r1
  unsigned int v5; // r7
  int v6; // r8
  unsigned int v7; // r6
  int v8; // r4
  int *v9; // r2
  __int64 v10; // r0
  int v11; // r1 OVERLAPPED
  _DWORD *v12; // r2 OVERLAPPED
  __int16 v13; // r3
  unsigned int v14; // r6
  int v15; // r2
  __int64 v16; // [sp+0h] [bp-40h] BYREF
  int v17; // [sp+8h] [bp-38h] BYREF
  int v18; // [sp+Ch] [bp-34h]
  int v19; // [sp+10h] [bp-30h]
  int v20; // [sp+14h] [bp-2Ch]
  int v21; // [sp+18h] [bp-28h]
  unsigned int v22; // [sp+1Ch] [bp-24h]

  if ( !WheapPolicyMemPfaDisable && (*(_DWORD *)a2 & 2) != 0 )
  {
    v16 = *(_QWORD *)(a2 + 16);
    if ( !MmGetPageBadStatus(&v16) )
    {
      v2 = v16 >> 12;
      v3 = KeQueryInterruptTime();
      v5 = v4;
      v6 = v3;
      WheapPfaRetireExpiredMemoryEntries();
      v7 = 0;
      v8 = 0;
      v9 = (int *)WheapPfaList;
      while ( v9 != &WheapPfaList )
      {
        v8 = (int)v9;
        if ( v9[8] == v2 )
        {
          v10 = *(_QWORD *)v9;
          if ( *(int **)(*v9 + 4) != v9 || *(int **)HIDWORD(v10) != v9 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v10) = v10;
          *(_DWORD *)(v10 + 4) = HIDWORD(v10);
          goto LABEL_19;
        }
        v9 = (int *)*v9;
        ++v7;
      }
      if ( v7 >= WheapPolicyMemPfaPageCount )
      {
        *(_QWORD *)&v11 = *(_QWORD *)v8;
        if ( *(_DWORD *)(*(_DWORD *)v8 + 4) != v8 || *v12 != v8 )
          __fastfail(3u);
        *v12 = v11;
        *(_DWORD *)(v11 + 4) = v12;
        WheapSqmIncrementDword(7195);
        v18 = 3;
        v17 = 1;
        v20 = _rt_udiv64((unsigned int)dword_989680, __PAIR64__(v5, v6) - *(_QWORD *)(v8 + 16));
        v19 = 1;
        v22 = *(unsigned __int16 *)(v8 + 8);
        v21 = 1;
        WheapSqmAddToStream(7213, 3, &v17);
        WheapSqmCollectWheaPolicyTelemetry();
      }
      else
      {
        v8 = ExAllocatePoolWithTag(1, 40, 1634035799);
        if ( !v8 )
          return;
        WheapSqmDwordCommon(8, (int)WHEA_SQM_EVENT_SETIFMAXDWORD, 7196, v7 + 1);
      }
      memset((_BYTE *)v8, 0, 40);
      *(_WORD *)(v8 + 8) = 0;
      *(_DWORD *)(v8 + 16) = v6;
      *(_DWORD *)(v8 + 20) = v5;
      *(_DWORD *)(v8 + 32) = v2;
LABEL_19:
      v13 = *(_WORD *)(v8 + 8);
      *(_DWORD *)(v8 + 24) = v6;
      *(_DWORD *)(v8 + 28) = v5;
      v14 = (unsigned __int16)(v13 + 1);
      *(_WORD *)(v8 + 8) = v14;
      if ( v14 >= WheapPolicyMemPfaThreshold )
      {
        v17 = 1;
        v18 = 1;
        v20 = _rt_udiv64((unsigned int)dword_989680, __PAIR64__(v5, v6) - *(_QWORD *)(v8 + 16));
        v19 = 1;
        v21 = 1;
        v22 = v14;
        WheapSqmAddToStream(7213, 3, &v17);
        WheapSqmCollectWheaPolicyTelemetry();
        WheaAttemptPhysicalPageOffline(v2, 0);
        ExFreePoolWithTag(v8);
      }
      else
      {
        v15 = WheapPfaList;
        *(_DWORD *)v8 = WheapPfaList;
        *(_DWORD *)(v8 + 4) = &WheapPfaList;
        if ( *(int **)(v15 + 4) != &WheapPfaList )
          __fastfail(3u);
        *(_DWORD *)(v15 + 4) = v8;
        WheapPfaList = v8;
      }
    }
  }
}

// PspEstablishJobHierarchy 
 
int __fastcall PspEstablishJobHierarchy(int a1, int a2, int a3)
{
  int v3; // r10
  int v6; // r4
  int v8; // r6
  int v9; // r3
  int v10; // r2
  int v11; // r0
  _DWORD *v12; // r3
  unsigned int v13; // r7
  int v14; // r1
  int *v15; // r0
  int v16; // r2
  int v17; // r3
  int v18; // r3
  unsigned __int8 *v19; // r3
  unsigned int v20; // r2
  unsigned __int8 *v21; // r3
  unsigned int v22; // r2
  unsigned int v23; // r1
  int i; // r7
  _DWORD *v26; // r6
  int v27; // r0
  int v28; // r3
  int v29; // r7
  int v30; // r3
  int v31; // r3
  int v32; // r3
  int v33; // r3
  int v34; // r0
  unsigned int *v36; // [sp+18h] [bp-30h]

  v3 = a3;
  if ( a3 == 1 )
  {
    v6 = PspBindProcessSessionToJob(a1, a2);
    if ( v6 < 0 )
      return v6;
    ObfReferenceObject(a1);
    MmLinkJobProcess(a1, a2);
LABEL_4:
    if ( PsCpuFairShareEnabled && PsGetProcessSessionId(a2) && (v3 == 1 || v3 == 3) )
    {
      v26 = (_DWORD *)MmGetSessionSchedulingGroupByProcess(a2);
      v27 = MmGetSessionObjectByProcess(a2);
      v28 = *(_DWORD *)(a1 + 576);
      v29 = v27;
      __dmb(0xBu);
      if ( *(_DWORD *)(v28 + 532) || *(_DWORD **)(a1 + 536) == v26 )
      {
        if ( v3 == 1 )
        {
          v33 = *(_DWORD *)(a1 + 576);
          __dmb(0xBu);
          if ( v33 == a1 && *(_DWORD *)(a1 + 532) && !*(_DWORD *)(a1 + 144) && *(_DWORD *)(a1 + 592) != v27 )
          {
            KeRemoveSchedulingGroup(*(unsigned __int16 **)(a1 + 536));
            KeInsertSchedulingGroup(
              *(_DWORD *)(a1 + 532) + 128,
              *(_DWORD *)(*(_DWORD *)(a1 + 532) + 128),
              *(_DWORD *)(*(_DWORD *)(a1 + 532) + 132),
              v26);
            v34 = *(_DWORD *)(a1 + 592);
            if ( v34 )
              ObfDereferenceObject(v34);
            *(_DWORD *)(a1 + 592) = v29;
            ObfReferenceObject(v29);
          }
        }
      }
      else
      {
        v30 = *(_DWORD *)(a1 + 576);
        __dmb(0xBu);
        if ( *(_DWORD **)(v30 + 536) != v26 )
        {
          v31 = *(_DWORD *)(a1 + 576);
          __dmb(0xBu);
          *(_DWORD *)(v31 + 536) = v26;
          v32 = *(_DWORD *)(a1 + 576);
          __dmb(0xBu);
          *(_DWORD *)(v32 + 592) = v27;
        }
        *(_DWORD *)(a1 + 536) = v26;
      }
    }
    return v6;
  }
  if ( a3 == 4 )
  {
    v8 = *(_DWORD *)(a2 + 288);
    __dmb(0xBu);
    if ( *(unsigned __int8 *)(v8 + 426) + 1 > 100
      || (v9 = *(_DWORD *)(v8 + 576), __dmb(0xBu), (*(_DWORD *)(v9 + 748) & *(_DWORD *)(a1 + 748)) != 0) )
    {
      JUMPOUT(0x7C1D58);
    }
    v10 = 0;
    v36 = (unsigned int *)(a1 + 744);
    do
    {
      if ( v10 != 2 )
      {
        v11 = PspGetRateControlJobFlag(v10, 0);
        if ( (v11 & *v12) != 0 )
          JUMPOUT(0x7C1D60);
      }
      ++v10;
    }
    while ( v10 < 3 );
    v13 = *(_DWORD *)(v8 + 588) + 1;
    if ( v13 > 2 )
      JUMPOUT(0x7C1D6A);
    v6 = PspBindProcessSessionToJob(a1, a2);
    if ( v6 < 0 )
      JUMPOUT(0x7C203A);
    __dmb(0xBu);
    v14 = *(_DWORD *)(v8 + 576);
    __dmb(0xBu);
    *(_DWORD *)(v14 + 748) |= *(_DWORD *)(a1 + 748);
    ObfReferenceObject(a1);
    v15 = *(int **)(v8 + 568);
    v16 = a1 + 556;
    *(_DWORD *)(a1 + 556) = v8 + 564;
    *(_DWORD *)(a1 + 560) = v15;
    if ( *v15 != v8 + 564 )
      JUMPOUT(0x7C1D84);
    *v15 = v16;
    *(_DWORD *)(v8 + 568) = v16;
    *(_DWORD *)(a1 + 572) = v8;
    v17 = *(_DWORD *)(v8 + 576);
    __dmb(0xBu);
    *(_DWORD *)(a1 + 576) = v17;
    LOBYTE(v17) = *(_BYTE *)(v8 + 426);
    *(_DWORD *)(a1 + 588) = v13;
    *(_BYTE *)(a1 + 426) = v17 + 1;
    PspUnlinkJobProcess(v8, a2);
    MmLinkJobProcess(a1, a2);
    if ( *(_DWORD *)(a1 + 536) )
      JUMPOUT(0x7C1DB8);
    v18 = *(_DWORD *)(v8 + 536);
    if ( v18 )
      *(_DWORD *)(a1 + 536) = v18;
    PspSetEffectiveJobLimits(a1, 0);
    *(_DWORD *)(a1 + 408) += *(_DWORD *)(v8 + 408);
    *(_DWORD *)(a1 + 416) += *(_DWORD *)(v8 + 416);
    *(_DWORD *)(a1 + 412) += *(_DWORD *)(v8 + 412);
    *(_DWORD *)(a1 + 420) += *(_DWORD *)(v8 + 420);
    if ( (*(_DWORD *)(*(_DWORD *)(a1 + 572) + 744) & 0x40000) != 0 )
    {
      __dmb(0xBu);
      v19 = (unsigned __int8 *)(a1 + 746);
      do
        v20 = __ldrex(v19);
      while ( __strex(v20 | 4, v19) );
      __dmb(0xBu);
    }
    if ( (*(_DWORD *)(a1 + 744) & 0x1000) == 0 && (*(_DWORD *)(v8 + 744) & 0x1000) != 0 )
    {
      __dmb(0xBu);
      v21 = (unsigned __int8 *)(a1 + 745);
      do
        v22 = __ldrex(v21);
      while ( __strex(v22 | 0x10, v21) );
      __dmb(0xBu);
    }
    if ( (*(_DWORD *)(*(_DWORD *)(a1 + 572) + 744) & 0x1000000) != 0 )
    {
      __dmb(0xBu);
      do
        v23 = __ldrex(v36);
      while ( __strex(v23 | 0x1000000, v36) );
      __dmb(0xBu);
      if ( (*(_DWORD *)(*(_DWORD *)(a1 + 572) + 744) & 0x800000) != 0 )
        JUMPOUT(0x7C2012);
    }
    for ( i = 0; i < 3; ++i )
    {
      if ( i != 2 )
      {
        if ( i ? *(_DWORD *)(v8 + 388) : *(_DWORD *)(v8 + 392) )
          JUMPOUT(0x7C202E);
      }
    }
    v3 = a3;
    goto LABEL_4;
  }
  return sub_7C1D40();
}

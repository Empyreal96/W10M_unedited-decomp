// MiChargeCommit 
 
int __fastcall MiChargeCommit(int a1, unsigned int a2, char a3)
{
  char v3; // lr
  unsigned int v6; // r3
  int v7; // r9
  unsigned int *v8; // r6
  unsigned int v9; // r5
  unsigned int v10; // r7
  int v12; // r7
  int v13; // r0
  unsigned int *v14; // r1
  unsigned int v15; // r6
  unsigned int v16; // r5
  unsigned int v17; // r3
  unsigned int v18; // r7
  unsigned int v19; // r2
  unsigned int v20; // r3
  unsigned int v21; // r5
  unsigned int v22; // r3
  unsigned int v23; // r6
  unsigned int v24; // r2
  unsigned int v25; // r3
  int v26; // r3
  unsigned int v27; // r2
  int v28; // r2
  int v29; // r3
  unsigned int v30; // r3
  bool v31; // cc
  unsigned int v32; // r1
  unsigned int v33; // r3
  char v34; // [sp+0h] [bp-28h]
  int v35; // [sp+4h] [bp-24h]

  v3 = a3;
  v34 = a3;
  v6 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v7 = v6 + 1408;
  if ( (__int16 *)a1 != MiSystemPartition
    || (v8 = (unsigned int *)(v6 + 4988), __pld((void *)(v6 + 4988)), v9 = *(_DWORD *)(v6 + 4988), a2 > v9) )
  {
    if ( (a3 & 4) != 0 )
    {
      v3 = a3 | 2;
      v34 = a3 | 2;
    }
    if ( (v3 & 8) != 0 )
    {
      v3 |= 2u;
      v34 = v3;
      if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C4) & 2) == 0 )
        goto LABEL_12;
      if ( (__get_CPSR() & 0x80) != 0 )
      {
        v28 = 0;
      }
      else
      {
        __disable_irq();
        v28 = 1;
      }
      v29 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
      if ( v28 )
        __enable_irq();
      if ( (v29 & 0x10001) != 0 )
      {
LABEL_12:
        v12 = 64;
        v35 = 64;
        if ( (__int16 *)a1 == MiSystemPartition || *(_DWORD *)(a1 + 3592) >> 6 >= 0x40u )
          goto LABEL_13;
        v12 = *(_DWORD *)(a1 + 3592) >> 6;
      }
      else
      {
        v3 |= 4u;
        v34 = v3;
        v12 = 0;
      }
    }
    else if ( (v3 & 7) != 0 )
    {
      v12 = 0;
    }
    else
    {
      v12 = *(_DWORD *)(a1 + 3228);
    }
    v35 = v12;
LABEL_13:
    v13 = 4116;
    v14 = (unsigned int *)(a1 + 3844);
    do
    {
      v15 = *v14;
      v16 = *v14 + a2;
      if ( v16 <= *v14 || (v17 = v16 + v12, v16 + v12 < v16) )
      {
        if ( (v3 & 4) == 0 )
        {
          if ( (v3 & 2) == 0 )
          {
            ++*(_DWORD *)(a1 + 4144);
            if ( (v3 & 1) == 0 )
              MiCauseOverCommitPopup(a1);
            MiPulseCommitSignal(a1);
          }
          return 0;
        }
        if ( !v12 )
        {
          v13 = 4116;
          ++dword_634400;
        }
      }
      else
      {
        v18 = *(_DWORD *)(a1 + 4116);
        if ( v17 > v18 )
        {
          v30 = *(_DWORD *)(a1 + 3220);
          if ( v16 >= v30 && v15 < v30 )
          {
            MiPulseCommitSignal(a1);
            v3 = v34;
            v14 = (unsigned int *)(a1 + 3844);
            v13 = 4116;
          }
          if ( (v3 & 4) == 0 )
          {
            if ( (v3 & 2) == 0 )
            {
              if ( v18 == *(_DWORD *)(a1 + 3204) )
              {
                ++*(_DWORD *)(a1 + 4136);
                MiTrimSegmentCache(4116);
                if ( (v34 & 1) == 0 )
                  MiCauseOverCommitPopup(a1);
              }
              else if ( (v3 & 1) != 0 )
              {
                ++*(_DWORD *)(a1 + 4140);
                MiIssuePageExtendRequestNoWait(a1, 4096, 0);
              }
              else
              {
                if ( MiIssuePageExtendRequest(a1, a2, 255, 0) )
                {
                  v3 = v34;
                  v12 = v35;
                  goto LABEL_13;
                }
                ++*(_DWORD *)(a1 + 4132);
                MiCauseOverCommitPopup(a1);
              }
            }
            return 0;
          }
          v12 = v35;
          if ( !v35 )
          {
            ++dword_6343FC;
            v13 = 4116;
          }
        }
        else
        {
          v12 = v35;
        }
      }
      do
        v19 = __ldrex(v14);
      while ( v19 == v15 && __strex(v16, v14) );
    }
    while ( v19 != v15 );
    v20 = *(_DWORD *)(a1 + 3220);
    v21 = v19 + a2;
    if ( v19 + a2 >= v20 && v15 < v20 || (v22 = *(_DWORD *)(a1 + 3216), v21 >= v22) && v15 < v22 )
    {
      MiSyncCommitSignals(a1, 0);
      v3 = v34;
      v13 = 4116;
    }
    if ( v21 > *(_DWORD *)(a1 + 3200) )
      *(_DWORD *)(a1 + 3200) = v21;
    if ( (v3 & 2) != 0 )
      return 1;
    v23 = *(_DWORD *)(a1 + 4116);
    v24 = v23 / 0xA;
    if ( v21 < 9 * (v23 / 0xA) )
      goto LABEL_27;
    v31 = v21 > v23;
    if ( v21 < v23 )
    {
      if ( v23 - v21 >= 0x400000 )
      {
LABEL_27:
        if ( (__int16 *)a1 == MiSystemPartition )
        {
          if ( (v3 & 1) == 0 && v21 >= *(_DWORD *)(a1 + 3220) && v23 == *(_DWORD *)(a1 + 3204) )
            MiTrimSegmentCache(v13);
          v25 = *(_DWORD *)(v7 + 3580);
          if ( v25 < 0x80 )
          {
            v26 = 256 - v25;
            if ( v21 + v26 > v21 )
            {
              v27 = v21 + v26 + v12;
              if ( v27 > v21 && v27 <= v23 )
                MiReplenishLocalCommit((_DWORD *)a1, v7, v21, v26);
            }
          }
        }
        return 1;
      }
      v31 = v21 > v23;
    }
    if ( !v31 )
    {
      v32 = *(_DWORD *)(a1 + 3204);
      if ( v23 < v32 && v21 < v32 )
      {
        if ( v24 > 0x40000 )
          v24 = 0x40000;
        v33 = v24 - v21 + v23;
        if ( v33 > v32 - v23 )
          v33 = v32 - v23;
        v13 = MiIssuePageExtendRequestNoWait(a1, v33, 0);
        v3 = v34;
      }
    }
    goto LABEL_27;
  }
  do
    v10 = __ldrex(v8);
  while ( v10 == v9 && __strex(v9 - a2, v8) );
  if ( v10 != v9 )
    return sub_53062C();
  return 1;
}

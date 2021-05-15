// KiSetPriorityThread 
 
int __fastcall KiSetPriorityThread(int result, _DWORD *a2, int a3, int a4)
{
  unsigned int v4; // r3
  int v6; // r4
  int v7; // r5
  int v8; // r0
  int v9; // r6
  _DWORD *v10; // r8
  int v11; // r7
  int v12; // r10
  char v13; // r2
  int v14; // r0
  int v15; // r5
  char v16; // r2
  int v17; // r2
  int v18; // r1
  signed int v19; // r3
  int v20; // r2
  unsigned int *v21; // r1
  unsigned int v22; // r4
  unsigned int v23; // r3
  char v24; // r3
  char v25; // r2
  int v26; // r0
  int v27; // r5
  char v28; // r2
  int v29; // r2
  int v30; // r1
  int v31; // r2
  int v32; // r1
  int v33; // r2
  int v34; // r1
  char v35; // r3
  int v36; // [sp+0h] [bp-28h]
  _DWORD *v37; // [sp+4h] [bp-24h] BYREF
  int v38[8]; // [sp+8h] [bp-20h] BYREF

  v37 = (_DWORD *)a3;
  v38[0] = a4;
  v4 = *(_DWORD *)(result + 800);
  v6 = result;
  v7 = (char)a3;
  if ( v4 )
  {
    v19 = 31 - __clz(v4);
    if ( (char)a3 < v19 )
      v7 = (char)v19;
  }
  if ( *(char *)(result + 123) != v7 )
  {
    v8 = KiAcquireThreadStateLock(result, v38, &v37);
    v10 = v37;
    v9 = v38[0];
    v11 = 0;
    v36 = *(char *)(v6 + 123);
    v12 = 1;
    switch ( v8 )
    {
      case 2:
        if ( *(_DWORD *)(v38[0] + 8) )
          v12 = 0;
        KiAbProcessThreadPriorityModification(v6, v7, 1);
        *(_BYTE *)(v6 + 123) = v7;
        if ( v12 )
        {
          if ( (*(_BYTE *)(v6 + 2) & 4) != 0 )
          {
            if ( v7 < 16
              && *(_DWORD *)(v6 + 68)
              && (v17 = *(_DWORD *)(v6 + 68)) != 0
              && (v18 = *(_DWORD *)(v9 + 2352) + v17) != 0
              && KiGetThreadEffectiveRankNonZero(v6, v18, 0) )
            {
              v13 = 1;
            }
            else
            {
              v13 = *(_BYTE *)(v6 + 123);
            }
          }
          else
          {
            v13 = v7;
          }
          **(_BYTE **)(v9 + 28) = v13;
        }
        if ( v7 < v36 && v12 )
        {
          if ( *(_BYTE *)(v6 + 132) == 2 )
          {
            v14 = KiSelectReadyThreadEx(v9, v6, 0);
            v15 = v14;
            if ( v14 )
            {
              if ( (*(_BYTE *)(v14 + 2) & 4) != 0 )
              {
                if ( *(char *)(v14 + 123) < 16
                  && *(_DWORD *)(v14 + 68)
                  && (v29 = *(_DWORD *)(v14 + 68)) != 0
                  && (v30 = *(_DWORD *)(v9 + 2352) + v29) != 0
                  && KiGetThreadEffectiveRankNonZero(v14, v30, 0) )
                {
                  v16 = 1;
                }
                else
                {
                  v16 = *(_BYTE *)(v15 + 123);
                }
              }
              else
              {
                v16 = *(_BYTE *)(v14 + 123);
              }
              **(_BYTE **)(v9 + 28) = v16;
              *(_DWORD *)(v9 + 8) = v15;
              *(_BYTE *)(v15 + 132) = 3;
              v11 = 1;
            }
          }
          else if ( *(_DWORD *)(v9 + 1932) >> (v7 + 1) )
          {
            *(_BYTE *)(v6 + 72) |= 0x10u;
          }
        }
        break;
      case 1:
        KiRemoveThreadFromAnyReadyQueue(v38[0], (int)v37, v6, *(_BYTE *)(v6 + 123));
        KiAbProcessThreadPriorityModification(v6, v7, 1);
        *(_BYTE *)(v6 + 123) = v7;
        KiPrepareReadyThreadForRescheduling(v6, v7, a2);
        break;
      case 3:
        KiAbProcessThreadPriorityModification(v6, v7, 1);
        v24 = *(_BYTE *)(v6 + 2);
        *(_BYTE *)(v6 + 123) = v7;
        if ( (v24 & 4) != 0 )
        {
          if ( v7 < 16
            && *(_DWORD *)(v6 + 68)
            && (v31 = *(_DWORD *)(v6 + 68)) != 0
            && (v32 = *(_DWORD *)(v9 + 2352) + v31) != 0
            && KiGetThreadEffectiveRankNonZero(v6, v32, 0) )
          {
            v25 = 1;
          }
          else
          {
            v25 = *(_BYTE *)(v6 + 123);
          }
        }
        else
        {
          v25 = v7;
        }
        **(_BYTE **)(v9 + 28) = v25;
        if ( v7 < v36 )
        {
          v26 = KiSelectReadyThreadEx(v9, v6, 0);
          v27 = v26;
          if ( v26 )
          {
            if ( (*(_BYTE *)(v26 + 2) & 4) != 0 )
            {
              if ( *(char *)(v26 + 123) < 16
                && *(_DWORD *)(v26 + 68)
                && (v33 = *(_DWORD *)(v26 + 68)) != 0
                && (v34 = *(_DWORD *)(v9 + 2352) + v33) != 0
                && KiGetThreadEffectiveRankNonZero(v26, v34, 0) )
              {
                v35 = 1;
              }
              else
              {
                v35 = *(_BYTE *)(v27 + 123);
              }
              v28 = v35;
            }
            else
            {
              v28 = *(_BYTE *)(v26 + 123);
            }
            **(_BYTE **)(v9 + 28) = v28;
            *(_DWORD *)(v9 + 8) = v27;
            *(_BYTE *)(v27 + 132) = 3;
            *(_BYTE *)(v6 + 132) = 7;
            *(_DWORD *)(v6 + 144) = *a2;
            *a2 = v6 + 144;
          }
        }
        break;
      default:
        KiAbProcessThreadPriorityModification(v6, v7, 1);
        *(_BYTE *)(v6 + 123) = v7;
        break;
    }
    result = KiUpdateSharedReadyQueueAffinityThread(0, v6);
    if ( v9 )
    {
      __dmb(0xBu);
      *(_DWORD *)(v9 + 24) = 0;
    }
    if ( v10 )
    {
      __dmb(0xBu);
      *v10 = 0;
    }
    if ( v11 )
    {
      result = *(_DWORD *)(v9 + 20);
      if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x594) != result )
      {
        v20 = (int)*(&KiProcessorBlock + result);
        __dmb(0xBu);
        v21 = (unsigned int *)(v20 + 1676);
        do
          v22 = __ldrex(v21);
        while ( __strex(v22 | 2, v21) );
        __dmb(0xBu);
        v23 = (unsigned int)KeGetPcr();
        ++*(_DWORD *)((v23 & 0xFFFFF000) + 0x1414);
        result = HalSendSoftwareInterrupt(result, 2);
      }
    }
  }
  return result;
}

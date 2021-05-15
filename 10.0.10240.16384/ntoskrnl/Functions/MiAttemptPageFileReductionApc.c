// MiAttemptPageFileReductionApc 
 
int __fastcall MiAttemptPageFileReductionApc(_DWORD *a1)
{
  unsigned int v1; // r7
  _DWORD *v2; // r8
  unsigned int v4; // r1
  int v5; // r0
  unsigned int v6; // r3
  unsigned int v7; // r4
  unsigned int v8; // r4
  unsigned int v9; // r1
  unsigned int *v10; // r5
  __int16 v11; // r3
  unsigned int v12; // r6
  unsigned int v13; // r10
  int v14; // lr
  unsigned int v15; // r1
  int v16; // r0
  unsigned int v17; // r6
  unsigned int v18; // r3
  unsigned int v19; // r4
  unsigned int v20; // r0
  int v21; // r0
  int v22; // r1
  unsigned int v23; // r3
  unsigned int v24; // r6
  unsigned int v25; // r2
  unsigned int v26; // r3
  int v27; // r3
  int v29; // [sp+0h] [bp-60h]
  int v30; // [sp+4h] [bp-5Ch]
  int v31; // [sp+8h] [bp-58h]
  int v32; // [sp+Ch] [bp-54h]
  unsigned int v33; // [sp+10h] [bp-50h]
  int v34; // [sp+14h] [bp-4Ch]
  unsigned int v35; // [sp+18h] [bp-48h]
  unsigned int v36; // [sp+1Ch] [bp-44h]
  _DWORD v37[2]; // [sp+20h] [bp-40h] BYREF
  unsigned int v38[2]; // [sp+28h] [bp-38h] BYREF
  unsigned int v39[2]; // [sp+30h] [bp-30h] BYREF
  char v40[40]; // [sp+38h] [bp-28h] BYREF

  v1 = a1[5];
  v2 = (_DWORD *)a1[4];
  if ( v1 >= 2 )
  {
    v8 = v2[961];
    if ( !MiOkToShrinkPageFiles(v8, v2[1029]) )
      return KeSetEvent((int)a1, 0, 0);
    v32 = 0x8000;
    v7 = 8 * (v9 / 0xA) - v8 - 0x8000;
    v30 = v7;
    v31 = 1;
    v6 = v2[899];
    v4 = 0x4000;
    v5 = 1;
    v33 = v6;
    v34 = 1;
    v29 = 0x4000;
    v1 = 0;
    __dmb(0xBu);
  }
  else
  {
    v4 = a1[6];
    v32 = 0;
    v5 = 0;
    v6 = v1 + 1;
    v7 = 0x7FFFFFFF;
    v33 = v1 + 1;
    v34 = 0;
    v29 = v4;
    v30 = 0x7FFFFFFF;
    v31 = 0;
  }
  if ( v1 < v6 )
  {
    while ( v4 <= v7 )
    {
      v10 = (unsigned int *)v2[v1 + 900];
      v11 = *((_WORD *)v10 + 48);
      if ( ((v11 & 0x10) == 0 || !v5) && (v11 & 0x40) == 0 && *v10 != v10[2] && v10[3] >= v4 )
      {
        v12 = v10[16];
        v2 = (_DWORD *)v10[32];
        v36 = v12;
        KeAcquireInStackQueuedSpinLock(v10 + 29, (unsigned int)v40);
        v13 = *v10;
        v14 = *(_DWORD *)(v12 + 8);
        v15 = *v10 - 1;
        if ( ((*(char *)((v15 >> 3) + v14) >> (v15 & 7)) & 1) != 0
          || (v16 = *(_DWORD *)(v12 + 16), ((*(char *)((v15 >> 3) + v16) >> (v15 & 7)) & 1) != 0) )
        {
          v22 = v29;
          v21 = v31;
          v19 = 0;
        }
        else
        {
          v17 = v7;
          if ( v7 > v13 - v10[2] )
            v17 = v13 - v10[2];
          v18 = (v13 - v17) & 0xFFFFFFE0;
          v38[0] = v13 - v18;
          v38[1] = v14 + 4 * (v18 >> 5);
          v35 = v13 - v18;
          v39[0] = v13 - v18;
          v39[1] = v16 + 4 * (v18 >> 5);
          v19 = RtlFindLastBackwardRunClear(v38, v13 - v18 - 1, v37);
          if ( v19 > v17 )
            v19 = v17;
          v20 = RtlFindLastBackwardRunClear(v39, v35 - 1, v37);
          if ( v19 > v20 )
            v19 = v20;
          v21 = v31;
          v22 = v29;
          if ( !v31 )
            v19 &= ~(v29 - 1);
        }
        if ( !v19 )
          goto LABEL_24;
        v23 = v10[31];
        v24 = v13 - v19;
        if ( !v23 )
          goto LABEL_35;
        do
        {
          v25 = v23;
          v23 = *(_DWORD *)(v23 + 4);
        }
        while ( v23 );
        v26 = *(_DWORD *)(v25 - 4);
        if ( !v26 || v24 > v26 )
          goto LABEL_35;
        v24 = v26 + 1;
        if ( v26 + 1 < v26 )
          goto LABEL_24;
        v19 = v13 - v24;
        if ( !v21 )
        {
          v19 &= ~(v22 - 1);
          v24 = v13 - v19;
        }
        if ( !v19 )
        {
LABEL_24:
          KeReleaseInStackQueuedSpinLock((int)v40);
          v4 = v29;
          v7 = v30;
        }
        else
        {
LABEL_35:
          v10[3] -= v19;
          v10[6] -= v19;
          *v10 = v24;
          RtlSetBits((_BYTE *)(v36 + 4), v24, v19);
          RtlSetBits((_BYTE *)(v36 + 12), v24, v19);
          KeReleaseInStackQueuedSpinLock((int)v40);
          v30 -= v19;
          if ( (v10[24] & 0x10) == 0 )
          {
            if ( !MiChargeCommit((int)v2, v19 + v32, 2) )
            {
              KeAcquireInStackQueuedSpinLock(v10 + 29, (unsigned int)v40);
              *v10 = v24 + v19;
              v10[3] += v19;
              v10[6] += v19;
              RtlClearBits((_BYTE *)(v10[16] + 4), v24, v19);
              RtlClearBits((_BYTE *)(v10[16] + 12), v24, v19);
              if ( v24 < v10[17] )
                v10[17] = v24;
              KeReleaseInStackQueuedSpinLock((int)v40);
              return KeSetEvent((int)a1, 0, 0);
            }
            MiReduceCommitLimits(v2, v19, 0, v27);
            MiReturnCommit((int)v2, v19 + v32);
          }
          v4 = v29;
          v7 = v30;
          a1[v1 + 7] = v24;
        }
      }
      if ( ++v1 >= v33 )
        return KeSetEvent((int)a1, 0, 0);
      v5 = v34;
    }
  }
  return KeSetEvent((int)a1, 0, 0);
}

// ExpWorkerThreadBalanceManager 
 
int __fastcall ExpWorkerThreadBalanceManager(unsigned __int16 a1)
{
  int v2; // r8
  int v3; // r0
  int v4; // r6
  int v6; // r9
  int v7; // r0
  int v8; // r7
  int v9; // r4
  int *v10; // r5
  int v11; // r0
  int v12; // t1
  __int64 v13; // r0
  int v14; // r3
  int v15; // r2
  int v16; // r2
  int v17; // r3
  int v18; // r4
  int v19; // r2
  int *v20; // r5
  int v21; // r0
  int v22; // t1
  unsigned __int64 v23; // r8
  int v24; // r4
  _DWORD *v25; // r5
  _DWORD *v26; // r0
  _DWORD *v27; // t1
  unsigned int v28; // r3
  int v29; // r1
  int v30; // r2
  int v31; // r3
  int v32; // r1
  int v33; // r2
  int v34; // r2
  int v35; // r3
  int v36; // [sp+10h] [bp-50h]
  unsigned __int16 v37; // [sp+14h] [bp-4Ch] BYREF
  int v38; // [sp+18h] [bp-48h]
  unsigned __int64 v39; // [sp+1Ch] [bp-44h]
  int v40; // [sp+28h] [bp-38h] BYREF
  unsigned __int16 v41; // [sp+2Ch] [bp-34h]
  unsigned int v42[10]; // [sp+38h] [bp-28h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v38 = v2;
  v3 = KeSetActualBasePriorityThread(v2, 12);
  v4 = (int)*(&KeNodeBlock + a1);
  if ( (_UNKNOWN *)v4 != (_UNKNOWN *)((char *)&KiNodeInit + 384 * a1) )
  {
    v6 = 0;
    v36 = 0;
    v39 = ExpWorkerThreadTimeoutInSeconds * (__int64)(int)dword_989680;
    v42[0] = v4 + 872;
    v42[1] = v4 + 856;
    v42[2] = v4 + 920;
    while ( 1 )
    {
      v7 = KeWaitForMultipleObjects(3u, v42, 1, 0, 1, 0, 0, (int *)(v4 + 936));
      v8 = 0;
      if ( v7 == 1 )
        break;
      if ( v7 )
      {
        if ( v7 != 2 )
          goto LABEL_9;
        v23 = v39;
        v24 = 8;
        v25 = (_DWORD *)(v4 + 384);
        do
        {
          v27 = (_DWORD *)*v25++;
          v26 = v27;
          if ( ((unsigned __int8)v27 & 1) == 0 )
          {
            if ( v26 )
            {
              if ( (v26[106] & 0x4000) == 0 && !v26[1] )
              {
                v28 = (v26[106] & 0x3FFF) - ((2 * v26[107]) >> 1);
                if ( v28 )
                  KeTimeOutQueueWaiters((int)v26, v23, v28);
              }
            }
          }
          --v24;
        }
        while ( v24 );
LABEL_8:
        v2 = v38;
        v6 = v36;
        goto LABEL_9;
      }
      v32 = *(_DWORD *)(v4 + 384);
      v6 = 0;
      v36 = 0;
      if ( (v32 & 1) != 0 )
        v32 = 0;
      v33 = *(_DWORD *)(v32 + 416);
      __dmb(0xBu);
      if ( v33 == *(_DWORD *)(v32 + 420) )
      {
        v34 = *(_DWORD *)(v32 + 424);
        __dmb(0xBu);
        if ( v34 < (2 * *(_DWORD *)(v32 + 428)) >> 1
          || v34 < 0x3FFF
          && (v34 = v32 + 8, *(_DWORD *)(v32 + 8) == v32 + 8)
          && (*(_DWORD *)(v32 + 4) || (v35 = *(_DWORD *)(v32 + 428), __dmb(0xBu), (v35 & 0x80000000) != 0)) )
        {
          if ( (ExpWorkerQueueTestFlags & 2) != 0 )
            KeBugCheckEx(355, ExpWorkerQueueTestFlags, 2, 0, 0);
          if ( ExpCreateWorkerThread(v4, v32, v34, (int)&ExpWorkerQueueTestFlags) < 0 )
          {
            v8 = 1;
LABEL_9:
            if ( v6 )
              goto LABEL_14;
            goto LABEL_10;
          }
        }
      }
LABEL_10:
      HIDWORD(v13) = *(_DWORD *)(v4 + 384);
      if ( (v13 & 0x100000000i64) != 0 )
        HIDWORD(v13) = 0;
      v14 = *(_DWORD *)(HIDWORD(v13) + 416);
      __dmb(0xBu);
      *(_DWORD *)(HIDWORD(v13) + 420) = v14;
      v15 = *(_DWORD *)(HIDWORD(v13) + 424);
      __dmb(0xBu);
      if ( (v15 & 0x3FFF) >= *(_DWORD *)(HIDWORD(v13) + 432) || v8 )
      {
        LODWORD(v13) = v4 + 872;
        KeSetCoalescableTimer(v13, -10000000i64, 0, 0xA0u, 0);
        v6 = 1;
        v36 = 1;
      }
LABEL_14:
      KeQueryNodeActiveAffinity(*(unsigned __int16 *)(v4 + 266), &v40, &v37);
      v16 = *(unsigned __int16 *)(v2 + 344);
      v17 = v41;
      if ( v16 != v41 || (v16 = *(_DWORD *)(v2 + 340), v17 = v40, v16 != v40) )
        KeSetAffinityThread(v2, (int)&v40, v16, v17);
      v18 = v37;
      v19 = 8;
      v20 = (int *)(v4 + 384);
      do
      {
        v22 = *v20++;
        v21 = v22;
        if ( (v22 & 1) == 0 && v21 && *(_DWORD *)(v21 + 400) != v18 )
          KeSetMaximumCountPriQueue(v21, v18);
        --v19;
      }
      while ( v19 );
    }
    v9 = 0;
    v10 = (int *)(v4 + 384);
    do
    {
      v12 = *v10++;
      v11 = v12;
      if ( v12 )
      {
        if ( (v11 & 1) != 0 )
        {
          v11 = ExpAllocatePoolForNode(v4, v9);
          if ( !v11 )
            goto LABEL_36;
        }
        v29 = *(_DWORD *)(v11 + 432);
        v30 = *(_DWORD *)(v11 + 424);
        __dmb(0xBu);
        v31 = (2 * *(_DWORD *)(v11 + 428)) >> 1;
        if ( v30 < v31
          || v30 < v29
          && (v30 = v11 + 8, *(_DWORD *)(v11 + 8) == v11 + 8)
          && ((v31 = *(_DWORD *)(v11 + 4)) != 0 || (v31 = *(_DWORD *)(v11 + 428), __dmb(0xBu), (v31 & 0x80000000) != 0)) )
        {
          if ( ExpCreateWorkerThread(v4, v11, v30, v31) < 0 )
LABEL_36:
            v8 = 1;
        }
      }
      ++v9;
    }
    while ( v9 < 8 );
    goto LABEL_8;
  }
  return sub_812AE8(v3);
}

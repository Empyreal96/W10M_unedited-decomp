// MiInitializeImageProtos 
 
int __fastcall MiInitializeImageProtos(int a1, int a2, int a3)
{
  unsigned int v3; // r3
  __int64 v5; // r0
  int v6; // r5
  int v7; // r9
  int v8; // r7
  int v9; // r2
  unsigned int v10; // r6
  __int16 v11; // r3
  unsigned int v12; // r4
  unsigned int v13; // r10
  __int64 v14; // kr08_8
  int v15; // r2
  int v16; // r3
  unsigned int v17; // r8
  int v18; // r5
  int v19; // r4
  int v20; // r7
  int v21; // r4
  unsigned __int8 *v22; // r3
  unsigned int v23; // r1
  unsigned __int8 *v24; // r1
  int v25; // r3
  unsigned int v26; // r2
  char v28[4]; // [sp+8h] [bp-58h] BYREF
  int v29; // [sp+Ch] [bp-54h]
  int v30; // [sp+10h] [bp-50h]
  int v31; // [sp+14h] [bp-4Ch]
  int v32; // [sp+18h] [bp-48h]
  unsigned int v33; // [sp+1Ch] [bp-44h]
  int v34; // [sp+20h] [bp-40h]
  unsigned int v35; // [sp+24h] [bp-3Ch]
  int v36; // [sp+28h] [bp-38h]
  int v37; // [sp+2Ch] [bp-34h]
  unsigned int v38; // [sp+30h] [bp-30h]
  int v39; // [sp+34h] [bp-2Ch]
  int v40; // [sp+38h] [bp-28h]
  unsigned int v41; // [sp+3Ch] [bp-24h]
  unsigned int i; // [sp+40h] [bp-20h]

  v3 = *(_DWORD *)(a2 + 20);
  v36 = a3;
  v37 = a1;
  v38 = v3;
  v40 = a2;
  LODWORD(v5) = MiGetEffectivePagePriorityThread((_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0));
  v32 = v5;
  if ( (unsigned int)v5 > 5 )
  {
    LODWORD(v5) = sub_53AACC();
    return v5;
  }
  if ( (_DWORD)v5 )
    v32 = v5 - 1;
  v6 = a1 + 80;
  v7 = 17;
  v8 = 0;
  v31 = a1 + 80;
  v39 = a1 + 80;
  v29 = 17;
  v28[0] = 17;
  v34 = 0;
  if ( a1 != -80 )
  {
    do
    {
      v9 = *(_DWORD *)(v6 + 8);
      v10 = *(_DWORD *)(v6 + 4);
      v11 = *(_WORD *)(v6 + 18);
      v30 = v9;
      if ( (v11 & 2) == 0 )
      {
        v14 = MiStartingOffset(v6, v10, -1);
        v12 = HIDWORD(v14);
        v13 = v14;
        v5 = MiEndingOffset(v6);
        v16 = *(_DWORD *)(v6 + 28);
        v41 = HIDWORD(v5);
        v35 = v5;
        for ( i = v10 + 4 * v16; v10 < i; v7 = v29 )
        {
          if ( (v10 & 0xFFF) != 0 )
          {
            if ( v8 )
              goto LABEL_10;
          }
          else if ( v8 )
          {
            MiUnlockProtoPoolPage(v8, v7);
          }
          LODWORD(v5) = MiLockProtoPoolPage(v10, v28);
          v8 = v5;
          v34 = v5;
          if ( !(_DWORD)v5 )
          {
            LODWORD(v5) = MmAccessFault(1, v10, 0, 0);
            v29 = (unsigned __int8)v28[0];
            continue;
          }
          v29 = (unsigned __int8)v28[0];
LABEL_10:
          v12 = (__PAIR64__(v12, v13) + 4096) >> 32;
          v33 = v12;
          if ( __PAIR64__(v12, v13 + 4096) > v38 )
          {
            v9 = 0;
            v7 = v29;
            v30 = 0;
            goto LABEL_33;
          }
          v17 = *(_DWORD *)v10;
          if ( (*(_DWORD *)v10 & 2) == 0 && ((v17 >> 10) & 1) != 0 )
          {
            if ( v6 == v39 && v10 == *(_DWORD *)(v6 + 4) )
            {
              v15 = v36 - MmPfnDatabase;
              HIDWORD(v5) = (unsigned __int64)(715827883i64 * (v36 - MmPfnDatabase)) >> 32;
              v18 = (v36 - MmPfnDatabase) / 24;
            }
            else
            {
              LODWORD(v5) = MiGetPageForHeader(
                              (*(_DWORD *)(v37 + 28) >> 20) & 0x3F,
                              SHIDWORD(v5),
                              v15,
                              *(_DWORD *)(v37 + 28));
              v18 = v5;
            }
            if ( v18 != -1 )
            {
              if ( (*(_WORD *)(v40 + 6) & 5) != 0 )
                v19 = *(_DWORD *)(v40 + 12);
              else
                v19 = MmMapLockedPagesSpecifyCache(v40, 0, 1, 0, 0, -1073741792);
              v20 = MiMapPageInHyperSpaceWorker(v18, 0, 0x80000000);
              memmove(v20, v13 + v19, 0x1000u);
              if ( v33 >= v41 && (v33 > v41 || v13 + 4096 > v35) )
                memset((_BYTE *)(v20 - (v13 - v35)), 0, v13 - v35 + 4096);
              LODWORD(v5) = MiUnmapPageInHyperSpaceWorker(v20, 17, 0x80000000);
              v15 = 3 * v18;
              v21 = MmPfnDatabase + 24 * v18;
              if ( v21 != v36 )
              {
                MiReferenceControlAreaPfn(v37, 0, 1);
                v22 = (unsigned __int8 *)(v21 + 15);
                do
                  v23 = __ldrex(v22);
                while ( __strex(v23 | 0x80, v22) );
                __dmb(0xBu);
                if ( v23 >> 7 )
                {
                  v24 = (unsigned __int8 *)(v21 + 15);
                  do
                  {
                    do
                    {
                      __dmb(0xAu);
                      __yield();
                      v25 = *(_DWORD *)(v21 + 12);
                      __dmb(0xBu);
                    }
                    while ( (v25 & 0x80000000) != 0 );
                    do
                      v26 = __ldrex(v24);
                    while ( __strex(v26 | 0x80, v24) );
                    __dmb(0xBu);
                  }
                  while ( v26 >> 7 );
                }
                if ( (BYTE2(MiFlags) & 3) == 2
                  && ((*(unsigned __int16 *)((v17 & 0xFFFFF800 | (2 * (v17 & 0x3FC))) + 0x10) >> 1) & 2) != 0 )
                {
                  MiMarkPfnVerified(v21, 6);
                }
                MiInitializeTransitionPfn(v18, (int *)v10);
                *(_BYTE *)(v21 + 19) ^= (v32 ^ *(_BYTE *)(v21 + 19)) & 7;
                MiRemoveLockedPageChargeAndDecRef(v21);
                __dmb(0xBu);
                v15 = v21 + 12;
                do
                {
                  LODWORD(v5) = __ldrex((unsigned int *)v15);
                  HIDWORD(v5) = v5 & 0x7FFFFFFF;
                }
                while ( __strex(v5 & 0x7FFFFFFF, (unsigned int *)v15) );
              }
              v12 = v33;
            }
            v6 = v31;
          }
          v8 = v34;
          v10 += 4;
          v13 += 4096;
        }
        v9 = v30;
LABEL_33:
        if ( v8 )
        {
          LODWORD(v5) = MiUnlockProtoPoolPage(v8, v7);
          v8 = 0;
          v9 = v30;
          v34 = 0;
        }
      }
      v6 = v9;
      v31 = v9;
    }
    while ( v9 );
  }
  return v5;
}

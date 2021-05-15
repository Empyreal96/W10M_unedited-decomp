// EmpProviderRegister 
 
int __fastcall EmpProviderRegister(int a1, unsigned int *a2, unsigned int a3, unsigned int *a4, unsigned int a5, int **a6)
{
  int *v8; // r6
  int v9; // r7
  int v10; // r0
  unsigned int v11; // r5
  int *v13; // r0
  _BYTE *v14; // r0
  unsigned int v15; // r5
  unsigned int *v16; // r9
  unsigned int v17; // r4
  _DWORD *v18; // r0
  int v19; // r3
  unsigned int v20; // r3
  unsigned int i; // r5
  unsigned int k; // r5
  int v23; // r0
  unsigned int *v24; // r2
  unsigned int v25; // r1
  _DWORD *l; // r4
  unsigned int v27; // r1
  _BYTE *v28; // r0
  unsigned int *v29; // r2
  unsigned int v30; // r1
  int v31; // r4
  unsigned int v32; // r4
  int v33; // r5
  _DWORD *v34; // r0
  unsigned int v35; // r1
  int v36; // r0
  unsigned int *v37; // r2
  unsigned int v38; // r1
  _DWORD *j; // r4
  _BYTE *v40; // r0
  unsigned int *v41; // r2
  _DWORD *v42; // r1
  _DWORD *v43; // r0
  _DWORD *v44; // r2
  unsigned int v45; // r0
  unsigned int v46; // r2
  int v47; // r1
  int v48; // r0
  __int64 v49; // kr00_8
  unsigned int m; // r2
  int v51; // r0
  unsigned int v52; // [sp+0h] [bp-28h]

  v8 = 0;
  v9 = 0;
  v52 = 0;
  v10 = KeAbPreAcquire((unsigned int)&EmpDatabaseLock, 0, 0);
  do
    v11 = __ldrex((unsigned __int8 *)&EmpDatabaseLock);
  while ( __strex(v11 | 1, (unsigned __int8 *)&EmpDatabaseLock) );
  __dmb(0xBu);
  if ( (v11 & 1) != 0 )
    return sub_80FDEC(v10);
  if ( v10 )
    *(_BYTE *)(v10 + 14) |= 1u;
  if ( !a6 || a3 && !a2 || a5 && !a4 )
    goto LABEL_66;
  v13 = (int *)ExAllocatePoolWithTag(1, 36, 1919962437);
  v8 = v13;
  if ( v13 )
  {
    v13[3] = 0;
    v13[4] = 0;
    v13[5] = 0;
    v13[6] = 0;
    v13[1] = 0;
    v13[2] = 0;
    v13[7] = (int)(v13 + 7);
    v13[8] = (int)(v13 + 7);
    if ( a3 )
    {
      v28 = (_BYTE *)ExAllocatePoolWithTag(1, 4 * a3, 1919962437);
      v8[1] = (int)v28;
      if ( v28 )
      {
        memset(v28, 0, 4 * a3);
        v8[2] = a3;
        v29 = a2;
        v30 = a3;
        do
        {
          if ( v29[1] )
            ++v8[4];
          v29 += 3;
          --v30;
        }
        while ( v30 );
        v31 = v8[4];
        if ( v31 )
        {
          v40 = (_BYTE *)ExAllocatePoolWithTag(1, 16 * v31, 1919962437);
          v8[3] = (int)v40;
          if ( !v40 )
            goto LABEL_57;
          memset(v40, 0, 16 * v31);
        }
        v32 = 0;
        v52 = 0;
        v33 = 0;
        while ( *a2 )
        {
          v34 = EmpSearchEntryDatabase(*a2);
          if ( !v34 )
          {
LABEL_63:
            v9 = -1073741275;
            goto LABEL_67;
          }
          *(_DWORD *)(v8[1] + 4 * v32) = v34;
          v35 = a2[1];
          if ( v35 )
          {
            v41 = (unsigned int *)(v8[3] + v33);
            *v41 = v35;
            v42 = v34 + 9;
            v41[1] = a2[2];
            v43 = (_DWORD *)v34[10];
            v41[2] = (unsigned int)v42;
            v41[3] = (unsigned int)v43;
            v44 = v41 + 2;
            if ( (_DWORD *)*v43 != v42 )
              __fastfail(3u);
            *v43 = v44;
            v42[1] = v44;
            ++v52;
            v33 += 16;
          }
          ++v32;
          a2 += 3;
          if ( v32 >= a3 )
            goto LABEL_14;
        }
        goto LABEL_66;
      }
    }
    else
    {
LABEL_14:
      if ( !a5 )
      {
LABEL_22:
        for ( i = 0; i < v8[2]; ++i )
        {
          v36 = *(_DWORD *)(v8[1] + 4 * i);
          __dmb(0xBu);
          v37 = (unsigned int *)(v36 + 16);
          do
            v38 = __ldrex(v37);
          while ( __strex(v38 + 1, v37) );
          __dmb(0xBu);
          for ( j = *(_DWORD **)(v36 + 44); j; j = (_DWORD *)*j )
            EmpQueueRuleUpdateState(*(j - 1), 0);
        }
        for ( k = 0; k < v8[6]; ++k )
        {
          v23 = *(_DWORD *)(v8[5] + 4 * k);
          __dmb(0xBu);
          v24 = (unsigned int *)(v23 + 20);
          do
            v25 = __ldrex(v24);
          while ( __strex(v25 + 1, v24) );
          __dmb(0xBu);
          for ( l = *(_DWORD **)(v23 + 32); l; l = (_DWORD *)*l )
            EmpQueueRuleUpdateState(*(l - 1), 0);
        }
        if ( a1 )
          ObfReferenceObject(a1);
        *v8 = a1;
        *a6 = v8;
        goto LABEL_33;
      }
      v14 = (_BYTE *)ExAllocatePoolWithTag(1, 4 * a5, 1919962437);
      v8[5] = (int)v14;
      if ( v14 )
      {
        memset(v14, 0, 4 * a5);
        v15 = 0;
        v8[6] = a5;
        v16 = a4;
        while ( 1 )
        {
          v17 = v16[1];
          if ( !v17 || !*v16 )
            break;
          v18 = EmpSearchCallbackDatabase(*v16);
          if ( !v18 )
            goto LABEL_63;
          v19 = v18[4];
          if ( v19 && v19 != v17 )
          {
            v9 = -1073741771;
            goto LABEL_67;
          }
          *(_DWORD *)(v8[5] + 4 * v15++) = v18;
          v18[4] = v16[1];
          v20 = v16[2];
          v16 += 3;
          v18[6] = v20;
          if ( v15 >= a5 )
            goto LABEL_22;
        }
LABEL_66:
        v9 = -1073741811;
LABEL_67:
        if ( v8 )
        {
          v45 = v8[1];
          if ( v45 )
            ExFreePoolWithTag(v45);
          if ( v8[3] )
          {
            v46 = 0;
            if ( v52 )
            {
              v47 = 0;
              do
              {
                v48 = v8[3] + v47 + 8;
                v49 = *(_QWORD *)v48;
                if ( *(_DWORD *)(*(_DWORD *)v48 + 4) != v48 || *(_DWORD *)HIDWORD(v49) != v48 )
                  __fastfail(3u);
                ++v46;
                *(_DWORD *)HIDWORD(v49) = v49;
                v47 += 16;
                *(_DWORD *)(v49 + 4) = HIDWORD(v49);
              }
              while ( v46 < v52 );
            }
            ExFreePoolWithTag(v8[3]);
          }
          if ( v8[5] )
          {
            for ( m = 0; m < a5; ++m )
            {
              v51 = *(_DWORD *)(v8[5] + 4 * m);
              if ( v51 && !*(_DWORD *)(v51 + 20) )
                *(_DWORD *)(v51 + 16) = 0;
            }
            ExFreePoolWithTag(v8[5]);
          }
          ExFreePoolWithTag((unsigned int)v8);
        }
        goto LABEL_33;
      }
    }
LABEL_57:
    v9 = -1073741670;
    goto LABEL_67;
  }
  v9 = -1073741670;
LABEL_33:
  __dmb(0xBu);
  do
    v27 = __ldrex((unsigned int *)&EmpDatabaseLock);
  while ( __strex(v27 - 1, (unsigned int *)&EmpDatabaseLock) );
  if ( (v27 & 2) != 0 && (v27 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&EmpDatabaseLock);
  KeAbPostRelease((unsigned int)&EmpDatabaseLock);
  return v9;
}

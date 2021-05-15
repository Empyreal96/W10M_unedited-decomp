// ExpWnfCreateNameInstance 
 
int __fastcall ExpWnfCreateNameInstance(int a1, signed __int64 a2, _DWORD *a3, int a4, unsigned int *a5)
{
  int v8; // r9
  _BYTE *v9; // r0
  unsigned int v10; // r5
  int v11; // r4
  unsigned __int8 *v12; // r6
  int v13; // r0
  int v14; // r4
  unsigned int v15; // r2
  int *v16; // r0
  int *v17; // r7
  unsigned int *v18; // r0
  unsigned int v19; // r4
  unsigned int v20; // r1
  int v21; // r1
  int v22; // r2
  unsigned int *v23; // r0
  unsigned int v24; // r4
  unsigned int v25; // r1
  unsigned int v26; // r1
  unsigned int v27; // r0
  _DWORD *v28; // r2
  int v29; // r3
  int v30; // r8
  unsigned __int8 *v31; // r4
  int v32; // r0
  int v33; // r7
  unsigned int v34; // r2
  unsigned int *v35; // r0
  unsigned int v36; // r1
  unsigned int v37; // r1
  unsigned int v38; // r1
  int varg_r0; // [sp+28h] [bp+8h]

  varg_r0 = a1;
  if ( a3[1] )
    return sub_7E7568();
  v8 = (a2 >> 4) & 3;
  if ( v8 != 3 || PsInitialSystemProcess == a4 )
    v9 = (_BYTE *)ExAllocatePoolWithTag(1, 96, 543583831);
  else
    v9 = (_BYTE *)ExAllocatePoolWithQuotaTag(9u, 0x60u, 543583831);
  v10 = (unsigned int)v9;
  if ( !v9 )
    return -1073741670;
  memset(v9, 0, 96);
  *(_WORD *)v10 = 2307;
  *(_WORD *)(v10 + 2) = 96;
  *(_DWORD *)(v10 + 32) = a1;
  *(_DWORD *)(v10 + 4) = 0;
  *(_QWORD *)(v10 + 24) = a2;
  *(_DWORD *)(v10 + 36) = *a3;
  if ( a3[1] )
  {
    *(_DWORD *)(v10 + 40) = v10 + 96;
    v28 = (_DWORD *)a3[1];
    *(_DWORD *)(v10 + 96) = *v28;
    *(_DWORD *)(v10 + 100) = v28[1];
    *(_DWORD *)(v10 + 104) = v28[2];
    *(_DWORD *)(v10 + 108) = v28[3];
  }
  if ( ObLogSecurityDescriptor(a3[2], v10 + 44, 1) >= 0 )
  {
    *(_DWORD *)(v10 + 68) = v10 + 68;
    *(_DWORD *)(v10 + 72) = v10 + 68;
    *(_DWORD *)(v10 + 64) = 0;
    *(_DWORD *)(v10 + 48) = 0;
    if ( (a2 & 0x400) == 0 )
      goto LABEL_16;
    if ( ExpWnfGetPermanentDataStoreHandle(a1, v8, 1, v10 + 60) < 0 )
    {
      v11 = -1073741670;
    }
    else
    {
      v11 = ExpWnfPopulateStateData(v10);
      if ( !v11 )
      {
LABEL_16:
        v12 = (unsigned __int8 *)(a1 + 28);
        v13 = KeAbPreAcquire(a1 + 28, 0, 0);
        v14 = v13;
        do
          v15 = __ldrex(v12);
        while ( __strex(v15 | 1, v12) );
        __dmb(0xBu);
        if ( (v15 & 1) != 0 )
          ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 28), v13, a1 + 28);
        if ( v14 )
          *(_BYTE *)(v14 + 14) |= 1u;
        v16 = ExpWnfFindStateName(a1, a2);
        v17 = v16;
        if ( v16 )
        {
          v23 = (unsigned int *)(v16 + 1);
          __pld(v17 + 1);
          v24 = v17[1] & 0xFFFFFFFE;
          do
            v25 = __ldrex(v23);
          while ( v25 == v24 && __strex(v24 + 2, v23) );
          __dmb(0xBu);
          if ( v25 != v24 )
            ExfAcquireRundownProtection(v23);
          __dmb(0xBu);
          do
            v26 = __ldrex((unsigned int *)v12);
          while ( __strex(v26 - 1, (unsigned int *)v12) );
          if ( (v26 & 2) != 0 && (v26 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)(a1 + 28));
          KeAbPostRelease(a1 + 28);
          ObDereferenceSecurityDescriptor(*(_DWORD *)(v10 + 44), 1);
          v27 = *(_DWORD *)(v10 + 52);
          if ( v27 )
            ExFreePoolWithTag(v27);
          ExFreePoolWithTag(v10);
          *a5 = (unsigned int)v17;
        }
        else
        {
          v18 = (unsigned int *)(v10 + 4);
          __pld((void *)(v10 + 4));
          v19 = *(_DWORD *)(v10 + 4) & 0xFFFFFFFE;
          do
            v20 = __ldrex(v18);
          while ( v20 == v19 && __strex(v19 + 2, v18) );
          __dmb(0xBu);
          if ( v20 != v19 )
            ExfAcquireRundownProtection(v18);
          v21 = *(_DWORD *)(a1 + 32);
          v22 = 0;
          if ( v21 )
          {
            while ( 1 )
            {
              if ( *(_QWORD *)(v10 + 24) < *(_QWORD *)(v21 + 16) )
              {
                v29 = *(_DWORD *)v21;
                if ( !*(_DWORD *)v21 )
                {
                  v22 = 0;
                  break;
                }
              }
              else
              {
                v29 = *(_DWORD *)(v21 + 4);
                if ( !v29 )
                {
                  v22 = 1;
                  break;
                }
              }
              v21 = v29;
            }
          }
          RtlAvlInsertNodeEx(a1 + 32, v21, v22, (_DWORD *)(v10 + 8));
          if ( v8 == 3 )
          {
            *(_DWORD *)(v10 + 84) = a4;
            v30 = *(_DWORD *)(a4 + 724);
            __dmb(0xBu);
            v31 = (unsigned __int8 *)(v30 + 28);
            v32 = KeAbPreAcquire(v30 + 28, 0, 0);
            v33 = v32;
            do
              v34 = __ldrex(v31);
            while ( __strex(v34 | 1, v31) );
            __dmb(0xBu);
            if ( (v34 & 1) != 0 )
              ExfAcquirePushLockExclusiveEx((_DWORD *)(v30 + 28), v32, v30 + 28);
            if ( v33 )
              *(_BYTE *)(v33 + 14) |= 1u;
            v35 = *(unsigned int **)(v30 + 36);
            v36 = v10 + 76;
            *(_DWORD *)(v10 + 76) = v30 + 32;
            *(_DWORD *)(v10 + 80) = v35;
            if ( *v35 != v30 + 32 )
              __fastfail(3u);
            *v35 = v36;
            *(_DWORD *)(v30 + 36) = v36;
            __dmb(0xBu);
            do
              v37 = __ldrex((unsigned int *)v31);
            while ( __strex(v37 - 1, (unsigned int *)v31) );
            if ( (v37 & 2) != 0 && (v37 & 4) == 0 )
              ExfTryToWakePushLock((unsigned int *)(v30 + 28));
            KeAbPostRelease(v30 + 28);
          }
          __dmb(0xBu);
          do
            v38 = __ldrex((unsigned int *)v12);
          while ( __strex(v38 - 1, (unsigned int *)v12) );
          if ( (v38 & 2) != 0 && (v38 & 4) == 0 )
            ExfTryToWakePushLock((unsigned int *)v12);
          KeAbPostRelease((unsigned int)v12);
          *a5 = v10;
        }
        return 0;
      }
    }
    ObDereferenceSecurityDescriptor(*(_DWORD *)(v10 + 44), 1);
    ExFreePoolWithTag(v10);
    return v11;
  }
  ExFreePoolWithTag(v10);
  return -1073741670;
}

// FsRtlNotifyFilterReportChangeLite 
 
unsigned int __fastcall FsRtlNotifyFilterReportChangeLite(unsigned int result, int **a2, unsigned __int16 *a3, unsigned __int16 *a4, int a5, int a6, int a7, int a8, unsigned int a9)
{
  int **v9; // r9
  unsigned int *v10; // r6
  unsigned int v11; // r3
  unsigned int v12; // r5
  unsigned int v13; // r8
  unsigned int v14; // r5
  unsigned int v15; // r9
  int v16; // r0
  int v17; // r4
  unsigned int v18; // r2
  int *v19; // r10
  int v20; // r6
  int v21; // r2
  int (__fastcall *v22)(_DWORD, int, _DWORD); // r3
  int (__fastcall *v23)(_DWORD, int); // r3
  __int16 v24; // r0
  unsigned int v25; // r6
  int v26; // r1
  unsigned int v27; // r8
  unsigned int v28; // r9
  _DWORD *v29; // r0
  int v30; // r2
  int v31; // r3
  int v32; // lr
  int v33; // r0
  _DWORD *v34; // r6
  _WORD *v35; // r3
  int v36; // r1
  unsigned int *v37; // r4
  unsigned int v38; // r1
  _DWORD v42[4]; // [sp+30h] [bp-38h] BYREF
  int v43; // [sp+40h] [bp-28h]
  int varg_r0; // [sp+70h] [bp+8h]
  int **varg_r1; // [sp+74h] [bp+Ch]
  unsigned __int16 *varg_r2; // [sp+78h] [bp+10h]
  unsigned __int16 *varg_r3; // [sp+7Ch] [bp+14h]

  varg_r3 = a4;
  varg_r2 = a3;
  v9 = a2;
  varg_r1 = a2;
  v10 = (unsigned int *)result;
  varg_r0 = result;
  v42[1] = 0;
  if ( *a2 == (int *)a2 )
    return result;
  if ( !*(_DWORD *)result )
  {
    FsRtlNotifyInitializeSync(v42);
    __dmb(0xBu);
    v11 = v42[0];
    do
      v12 = __ldrex(v10);
    while ( !v12 && __strex(v11, v10) );
    __dmb(0xBu);
    if ( v12 )
      FsRtlNotifyUninitializeSync(v42);
  }
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v14 = *v10;
  if ( v13 != *(_DWORD *)(*v10 + 32) )
  {
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = KeAbPreAcquire(v14, 0, 0);
    v17 = v16;
    do
      v18 = __ldrex((unsigned __int8 *)v14);
    while ( __strex(v18 & 0xFE, (unsigned __int8 *)v14) );
    __dmb(0xBu);
    if ( (v18 & 1) == 0 )
      ExpAcquireFastMutexContended(v14, v16);
    if ( v17 )
      *(_BYTE *)(v17 + 14) |= 1u;
    *(_DWORD *)(v14 + 4) = v15;
    *(_DWORD *)(*v10 + 32) = v13;
    v9 = a2;
  }
  ++*(_DWORD *)(*v10 + 36);
  v19 = *v9;
  result = a9;
  v20 = a5;
  while ( 1 )
  {
    v21 = a8;
    if ( v19 == (int *)v9 )
      break;
    if ( (v19[6] & v20) == 0 )
      goto LABEL_68;
    if ( (result & 1) == 0 )
    {
      if ( (v19[5] & 1) == 0 )
        goto LABEL_68;
      v22 = (int (__fastcall *)(_DWORD, int, _DWORD))*(v19 - 2);
      if ( v22 )
      {
        if ( !v22(*(v19 - 3), a7, *(v19 - 1)) )
          goto LABEL_68;
        v21 = a8;
      }
    }
    v23 = (int (__fastcall *)(_DWORD, int))v19[4];
    if ( !v23 || !v21 || v23(*(v19 - 3), v21) )
    {
      v24 = *((_WORD *)v19 + 10);
      if ( (v24 & 2) == 0 )
      {
        v25 = v19[9];
        if ( v25 )
        {
          v26 = 0;
          if ( v19[10] )
          {
            v25 = v19[10];
          }
          else if ( (int *)v19[2] != v19 + 2 )
          {
            v26 = v19[2] - 88;
            v43 = *(_DWORD *)(v19[2] + 8);
            v25 = *(_DWORD *)(v43 + 8);
          }
          v27 = *a3 + 12;
          if ( a4 )
            v27 += *a4 + 2;
          v28 = (v19[11] + 3) & 0xFFFFFFFC;
          v42[3] = v28;
          if ( v27 > v25 || v28 + v27 > v25 )
          {
            *((_WORD *)v19 + 10) = v24 | 2;
          }
          else
          {
            v29 = 0;
            v30 = v19[8];
            if ( v30 )
            {
              *(_DWORD *)(v30 + v19[12]) = v28 - v19[12];
              v19[12] = v28;
              v29 = (_DWORD *)(v28 + v19[8]);
              goto LABEL_50;
            }
            if ( v26 )
            {
              v31 = *(_DWORD *)(v26 + 12);
              if ( v31 )
              {
                v29 = *(_DWORD **)(v26 + 12);
                v19[8] = v31;
                goto LABEL_49;
              }
              v32 = *(_DWORD *)(v26 + 4);
              if ( v32 )
              {
                if ( (*(_WORD *)(v32 + 6) & 5) != 0 )
                  v29 = *(_DWORD **)(v32 + 12);
                else
                  v29 = (_DWORD *)MmMapLockedPagesSpecifyCache(v32, 0, 1, 0, 0, 1073741840);
                v42[2] = v29;
                v19[8] = (int)v29;
LABEL_49:
                v19[10] = v25;
              }
            }
LABEL_50:
            if ( !v19[8] )
            {
              PsChargePoolQuota();
              v33 = ExAllocatePoolWithTag(17, v25, 1316115270);
              v19[8] = v33;
              v19[7] = v33;
              v19[10] = v25;
              v29 = (_DWORD *)v19[8];
            }
            if ( v29 )
            {
              *v29 = 0;
              v29[1] = a6;
              v29[2] = v27 - 12;
              v34 = v29 + 3;
              memmove((int)(v29 + 3), *((_DWORD *)a3 + 1), *a3);
              if ( a4 )
              {
                v35 = (_WORD *)((char *)v34 + *a3);
                *v35 = 58;
                memmove((int)(v35 + 1), *((_DWORD *)a4 + 1), *a4);
              }
              v19[11] = v28 + v27;
            }
          }
          if ( (v19[5] & 2) != 0 && v19[8] )
          {
            if ( v19[7] )
            {
              PsReturnProcessPagedPoolQuota(v19[14], v19[10]);
              ExFreePoolWithTag(v19[7]);
            }
            v19[8] = 0;
            v19[7] = 0;
            v19[12] = 0;
            v19[11] = 0;
            v19[10] = 0;
          }
          v9 = a2;
        }
        v20 = a5;
      }
      if ( a6 == 4 )
      {
        *((_WORD *)v19 + 10) |= 8u;
      }
      else
      {
        *((_WORD *)v19 + 10) &= 0xFFF7u;
        if ( (int *)v19[2] != v19 + 2 )
          FsRtlNotifyCompleteIrpList(v19 - 4, 0);
      }
    }
LABEL_68:
    v19 = (int *)*v19;
    result = a9;
  }
  v36 = varg_r0;
  --*(_DWORD *)(*(_DWORD *)varg_r0 + 36);
  if ( !*(_DWORD *)(*(_DWORD *)v36 + 36) )
  {
    *(_DWORD *)(*(_DWORD *)v36 + 32) = 0;
    v37 = *(unsigned int **)v36;
    *(_DWORD *)(*(_DWORD *)v36 + 4) = 0;
    __dmb(0xBu);
    do
      v38 = __ldrex(v37);
    while ( !v38 && __strex(1u, v37) );
    if ( v38 )
      ExpReleaseFastMutexContended(v37, v38);
    result = KeAbPostRelease((unsigned int)v37);
  }
  return result;
}

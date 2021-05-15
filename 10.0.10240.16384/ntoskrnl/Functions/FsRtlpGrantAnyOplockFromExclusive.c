// FsRtlpGrantAnyOplockFromExclusive 
 
int __fastcall FsRtlpGrantAnyOplockFromExclusive(int *a1, int a2, _DWORD *a3, int a4, _DWORD *a5, char a6, int **a7, _BYTE *a8, _BYTE *a9, int a10)
{
  int *v10; // r5
  int v12; // r4
  int v15; // r4
  int v16; // r3
  int v17; // r2
  int v18; // r3
  int v19; // r3
  int v20; // r8
  int *v21; // r2
  int v22; // r8
  int v23; // r0
  int v24; // r0
  char v25; // r0
  int v26; // r3
  unsigned int *v27; // r1
  unsigned int v28; // r4
  _DWORD *varg_r0[4]; // [sp+38h] [bp+8h] BYREF

  varg_r0[0] = a1;
  varg_r0[1] = (_DWORD *)a2;
  varg_r0[2] = a3;
  varg_r0[3] = (_DWORD *)a4;
  v10 = a1;
  v12 = *(unsigned __int8 *)(a3[7] + 37);
  varg_r0[0] = a1;
  if ( v12 && (a4 & 0x2000) != 0 )
  {
    v15 = *(_DWORD *)(a2 + 12);
    memset((_BYTE *)v15, 0, 24);
    v16 = v10[18];
    if ( (v16 & 0x4000) != 0 )
      v17 = 4;
    else
      v17 = 0;
    if ( (v16 & 0x2000) != 0 )
      v18 = 2;
    else
      v18 = 0;
    *(_DWORD *)(v15 + 4) = v18 | v17 | ((v10[18] & 0x1000) != 0);
    if ( (a4 & 0x4000) != 0 )
      v19 = 4;
    else
      v19 = 0;
    *(_DWORD *)(v15 + 8) = v19 | ((a4 & 0x1000) != 0);
    *(_DWORD *)(v15 + 12) |= 1u;
    *(_DWORD *)(a2 + 28) = 24;
    v20 = -2147483602;
    *(_DWORD *)(a2 + 24) = -2147483602;
    pIofCompleteRequest(a2, 1);
    return v20;
  }
  if ( a6 )
  {
    (*a7)[2] = a1[1];
    v21 = *a7;
    v22 = a1[13];
    *v21 = v22;
    v21[1] = (int)(a1 + 13);
    if ( *(int **)(v22 + 4) != a1 + 13 )
      __fastfail(3u);
    *(_DWORD *)(v22 + 4) = v21;
    a1[13] = (int)v21;
    *a7 = 0;
LABEL_21:
    a1[1] = 0;
    goto LABEL_22;
  }
  *a8 = 1;
  if ( !a4 )
  {
    *a9 = 1;
    goto LABEL_23;
  }
  if ( (a4 & 0x3010) != 0 && (a4 & 0x4040) == 0 )
    goto LABEL_21;
LABEL_22:
  if ( a4 )
  {
    if ( (a4 & 0x3010) == 0 || (a4 & 0x4040) != 0 )
    {
      *a1 = a2;
      v20 = 259;
      *(_BYTE *)(*(_DWORD *)(a2 + 96) + 3) |= 1u;
      *(_DWORD *)(a2 + 28) = a1;
      a1[2] = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v10[3] = v24;
      ObfReferenceObjectWithTag(v24);
      *((_BYTE *)v10 + 16) = 0;
      if ( a6 )
      {
        ObfReferenceObjectWithTag(a3[7]);
        v10[1] = a3[7];
      }
      v10[18] = v10[18] & 0x20 | a4 | 0x40;
      v25 = KeAcquireQueuedSpinLock(7);
      v26 = *(unsigned __int8 *)(a2 + 36);
      *(_BYTE *)(a2 + 37) = v25;
      if ( v26 )
      {
        FsRtlpCancelExclusiveIrp(a2, 1, a6 == 0, v26);
      }
      else
      {
        __dmb(0xBu);
        v27 = (unsigned int *)(a2 + 56);
        do
          v28 = __ldrex(v27);
        while ( __strex((unsigned int)FsRtlpExclusiveIrpCancelRoutine, v27) );
        __dmb(0xBu);
        KeReleaseQueuedSpinLock(7, *(unsigned __int8 *)(a2 + 37));
      }
    }
    else
    {
      v23 = FsRtlpRequestShareableOplock(varg_r0, (int)a3, a2, a4, a5, a6, 1u, a10);
      v10 = varg_r0[0];
      v20 = v23;
    }
    goto LABEL_34;
  }
LABEL_23:
  v20 = 0;
  a1[18] = a1[18] & 0x20 | 1;
  *(_DWORD *)(a2 + 24) = 0;
  pIofCompleteRequest(a2, 1);
LABEL_34:
  if ( a6 )
    v10[18] |= 0x1000000u;
  return v20;
}

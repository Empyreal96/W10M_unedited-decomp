// FsRtlNotifyFilterChangeDirectory 
 
int __fastcall FsRtlNotifyFilterChangeDirectory(int result, _DWORD *a2, int a3, unsigned __int16 *a4, char a5, char a6, int a7, _DWORD *a8, int a9, unsigned int a10, int a11)
{
  int v11; // lr
  _DWORD *v12; // r2
  int v13; // r10
  unsigned int v14; // r6
  unsigned int v15; // r9
  int v16; // r0
  int v17; // r4
  unsigned int v18; // r2
  int v19; // r9
  int v20; // r3
  int v21; // r0
  int v22; // r4
  int v23; // r1
  int *v24; // r0
  __int16 v25; // r2
  int v26; // r1
  _DWORD *v27; // r2
  _DWORD *v28; // r0
  unsigned int *v29; // r2
  unsigned int v30; // r1
  int v31; // r3
  unsigned int v32; // r1
  unsigned __int16 *v35; // [sp+14h] [bp-24h]
  unsigned int *varg_r0; // [sp+40h] [bp+8h]
  _DWORD *varg_r1; // [sp+44h] [bp+Ch]
  int varg_r2; // [sp+48h] [bp+10h]

  varg_r1 = a2;
  varg_r2 = a3;
  v35 = a4;
  v11 = a3;
  v12 = a2;
  v13 = result;
  varg_r0 = (unsigned int *)result;
  if ( (_DWORD *)*a2 == a2 && !a8 )
    return result;
  v14 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( v14 != *(_DWORD *)(result + 32) )
  {
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = KeAbPreAcquire(result, 0, 0);
    v17 = v16;
    do
      v18 = __ldrex((unsigned __int8 *)v13);
    while ( __strex(v18 & 0xFE, (unsigned __int8 *)v13) );
    __dmb(0xBu);
    if ( (v18 & 1) == 0 )
      ExpAcquireFastMutexContended(v13, v16);
    if ( v17 )
      *(_BYTE *)(v17 + 14) |= 1u;
    *(_DWORD *)(v13 + 4) = v15;
    *(_DWORD *)(v13 + 32) = v14;
    v12 = a2;
    v11 = a3;
  }
  ++*(_DWORD *)(v13 + 36);
  if ( a8 )
  {
    v19 = a8[24];
    a8[6] = 0;
    a8[7] = 0;
    if ( (*(_DWORD *)(*(_DWORD *)(v19 + 28) + 44) & 0x4000) != 0 )
    {
LABEL_14:
      *(_BYTE *)(v19 + 3) |= 1u;
      v20 = 267;
LABEL_15:
      a8[6] = v20;
      result = IofCompleteRequest((int)a8, 1);
      goto LABEL_46;
    }
    v21 = FsRtlIsNotifyOnList(v12, v11);
    v22 = v21;
    if ( v21 )
    {
      v25 = *(_WORD *)(v21 + 36);
      if ( (v25 & 4) != 0 )
        goto LABEL_14;
      if ( (v25 & 0x20) != 0 )
      {
        *(_BYTE *)(v19 + 3) |= 1u;
        v20 = -1073741738;
        goto LABEL_15;
      }
      if ( (v25 & 2) != 0 && (v25 & 8) == 0 )
      {
        *(_WORD *)(v21 + 36) = v25 & 0xFFFD;
        *(_BYTE *)(a8[24] + 3) |= 1u;
        v20 = 268;
        goto LABEL_15;
      }
      v26 = *(_DWORD *)(v21 + 60);
      if ( v26 && (v25 & 8) == 0 )
      {
        *(_DWORD *)(v21 + 60) = 0;
        *(_DWORD *)(v21 + 64) = 0;
        result = FsRtlNotifyCompleteIrp(a8, v21, v26, 0, 0);
        goto LABEL_46;
      }
    }
    else
    {
      v22 = ExAllocatePoolWithTag(17, 88, 1316115270);
      memset((_BYTE *)v22, 0, 88);
      *(_DWORD *)v22 = v13;
      *(_DWORD *)(v22 + 4) = a3;
      *(_DWORD *)(v22 + 76) = *(_DWORD *)(*(_DWORD *)(v19 + 28) + 12);
      *(_DWORD *)(v22 + 8) = a9;
      *(_DWORD *)(v22 + 12) = a10;
      a10 = 0;
      *(_DWORD *)(v22 + 32) = a11;
      *(_DWORD *)(v22 + 80) = v35;
      *(_DWORD *)(v22 + 28) = v22 + 24;
      *(_DWORD *)(v22 + 24) = v22 + 24;
      if ( a5 )
        *(_WORD *)(v22 + 36) |= 1u;
      if ( v35 )
      {
        if ( *v35 < 2u || *(_BYTE *)(*((_DWORD *)v35 + 1) + 1) )
          *(_BYTE *)(v22 + 84) = 1;
        else
          *(_BYTE *)(v22 + 84) = 2;
        if ( *v35 == *(unsigned __int8 *)(v22 + 84) )
          *(_WORD *)(v22 + 36) |= 0x10u;
      }
      else
      {
        *(_BYTE *)(v22 + 84) = 1;
      }
      *(_DWORD *)(v22 + 40) = a7;
      if ( !a6 )
        *(_DWORD *)(v22 + 52) = *(_DWORD *)(v19 + 8);
      *(_DWORD *)(v22 + 72) = *(_DWORD *)(a8[20] + 336);
      v23 = v22 + 16;
      v24 = (int *)a2[1];
      *(_DWORD *)(v22 + 16) = a2;
      *(_DWORD *)(v22 + 20) = v24;
      if ( (_DWORD *)*v24 != a2 )
        __fastfail(3u);
      *v24 = v23;
      a2[1] = v23;
      *(_DWORD *)(v22 + 68) = 1;
    }
    a8[7] = v22;
    *(_BYTE *)(a8[24] + 3) |= 1u;
    v27 = a8 + 22;
    v28 = *(_DWORD **)(v22 + 28);
    a8[22] = v22 + 24;
    a8[23] = v28;
    if ( *v28 != v22 + 24 )
      __fastfail(3u);
    *v28 = v27;
    *(_DWORD *)(v22 + 28) = v27;
    __dmb(0xBu);
    v29 = (unsigned int *)(v22 + 68);
    do
      v30 = __ldrex(v29);
    while ( __strex(v30 + 1, v29) );
    __dmb(0xBu);
    result = FsRtlNotifySetCancelRoutine((int)a8, 0);
    goto LABEL_46;
  }
  result = FsRtlCheckNotifyForDelete(v12, v11);
LABEL_46:
  v31 = varg_r0[9] - 1;
  varg_r0[9] = v31;
  if ( !v31 )
  {
    varg_r0[8] = 0;
    varg_r0[1] = 0;
    __dmb(0xBu);
    do
      v32 = __ldrex(varg_r0);
    while ( !v32 && __strex(1u, varg_r0) );
    if ( v32 )
      ExpReleaseFastMutexContended(varg_r0, v32);
    result = KeAbPostRelease((unsigned int)varg_r0);
  }
  if ( a10 )
  {
    if ( a4 )
    {
      SeReleaseSubjectContext(a10);
      result = ExFreePoolWithTag(a10);
    }
  }
  return result;
}

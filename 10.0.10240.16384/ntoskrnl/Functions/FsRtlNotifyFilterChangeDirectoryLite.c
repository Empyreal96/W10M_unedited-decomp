// FsRtlNotifyFilterChangeDirectoryLite 
 
unsigned int *__fastcall FsRtlNotifyFilterChangeDirectoryLite(unsigned int *result, _DWORD *a2, int a3, int a4, int a5, _DWORD *a6, int a7, unsigned int a8, int a9)
{
  unsigned int *v10; // r5
  unsigned int v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r8
  int v14; // r0
  int v15; // r6
  unsigned int v16; // r2
  int v17; // r8
  int v18; // r3
  int v19; // r0
  int v20; // r5
  char v21; // r2
  int v22; // r2
  int *v23; // r1
  __int16 v24; // r2
  int v25; // r1
  _DWORD *v26; // r2
  _DWORD *v27; // r0
  unsigned int *v28; // r2
  unsigned int v29; // r1
  int v30; // r1
  unsigned int *v31; // r4
  unsigned int v32; // r1
  unsigned int v33; // [sp+8h] [bp-38h] BYREF
  int v34; // [sp+Ch] [bp-34h]
  unsigned int v35; // [sp+10h] [bp-30h]
  int v36; // [sp+14h] [bp-2Ch]
  unsigned int *v37; // [sp+18h] [bp-28h]
  int v38; // [sp+1Ch] [bp-24h]
  unsigned int *varg_r0; // [sp+48h] [bp+8h]
  _DWORD *varg_r1; // [sp+4Ch] [bp+Ch]
  int varg_r2; // [sp+50h] [bp+10h]
  int varg_r3; // [sp+54h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v38 = a4;
  v34 = a3;
  v10 = result;
  v37 = result;
  varg_r0 = result;
  if ( (_DWORD *)*a2 == a2 && !a6 )
    return result;
  if ( !*result )
  {
    FsRtlNotifyInitializeSync(&v33);
    __dmb(0xBu);
    v11 = v33;
    do
      v12 = __ldrex(v10);
    while ( !v12 && __strex(v11, v10) );
    __dmb(0xBu);
    if ( v12 )
      FsRtlNotifyUninitializeSync(&v33);
  }
  v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v13 = *v10;
  if ( v35 != *(_DWORD *)(*v10 + 32) )
  {
    v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v14 = KeAbPreAcquire(v13, 0, 0);
    v15 = v14;
    do
      v16 = __ldrex((unsigned __int8 *)v13);
    while ( __strex(v16 & 0xFE, (unsigned __int8 *)v13) );
    __dmb(0xBu);
    if ( (v16 & 1) == 0 )
      ExpAcquireFastMutexContended(v13, v14);
    if ( v15 )
      *(_BYTE *)(v15 + 14) |= 1u;
    *(_DWORD *)(v13 + 4) = v33;
    *(_DWORD *)(*v10 + 32) = v35;
  }
  ++*(_DWORD *)(*v10 + 36);
  if ( a6 )
  {
    v17 = a6[24];
    a6[6] = 0;
    a6[7] = 0;
    if ( (*(_DWORD *)(*(_DWORD *)(v17 + 28) + 44) & 0x4000) != 0 )
    {
LABEL_20:
      *(_BYTE *)(v17 + 3) |= 1u;
      v18 = 267;
LABEL_21:
      a6[6] = v18;
      result = (unsigned int *)IofCompleteRequest((int)a6, 1);
      goto LABEL_44;
    }
    v19 = FsRtlIsNotifyOnList(a2, v34);
    v20 = v19;
    v36 = v19;
    if ( v19 )
    {
      v24 = *(_WORD *)(v19 + 36);
      if ( (v24 & 4) != 0 )
        goto LABEL_20;
      if ( (v24 & 0x20) != 0 )
      {
        *(_BYTE *)(v17 + 3) |= 1u;
        v18 = -1073741738;
        goto LABEL_21;
      }
      if ( (v24 & 2) != 0 && (v24 & 8) == 0 )
      {
        *(_WORD *)(v19 + 36) = v24 & 0xFFFD;
        *(_BYTE *)(a6[24] + 3) |= 1u;
        v18 = 268;
        goto LABEL_21;
      }
      v25 = *(_DWORD *)(v19 + 60);
      if ( v25 && (v24 & 8) == 0 )
      {
        *(_DWORD *)(v19 + 60) = 0;
        *(_DWORD *)(v19 + 64) = 0;
        result = (unsigned int *)FsRtlNotifyCompleteIrp(a6, v19, v25, 0, 0);
        goto LABEL_44;
      }
    }
    else
    {
      v20 = ExAllocatePoolWithTag(17, 76, 1316115270);
      v36 = v20;
      memset((_BYTE *)v20, 0, 76);
      *(_WORD *)(v20 + 36) |= 0x40u;
      *(_DWORD *)v20 = *v37;
      *(_DWORD *)(v20 + 4) = v34;
      *(_DWORD *)(v20 + 8) = a7;
      *(_DWORD *)(v20 + 12) = a8;
      a8 = 0;
      *(_DWORD *)(v20 + 32) = a9;
      *(_DWORD *)(v20 + 28) = v20 + 24;
      *(_DWORD *)(v20 + 24) = v20 + 24;
      v21 = v38;
      if ( (v38 & 1) != 0 )
        *(_WORD *)(v20 + 36) |= 1u;
      *(_DWORD *)(v20 + 40) = a5;
      if ( (v21 & 2) == 0 )
        *(_DWORD *)(v20 + 52) = *(_DWORD *)(v17 + 8);
      *(_DWORD *)(v20 + 72) = *(_DWORD *)(a6[20] + 336);
      v22 = v20 + 16;
      v23 = (int *)a2[1];
      *(_DWORD *)(v20 + 16) = a2;
      *(_DWORD *)(v20 + 20) = v23;
      if ( (_DWORD *)*v23 != a2 )
        __fastfail(3u);
      *v23 = v22;
      a2[1] = v22;
      *(_DWORD *)(v20 + 68) = 1;
    }
    a6[7] = v20;
    *(_BYTE *)(a6[24] + 3) |= 1u;
    v26 = a6 + 22;
    v27 = *(_DWORD **)(v20 + 28);
    a6[22] = v20 + 24;
    a6[23] = v27;
    if ( *v27 != v20 + 24 )
      __fastfail(3u);
    *v27 = v26;
    *(_DWORD *)(v20 + 28) = v26;
    __dmb(0xBu);
    v28 = (unsigned int *)(v20 + 68);
    do
      v29 = __ldrex(v28);
    while ( __strex(v29 + 1, v28) );
    __dmb(0xBu);
    result = (unsigned int *)FsRtlNotifySetCancelRoutine((int)a6, 0);
    goto LABEL_44;
  }
  result = (unsigned int *)FsRtlCheckNotifyForDeleteLite(a2);
LABEL_44:
  v30 = (int)varg_r0;
  --*(_DWORD *)(*varg_r0 + 36);
  if ( !*(_DWORD *)(*(_DWORD *)v30 + 36) )
  {
    *(_DWORD *)(*(_DWORD *)v30 + 32) = 0;
    v31 = *(unsigned int **)v30;
    *(_DWORD *)(*(_DWORD *)v30 + 4) = 0;
    __dmb(0xBu);
    do
      v32 = __ldrex(v31);
    while ( !v32 && __strex(1u, v31) );
    if ( v32 )
      ExpReleaseFastMutexContended(v31, v32);
    result = (unsigned int *)KeAbPostRelease((unsigned int)v31);
  }
  if ( a8 )
  {
    SeReleaseSubjectContext(a8);
    result = (unsigned int *)ExFreePoolWithTag(a8);
  }
  return result;
}

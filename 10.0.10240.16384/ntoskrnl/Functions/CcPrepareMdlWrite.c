// CcPrepareMdlWrite 
 
int __fastcall CcPrepareMdlWrite(int a1, _DWORD *a2, int a3, int *a4, _DWORD *a5)
{
  unsigned int v5; // r6
  int v8; // r10
  int v9; // r8
  unsigned int v10; // r5
  unsigned int v11; // r9
  int v12; // r4
  unsigned int v13; // r8
  int v14; // r5
  int v15; // r10
  int v16; // r1
  unsigned int v17; // r2
  signed __int64 v18; // kr00_8
  unsigned int v19; // r1
  int v20; // r0
  int v21; // r8
  int v22; // r3
  char v23; // r4
  int v24; // r4
  int v25; // r1
  unsigned int v26; // r2
  unsigned int v27; // r2
  int v28; // r4
  unsigned int v29; // r1
  int *v30; // r3
  int v31; // r0
  int v33; // [sp+10h] [bp-78h]
  int v34; // [sp+10h] [bp-78h]
  int v35; // [sp+10h] [bp-78h]
  unsigned int v36; // [sp+18h] [bp-70h]
  int v37; // [sp+1Ch] [bp-6Ch] BYREF
  unsigned __int64 v38; // [sp+20h] [bp-68h]
  int v39; // [sp+28h] [bp-60h]
  int v40; // [sp+2Ch] [bp-5Ch]
  int v41; // [sp+30h] [bp-58h]
  int v42; // [sp+34h] [bp-54h]
  unsigned int v43; // [sp+38h] [bp-50h]
  int v44; // [sp+40h] [bp-48h]
  unsigned int v45; // [sp+44h] [bp-44h]
  unsigned int v46; // [sp+48h] [bp-40h]
  unsigned int v47; // [sp+4Ch] [bp-3Ch] BYREF
  int v48; // [sp+50h] [bp-38h]
  int *v49; // [sp+54h] [bp-34h]
  int v50; // [sp+58h] [bp-30h]
  unsigned __int64 v51; // [sp+60h] [bp-28h]
  int varg_r0; // [sp+90h] [bp+8h]
  _DWORD *varg_r1; // [sp+94h] [bp+Ch]
  unsigned int varg_r2; // [sp+98h] [bp+10h]
  int *varg_r3; // [sp+9Ch] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  v49 = a4;
  varg_r3 = a4;
  v5 = a3;
  varg_r1 = a2;
  v42 = 0;
  v40 = 0;
  v48 = 0;
  v39 = 0;
  v37 = 0;
  v8 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 4);
  v50 = v8;
  v41 = v8;
  if ( (*(_DWORD *)(a1 + 44) & 0x10) == 0 && IoIsFileOriginRemote() && !CcCanIWriteStream(a1, v5, 0, 0) )
    RtlRaiseStatus(-1073741670);
  v9 = *a2;
  v10 = a2[1];
  v36 = v10;
  while ( v5 )
  {
    v34 = CcGetVirtualAddress(v8, 0, v9, v10, &v37, &v47, 0, 0, v33);
    v11 = v47;
    if ( v47 > v5 )
    {
      v11 = v5;
      v47 = v5;
    }
    v43 = v11 + v9;
    v46 = (__PAIR64__(v10, v11) + (unsigned int)v9) >> 32;
    v51 = __PAIR64__(v10, v11) + (unsigned int)v9;
    v12 = 2;
    if ( (v9 & 0xFFF) == 0 && v11 >= 0x1000 )
      v12 = 3;
    if ( (((_WORD)v11 + (_WORD)v9) & 0xFFF) == 0 )
      v12 |= 4u;
    v13 = v9 & 0xFFFFF000;
    v38 = __PAIR64__(v10, v13);
    v14 = v8 + 180;
    v15 = KeAbPreAcquire(v8 + 180, 0, 0);
    v16 = KfRaiseIrql(1);
    LODWORD(v38) = v16;
    do
      v17 = __ldrex((unsigned __int8 *)v14);
    while ( __strex(v17 & 0xFE, (unsigned __int8 *)v14) );
    __dmb(0xBu);
    if ( (v17 & 1) == 0 )
    {
      ExpAcquireFastMutexContended(v14, v15);
      v16 = v38;
    }
    if ( v15 )
      *(_BYTE *)(v15 + 14) |= 1u;
    *(_DWORD *)(v14 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v14 + 28) = v16;
    v8 = v50;
    v18 = *(_QWORD *)(v50 + 40) - __PAIR64__(v36, v13);
    v38 = v18;
    *(_DWORD *)(v14 + 4) = 0;
    LODWORD(v38) = *(_DWORD *)(v14 + 28);
    __dmb(0xBu);
    do
      v19 = __ldrex((unsigned int *)v14);
    while ( !v19 && __strex(1u, (unsigned int *)v14) );
    if ( v19 )
      ExpReleaseFastMutexContended(v14, v19, 1);
    KfLowerIrql((unsigned __int8)v38);
    KeAbPostRelease(v14);
    if ( SHIDWORD(v18) <= 0 )
    {
      if ( v18 > 0 )
      {
        if ( (unsigned int)v18 <= 0x1000 )
          v12 |= 6u;
      }
      else
      {
        v12 = 7;
      }
    }
    CcMapAndRead(v11, v12, 1, v34);
    v20 = IoAllocateMdl(v34, v11, 0, 0, 0);
    v21 = v20;
    v42 = v20;
    if ( !v20 )
      RtlRaiseStatus(-1073741670);
    v22 = *(unsigned __int8 *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3CD);
    v23 = v22 + 2;
    v40 = v22 + 2;
    *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3CD) = 1;
    MmProbeAndLockPages(v20, 0, 1);
    *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3CD) = v23 - 2;
    v40 = 0;
    v24 = KeAbPreAcquire(v14, 0, 0);
    v25 = KfRaiseIrql(1);
    v35 = v25;
    do
      v26 = __ldrex((unsigned __int8 *)v14);
    while ( __strex(v26 & 0xFE, (unsigned __int8 *)v14) );
    __dmb(0xBu);
    if ( (v26 & 1) == 0 )
    {
      ExpAcquireFastMutexContended(v14, v24);
      v25 = v35;
    }
    if ( v24 )
      *(_BYTE *)(v24 + 14) |= 1u;
    *(_DWORD *)(v14 + 4) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    *(_DWORD *)(v14 + 28) = v25;
    v27 = v46;
    v28 = v43;
    if ( __SPAIR64__(v46, v43) > *(_QWORD *)(v8 + 40) )
    {
      *(_DWORD *)(v8 + 40) = v43;
      *(_DWORD *)(v8 + 44) = v27;
    }
    *(_DWORD *)(v14 + 4) = 0;
    v33 = *(_DWORD *)(v14 + 28);
    __dmb(0xBu);
    do
      v29 = __ldrex((unsigned int *)v14);
    while ( !v29 && __strex(1u, (unsigned int *)v14) );
    if ( v29 )
      ExpReleaseFastMutexContended(v14, v29, 1);
    KfLowerIrql((unsigned __int8)v33);
    KeAbPostRelease(v14);
    CcFreeVirtualAddress(v37);
    v37 = 0;
    v30 = (int *)*v49;
    if ( *v49 )
    {
      while ( *v30 )
        v30 = (int *)*v30;
      *v30 = v21;
    }
    else
    {
      *v49 = v21;
    }
    v42 = 0;
    v9 = v28;
    v44 = v28;
    v10 = v46;
    v36 = v46;
    v45 = v46;
    v48 += v11;
    v39 = v48;
    v5 -= v11;
    varg_r2 = v5;
  }
  *a5 = 0;
  a5[1] = v39;
  v31 = KeAcquireQueuedSpinLock(5);
  ++*(_DWORD *)(v41 + 4);
  return KeReleaseQueuedSpinLock(5, v31);
}

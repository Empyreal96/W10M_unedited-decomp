// NtFreeUserPhysicalPages 
 
int __fastcall NtFreeUserPhysicalPages(int a1, _DWORD *a2, int a3)
{
  int v3; // r4
  _DWORD *v4; // r2
  unsigned int v5; // r10
  int v6; // r5
  int v7; // r5
  _BYTE *v8; // r8
  unsigned int v9; // r6
  int v10; // r9
  int v11; // lr
  unsigned int v12; // r5
  _DWORD *v13; // r3
  int v14; // r2
  unsigned int *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // lr
  int v18; // r3
  _DWORD *v19; // r2
  unsigned int *v20; // r1
  unsigned int v21; // r4
  int v22; // r2
  int v23; // r0
  __int16 v24; // r3
  int v25; // r3
  int v26; // r2
  int v27; // r4
  unsigned int *v28; // r2
  unsigned int v29; // r0
  unsigned int *v30; // r2
  unsigned int v31; // r0
  char v32; // r4
  unsigned int *v35; // [sp+14h] [bp-194h] BYREF
  int v36; // [sp+18h] [bp-190h]
  char v37; // [sp+1Ch] [bp-18Ch]
  unsigned int v38; // [sp+20h] [bp-188h]
  int v39; // [sp+24h] [bp-184h]
  int v40; // [sp+28h] [bp-180h]
  unsigned int v41; // [sp+2Ch] [bp-17Ch]
  _DWORD *v42; // [sp+30h] [bp-178h]
  __int16 *v43; // [sp+34h] [bp-174h]
  int v44; // [sp+38h] [bp-170h]
  unsigned int *v45; // [sp+40h] [bp-168h]
  _DWORD *v46; // [sp+44h] [bp-164h]
  int v47; // [sp+48h] [bp-160h]
  _BYTE v48[24]; // [sp+50h] [bp-158h] BYREF
  _BYTE v49[320]; // [sp+68h] [bp-140h] BYREF

  v38 = a3;
  v46 = a2;
  v36 = a1;
  v42 = a2;
  v39 = a3;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v40 = v3;
  v43 = (__int16 *)v3;
  v44 = *(char *)(v3 + 0x15A);
  v37 = v44;
  if ( v44 )
  {
    v4 = a2;
    if ( (unsigned int)a2 >= MmUserProbeAddress )
      v4 = (_DWORD *)MmUserProbeAddress;
    *v4 = *v4;
    v5 = *a2;
    v47 = *a2;
    *a2 = 0;
  }
  else
  {
    v5 = *a2;
  }
  if ( !v5 )
    return -1073741584;
  v7 = 0;
  v41 = 0;
  v39 = 0;
  v8 = 0;
  v9 = 0;
  if ( v5 > 0x40 )
  {
    v9 = 1048574;
    if ( v5 <= 0xFFFFE )
      v9 = v5;
    do
    {
      v8 = (_BYTE *)IoAllocateMdl(0, v9 << 12, 0, 0, 0);
      if ( v8 )
        break;
      v9 >>= 1;
    }
    while ( v9 > 0x40 );
    v7 = 0;
  }
  if ( !v8 )
  {
    v9 = 64;
    v8 = v49;
  }
  v10 = *(_DWORD *)(v3 + 116);
  v35 = (unsigned int *)v10;
  if ( a1 == -1 )
    goto LABEL_19;
  v6 = ObReferenceObjectByHandleWithTag(a1, 8, PsProcessType, v44, 1750101325, (int *)&v35, 0);
  v10 = (int)v35;
  if ( v6 >= 0 )
  {
    v7 = 2;
LABEL_19:
    v43 = MiGetThreadPartition();
    v11 = (int)(v8 + 28);
    v45 = (unsigned int *)(v8 + 28);
    while ( 1 )
    {
      if ( v5 < v9 )
        v9 = v5;
      *(_DWORD *)v8 = 0;
      *((_WORD *)v8 + 2) = 4 * ((((v9 << 12) + 4095) >> 12) + 7);
      *((_WORD *)v8 + 3) = 0;
      *((_DWORD *)v8 + 4) = 0;
      *((_DWORD *)v8 + 6) = 0;
      *((_DWORD *)v8 + 5) = v9 << 12;
      v35 = (unsigned int *)v11;
      v12 = v7 & 0xFFFFFFFE;
      v41 = v12;
      if ( v44 )
      {
        v6 = MiCaptureUlongPtrArray(v11, v38, v9);
        if ( v6 < 0 )
          goto LABEL_64;
        v12 = v41;
      }
      else
      {
        memmove(v11, v38, 4 * v9);
      }
      if ( *(_DWORD *)(v3 + 116) != v10 )
      {
        KiStackAttachProcess(v10, 0, (int)v48);
        v41 = v12 | 1;
      }
      v13 = *(_DWORD **)(v10 + 328);
      v36 = (int)v13;
      if ( !v13 || !*v13 )
        break;
      v6 = 0;
      LOCK_ADDRESS_SPACE(v3, v10);
      if ( (*(_DWORD *)(v10 + 192) & 0x20) != 0 )
      {
        UNLOCK_ADDRESS_SPACE(v3, v10);
        v6 = -1073741558;
        goto LABEL_64;
      }
      v14 = v36;
      v45 = *(unsigned int **)v36;
      v42 = (_DWORD *)v45[1];
      --*(_WORD *)(v3 + 310);
      ExAcquireAutoExpandPushLockExclusive(v14 + 4, 0, v14);
      if ( v8 + 28 < &v8[4 * v9 + 28] )
      {
        v15 = v35;
        while ( 1 )
        {
          v16 = *v15;
          if ( *v15 >= *v45 )
            break;
          v17 = v42[v16 >> 5];
          if ( ((v17 >> (v16 & 0x1F)) & 1) == 0 )
            break;
          ++v39;
          v42[v16 >> 5] = v17 & ~(1 << (v16 & 0x1F));
          v18 = MmPfnDatabase + 24 * v16;
          v19 = *(_DWORD **)(v18 + 4);
          if ( v19 )
          {
            __dmb(0xBu);
            v20 = (unsigned int *)(v18 + 4);
            do
              v21 = __ldrex(v20);
            while ( __strex(0, v20) );
            if ( (unsigned int)(v19 + 0x10000000) > 0x3FFFFF )
            {
              *v19 = 0;
            }
            else
            {
              __dmb(0xBu);
              *v19 = 0;
              if ( (unsigned int)(v19 + 267649024) <= 0xFFF )
                MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 0, (__int16)v19);
            }
          }
          v15 = v35 + 1;
          v35 = v15;
          if ( v15 >= (unsigned int *)&v8[4 * v9 + 28] )
            goto LABEL_45;
        }
        v6 = -1073741800;
LABEL_45:
        v3 = v40;
      }
      KeFlushTb(1, 0);
      v23 = ExReleaseAutoExpandPushLockExclusive((int *)(v36 + 4), 0, v22);
      v24 = *(_WORD *)(v3 + 310) + 1;
      *(_WORD *)(v3 + 310) = v24;
      if ( !v24 && *(_DWORD *)(v3 + 100) != v3 + 100 )
        KiCheckForKernelApcDelivery(v23);
      v25 = ((char *)v35 - v8 - 28) >> 2;
      v36 = v25;
      if ( v25 )
        MiReturnProcessCommitment(v10, v25);
      UNLOCK_ADDRESS_SPACE(v3, v10);
      v26 = v36;
      *((_DWORD *)v8 + 5) = v36 << 12;
      if ( v26 )
      {
        v27 = -v26;
        v28 = (unsigned int *)(v10 + 648);
        do
          v29 = __ldrex(v28);
        while ( __strex(v29 + v27, v28) );
        v30 = (unsigned int *)(v43 + 2062);
        do
          v31 = __ldrex(v30);
        while ( __strex(v31 + v27, v30) );
        MiSynchronizePageFree(v10);
        MiFreePagesFromMdl(v43, (int)v8, 1);
        v3 = v40;
        v26 = v36;
      }
      v5 -= v26;
      if ( v6 || !v5 )
        goto LABEL_64;
      v7 = v41;
      if ( (v41 & 1) != 0 )
      {
        KiUnstackDetachProcess((unsigned int)v48, 0);
        v7 &= 0xFFFFFFFE;
      }
      v38 += 4 * v9;
      v11 = (int)(v8 + 28);
    }
    v6 = -1073741585;
  }
LABEL_64:
  if ( v8 != v49 )
    IoFreeMdl((int)v8);
  v32 = v41;
  if ( (v41 & 1) != 0 )
    KiUnstackDetachProcess((unsigned int)v48, 0);
  if ( (v32 & 2) != 0 )
    ObfDereferenceObjectWithTag(v10);
  *v46 = v39;
  return v6;
}

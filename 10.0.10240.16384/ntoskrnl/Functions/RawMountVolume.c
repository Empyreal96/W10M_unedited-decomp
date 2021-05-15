// RawMountVolume 
 
int __fastcall RawMountVolume(_DWORD *a1)
{
  int v2; // r6
  int v3; // r5
  unsigned int v4; // r2
  int v5; // r4
  int v6; // r0
  int v7; // r6
  int v8; // r8
  int v9; // r9
  unsigned int v10; // r2
  int v11; // r0
  unsigned __int8 v12; // r4
  unsigned int v13; // r1
  int v15; // [sp+10h] [bp-60h] BYREF
  int v16; // [sp+14h] [bp-5Ch]
  _WORD v17[10]; // [sp+18h] [bp-58h] BYREF
  int v18; // [sp+2Ch] [bp-44h]
  int v19; // [sp+30h] [bp-40h]
  int v20; // [sp+34h] [bp-3Ch]
  int v21; // [sp+38h] [bp-38h]
  int v22; // [sp+3Ch] [bp-34h]
  int v23; // [sp+40h] [bp-30h]
  _BYTE v24[6]; // [sp+44h] [bp-2Ch] BYREF

  RawScanDeletedList();
  v2 = a1[3];
  if ( *(unsigned __int16 *)(v2 + 172) > 0x1000u )
    return -1073741489;
  v3 = IoCreateDevice(*(_DWORD *)(a1[6] + 8), 224, 0, 8u, 0, 0, &v15);
  if ( v3 >= 0 )
  {
    v4 = *(_DWORD *)(v2 + 92);
    v5 = v15;
    if ( v4 > *(_DWORD *)(v15 + 92) )
      *(_DWORD *)(v15 + 92) = v4;
    *(_WORD *)(v5 + 172) = *(_WORD *)(v2 + 172);
    *(_DWORD *)(v5 + 28) |= 0x10u;
    v3 = RawInitializeVcb(v5 + 184, a1[3], a1[2]);
    if ( v3 >= 0 )
    {
      *(_DWORD *)(*(_DWORD *)(v5 + 324) + 8) = v5;
      *(_DWORD *)(*(_DWORD *)(v5 + 324) + 16) = -1;
      *(_WORD *)(*(_DWORD *)(v5 + 324) + 6) = 0;
      *(_DWORD *)(v5 + 28) &= 0xFFFFFF7F;
      *(_BYTE *)(v5 + 48) = *(_BYTE *)(v2 + 48) + 1;
      v16 = 0;
      v6 = IoCreateStreamFileObjectLite(0, v5);
      v7 = v6;
      v16 = v6;
      *(_DWORD *)(v5 + 260) += 2;
      *(_DWORD *)(v5 + 264) += 2;
      v17[0] = 1;
      v18 = 0;
      v17[1] = 54;
      v19 = -1;
      v20 = 1;
      v21 = 0;
      v22 = 6;
      v23 = 16;
      qmemcpy(v24, "RAW", sizeof(v24));
      FsRtlNotifyVolumeEventEx(v6, 6, v17);
      ObfDereferenceObject(v7);
      *(_DWORD *)(v5 + 260) -= 2;
      *(_DWORD *)(v5 + 264) -= 2;
      v8 = KeAbPreAcquire((unsigned int)&RawGlobalLock, 0, 0);
      v9 = KfRaiseIrql(1);
      do
        v10 = __ldrex((unsigned __int8 *)&RawGlobalLock);
      while ( __strex(v10 & 0xFE, (unsigned __int8 *)&RawGlobalLock) );
      __dmb(0xBu);
      if ( (v10 & 1) == 0 )
        ExpAcquireFastMutexContended((int)&RawGlobalLock, v8);
      if ( v8 )
        *(_BYTE *)(v8 + 14) |= 1u;
      dword_61D964 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      dword_61D97C = v9;
      v11 = RawMountedQueue;
      *(_DWORD *)(v5 + 312) = RawMountedQueue;
      *(_DWORD *)(v5 + 316) = &RawMountedQueue;
      if ( *(int **)(v11 + 4) != &RawMountedQueue )
        __fastfail(3u);
      *(_DWORD *)(v11 + 4) = v5 + 312;
      RawMountedQueue = v5 + 312;
      dword_61D964 = 0;
      v12 = dword_61D97C;
      __dmb(0xBu);
      do
        v13 = __ldrex((unsigned int *)&RawGlobalLock);
      while ( !v13 && __strex(1u, (unsigned int *)&RawGlobalLock) );
      if ( v13 )
        ExpReleaseFastMutexContended((unsigned int *)&RawGlobalLock, v13);
      KfLowerIrql(v12);
      KeAbPostRelease((unsigned int)&RawGlobalLock);
    }
    else
    {
      RawCleanupVcb(v5 + 184);
      IoDeleteDevice((_DWORD *)v5);
    }
  }
  return v3;
}

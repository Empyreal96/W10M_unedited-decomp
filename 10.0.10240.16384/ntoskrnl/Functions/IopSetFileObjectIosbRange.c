// IopSetFileObjectIosbRange 
 
int __fastcall IopSetFileObjectIosbRange(int a1, int a2)
{
  int *v2; // r4
  unsigned int *v3; // r6
  int v4; // r9
  int v5; // r5
  unsigned int *v6; // r3
  int v7; // r2
  unsigned int v8; // r10
  int v9; // r8
  int *v10; // r1
  unsigned int v11; // r2
  int v12; // r8
  int *v13; // r0
  int v14; // r2
  int v15; // r3
  int v16; // r10
  int v17; // r0
  int v18; // r1
  int v19; // r0
  unsigned int *v20; // r0
  int v21; // r10
  int v22; // r0
  _DWORD *v23; // r1
  unsigned int *v24; // r5
  unsigned int v25; // r1
  unsigned __int8 v26; // r4
  unsigned int v27; // r1
  char v29[4]; // [sp+8h] [bp-70h] BYREF
  int v30; // [sp+Ch] [bp-6Ch]
  char v31; // [sp+10h] [bp-68h]
  int v32; // [sp+14h] [bp-64h]
  int v33; // [sp+18h] [bp-60h]
  int *v34; // [sp+1Ch] [bp-5Ch]
  int v35; // [sp+20h] [bp-58h]
  int v36; // [sp+24h] [bp-54h]
  int *v37; // [sp+28h] [bp-50h] BYREF
  int v38; // [sp+2Ch] [bp-4Ch]
  int v39; // [sp+30h] [bp-48h]
  int v40; // [sp+34h] [bp-44h]
  int v41; // [sp+38h] [bp-40h]
  int v42; // [sp+3Ch] [bp-3Ch]
  unsigned int v43; // [sp+40h] [bp-38h]
  int v44; // [sp+44h] [bp-34h]
  int v45; // [sp+48h] [bp-30h]
  int v46; // [sp+4Ch] [bp-2Ch]
  _DWORD _50[14]; // [sp+50h] [bp-28h] BYREF

  _50[13] = a2;
  v44 = a2;
  v38 = a1;
  _50[12] = a1;
  v35 = 0;
  v29[0] = 0;
  v2 = 0;
  v3 = 0;
  v42 = 0;
  v4 = 0;
  v39 = 0;
  v36 = 0;
  v46 = 0;
  v5 = 0;
  v32 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v40 = v32;
  v6 = *(unsigned int **)(a2 + 12);
  v7 = v6[1];
  v33 = v7;
  if ( !v7 )
    return -1073741811;
  v41 = v7;
  v8 = *v6;
  v43 = *v6;
  v9 = KeAbPreAcquire((unsigned int)&IoStatusBlockRangeTableLock, 0, 0);
  v10 = (int *)KfRaiseIrql(1);
  v34 = v10;
  do
    v11 = __ldrex((unsigned __int8 *)&IoStatusBlockRangeTableLock);
  while ( __strex(v11 & 0xFE, (unsigned __int8 *)&IoStatusBlockRangeTableLock) );
  __dmb(0xBu);
  if ( (v11 & 1) == 0 )
  {
    ExpAcquireFastMutexContended((int)&IoStatusBlockRangeTableLock, v9);
    v10 = v34;
  }
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  dword_631B64 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  dword_631B7C = (int)v10;
  v12 = v32;
  _50[0] = v32;
  v13 = (int *)RtlInsertElementGenericTableAvl((int)&IoStatusBlockRangeTable, (int)_50, 8, (int)v29);
  v34 = v13;
  v37 = v13;
  if ( !v13 )
  {
    v5 = -1073741670;
    v16 = (unsigned __int8)v29[0];
LABEL_63:
    if ( v4 )
    {
      if ( v36 )
        MmUnmapLockedPages(v36, v4, v14);
      MmUnlockPages(v4);
      IoFreeMdl(v4);
    }
    if ( v3 )
    {
      ObfDereferenceObjectWithTag(v12);
      ExFreePoolWithTag((unsigned int)v3);
    }
    if ( v16 == 1 )
      RtlDeleteElementGenericTableAvl((int)&IoStatusBlockRangeTable, (int)_50, v14, v15);
    if ( v35 == 1 )
      ExFreePoolWithTag((unsigned int)v2);
    goto LABEL_73;
  }
  v30 = (unsigned __int8)v29[0];
  if ( v29[0] )
  {
LABEL_16:
    if ( v2 )
      goto LABEL_33;
    goto LABEL_17;
  }
  v2 = (int *)v13[1];
  if ( v2 )
  {
    do
    {
      v15 = v2[1];
      if ( v15 == v8 )
      {
        v14 = v8 + v33;
        v15 = v2[2];
        if ( v15 == v8 + v33 )
          break;
      }
      v2 = (int *)v2[5];
    }
    while ( v2 );
    goto LABEL_16;
  }
LABEL_17:
  v17 = ExAllocatePoolWithTag(1, 24, 1700032329);
  v2 = (int *)v17;
  v45 = v17;
  if ( !v17 )
  {
LABEL_18:
    v5 = -1073741670;
    v16 = v30;
    goto LABEL_63;
  }
  v35 = 1;
  v31 = 1;
  v18 = v33;
  if ( v33 )
  {
    if ( (v8 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v17);
    if ( v8 + v33 > MmUserProbeAddress || v8 + v33 < v8 )
      *(_BYTE *)MmUserProbeAddress = 0;
  }
  v19 = IoAllocateMdl(v8, v18, 0, 1, 0);
  v4 = v19;
  v39 = v19;
  if ( !v19 )
    RtlRaiseStatus(-1073741670);
  MmProbeAndLockPages(v19);
  v15 = *(unsigned __int16 *)(v4 + 6);
  if ( (v15 & 5) != 0 )
    v14 = *(_DWORD *)(v4 + 12);
  else
    v14 = MmMapLockedPagesSpecifyCache(v4, 0, 1, 0, 0, 1073741840);
  v36 = v14;
  if ( v14 )
  {
    v2[3] = v4;
    v2[1] = v8;
    v2[2] = v8 + v33;
    v15 = 1;
    *v2 = 1;
    v2[5] = 0;
    v2[4] = v14;
  }
  else
  {
    v5 = -1073741670;
  }
LABEL_33:
  if ( v5 < 0 )
  {
    v12 = v32;
LABEL_61:
    v16 = v30;
    goto LABEL_62;
  }
  v20 = (unsigned int *)ExAllocatePoolWithTag(512, 24, 1700032329);
  v3 = v20;
  if ( !v20 )
  {
    v12 = v32;
    goto LABEL_18;
  }
  memset(v20, 0, 24);
  *v3 = v8;
  v3[1] = v33 + v8;
  v3[3] = v2[4] - v2[1] + v8;
  v3[2] = v2[3];
  v3[5] = 0;
  v12 = v32;
  ObfReferenceObjectWithTag(v32);
  v3[4] = v12;
  v21 = v38;
  v5 = IopAllocateFileObjectExtension(v38, &v37);
  if ( v5 < 0 )
    goto LABEL_61;
  v5 = IopSetTypeSpecificFoExtension((int)v37, 2u, (unsigned int)v3);
  v15 = -1073741823;
  if ( v5 == -1073741823 )
  {
    v22 = IopGetFileObjectExtension(v21, 2, 0);
    v15 = v3[4];
    if ( v15 == v12 )
    {
      v23 = (_DWORD *)v22;
      if ( v22 )
      {
        while ( *v3 != *v23 || v3[1] != v23[1] )
        {
          v23 = (_DWORD *)v23[5];
          if ( !v23 )
            goto LABEL_45;
        }
        ObfDereferenceObjectWithTag(v12);
        ExFreePoolWithTag((unsigned int)v3);
        v5 = 0;
        goto LABEL_73;
      }
LABEL_45:
      v3[5] = *(_DWORD *)(v22 + 20);
      __dmb(0xBu);
      v24 = (unsigned int *)(v22 + 20);
      v14 = v3[5];
      do
        v25 = __ldrex(v24);
      while ( v25 == v14 && __strex((unsigned int)v3, v24) );
      while ( 1 )
      {
        __dmb(0xBu);
        v15 = v3[5];
        if ( v25 == v15 )
          break;
        v3[5] = *(_DWORD *)(v22 + 20);
        __dmb(0xBu);
        v14 = v3[5];
        do
          v25 = __ldrex(v24);
        while ( v25 == v14 && __strex((unsigned int)v3, v24) );
      }
      v5 = 0;
    }
  }
  v16 = v30;
  if ( v5 < 0 )
    goto LABEL_63;
  if ( v35 == 1 )
  {
    if ( v30 == 1 )
    {
      v15 = (int)v34;
      *v34 = v12;
      *(_DWORD *)(v15 + 4) = v2;
    }
    else
    {
      v14 = (int)v34;
      v15 = v34[1];
      v2[5] = v15;
      *(_DWORD *)(v14 + 4) = v2;
    }
  }
  else
  {
    v15 = *v2 + 1;
    *v2 = v15;
  }
LABEL_62:
  if ( v5 < 0 )
    goto LABEL_63;
LABEL_73:
  dword_631B64 = 0;
  v26 = dword_631B7C;
  __dmb(0xBu);
  do
    v27 = __ldrex((unsigned int *)&IoStatusBlockRangeTableLock);
  while ( !v27 && __strex(1u, (unsigned int *)&IoStatusBlockRangeTableLock) );
  if ( v27 )
    ExpReleaseFastMutexContended((unsigned int *)&IoStatusBlockRangeTableLock, v27);
  KfLowerIrql(v26);
  KeAbPostRelease((unsigned int)&IoStatusBlockRangeTableLock);
  return v5;
}

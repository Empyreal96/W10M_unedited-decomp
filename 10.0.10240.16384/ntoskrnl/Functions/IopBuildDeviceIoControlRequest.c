// IopBuildDeviceIoControlRequest 
 
_DWORD *__fastcall IopBuildDeviceIoControlRequest(int a1, int a2, int a3, unsigned int a4, int a5, unsigned int a6, char a7, int a8, int a9, int a10)
{
  _DWORD *v12; // r0
  _DWORD *v13; // r4
  int v14; // r5
  char v15; // r3
  unsigned int v16; // r6
  unsigned int v17; // r8
  int v18; // r0
  int v19; // r3
  int v20; // r0
  int v22; // r0
  int v23; // r3
  int v24; // r1
  int *v25; // r5
  int *v26; // r6
  unsigned int *v27; // r8
  int v28; // r10
  unsigned int v29; // r2
  int v30; // r2
  _DWORD *v31; // r1
  int v32; // r2
  int v33; // [sp+8h] [bp-28h]
  int varg_r0; // [sp+38h] [bp+8h]
  unsigned int varg_r3; // [sp+44h] [bp+14h]

  varg_r0 = a1;
  varg_r3 = a4;
  v33 = a3;
  v12 = (_DWORD *)pIoAllocateIrp(a2, *(char *)(a2 + 48), 0, a10);
  v13 = v12;
  if ( !v12 )
    return 0;
  v14 = v12[24];
  if ( a7 )
    v15 = 15;
  else
    v15 = 14;
  *(_BYTE *)(v14 - 40) = v15;
  v16 = a6;
  *(_DWORD *)(v14 - 32) = a6;
  *(_DWORD *)(v14 - 28) = a4;
  *(_DWORD *)(v14 - 24) = a1;
  v17 = a1 & 3;
  if ( !v17 )
  {
    if ( !a4 && !a6 )
    {
      v12[2] = 0;
      v12[15] = 0;
      goto LABEL_41;
    }
    if ( a4 > a6 )
      v16 = a4;
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v23 = 40;
      else
        v23 = 32;
      v22 = ExAllocatePoolWithTagPriority(516, v16, 538996553, v23);
    }
    else
    {
      v22 = ExAllocatePoolWithTag(516, v16, 538996553);
    }
    v13[3] = v22;
    if ( v22 )
    {
      if ( v33 )
        memmove(v22, v33, a4);
      v13[2] = 48;
      v13[15] = a5;
      if ( a5 )
        v13[2] = 112;
      goto LABEL_41;
    }
    goto LABEL_22;
  }
  if ( v17 <= 2 )
  {
    if ( !v33 )
    {
      v12[2] = 0;
      goto LABEL_18;
    }
    if ( ViVerifierDriverAddedThunkListHead )
    {
      if ( (MmVerifierData & 0x10) != 0 )
        v19 = 40;
      else
        v19 = 32;
      v18 = ExAllocatePoolWithTagPriority(516, a4, 538996553, v19);
    }
    else
    {
      v18 = ExAllocatePoolWithTag(516, a4, 538996553);
    }
    v13[3] = v18;
    if ( v18 )
    {
      memmove(v18, v33, a4);
      v13[2] = 48;
LABEL_18:
      if ( !a5 )
        goto LABEL_41;
      v20 = IoAllocateMdl(a5, a6, 0, 0, 0);
      v13[1] = v20;
      if ( v20 )
      {
        sub_441640();
        goto LABEL_41;
      }
      if ( v33 )
        ExFreePoolWithTag(v13[3], 0);
    }
LABEL_22:
    pIoFreeIrp(v13);
    return 0;
  }
  v12[15] = a5;
  *(_DWORD *)(v14 - 20) = v33;
LABEL_41:
  v13[10] = a9;
  v13[11] = a8;
  v24 = __mrc(15, 0, 13, 0, 3);
  v13[20] = v24 & 0xFFFFFFC0;
  v25 = (int *)((v24 & 0xFFFFFFC0) + 908);
  v26 = v13 + 4;
  v27 = (unsigned int *)((v24 & 0xFFFFFFC0) + 1024);
  v28 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(v27);
  }
  else
  {
    do
      v29 = __ldrex(v27);
    while ( __strex(1u, v27) );
    __dmb(0xBu);
    if ( v29 )
      KxWaitForSpinLockAndAcquire(v27);
  }
  v30 = *v25;
  *v26 = *v25;
  v13[5] = v25;
  if ( *(int **)(v30 + 4) != v25 )
    __fastfail(3u);
  *(_DWORD *)(v30 + 4) = v26;
  *v25 = (int)v26;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v27);
  }
  else
  {
    __dmb(0xBu);
    *v27 = 0;
  }
  KfLowerIrql(v28);
  v31 = (_DWORD *)v13[20];
  v32 = (v31[240] >> 9) & 7;
  if ( (*(_DWORD *)(v31[84] + 192) & 0x100000) != 0 )
    v32 = 0;
  if ( v32 < 2 && v31 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
  {
    if ( v31[250] )
      v32 = 2;
  }
  v13[2] = v13[2] & 0xFFF1FFFF | ((v32 + 1) << 17);
  return v13;
}

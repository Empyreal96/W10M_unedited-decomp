// PopAllocateIrp 
 
int __fastcall PopAllocateIrp(int a1, int a2, int a3, int a4, int a5, char a6, unsigned __int8 a7, int a8, int a9, int *a10, unsigned int *a11)
{
  int v11; // r5
  unsigned int v12; // r4
  int v14; // r7
  int v15; // r0
  int v16; // r10
  _DWORD *v18; // r8
  int v19; // r2
  int v20; // r0
  int v21; // r6
  int v22; // r9
  char v23; // r2
  int v24; // r3
  int v25; // r3
  int v26; // r3
  int v27; // r3
  void **v28; // r1
  unsigned int v29; // r8
  unsigned int v30; // r8
  int v31; // [sp+10h] [bp-48h] BYREF
  unsigned int v32[2]; // [sp+18h] [bp-40h] BYREF
  int v33; // [sp+20h] [bp-38h]
  int v34; // [sp+24h] [bp-34h]
  int v35; // [sp+28h] [bp-30h]
  char var28[44]; // [sp+30h] [bp-28h] BYREF
  int varg_r0; // [sp+60h] [bp+8h]
  int varg_r1; // [sp+64h] [bp+Ch]
  int varg_r2; // [sp+68h] [bp+10h]
  int varg_r3; // [sp+6Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v33 = a3;
  v34 = a4;
  v11 = 0;
  *a10 = 0;
  v12 = 0;
  *a11 = 0;
  v35 = a1;
  v31 = 0;
  v32[0] = 0;
  v14 = IoGetAttachedDeviceReference();
  v15 = IoGetDeviceAttachmentBaseRef(a1);
  v16 = v15;
  if ( !v15 )
    return sub_52A184();
  v18 = *(_DWORD **)(*(_DWORD *)(v15 + 176) + 20);
  if ( !v18 )
  {
    v21 = -1073741808;
    goto LABEL_38;
  }
  v19 = v33;
  v20 = a8;
  if ( v33 == 2 && v34 == 1 )
  {
    v20 = PopFxAllocatePowerIrp(v18, a1, a5, a8, a9, a7, &v31, v32);
    v21 = v20;
    if ( v20 < 0 && v20 != -1073741130 )
    {
      v11 = v31;
      v12 = v32[0];
      goto LABEL_16;
    }
    v11 = v31;
    v12 = v32[0];
    if ( v20 == 259 )
      goto LABEL_16;
    v19 = v33;
  }
  else
  {
    v21 = -1073741130;
  }
  if ( v21 < 0 )
  {
    if ( v19 )
    {
      v22 = 0;
    }
    else
    {
      v20 = PopFxLockDevice(v18, 0);
      v22 = v20;
    }
    v29 = 0;
    v32[0] = -500000;
    v32[1] = -1;
    while ( 1 )
    {
      if ( v29 && (unsigned int)KeGetCurrentIrql(v20) <= 1 )
        KeDelayExecutionThread(0, 0, v32);
      ++v29;
      v20 = ExAllocateFromNPagedLookasideList(&PopIrpDataLookaside);
      v12 = v20;
      if ( v20 )
        break;
      if ( !a6 || v29 >= 0xA )
        goto LABEL_16;
    }
    v30 = 0;
    while ( 1 )
    {
      if ( v30 && (unsigned int)KeGetCurrentIrql(v20) <= 1 )
        KeDelayExecutionThread(0, 0, v32);
      ++v30;
      v20 = IoAllocateIrp((char)(*(_BYTE *)(v14 + 48) + 1), 0);
      v11 = v20;
      if ( v20 )
        break;
      if ( !a6 )
        goto LABEL_17;
      if ( v30 >= 0xA )
        goto LABEL_38;
    }
  }
  else
  {
    v22 = v18[10];
    if ( *(char *)(v14 + 48) > *(char *)(*(_DWORD *)(v22 + 8) + 34) )
    {
      ObfDereferenceObjectWithTag(v14);
      ObfReferenceObjectWithTag(*(_DWORD *)(v22 + 56), 1953261124);
      v14 = *(_DWORD *)(v22 + 56);
    }
  }
  IoReuseIrp(v11, -1073741637);
  if ( IovUtilVerifierEnabled )
    VfIrpWatermark(v11, 1);
  v21 = 0;
  *(_DWORD *)(v11 + 28) = 0;
  *(_DWORD *)(v11 + 88) = v11 + 88;
  *(_DWORD *)(v11 + 92) = v11 + 88;
  memset((_BYTE *)v12, 0, 152);
  v23 = v33;
  v24 = v34;
  *(_DWORD *)(v12 + 12) = v16;
  *(_DWORD *)(v12 + 16) = v14;
  *(_BYTE *)(v12 + 112) = v23;
  *(_DWORD *)(v12 + 116) = v24;
  *(_DWORD *)(v12 + 120) = a5;
  *(_DWORD *)(v12 + 8) = v11;
  *(_DWORD *)(v12 + 128) = v22;
  *(_DWORD *)(v12 + 136) = a8;
  *(_DWORD *)(v12 + 140) = a9;
  *(_DWORD *)(v12 + 144) = v35;
  v25 = *(_DWORD *)(v11 + 96);
  *(_DWORD *)(v25 - 16) = 0;
  *(_DWORD *)(v25 - 4) = v12;
  --*(_BYTE *)(v11 + 35);
  v26 = *(_DWORD *)(v11 + 96) - 40;
  *(_DWORD *)(v11 + 96) = v26;
  *(_BYTE *)(v26 - 40) = 22;
  *(_BYTE *)(v26 - 39) = v23;
  *(_DWORD *)(v26 - 16) = v14;
  KeAcquireInStackQueuedSpinLock(&PopIrpLock, var28);
  v27 = __mrc(15, 0, 13, 0, 3);
  v28 = (void **)dword_61EF34;
  PopIrpLockThread = v27 & 0xFFFFFFC0;
  *(_DWORD *)v12 = &PopIrpList;
  *(_DWORD *)(v12 + 4) = v28;
  if ( *v28 != &PopIrpList )
    __fastfail(3u);
  PopIrpLockThread = 0;
  *v28 = (void *)v12;
  dword_61EF34 = v12;
  KeReleaseInStackQueuedSpinLock(var28);
  v14 = 0;
  v16 = 0;
  *a10 = v11;
  *a11 = v12;
  v12 = 0;
LABEL_16:
  if ( !v11 )
  {
LABEL_38:
    if ( a6 && v21 != 259 )
      KeBugCheckEx(160, 1, 6);
  }
LABEL_17:
  if ( v12 )
    ExFreeToNPagedLookasideList(&PopIrpDataLookaside, v12);
  if ( v14 )
    ObfDereferenceObjectWithTag(v14);
  if ( v16 )
    ObfDereferenceObjectWithTag(v16);
  return v21;
}

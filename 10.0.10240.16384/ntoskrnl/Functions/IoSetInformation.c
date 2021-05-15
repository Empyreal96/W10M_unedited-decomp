// IoSetInformation 
 
int __fastcall IoSetInformation(_DWORD *a1, int a2, int a3, int a4)
{
  int v5; // r10
  int v8; // r0
  unsigned int v9; // r5
  unsigned int *v10; // r4
  unsigned int v11; // r2
  int v12; // r5
  unsigned int v13; // r1
  __int16 v14; // r3
  int v15; // r5
  int v16; // r0
  bool v17; // zf
  int v18; // r9
  int v19; // r0
  int v20; // r4
  int v21; // r5
  int v22; // r3
  int v23; // r2
  unsigned int v24; // r3
  int v25; // r3
  unsigned int v26; // r3
  int v27; // r3
  unsigned int v28; // r3
  int v29; // r7
  int v30; // r0
  unsigned int *v31; // r2
  unsigned int v32; // r1
  int v33; // r0
  unsigned int v34; // r1
  __int16 v35; // r3
  char v37[4]; // [sp+8h] [bp-48h] BYREF
  int v38; // [sp+Ch] [bp-44h] BYREF
  int v39; // [sp+10h] [bp-40h]
  int v40; // [sp+14h] [bp-3Ch]
  int v41; // [sp+18h] [bp-38h] BYREF
  char var30[52]; // [sp+20h] [bp-30h] BYREF
  int vars4; // [sp+54h] [bp+4h]

  v38 = 0;
  v5 = 0;
  v40 = a3;
  v8 = ObfReferenceObject((int)a1);
  if ( (a1[11] & 2) != 0 )
  {
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v9 + 308);
    __dmb(0xBu);
    v10 = a1 + 17;
    do
      v11 = __ldrex(v10);
    while ( __strex(1u, v10) );
    __dmb(0xBu);
    if ( v11 )
    {
      v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v14 = *(_WORD *)(v13 + 0x134) + 1;
      *(_WORD *)(v13 + 308) = v14;
      if ( !v14 && *(_DWORD *)(v13 + 100) != v13 + 100 && !*(_WORD *)(v13 + 310) )
        KiCheckForKernelApcDelivery(v8);
      v15 = IopAcquireFileObjectLock((int)a1, 0, (a1[11] & 4) != 0, v37);
      if ( v37[0] )
      {
        ObfDereferenceObject((int)a1);
        return v15;
      }
    }
    else
    {
      ObfReferenceObject((int)a1);
    }
    KeResetEvent((int)(a1 + 23));
    v12 = 1;
  }
  else
  {
    KeInitializeEvent((int)var30, 1, 0);
    v12 = 0;
  }
  v39 = v12;
  v16 = IoGetRelatedDeviceObject(a1);
  v17 = a2 == 56;
  if ( a2 == 56 )
    a2 = 10;
  v18 = v16;
  if ( !v17 )
  {
    if ( a2 != 57 )
      goto LABEL_20;
    a2 = 11;
  }
  v5 = 1;
LABEL_20:
  v19 = pIoAllocateIrp(v16, *(char *)(v16 + 48), v12 == 0, vars4);
  v20 = v19;
  if ( !v19 )
  {
    IopAllocateIrpCleanup((int)a1, 0);
    return -1073741670;
  }
  *(_DWORD *)(v19 + 100) = a1;
  *(_DWORD *)(v19 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_BYTE *)(v19 + 32) = 0;
  if ( v12 )
  {
    *(_DWORD *)(v19 + 44) = 0;
    *(_BYTE *)(v19 + 39) |= 2u;
  }
  else
  {
    *(_DWORD *)(v19 + 44) = var30;
    *(_DWORD *)(v19 + 8) = 4;
  }
  v21 = *(_DWORD *)(v19 + 96);
  *(_DWORD *)(v19 + 40) = &v41;
  *(_BYTE *)(v21 - 40) = 6;
  *(_DWORD *)(v21 - 12) = a1;
  v22 = *(_DWORD *)(v19 + 8);
  *(_DWORD *)(v19 + 12) = a4;
  *(_DWORD *)(v19 + 8) = v22 | 0x10;
  *(_DWORD *)(v21 - 32) = v40;
  *(_DWORD *)(v21 - 28) = a2;
  IopQueueThreadIrp(v19);
  switch ( a2 )
  {
    case 16:
      v23 = a1[11];
      if ( (v23 & 8) == 0 )
      {
        if ( (*(_DWORD *)a4 & 2) != 0 )
          v24 = v23 | 0x10;
        else
          v24 = v23 & 0xFFFFFFEF;
        a1[11] = v24;
      }
      v25 = a1[11];
      if ( (*(_DWORD *)a4 & 4) != 0 )
        v26 = v25 | 0x20;
      else
        v26 = v25 & 0xFFFFFFDF;
      a1[11] = v26;
      if ( (*(_DWORD *)a4 & 2) != 0 )
      {
        v27 = a1[11];
        if ( (*(_DWORD *)a4 & 0x10) != 0 )
          v28 = v27 | 4;
        else
          v28 = v27 & 0xFFFFFFFB;
        a1[11] = v28;
      }
      v15 = 0;
      --*(_BYTE *)(v20 + 35);
      *(_DWORD *)(v20 + 96) -= 40;
      *(_DWORD *)(v20 + 24) = 0;
      *(_DWORD *)(v20 + 28) = 0;
      IofCompleteRequest(v20, 0);
      v29 = 0;
      goto LABEL_54;
    case 10:
    case 11:
      *(_BYTE *)(v21 - 20) = *(_BYTE *)a4;
      if ( v5 )
        *(_BYTE *)(v21 - 38) |= 1u;
      break;
    case 31:
      *(_DWORD *)(v21 - 20) = *(_DWORD *)a4;
      break;
    default:
LABEL_43:
      v30 = IofCallDriver(v18, v20);
      v29 = 0;
LABEL_53:
      v15 = v30;
      goto LABEL_54;
  }
  if ( *(_WORD *)(a4 + 12) != 92 && !*(_DWORD *)(a4 + 4) )
    goto LABEL_43;
  v15 = IopOpenLinkOrRenameTarget(&v38, v20, a4, a1);
  if ( v15 >= 0 )
  {
    v30 = IofCallDriver(v18, v20);
    v29 = v38;
    goto LABEL_53;
  }
  --*(_BYTE *)(v20 + 35);
  *(_DWORD *)(v20 + 96) -= 40;
  IofCompleteRequest(v20, 2);
  v29 = v38;
LABEL_54:
  if ( v39 )
  {
    if ( v15 == 259 )
    {
      if ( KeWaitForSingleObject((unsigned int)(a1 + 23), 0, 0, (_DWORD *)((a1[11] & 4) != 0), 0) == 257 )
        IopCancelAlertedRequest((unsigned int)(a1 + 23), v20);
      v15 = a1[7];
    }
    __dmb(0xBu);
    v31 = a1 + 17;
    do
      v32 = __ldrex(v31);
    while ( __strex(0, v31) );
    __dmb(0xBu);
    if ( a1[16] )
      KeSetEvent((int)(a1 + 19), 0, 0);
    v33 = ObfDereferenceObject((int)a1);
    v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v35 = *(_WORD *)(v34 + 0x134) + 1;
    *(_WORD *)(v34 + 308) = v35;
    if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 && !*(_WORD *)(v34 + 310) )
      KiCheckForKernelApcDelivery(v33);
  }
  else if ( v15 == 259 )
  {
    KeWaitForSingleObject((unsigned int)var30, 0, 0, 0, 0);
    v15 = v41;
  }
  if ( v29 )
    ObCloseHandle(v29);
  return v15;
}

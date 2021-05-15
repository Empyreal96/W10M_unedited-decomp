// IopSynchronousServiceTail 
 
int __fastcall IopSynchronousServiceTail(int a1, int a2, _DWORD *a3, int a4, char a5, char a6, int a7)
{
  int v10; // r10
  _DWORD *v11; // r3
  int v13; // r4
  unsigned int *v14; // r2
  unsigned int v15; // r1
  int v16; // r0
  unsigned int v17; // r1
  int v18; // r3
  BOOL v19; // r4
  int v20; // r8
  int v21; // r0
  int v22; // r4
  unsigned __int64 *v23; // r3
  unsigned __int64 v24; // kr00_8
  unsigned int *v25; // r2
  unsigned __int64 *v26; // r3
  unsigned __int64 v27; // kr08_8
  unsigned int v28; // r1
  unsigned __int64 *v29; // r3
  unsigned __int64 v30; // kr10_8
  unsigned int *v31; // r2
  unsigned int v32; // r1
  int v33; // r1
  unsigned int v34; // r2
  int v35; // r3
  _DWORD *v36; // r2
  int v37; // r1
  int v38; // r0
  int v39; // r2
  int *v40; // r2
  _WORD *v41; // r3
  _DWORD *v43; // r2
  char v44; // r3
  int v45; // r0
  BOOL v46; // r8
  int v47; // r0
  int *v48; // [sp+8h] [bp-40h] BYREF
  int v49; // [sp+Ch] [bp-3Ch] BYREF
  int v50; // [sp+10h] [bp-38h] BYREF
  _DWORD *v51; // [sp+14h] [bp-34h] BYREF
  int v52[12]; // [sp+18h] [bp-30h] BYREF

  v50 = a4;
  v51 = a3;
  v10 = 0;
  if ( a6 || *(_DWORD *)(a2 + 48) )
  {
    if ( (a3[11] & 2) != 0 )
      *(_BYTE *)(a2 + 39) |= 2u;
  }
  else if ( *(_DWORD *)(a2 + 52) && !*(_DWORD *)(a2 + 44) && a3[27] )
  {
    if ( IopQueueIrpToFileObject((_DWORD *)a2, a3) )
    {
      v10 = 1;
      goto LABEL_9;
    }
  }
  else if ( (*(_DWORD *)(a2 + 8) & 0x10) == 0 && !a3[27] && a3[31] && IopGetFileObjectExtension((int)a3, 2, 0) )
  {
    return sub_7FA788();
  }
  IopQueueThreadIrp(a2);
LABEL_9:
  v11 = (_DWORD *)a3[31];
  if ( v11 )
  {
    if ( (*v11 & 4) != 0 )
    {
      v21 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      v48 = 0;
      v22 = PsReferencePrimaryToken(v21);
      SeQueryInformationToken(v22, 29, &v48);
      ObfDereferenceObject(v22);
      if ( v48 )
      {
        v20 = -1073739504;
        *(_DWORD *)(a2 + 24) = -1073739504;
        IofCompleteRequest(a2, 0);
        goto LABEL_25;
      }
    }
  }
  if ( a7 )
  {
    if ( a7 == 1 )
    {
      if ( IoCountOperations != 1 )
        goto LABEL_62;
      v26 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 440);
      do
        v27 = __ldrexd(v26);
      while ( __strexd(v27 + 1, v26) );
      v25 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3032);
      goto LABEL_53;
    }
    if ( a7 == 2 && IoCountOperations == 1 )
    {
      v23 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 448);
      do
        v24 = __ldrexd(v23);
      while ( __strexd(v24 + 1, v23) );
      v25 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3036);
      do
LABEL_53:
        v28 = __ldrex(v25);
      while ( __strex(v28 + 1, v25) );
      goto LABEL_62;
    }
  }
  else if ( IoCountOperations == 1 )
  {
    v29 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 432);
    do
      v30 = __ldrexd(v29);
    while ( __strexd(v30 + 1, v29) );
    v31 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3028);
    do
      v32 = __ldrex(v31);
    while ( __strex(v32 + 1, v31) );
  }
LABEL_62:
  if ( !a6 )
    ObfReferenceObject((int)a3);
  v33 = a3[31];
  if ( v33 && *(_DWORD *)(v33 + 32) )
  {
    v34 = *(_DWORD *)(a2 + 8) & 0xFFF1FFFF;
    *(_DWORD *)(a2 + 8) = v34;
    v35 = *(_DWORD *)(v33 + 32);
  }
  else
  {
    v36 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v37 = (v36[240] >> 9) & 7;
    if ( (*(_DWORD *)(v36[84] + 192) & 0x100000) != 0 )
      v37 = 0;
    if ( v37 < 2 && v36 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v36[250] )
      v37 = 2;
    v34 = *(_DWORD *)(a2 + 8) & 0xFFF1FFFF;
    v35 = v37 + 1;
  }
  *(_DWORD *)(a2 + 8) = v34 | (v35 << 17);
  v38 = IoGetIoPriorityHint(a2);
  if ( !*(_BYTE *)(a2 + 32) )
  {
    if ( v38 >= 2 )
      goto LABEL_86;
    v39 = *(_DWORD *)(a2 + 80);
    if ( !v39 || (*(_DWORD *)(v39 + 76) & 0x400) == 0 && (*(_DWORD *)(v39 + 964) & 0x20) == 0 )
    {
      ++IoKernelIssuedIoBoostedCount;
      *(_DWORD *)(a2 + 8) = *(_DWORD *)(a2 + 8) & 0xFFF1FFFF | 0x60000;
      goto LABEL_86;
    }
  }
  if ( v38 < 2 )
  {
    if ( a7 )
    {
      if ( a7 != 1 )
        goto LABEL_86;
      v40 = &IoLowPriorityWriteOperationCount;
    }
    else
    {
      v40 = &IoLowPriorityReadOperationCount;
    }
    ++*v40;
  }
LABEL_86:
  if ( (*(_BYTE *)(a2 + 39) & 0x80) == 0 && (v41 = *(_WORD **)(a2 + 104)) != 0 && (*v41 & 2) != 0 )
  {
    EtwActivityIdControlKernel(1, &v49);
    v43 = *(_DWORD **)(a2 + 104);
    v52[0] = v43[3];
    v52[1] = v43[4];
    v52[2] = v43[5];
    v52[3] = v43[6];
    v48 = v52;
    EtwActivityIdControlKernel(2, &v48);
    v20 = IofCallDriver(a1, a2);
    EtwActivityIdControlKernel(2, &v49);
  }
  else
  {
    v20 = IofCallDriver(a1, a2);
  }
  if ( !a6 )
    ObDereferenceObjectDeferDelete((int)a3);
LABEL_25:
  if ( v20 != 259 && v50 )
  {
    v13 = KfRaiseIrql(1);
    IopCompleteRequest(a2 + 64, (int)&v49, &v50, &v51, &v50);
    KfLowerIrql(v13);
  }
  if ( !a6 )
  {
    if ( v10 )
    {
      if ( (v20 & 0xC0000000) == 0x80000000 )
        v20 = 259;
    }
    return v20;
  }
  if ( v20 == 259 )
  {
    v19 = (a3[11] & 4) != 0;
    while ( 1 )
    {
      v44 = v19 ? a5 : 0;
      v45 = KeWaitForSingleObject((unsigned int)(a3 + 23), 0, v44, (_DWORD *)1, 0);
      if ( v45 != 257 && v45 != 192 )
        break;
      if ( !v19 && (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C0) & 1) == 0 )
      {
        v46 = 0;
        v47 = KfRaiseIrql(1);
        if ( !a3[24] )
          v46 = *(unsigned __int8 *)(a2 + 36) == 1;
        KfLowerIrql(v47);
        if ( !v46 )
          continue;
      }
      IopCancelAlertedRequest(a3 + 23, a2);
      break;
    }
    v20 = a3[7];
  }
  __dmb(0xBu);
  v14 = a3 + 17;
  do
    v15 = __ldrex(v14);
  while ( __strex(0, v14) );
  __dmb(0xBu);
  if ( a3[16] )
    KeSetEvent((int)(a3 + 19), 0, 0);
  v16 = ObfDereferenceObject((int)a3);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = (__int16)(*(_WORD *)(v17 + 0x134) + 1);
  *(_WORD *)(v17 + 308) = v18;
  if ( v18 || *(_DWORD *)(v17 + 100) == v17 + 100 || *(_WORD *)(v17 + 310) )
    return v20;
  KiCheckForKernelApcDelivery(v16);
  return v20;
}

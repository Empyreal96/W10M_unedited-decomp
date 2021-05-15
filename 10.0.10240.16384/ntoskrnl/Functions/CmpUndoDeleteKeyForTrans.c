// CmpUndoDeleteKeyForTrans 
 
int __fastcall CmpUndoDeleteKeyForTrans(int a1, int a2)
{
  int v2; // r5
  int v5; // r2
  unsigned int v6; // r8
  int v7; // r10
  int v8; // r0
  int v9; // r7
  int v10; // r0
  unsigned int v11; // r6
  int v12; // r9
  __int64 v13; // kr08_8
  int v14; // r0
  _BYTE *v15; // r0
  int v16; // r0
  _DWORD *v17; // r7
  int v18; // r0
  _QWORD *v19; // r2
  __int64 v20; // r0
  unsigned int v21; // r2
  int v22; // r0
  int v23; // r9
  unsigned int v24; // r2
  int v25; // r9
  int v26; // r2
  _DWORD *v27; // r0
  _DWORD *v28; // r1
  unsigned int v29; // r1
  int v30; // r0
  unsigned int v31; // r1
  __int16 v32; // r3
  unsigned int v33; // r9
  int v34; // r2
  int v35; // r3
  int v36; // r3
  unsigned int *v37; // r7
  int v39; // [sp+0h] [bp-40h] BYREF
  int v40; // [sp+4h] [bp-3Ch] BYREF
  unsigned int v41; // [sp+8h] [bp-38h]
  int v42; // [sp+Ch] [bp-34h]
  unsigned int v43; // [sp+10h] [bp-30h]
  unsigned int v44; // [sp+14h] [bp-2Ch]
  int v45; // [sp+18h] [bp-28h]
  int v46; // [sp+1Ch] [bp-24h]

  v2 = 0;
  v5 = *(_DWORD *)(a1 + 40);
  v39 = 0;
  v40 = -1;
  v42 = a2;
  v6 = 0;
  v7 = 0;
  do
  {
    v8 = CmListGetPrevElement(v5 + 108, &v39);
    v9 = v8;
    v45 = v8;
    if ( !v8 )
      return -1073741772;
  }
  while ( *(_DWORD *)(v8 + 36) != 3 || *(_DWORD *)(v8 + 48) != a1 );
  v39 = 0;
  v10 = CmListGetPrevElement(a1 + 108, &v39);
  v46 = v10;
  if ( !v10 || *(_DWORD *)(v10 + 36) != 2 )
    return -1073741772;
  if ( *(_DWORD *)(a1 + 152) == a2 )
  {
    v12 = *(_DWORD *)(a1 + 148);
    v11 = *(_DWORD *)(a1 + 144);
  }
  else
  {
    v13 = *(_QWORD *)(a1 + 20);
    v39 = -1;
    v14 = (*(int (__fastcall **)(_DWORD, _DWORD, int *))(v13 + 4))(v13, HIDWORD(v13), &v39);
    if ( !v14 )
      return -1073741670;
    v12 = *(_DWORD *)(v14 + 40);
    v11 = *(_DWORD *)(v14 + 36);
    (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(a1 + 20) + 8))(*(_DWORD *)(a1 + 20), &v39);
  }
  if ( v11 )
  {
    v15 = (_BYTE *)ExAllocatePoolWithTag(1, 4 * v11, 926174531);
    v6 = (unsigned int)v15;
    if ( v15 )
    {
      memset(v15, 0, 4 * v11);
      v16 = (*(int (__fastcall **)(_DWORD, int, int *))(*(_DWORD *)(a1 + 20) + 4))(*(_DWORD *)(a1 + 20), v12, &v40);
      v39 = v16;
      if ( v16 )
      {
        v41 = 0;
        v44 = v16 - v6;
        v17 = (_DWORD *)v6;
        while ( 1 )
        {
          v18 = CmpAllocateUnitOfWork(v16);
          *v17 = v18;
          if ( !v18 )
            break;
          v19 = (_QWORD *)(v18 + 16);
          LODWORD(v20) = a1 + 108;
          HIDWORD(v20) = *(_DWORD *)(a1 + 112);
          *v19 = v20;
          if ( *(_DWORD *)HIDWORD(v20) != a1 + 108 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v20) = v19;
          *(_DWORD *)(a1 + 112) = v19;
          CmpReferenceKeyControlBlock((unsigned int *)a1);
          *(_DWORD *)(*v17 + 24) = a1;
          v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v21 + 308);
          v43 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v22 = KeAbPreAcquire((unsigned int)&CmpTransactionListLock, 0, 0);
          v23 = v22;
          do
            v24 = __ldrex((unsigned __int8 *)&CmpTransactionListLock);
          while ( __strex(v24 & 0xFE, (unsigned __int8 *)&CmpTransactionListLock) );
          __dmb(0xBu);
          if ( (v24 & 1) == 0 )
            ExpAcquireFastMutexContended((int)&CmpTransactionListLock, v22);
          if ( v23 )
            *(_BYTE *)(v23 + 14) |= 1u;
          v25 = v42;
          v26 = v42 + 8;
          dword_632184 = v43;
          v27 = *(_DWORD **)(v42 + 12);
          v28 = (_DWORD *)*v17;
          *v28 = v42 + 8;
          v28[1] = v27;
          if ( *v27 != v26 )
            __fastfail(3u);
          *v27 = v28;
          *(_DWORD *)(v26 + 4) = v28;
          dword_632184 = 0;
          __dmb(0xBu);
          do
            v29 = __ldrex((unsigned int *)&CmpTransactionListLock);
          while ( !v29 && __strex(1u, (unsigned int *)&CmpTransactionListLock) );
          if ( v29 )
            ExpReleaseFastMutexContended((unsigned int *)&CmpTransactionListLock, v29);
          v30 = KeAbPostRelease((unsigned int)&CmpTransactionListLock);
          v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v32 = *(_WORD *)(v31 + 0x134) + 1;
          *(_WORD *)(v31 + 308) = v32;
          if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
            KiCheckForKernelApcDelivery(v30);
          *(_DWORD *)(*v17 + 28) = v25;
          if ( !CmpLockIXLockIntent(a1 + 128, *v17) || (v16 = CmpLockIXLockExclusive(a1 + 136, *v17, 1)) == 0 )
          {
            v2 = -1072103423;
            goto LABEL_16;
          }
          v33 = v41;
          *(_DWORD *)(*v17 + 36) = 6;
          v34 = *v17;
          ++v33;
          v35 = *(_DWORD *)((char *)v17++ + v44);
          v41 = v33;
          *(_DWORD *)(v34 + 48) = v35;
          if ( v33 >= v11 )
          {
            v9 = v45;
            (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(a1 + 20) + 8))(*(_DWORD *)(a1 + 20), &v40);
            v7 = 0;
            goto LABEL_40;
          }
        }
      }
      v2 = -1073741670;
LABEL_16:
      v7 = v39;
      goto LABEL_41;
    }
    return -1073741670;
  }
LABEL_40:
  v36 = v46;
  *(_DWORD *)(v9 + 36) = 13;
  *(_DWORD *)(v36 + 36) = 13;
  *(_DWORD *)(a1 + 152) = v42;
  *(_DWORD *)(a1 + 144) = 0;
  *(_DWORD *)(a1 + 148) = -1;
LABEL_41:
  if ( v6 )
  {
    if ( v2 < 0 && v11 )
    {
      v37 = (unsigned int *)v6;
      do
      {
        if ( *v37 )
        {
          CmpRundownUnitOfWork(*v37);
          ExFreePoolWithTag(*v37);
        }
        ++v37;
        --v11;
      }
      while ( v11 );
    }
    ExFreePoolWithTag(v6);
  }
  if ( v7 )
    (*(void (__fastcall **)(_DWORD, int *))(*(_DWORD *)(a1 + 20) + 8))(*(_DWORD *)(a1 + 20), &v40);
  return v2;
}

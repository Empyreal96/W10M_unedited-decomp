// IopCloseFile 
 
int __fastcall IopCloseFile(int result, _DWORD *a2, int a3, int a4)
{
  int v4; // r7
  int v5; // r9
  int v8; // r8
  int v9; // r10
  int **v10; // r2
  int v11; // r0
  int v12; // r6
  int v13; // r3
  int v14; // r4
  __int64 v15; // r2
  unsigned int *v16; // r2
  unsigned int v17; // r1
  unsigned int v18; // r1
  int v19; // r3
  int v20; // r0
  int v21; // r8
  int v22; // r4
  unsigned int v23; // r2
  unsigned int *v24; // r2
  unsigned int v25; // r1
  unsigned int v26; // r1
  __int16 v27; // r3
  int (__fastcall *v28)(_DWORD *, _DWORD, char *, int); // r6
  int v29; // r4
  int v30; // r7
  int v31; // r4
  int v32; // r3
  unsigned int *v33; // r2
  unsigned int v34; // r1
  unsigned int v35; // r1
  int v36; // r3
  unsigned int v37; // r2
  unsigned int *v38; // r2
  unsigned int v39; // r1
  unsigned int v40; // r1
  __int16 v41; // r3
  unsigned __int64 *v42; // r3
  unsigned __int64 v43; // kr00_8
  unsigned int *v44; // r2
  unsigned int v45; // r1
  char v46[8]; // [sp+8h] [bp-40h] BYREF
  char v47[8]; // [sp+10h] [bp-38h] BYREF
  char v48[48]; // [sp+18h] [bp-30h] BYREF

  v4 = 0;
  v5 = 0;
  v8 = result;
  v9 = 0;
  if ( a3 == 1 )
  {
    if ( a2[31] )
    {
      v9 = IopGetFileObjectExtension((int)a2, 2, 0);
      v4 = IopGetFileObjectExtension((int)a2, 4, v10);
    }
    if ( a4 == 1 )
    {
      if ( (a2[11] & 0x800) != 0 )
        v11 = IoGetAttachedDevice(a2[1]);
      else
        v11 = IoGetRelatedDeviceObject(a2);
      v12 = v11;
      v13 = a2[11] | 0x40000;
      a2[11] = v13;
      if ( v8 && (v13 & 2) != 0 )
      {
        v5 = 1;
        v37 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        --*(_WORD *)(v37 + 308);
        __dmb(0xBu);
        v38 = a2 + 17;
        do
          v39 = __ldrex(v38);
        while ( __strex(1u, v38) );
        __dmb(0xBu);
        if ( v39 )
        {
          v40 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v41 = *(_WORD *)(v40 + 0x134) + 1;
          *(_WORD *)(v40 + 308) = v41;
          if ( !v41 && *(_DWORD *)(v40 + 100) != v40 + 100 && !*(_WORD *)(v40 + 310) )
            KiCheckForKernelApcDelivery(1);
          while ( IopAcquireFileObjectLock(a2, 0, 0, v46) )
            ;
        }
        else
        {
          ObfReferenceObject((int)a2);
        }
      }
      if ( v4 )
        IopFreeBandwidthContract(a2, v4);
      KeInitializeEvent((int)v48, 1, 0);
      if ( (a2[11] & 0x4000000) == 0 )
        KeResetEvent((int)(a2 + 23));
      v14 = IopAllocateIrpMustSucceed(v12, *(_BYTE *)(v12 + 48));
      *(_DWORD *)(v14 + 100) = a2;
      *(_DWORD *)(v14 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      LODWORD(v15) = v14 + 24;
      HIDWORD(v15) = v48;
      *(_QWORD *)(v14 + 40) = v15;
      LODWORD(v15) = *(_DWORD *)(v14 + 96);
      *(_BYTE *)(v14 + 32) = 0;
      *(_DWORD *)(v14 + 48) = 0;
      *(_DWORD *)(v14 + 8) = 1028;
      *(_BYTE *)(v15 - 40) = 18;
      *(_DWORD *)(v15 - 12) = a2;
      IopQueueThreadIrp(v14);
      if ( IoCountOperations == 1 )
      {
        v42 = (unsigned __int64 *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x150) + 448);
        do
          v43 = __ldrexd(v42);
        while ( __strexd(v43 + 1, v42) );
        v44 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3036);
        do
          v45 = __ldrex(v44);
        while ( __strex(v45 + 1, v44) );
      }
      if ( IofCallDriver(v12, v14) == 259 )
        KeWaitForSingleObject((unsigned int)v48, 6, 0, 0, 0);
      *(_DWORD *)(v14 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      IopDequeueIrpFromThread((_DWORD *)v14);
      result = IoFreeIrp(v14);
      if ( v5 )
      {
        __dmb(0xBu);
        v16 = a2 + 17;
        do
          v17 = __ldrex(v16);
        while ( __strex(0, v16) );
        __dmb(0xBu);
        if ( a2[16] )
          KeSetEvent((int)(a2 + 19), 0, 0);
        result = ObfDereferenceObject((int)a2);
        v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v19 = (__int16)(*(_WORD *)(v18 + 0x134) + 1);
        *(_WORD *)(v18 + 308) = v19;
        if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
          result = KiCheckForKernelApcDelivery(result);
      }
      if ( a2[27] || v9 )
        result = IopCleanupProcessResources((int)a2, v8, v9);
    }
    else if ( a2[27] || v9 )
    {
      result = sub_7FA0CC();
    }
    else
    {
      result = IopSetLockOperationProcess((int)a2, v8, 1);
      if ( result >= 0 )
      {
        if ( (a2[11] & 0x800) != 0 )
          v20 = IoGetAttachedDevice(a2[1]);
        else
          v20 = IoGetRelatedDeviceObject(a2);
        v21 = v20;
        v22 = *(_DWORD *)(*(_DWORD *)(v20 + 8) + 40);
        if ( (a2[11] & 2) != 0 && (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3C0) & 1) == 0 )
        {
          v5 = 1;
          v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          --*(_WORD *)(v23 + 308);
          __dmb(0xBu);
          v24 = a2 + 17;
          do
            v25 = __ldrex(v24);
          while ( __strex(1u, v24) );
          __dmb(0xBu);
          if ( v25 )
          {
            v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
            v27 = *(_WORD *)(v26 + 0x134) + 1;
            *(_WORD *)(v26 + 308) = v27;
            if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
              KiCheckForKernelApcDelivery(1);
            do
              v20 = IopAcquireFileObjectLock(a2, 0, 0, v46);
            while ( v20 );
          }
          else
          {
            v20 = ObfReferenceObject((int)a2);
          }
        }
        if ( !v22 )
          goto LABEL_54;
        v28 = *(int (__fastcall **)(_DWORD *, _DWORD, char *, int))(v22 + 32);
        if ( !v28 )
          goto LABEL_54;
        if ( (MmVerifierData & 0x10) != 0 )
          v29 = VfFastIoSnapState(v20);
        else
          v29 = 0;
        result = v28(a2, *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v47, v21);
        v30 = result;
        if ( v29 )
          result = VfFastIoCheckState(v29, v28);
        if ( !v30 )
        {
LABEL_54:
          KeInitializeEvent((int)v48, 1, 0);
          if ( (a2[11] & 0x4000000) == 0 )
            KeResetEvent((int)(a2 + 23));
          v31 = IopAllocateIrpMustSucceed(v21, *(_BYTE *)(v21 + 48));
          *(_DWORD *)(v31 + 100) = a2;
          *(_DWORD *)(v31 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          *(_DWORD *)(v31 + 44) = v48;
          *(_DWORD *)(v31 + 40) = v31 + 24;
          *(_DWORD *)(v31 + 8) = 4;
          v32 = *(_DWORD *)(v31 + 96);
          *(_BYTE *)(v31 + 32) = 0;
          *(_DWORD *)(v31 + 48) = 0;
          *(_BYTE *)(v32 - 40) = 17;
          *(_BYTE *)(v32 - 39) = 3;
          *(_DWORD *)(v32 - 12) = a2;
          ObfReferenceObject((int)a2);
          IopQueueThreadIrp(v31);
          result = IofCallDriver(v21, v31);
          if ( result == 259 )
            result = KeWaitForSingleObject((unsigned int)v48, 6, 0, 0, 0);
        }
        if ( v5 == 1 )
        {
          __dmb(0xBu);
          v33 = a2 + 17;
          do
            v34 = __ldrex(v33);
          while ( __strex(0, v33) );
          __dmb(0xBu);
          if ( a2[16] )
            KeSetEvent((int)(a2 + 19), 0, 0);
          result = ObfDereferenceObject((int)a2);
          v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v36 = (__int16)(*(_WORD *)(v35 + 0x134) + 1);
          *(_WORD *)(v35 + 308) = v36;
          if ( !v36 && *(_DWORD *)(v35 + 100) != v35 + 100 && !*(_WORD *)(v35 + 310) )
            result = KiCheckForKernelApcDelivery(result);
        }
      }
    }
  }
  return result;
}

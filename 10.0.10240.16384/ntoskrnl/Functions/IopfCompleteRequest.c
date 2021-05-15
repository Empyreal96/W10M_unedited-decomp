// IopfCompleteRequest 
 
int __fastcall IopfCompleteRequest(int a1, unsigned __int8 a2)
{
  int v3; // r0
  int v4; // r10
  int v5; // r1
  int v6; // r6
  BOOL v7; // r7
  int v8; // r9
  int v9; // r4
  char v10; // r2
  int v11; // r3
  int v12; // r1
  char v13; // r2
  int v14; // r8
  int v15; // r4
  int result; // r0
  char v17; // r3
  int v18; // r4
  int v19; // r3
  int v20; // r2
  int v21; // r9
  int v22; // r2
  _DWORD *i; // r4
  int v24; // r2
  int v25; // r0
  int v26; // r3
  int v27; // r8
  int v28; // r4
  unsigned int *v29; // r6
  int v30; // r9
  unsigned int v31; // r2
  int v32; // r4
  int v33; // r4
  _DWORD *v34; // r2
  char v35; // r3
  unsigned int v36; // r3
  int v37; // r3
  int v38; // r4
  unsigned int *v39; // r2
  unsigned int v40; // r1
  unsigned int v41; // r1
  int v42; // r7
  int v43; // r0
  int *v44; // r2
  __int64 v45; // kr00_8
  int v46; // [sp+10h] [bp-30h] BYREF
  int v47; // [sp+14h] [bp-2Ch] BYREF
  int v48; // [sp+18h] [bp-28h] BYREF
  char v49[36]; // [sp+1Ch] [bp-24h] BYREF

  v3 = *(char *)(a1 + 34);
  v46 = 0;
  v47 = 0;
  v4 = a2;
  v5 = *(char *)(a1 + 35);
  v48 = v4;
  if ( v5 > (char)(v3 + 1) || *(_WORD *)a1 != 6 )
    KeBugCheckEx(68, a1, 4071);
  v6 = *(_DWORD *)(a1 + 96);
  v7 = v5 <= v3 && *(_BYTE *)v6 == 22;
  if ( v7 )
    PoDeviceReleaseIrp(a1, *(unsigned __int8 *)(v6 + 1), *(_DWORD *)(v6 + 24));
  if ( (*(_BYTE *)(a1 + 115) & 2) != 0 )
    v8 = *(_DWORD *)(a1 + 132);
  else
    v8 = 0;
  v9 = (char)(*(_BYTE *)(a1 + 35) + 1);
  v10 = *(_BYTE *)(a1 + 34);
  v11 = *(_DWORD *)(a1 + 96) + 40;
  *(_BYTE *)(a1 + 35) = v9;
  *(_DWORD *)(a1 + 96) = v11;
  if ( v9 <= (char)(v10 + 1) )
  {
    while ( 1 )
    {
      v12 = *(_DWORD *)(a1 + 24);
      *(_BYTE *)(a1 + 33) = *(_BYTE *)(v6 + 3) & 1;
      if ( v12 >= 0 )
        goto LABEL_12;
      if ( v12 != v8 )
      {
        v8 = v12;
        *(_BYTE *)(v6 + 3) |= 2u;
        v35 = *(_BYTE *)(a1 + 115);
        *(_DWORD *)(a1 + 132) = v12;
        *(_BYTE *)(a1 + 115) = v35 | 2;
      }
      if ( *(int *)(a1 + 24) >= 0 )
      {
LABEL_12:
        v13 = *(_BYTE *)(v6 + 3);
        if ( (v13 & 0x40) != 0 )
          goto LABEL_13;
      }
      else
      {
        v13 = *(_BYTE *)(v6 + 3);
        if ( (v13 & 0x80) != 0 )
          goto LABEL_13;
      }
      if ( *(_BYTE *)(a1 + 36) && (v13 & 0x20) != 0 )
      {
LABEL_13:
        v14 = *(unsigned __int8 *)(v6 + 1);
        *(_BYTE *)(v6 + 3) = v13 & 2;
        *(_BYTE *)(v6 + 1) = 0;
        *(_BYTE *)(v6 + 2) = 0;
        *(_DWORD *)(v6 + 8) = 0;
        *(_DWORD *)(v6 + 12) = 0;
        *(_DWORD *)(v6 + 16) = 0;
        *(_DWORD *)(v6 + 28) = 0;
        if ( *(char *)(a1 + 35) == (char)(*(_BYTE *)(a1 + 34) + 1) )
          v15 = 0;
        else
          v15 = *(_DWORD *)(*(_DWORD *)(a1 + 96) + 24);
        if ( v7 )
          PoDeviceAcquireIrp(a1, v14, v15);
        result = (*(int (__fastcall **)(int, int, _DWORD))(v6 + 32))(v15, a1, *(_DWORD *)(v6 + 36));
        if ( result == -1073741802 )
          return result;
        if ( v7 )
          PoDeviceReleaseIrp(a1, v14, v15);
        goto LABEL_23;
      }
      if ( *(_BYTE *)(a1 + 33) && *(char *)(a1 + 35) <= *(char *)(a1 + 34) )
        *(_BYTE *)(*(_DWORD *)(a1 + 96) + 3) |= 1u;
      v17 = *(_BYTE *)(v6 + 3);
      *(_BYTE *)(v6 + 1) = 0;
      *(_BYTE *)(v6 + 2) = 0;
      *(_BYTE *)(v6 + 3) = v17 & 2;
      *(_DWORD *)(v6 + 8) = 0;
      *(_DWORD *)(v6 + 12) = 0;
      *(_DWORD *)(v6 + 16) = 0;
      *(_DWORD *)(v6 + 28) = 0;
LABEL_23:
      v6 += 40;
      v18 = (char)(*(_BYTE *)(a1 + 35) + 1);
      v19 = *(_DWORD *)(a1 + 96) + 40;
      *(_BYTE *)(a1 + 35) = v18;
      *(_DWORD *)(a1 + 96) = v19;
      if ( v18 > (char)(*(_BYTE *)(a1 + 34) + 1) )
      {
        v4 = v48;
        break;
      }
    }
  }
  v20 = *(_DWORD *)(a1 + 8);
  if ( (v20 & 8) != 0 )
  {
    v38 = *(_DWORD *)(a1 + 12);
    result = IopFreeIrpAndMdls(a1);
    __dmb(0xBu);
    v39 = (unsigned int *)(v38 + 12);
    do
    {
      v40 = __ldrex(v39);
      v41 = v40 - 1;
    }
    while ( __strex(v41, v39) );
    __dmb(0xBu);
    if ( !v41 )
      result = IofCompleteRequest(v38, v4);
  }
  else
  {
    if ( *(_DWORD *)(a1 + 24) == 260 && (v36 = *(_DWORD *)(a1 + 28), v36 > 1) )
    {
      if ( v36 != -1610612733 )
        return sub_52C864(0);
      v21 = *(_DWORD *)(a1 + 84);
      *(_DWORD *)(a1 + 84) = 0;
      v46 = v21;
      v47 = v21;
    }
    else
    {
      v21 = 0;
    }
    if ( !v4 )
    {
      v25 = *(_DWORD *)(a1 + 100);
      if ( v25 )
      {
        if ( (v20 & 0x400) == 0 )
        {
          v26 = *(_DWORD *)(IoGetRelatedDeviceObject(v25) + 44);
          if ( v26 == 8 || v26 == 20 )
            v4 = 1;
        }
      }
    }
    result = *(_DWORD *)(a1 + 84);
    if ( result )
    {
      result = ExFreePoolWithTag(result, 0);
      *(_DWORD *)(a1 + 84) = 0;
    }
    if ( (*(_BYTE *)(a1 + 39) & 0x40) != 0 )
      result = IopFreeIrpExtension(a1, -1, 1);
    v22 = *(_DWORD *)(a1 + 8);
    if ( (v22 & 0x402) != 0 )
    {
      if ( (v22 & 0x440) != 0 )
      {
        v33 = *(_DWORD *)(a1 + 8) & 0x42;
        v34 = *(_DWORD **)(a1 + 40);
        *v34 = *(_DWORD *)(a1 + 24);
        v34[1] = *(_DWORD *)(a1 + 28);
        if ( v33 )
          IopDequeueIrpFromThread(a1);
        result = KeSetEvent(*(_DWORD *)(a1 + 44), v4, 0);
        if ( v33 )
          result = IoFreeIrp(a1);
      }
      else
      {
        IopDequeueIrpFromThread(a1);
        KeInitializeApc(a1 + 64, *(_DWORD *)(a1 + 80), *(char *)(a1 + 38), (int)IopCompletePageWrite, 0, 0, 0, 0);
        result = KeInsertQueueApc(a1 + 64, 0, 0, v4);
      }
    }
    else
    {
      for ( i = *(_DWORD **)(a1 + 4); i; i = (_DWORD *)*i )
        result = MmUnlockPages(i);
      if ( (*(_DWORD *)(a1 + 8) & 0x2000) != 0 )
        result = ObfDereferenceObject(*(_DWORD *)(a1 + 80));
      v24 = *(_DWORD *)(a1 + 8);
      if ( (v24 & 0x800) == 0 || *(_BYTE *)(a1 + 33) )
      {
        v27 = *(_DWORD *)(a1 + 100);
        v28 = *(_DWORD *)(a1 + 80);
        v48 = v27;
        if ( (v24 & 0x2000) == 0 || (result = IopCompleteIrpInFileObjectList(a1, v27)) == 0 )
        {
          if ( v28 )
          {
            v29 = (unsigned int *)(v28 + 1024);
            v30 = KfRaiseIrql(2);
            if ( (dword_682604 & 0x210000) != 0 )
            {
              KiAcquireSpinLockInstrumented(v28 + 1024);
            }
            else
            {
              do
                v31 = __ldrex(v29);
              while ( __strex(1u, v29) );
              __dmb(0xBu);
              if ( v31 )
                KxWaitForSpinLockAndAcquire(v28 + 1024);
            }
            if ( (dword_682604 & 0x10000) != 0 )
            {
              KiReleaseSpinLockInstrumented(v28 + 1024);
            }
            else
            {
              __dmb(0xBu);
              *v29 = 0;
            }
            result = KfLowerIrql(v30);
          }
          if ( *(_BYTE *)(a1 + 36) )
          {
            v42 = KeAcquireQueuedSpinLock(11);
            v43 = *(_DWORD *)(a1 + 80);
            v44 = (int *)IopDeadIrps;
            if ( (int *)IopDeadIrps == &IopDeadIrps )
            {
LABEL_98:
              if ( v43 )
              {
                KeInitializeApc(
                  a1 + 64,
                  v43,
                  *(char *)(a1 + 38),
                  (int)IopCompleteRequest,
                  (int)IopAbortRequest,
                  0,
                  0,
                  0);
                KeInsertQueueApc(a1 + 64, v27, v46, v4);
                return KeReleaseQueuedSpinLock(11, v42);
              }
            }
            else
            {
              while ( v44 - 4 != (int *)a1 )
              {
                v44 = (int *)*v44;
                if ( v44 == &IopDeadIrps )
                  goto LABEL_98;
              }
              v45 = *(_QWORD *)v44;
              if ( *(int **)(*v44 + 4) != v44 || *(int **)HIDWORD(v45) != v44 )
                __fastfail(3u);
              *(_DWORD *)HIDWORD(v45) = v45;
              *(_DWORD *)(v45 + 4) = HIDWORD(v45);
              *v44 = (int)v44;
              v44[1] = (int)v44;
              ObfDereferenceObject(v43);
            }
            KeReleaseQueuedSpinLock(11, v42);
            result = IopDropIrp(a1, v27);
          }
          else if ( v28 != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0)
                 || *(_WORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x136)
                 || (__get_CPSR() & 0x80) != 0
                 || KeGetCurrentIrql(result)
                 || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
          {
            KeInitializeApc(a1 + 64, v28, *(char *)(a1 + 38), (int)IopCompleteRequest, (int)IopAbortRequest, 0, 0, 0);
            result = KeInsertQueueApc(a1 + 64, v27, v46, v4);
          }
          else
          {
            v46 = 1;
            v32 = KfRaiseIrql(1);
            IopCompleteRequest(a1 + 64, v49, &v46, &v48, &v47);
            result = KfLowerIrql(v32);
          }
        }
      }
      else if ( *(_DWORD *)(a1 + 24) == 260 )
      {
        v37 = *(_DWORD *)(a1 + 28);
        if ( v37 == -1610612733 || v37 == -1610612724 || v37 == -2147483623 )
          *(_DWORD *)(a1 + 84) = v21;
      }
    }
  }
  return result;
}

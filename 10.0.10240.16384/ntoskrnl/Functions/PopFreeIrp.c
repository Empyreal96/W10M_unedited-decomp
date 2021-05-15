// PopFreeIrp 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopFreeIrp(int a1, int a2, int a3, int a4)
{
  int v5; // r4
  int v6; // r5
  __int64 v7; // kr00_8
  int v8; // r0
  int v9; // r3
  int v10; // r1 OVERLAPPED
  _DWORD *v11; // r2 OVERLAPPED
  _DWORD v13[10]; // [sp+0h] [bp-28h] BYREF

  v13[0] = a1;
  v13[2] = a3;
  v13[3] = a4;
  v5 = *(_DWORD *)(a1 + 40 * *(char *)(a1 + 34) + 108);
  v6 = *(_DWORD *)(v5 + 128);
  v7 = *(_QWORD *)(v5 + 12);
  v8 = KeAcquireInStackQueuedSpinLock((unsigned int *)&PopIrpLock, (unsigned int)v13);
  v9 = __mrc(15, 0, 13, 0, 3);
  *(_QWORD *)&v10 = *(_QWORD *)v5;
  PopIrpLockThread = v9 & 0xFFFFFFC0;
  if ( *(_DWORD *)(v10 + 4) != v5 || *v11 != v5 )
    sub_54AD48(v8);
  *v11 = v10;
  PopIrpLockThread = 0;
  *(_DWORD *)(v10 + 4) = v11;
  KeReleaseInStackQueuedSpinLock((int)v13);
  if ( v6 && *(_BYTE *)(v5 + 112) == 2 && *(_DWORD *)(v5 + 116) == 1 )
  {
    PopFxReleasePowerIrp(v6);
  }
  else
  {
    ExFreeToNPagedLookasideList(&PopIrpDataLookaside, v5);
    pIoFreeIrp(a1);
  }
  ObfDereferenceObjectWithTag(SHIDWORD(v7));
  ObfDereferenceObjectWithTag(v7);
  return v13[0];
}

// SmKmStoreHelperCommandProcess 
 
__int64 __fastcall SmKmStoreHelperCommandProcess(__int64 a1, _DWORD *a2, unsigned int a3)
{
  int v4; // r6
  int v5; // r4
  __int64 v6; // kr00_8
  struct _MDL *v7; // r7
  int v8; // r3
  int v9; // r1
  int v10; // r8
  __int64 v11; // kr08_8
  int v12; // r0
  int v13; // r4
  int v14; // r0
  unsigned int v17[8]; // [sp+8h] [bp-20h] BYREF

  v17[0] = (unsigned int)a2;
  v17[1] = a3;
  v4 = a1;
  if ( HIDWORD(a1) == 2 )
  {
    v13 = a2[1];
    v7 = (struct _MDL *)MmStoreAllocateVirtualMemory(v13);
    if ( !v7 )
      goto LABEL_6;
    v14 = *(_DWORD *)(v4 + 64);
    if ( v14 )
    {
      v5 = SmKmVirtualLockCtxLockMemory(v14, v7, v13);
      if ( v5 < 0 )
      {
        MmStoreFreeVirtualMemory(v7);
        goto LABEL_20;
      }
    }
    goto LABEL_19;
  }
  if ( HIDWORD(a1) != 3 )
  {
    if ( HIDWORD(a1) != 4 )
    {
      v5 = -1073741811;
      goto LABEL_20;
    }
    v6 = *(_QWORD *)a2;
    v7 = (struct _MDL *)SmFpAllocate(*(_DWORD *)(a1 + 68), 2, a1, 0, a2[3] & 1);
    if ( !v7 )
    {
LABEL_6:
      v5 = -1073741670;
      goto LABEL_20;
    }
    v8 = __mrc(15, 0, 13, 0, 3);
    v9 = a2[2];
    v17[0] = v8 & 0xFFFFFFC0;
    v10 = SmSetThreadPagePriority(v17, v9);
    v5 = SmKmProbeAndLockAddress(v6, v7);
    if ( v10 != a2[2] )
      SmSetThreadPagePriority(v17, v10);
    if ( v5 < 0 )
    {
LABEL_12:
      SmFpFree(*(_DWORD *)(v4 + 68), 2, v4, (unsigned int)v7);
      goto LABEL_20;
    }
    if ( !SmFpAllocate(*(_DWORD *)(v4 + 68), 4, v4, (int)v7, a2[3] & 1) )
    {
      v5 = -1073741670;
      SmKmUnlockMdl(v7, *(_DWORD *)(v4 + 68), v4);
      goto LABEL_12;
    }
LABEL_19:
    v5 = 0;
    a2[4] = v7;
    goto LABEL_20;
  }
  v11 = *(_QWORD *)a2;
  MmStoreFreeVirtualMemory(*a2);
  v12 = *(_DWORD *)(v4 + 64);
  v5 = 0;
  if ( v12 )
    SmKmVirtualLockCtxMemoryUnlocked(v12, HIDWORD(v11));
LABEL_20:
  a2[5] = v5;
  return a1;
}

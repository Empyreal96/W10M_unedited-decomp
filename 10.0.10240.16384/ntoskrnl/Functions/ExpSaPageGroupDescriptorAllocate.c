// ExpSaPageGroupDescriptorAllocate 
 
unsigned int __fastcall ExpSaPageGroupDescriptorAllocate(int a1, int a2)
{
  int v4; // r9
  unsigned int v5; // r6
  unsigned int v6; // r10
  int v7; // r7
  _BYTE *v8; // r0
  unsigned int v9; // r5
  __int64 v10; // r2
  int v11; // r0
  int v12; // r4
  unsigned int v13; // r2
  int v14; // r0
  int *v15; // r1
  int *v16; // r3
  unsigned int v17; // r2
  char *v18; // r1
  int v19; // r0
  int v20; // r4
  int v21; // r7
  unsigned int v22; // r2
  int v23; // r4
  unsigned int v24; // r3
  unsigned int v25; // r1
  int v27; // [sp+0h] [bp-48h]
  int v28[3]; // [sp+8h] [bp-40h] BYREF
  unsigned int **v29; // [sp+14h] [bp-34h]
  char v30[48]; // [sp+18h] [bp-30h] BYREF

  v4 = 0;
  v5 = 0;
  v6 = KeQueryMaximumProcessorCountEx(0xFFFFu, a2);
  if ( a2 )
    v7 = 1;
  else
    v7 = 512;
  v8 = (_BYTE *)ExAllocatePoolWithTag(v7, 168);
  v9 = (unsigned int)v8;
  if ( !v8 )
    return 0;
  memset(v8, 0, 168);
  *(_DWORD *)(v9 + 12) = 0;
  HIDWORD(v10) = v9 + 40;
  LODWORD(v10) = 1024;
  *(_QWORD *)(v9 + 32) = v10;
  *(_DWORD *)(v9 + 8) = a1;
  *(_DWORD *)(v9 + 20) = 1024;
  v11 = KeAbPreAcquire((unsigned int)&ExSaPageGroupDescriptorArrayLock, 0, 0);
  v12 = v11;
  do
    v13 = __ldrex((unsigned __int8 *)&ExSaPageGroupDescriptorArrayLock);
  while ( __strex(v13 | 1, (unsigned __int8 *)&ExSaPageGroupDescriptorArrayLock) );
  __dmb(0xBu);
  if ( (v13 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(
      &ExSaPageGroupDescriptorArrayLock,
      v11,
      (unsigned int)&ExSaPageGroupDescriptorArrayLock);
  if ( v12 )
    *(_BYTE *)(v12 + 14) |= 1u;
  v14 = ExpSaBinaryArrayInsert((unsigned int **)ExSaPageGroupDescriptorArray, v9);
  v15 = &ExSaPageArrays;
  *(_DWORD *)(v9 + 16) = v14;
  if ( v14 == -1 )
    goto LABEL_28;
  v16 = &KeNumberProcessors_0;
  v5 = 0;
  v17 = KeNumberProcessors_0;
  v27 = KeNumberProcessors_0;
  if ( v6 )
  {
    while ( 1 )
    {
      v29 = *(unsigned int ***)(ExSaPageArrays + 4 * v5);
      if ( v5 < v17 )
      {
        v28[1] = 0;
        v28[2] = 0;
        v28[0] = 1 << v5;
        if ( v4 )
        {
          v18 = 0;
        }
        else
        {
          v18 = v30;
          v4 = 1;
        }
        KeSetSystemGroupAffinityThread((int)v28, v18);
      }
      v19 = ExAllocatePoolWithTag(v7, 4096);
      v20 = v19;
      if ( !v19 || ExpSaBinaryArrayInsert(v29, v19) == -1 )
        break;
      ++v5;
      v17 = v27;
      v15 = &ExSaPageArrays;
      if ( v5 >= v6 )
        goto LABEL_22;
    }
    v21 = 0;
  }
  else
  {
LABEL_22:
    v20 = 0;
    v21 = 1;
  }
  if ( v4 )
    KeRevertToUserGroupAffinityThread((int)v30, (int)v15, v17, (int)v16);
  if ( v20 )
    ExFreePoolWithTag(v20);
  if ( !v21 )
  {
LABEL_28:
    if ( *(_DWORD *)(v9 + 16) != -1 )
    {
      for ( ; v5; --v5 )
      {
        v22 = *(_DWORD *)(v9 + 16);
        v23 = *(_DWORD *)(ExSaPageArrays + 4 * v5 - 4);
        v24 = __clz(v22);
        ExFreePoolWithTag(*(_DWORD *)(*(_DWORD *)(v23 + 4 * (29 - v24)) + 4 * (v22 ^ (1 << (31 - v24))) + 4));
        ExpSaBinaryArrayRemove(v23, *(_DWORD *)(v9 + 16));
      }
      ExpSaBinaryArrayRemove(ExSaPageGroupDescriptorArray, *(_DWORD *)(v9 + 16));
    }
    ExFreePoolWithTag(v9);
    v9 = 0;
  }
  __dmb(0xBu);
  do
    v25 = __ldrex((unsigned int *)&ExSaPageGroupDescriptorArrayLock);
  while ( __strex(v25 - 1, (unsigned int *)&ExSaPageGroupDescriptorArrayLock) );
  if ( (v25 & 2) != 0 && (v25 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&ExSaPageGroupDescriptorArrayLock);
  KeAbPostRelease((unsigned int)&ExSaPageGroupDescriptorArrayLock);
  return v9;
}

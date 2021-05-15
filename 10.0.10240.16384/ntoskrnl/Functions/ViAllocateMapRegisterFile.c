// ViAllocateMapRegisterFile 
 
_DWORD *__fastcall ViAllocateMapRegisterFile(_DWORD *a1, int a2)
{
  int v2; // r5
  int v4; // r6
  _BYTE *v5; // r0
  _DWORD *v6; // r4
  int v7; // r6
  int v8; // r0
  _DWORD *v9; // r9
  _DWORD *v10; // r7
  int v11; // r0
  unsigned int *v12; // r2
  unsigned int v13; // r1
  int v14; // r0
  unsigned int *v15; // r2
  unsigned int v16; // r1
  int v17; // r2
  int v18; // r0
  int v19; // r5
  _DWORD *i; // r7
  int v21; // r1
  unsigned int v22; // r0
  __int64 v24[5]; // [sp+8h] [bp-28h] BYREF

  v2 = a2;
  if ( (unsigned int)(a1[22] + a2) > 0x20 )
    return 0;
  if ( !a2 )
    return 0;
  v4 = 20 * (a2 - 1);
  v5 = (_BYTE *)ExAllocatePoolWithTag(512, v4 + 68, 1449943368);
  v6 = v5;
  if ( !v5 )
    return 0;
  memset(v5, 0, v4 + 68);
  v6[4] = v2;
  v7 = IoAllocateMdl(0, v2 << 12, 0, 0, 0);
  if ( !v7 )
    goto LABEL_17;
  v8 = ExAllocatePoolWithTag(512, v2 << 12, 1449943368);
  v6[10] = v8;
  if ( !v8 )
    goto LABEL_17;
  v9 = (_DWORD *)(v7 + 28);
  v10 = v6 + 12;
  do
  {
    v11 = ViAllocateFromContiguousMemory(a1, v6[4] - v2);
    v10[3] = v11;
    if ( v11 )
    {
      __dmb(0xBu);
      v12 = a1 + 54;
      do
        v13 = __ldrex(v12);
      while ( __strex(v13 + 1, v12) );
    }
    else
    {
      v14 = ExAllocatePoolWithTag(516, 12288, 1449943368);
      v10[3] = v14;
      if ( !v14 )
        goto LABEL_17;
      __dmb(0xBu);
      v15 = a1 + 55;
      do
        v16 = __ldrex(v15);
      while ( __strex(v16 + 1, v15) );
    }
    __dmb(0xBu);
    ViInitializePadding(v10[3], 12288, 0, 0);
    MmGetPhysicalAddress((int)v24, v10[3] + 4096, v17, v10[3]);
    --v2;
    v10 += 5;
    *v9++ = v24[0] >> 12;
  }
  while ( v2 );
  *(_WORD *)(v7 + 6) |= 2u;
  v18 = MmMapLockedPagesSpecifyCache(v7, 0, 1, 0, 0, 1073741840);
  v6[9] = v18;
  if ( !v18 )
  {
LABEL_17:
    v19 = v6[4];
    for ( i = v6 + 12; v19; i += 5 )
    {
      v21 = i[3];
      if ( !v21 )
        break;
      if ( !ViFreeToContiguousMemory(a1, v21, v6[4] - v19) )
        ExFreePoolWithTag(i[3]);
      --v19;
    }
    if ( v7 )
      IoFreeMdl(v7);
    v22 = v6[10];
    if ( v22 )
      ExFreePoolWithTag(v22);
    ExFreePoolWithTag((unsigned int)v6);
    return 0;
  }
  *v6 = -1393569779;
  v6[8] = v7;
  v6[11] = 0;
  ExInterlockedInsertHeadList(a1 + 14, v6 + 1, a1 + 16);
  return v6;
}

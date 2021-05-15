// MiMappedPageWriter 
 
int __fastcall MiMappedPageWriter(int a1)
{
  int v2; // r6
  int v3; // r0
  unsigned int *v4; // r2
  int v5; // r9
  int v6; // r3
  int v7; // r1
  unsigned int v8; // r7
  int v9; // r0
  unsigned int v10; // r3
  unsigned int v11; // r2
  int v13; // r5
  unsigned int *v14; // r1
  unsigned int v15; // r2
  unsigned int v16; // r2
  bool v17; // zf
  unsigned int *v18; // r1
  unsigned int v19; // r2
  __int64 **v20; // r4
  __int64 *v21; // r0
  __int64 v22; // r2
  _DWORD *v23; // r2
  __int64 *v24; // r3
  __int64 v25; // kr00_8
  int v26; // r3
  int *v27; // r1
  int v28; // r3
  unsigned int v29[18]; // [sp+10h] [bp-218h] BYREF
  int v30[116]; // [sp+58h] [bp-1D0h] BYREF

  v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v3 = KeSetPriorityThread(v2, 18);
  v4 = v29;
  v5 = v3;
  *(_DWORD *)(v2 + 964) |= 2u;
  v6 = a1 + 2516;
  v7 = 16;
  do
  {
    *v4++ = v6;
    v6 += 16;
    --v7;
  }
  while ( v7 );
  v29[16] = a1 + 120;
  v29[17] = a1 + 452;
  v8 = -1;
  *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x394) = 3;
  v9 = 4120;
LABEL_4:
  if ( v8 == -1
    || (v10 = *(_DWORD *)(a1 + 3968), v11 = *(_DWORD *)(a1 + 4120), v10 <= v11)
    || v10 - v11 < 0x10 && !*(_DWORD *)(a1 + 448) )
  {
    v8 = KeWaitForMultipleObjects(0x12u, v29, 1, 8, 0, 0, 0, v30);
    goto LABEL_23;
  }
  while ( 1 )
  {
    if ( v8 < 0x10 )
      return sub_5508F8();
    if ( *(_DWORD *)(a1 + 3968) == *(_DWORD *)(a1 + 4120) )
      break;
    if ( *(_DWORD *)(a1 + 348) >= *(_DWORD *)(a1 + 344) )
    {
      v13 = 0;
    }
    else
    {
      v9 = MiAllocateModWriterEntry((__int16 *)a1, 16, 1);
      v13 = v9;
    }
    if ( v13 )
    {
      memset((_BYTE *)v13, 0, 160);
      *(_DWORD *)v13 = 97;
      *(_DWORD *)(v13 + 120) = a1;
    }
    else
    {
      --*(_WORD *)(v2 + 310);
      v23 = (_DWORD *)(a1 + 356);
      v24 = *(__int64 **)(a1 + 356);
      if ( v24 == (__int64 *)(a1 + 356) )
      {
        *(_BYTE *)(a1 + 380) = 1;
      }
      else
      {
        v13 = *(_DWORD *)(a1 + 356);
        v25 = *v24;
        if ( *((_DWORD **)v24 + 1) != v23 || *(_DWORD *)(v25 + 4) != v13 )
          __fastfail(3u);
        *v23 = v25;
        *(_DWORD *)(v25 + 4) = v23;
      }
      v26 = (__int16)(*(_WORD *)(v2 + 310) + 1);
      *(_WORD *)(v2 + 310) = v26;
      if ( !v26 && *(_DWORD *)(v2 + 100) != v2 + 100 )
        KiCheckForKernelApcDelivery(v9);
    }
    if ( v13 )
    {
      v14 = (unsigned int *)(a1 + 348);
      do
      {
        v15 = __ldrex(v14);
        v16 = v15 + 1;
      }
      while ( __strex(v16, v14) );
      if ( v16 > *(_DWORD *)(a1 + 352) )
        *(_DWORD *)(a1 + 352) = v16;
      *(_DWORD *)(v13 + 124) = 0;
      v17 = MiGatherMappedPages(a1, v8, (_DWORD *)v13) == 0;
      v9 = 4120;
      if ( v17 )
      {
        v18 = (unsigned int *)(a1 + 348);
        do
          v19 = __ldrex(v18);
        while ( __strex(v19 - 1, v18) );
        if ( (*(_DWORD *)(v13 + 20) & 1) == 0 )
        {
          MiFreeModWriterEntry(v13, 1);
LABEL_28:
          v9 = 4120;
          goto LABEL_4;
        }
        --*(_WORD *)(v2 + 310);
        v27 = *(int **)(a1 + 360);
        *(_DWORD *)v13 = a1 + 356;
        *(_DWORD *)(v13 + 4) = v27;
        if ( *v27 != a1 + 356 )
          __fastfail(3u);
        *v27 = v13;
        *(_DWORD *)(a1 + 360) = v13;
        v9 = 4120;
        v28 = (__int16)(*(_WORD *)(v2 + 310) + 1);
        *(_WORD *)(v2 + 310) = v28;
        if ( !v28 && *(_DWORD *)(v2 + 100) != v2 + 100 )
        {
          KiCheckForKernelApcDelivery(4120);
          goto LABEL_28;
        }
      }
      goto LABEL_4;
    }
    KeWaitForGate(a1 + 364, 19);
LABEL_23:
    v9 = 4120;
  }
  if ( !*(_DWORD *)(a1 + 124) )
    JUMPOUT(0x550916);
  if ( *(_DWORD *)(a1 + 348) )
  {
    do
      KeDelayExecutionThread(0, 0, (unsigned int *)MiShortTime);
    while ( *(_DWORD *)(a1 + 348) );
    goto LABEL_23;
  }
  v20 = (__int64 **)(a1 + 356);
  while ( *v20 != (__int64 *)v20 )
  {
    v21 = *v20;
    v22 = **v20;
    if ( (__int64 **)HIDWORD(v22) != v20 || *(__int64 **)(v22 + 4) != v21 )
      __fastfail(3u);
    *v20 = (__int64 *)v22;
    *(_DWORD *)(v22 + 4) = v20;
    MiFreeModWriterEntry((int)v21, 1);
  }
  return KeSetActualBasePriorityThread(v2, v5);
}

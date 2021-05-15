// RtlpDeCommitFreeBlock 
 
int RtlpDeCommitFreeBlock(unsigned int a1, unsigned __int16 *a2, ...)
{
  unsigned int v2; // r2
  int v3; // r9
  unsigned int v6; // r1
  int v7; // r0
  unsigned __int16 *v8; // r4
  char *v9; // r7
  unsigned int v10; // r6
  unsigned int v11; // r8
  unsigned int v12; // r2
  char *i; // r1
  __int64 *v14; // r8
  int v15; // r0
  unsigned __int16 *v16; // r10
  unsigned __int16 *v17; // r3
  int v18; // r0
  int v19; // r0
  unsigned __int16 *v20; // r1
  unsigned int v21; // r2
  int result; // r0
  unsigned int v23; // r2
  unsigned int v24; // r1
  unsigned __int16 *v25; // r4
  unsigned __int16 *v26; // r1
  unsigned int v27; // r2
  int v28; // r0
  char *v29; // r1
  char v30; // r3
  signed int v31; // r6
  unsigned int v32; // r2
  unsigned int v33; // r1
  unsigned __int16 *v34; // r10
  unsigned __int16 *v35; // r3
  unsigned int v36; // r3
  unsigned int v37; // r0
  unsigned __int16 *v38; // r6
  unsigned int v39; // r2
  unsigned int v40; // r2
  int v41; // r0
  char *v42; // r1
  char v43; // r3
  signed int v44; // r9
  unsigned int v45; // r2
  int v46; // r0
  __int128 v47; // [sp+10h] [bp-30h]
  unsigned int v48; // [sp+10h] [bp-30h]
  unsigned int v49; // [sp+10h] [bp-30h]
  unsigned __int16 *v50; // [sp+14h] [bp-2Ch]
  unsigned int v51; // [sp+14h] [bp-2Ch]
  int v52; // [sp+18h] [bp-28h]
  int v53; // [sp+1Ch] [bp-24h]
  unsigned int v54[8]; // [sp+20h] [bp-20h] BYREF
  unsigned int varg_r2; // [sp+50h] [bp+10h] BYREF
  va_list varg_r2a; // [sp+50h] [bp+10h]
  va_list varg_r3; // [sp+54h] [bp+14h] BYREF

  va_start(varg_r3, a2);
  va_start(varg_r2a, a2);
  varg_r2 = va_arg(varg_r3, _DWORD);
  v2 = varg_r2;
  HIDWORD(v47) = 0;
  v3 = 0;
  if ( RtlpHeapKey != *(_DWORD *)(a1 + 204)
    || varg_r2 < *(_DWORD *)(a1 + 108)
    || (v6 = *(_DWORD *)(a1 + 116) + varg_r2, v6 < *(_DWORD *)(a1 + 112))
    || v6 < *(_DWORD *)(a1 + 484) >> (*(_BYTE *)(a1 + 572) + 3) )
  {
    v20 = a2;
    return RtlpInsertFreeBlock(a1, v20, v2);
  }
  v7 = RtlpCoalesceFreeBlocks(a1, (unsigned __int8 *)a2, (int *)varg_r2a);
  v8 = (unsigned __int16 *)v7;
  if ( *((_BYTE *)a2 + 6) )
    v9 = (char *)(((unsigned int)a2 & 0xFFFF0000) - (*((unsigned __int8 *)a2 + 6) << 16) + 0x10000);
  else
    v9 = (char *)a1;
  v10 = varg_r2;
  v11 = v7 + 8 * varg_r2;
  if ( *(_BYTE *)(v11 + 7) == 3 )
  {
    RtlpRemoveUCRBlock(v7, (__int64 *)(v11 + 8));
    v52 = *(_DWORD *)(v11 + 28);
    v53 = *(_DWORD *)(v11 + 24);
    --*((_DWORD *)v9 + 12);
    *((_DWORD *)v9 + 11) -= *(_DWORD *)(v11 + 28) >> 12;
    *(_DWORD *)(a1 + 484) += *(_DWORD *)(v11 + 28);
    --*(_DWORD *)(a1 + 500);
    v12 = *(_DWORD *)(v11 + 28);
    if ( v12 >= 0x7F000 )
      *(_DWORD *)(a1 + 488) -= v12;
    v3 = 1;
    v10 += (*(_DWORD *)(v11 + 28) >> 3) + 32;
    varg_r2 = v10;
  }
  else
  {
    v52 = 0;
  }
  if ( v8[2] == *(unsigned __int16 *)(a1 + 84) )
  {
    v50 = v8;
    for ( i = (char *)*((_DWORD *)v9 + 14); ; i = *(char **)i )
    {
      if ( v9 + 56 == i )
      {
        v14 = 0;
        goto LABEL_19;
      }
      if ( (unsigned __int16 *)(*((_DWORD *)i + 2) + *((_DWORD *)i + 3)) == v8 )
        break;
    }
    v14 = (__int64 *)(i - 8);
LABEL_19:
    if ( RtlpHeapErrorHandlerThreshold >= 1 && !v14 )
    {
      v15 = DbgPrint("(UCRBlock != NULL)");
      RtlpHeapHandleError(v15);
    }
    v16 = &v8[4 * v10];
    v17 = v16 - 8;
    if ( v3 )
      v17 = &v8[4 * v10];
    v48 = ((unsigned int)v17 & 0xFFFFF000) - (_DWORD)v8;
    if ( !v48 )
    {
      if ( RtlpHeapErrorHandlerThreshold >= 1 )
      {
        if ( v3 )
        {
          v18 = DbgPrint("(!TrailingUCR)");
          RtlpHeapHandleError(v18);
        }
      }
      goto LABEL_32;
    }
    v19 = ZwFreeVirtualMemory();
    if ( v19 < 0 )
    {
      ++*(_DWORD *)(a1 + 524);
      if ( v3 )
      {
LABEL_31:
        RtlpCreateUCREntry(a1, v9, v53 - 24, v52, (unsigned int)v8, (int *)varg_r2a);
        v10 = varg_r2;
      }
LABEL_32:
      v2 = v10;
      v20 = v8;
      return RtlpInsertFreeBlock(a1, v20, v2);
    }
    if ( (dword_682608 & 0x20) != 0 )
      v19 = RtlpLogHeapDecommit(a1, v8, v48, 5);
    ++*(_DWORD *)(a1 + 508);
    v21 = *((_DWORD *)v14 + 5);
    if ( v21 >= 0x7F000 )
      *(_DWORD *)(a1 + 488) -= v21;
    RtlpRemoveUCRBlock(v19, v14);
    *((_DWORD *)v14 + 5) += v48;
    result = RtlpInsertUCRBlock(a1, (int *)v14);
    *((_DWORD *)v9 + 11) += v48 >> 12;
    v23 = v48;
    *(_DWORD *)(a1 + 484) -= v48;
    v24 = *((_DWORD *)v14 + 5);
    if ( v24 >= 0x7F000 )
      *(_DWORD *)(a1 + 488) += v24;
    if ( !v3 )
    {
      v25 = (unsigned __int16 *)((char *)v8 + v48);
      *(unsigned __int16 *)((char *)v50 + v48 + 4) = *(_WORD *)(a1 + 84);
      v23 = v48;
      v26 = v50;
      if ( v16 == (unsigned __int16 *)((char *)v50 + v48) )
      {
        if ( !*(_DWORD *)(a1 + 76) )
          goto LABEL_55;
        *((_BYTE *)v25 + 3) = *(_BYTE *)v25 ^ *((_BYTE *)v25 + 2) ^ *((_BYTE *)v25 + 1);
        *(_DWORD *)v25 ^= *(_DWORD *)(a1 + 80);
      }
      else
      {
        *((_BYTE *)v25 + 7) = 0;
        *((_BYTE *)v25 + 2) = 0;
        v27 = (unsigned __int16)((8 * v10 - v48) >> 3);
        *v25 = v27;
        if ( RtlpHeapErrorHandlerThreshold >= 1 && v27 <= 1 )
        {
          v28 = DbgPrint("((LONG)FreeEntry->Size > 1)");
          RtlpHeapHandleError(v28);
        }
        *((_BYTE *)v25 + 3) = 0;
        v29 = (char *)*((_DWORD *)v9 + 6);
        if ( v29 == v9 )
        {
          v30 = 0;
        }
        else
        {
          v31 = ((unsigned int)((char *)v25 - v9) >> 16) + 1;
          if ( v31 <= 0 || v31 >= 254 )
            RtlpLogHeapFailure(3, v29);
          v30 = ((unsigned int)((char *)v25 - v9) >> 16) + 1;
        }
        v32 = *v25;
        *((_BYTE *)v25 + 6) = v30;
        result = RtlpInsertFreeBlock(a1, v25, v32);
      }
      v23 = v48;
    }
    v26 = v50;
LABEL_55:
    if ( (dword_682608 & 0x20) != 0 )
      result = RtlpLogHeapContractEvent(a1, v26, v23, 8 * *(_DWORD *)(a1 + 116), v3, v52);
    return result;
  }
  v33 = ((unsigned int)v8 + 4127) & 0xFFFFF000;
  v51 = v33;
  if ( (unsigned __int16 *)v33 == v8 + 20 )
  {
    v33 += 4096;
    v51 = v33;
  }
  v34 = &v8[4 * v10];
  if ( v3 )
  {
    v54[0] = 8 * v10;
    v35 = &v8[4 * v10];
  }
  else
  {
    v35 = v34 - 8;
    v54[0] = 8 * v10;
  }
  v36 = (unsigned int)v35 & 0xFFFFF000;
  if ( v36 < v33 )
  {
    if ( RtlpHeapErrorHandlerThreshold >= 1 && v3 )
    {
      v46 = DbgPrint("(!TrailingUCR)");
      RtlpHeapHandleError(v46);
    }
    goto LABEL_32;
  }
  v37 = v36 - v33;
  v49 = v36 - v33;
  if ( *(_BYTE *)(v11 + 7) != 3 && (!v37 || v37 < *(_DWORD *)(a1 + 108)) )
    goto LABEL_32;
  if ( v37 )
  {
    ++*(_DWORD *)(a1 + 508);
    if ( ZwFreeVirtualMemory() < 0 )
    {
      ++*(_DWORD *)(a1 + 524);
      if ( !v3 )
        goto LABEL_32;
      goto LABEL_31;
    }
    if ( (dword_682608 & 0x20) != 0 )
      RtlpLogHeapDecommit(a1, v51, v49, 6);
    v37 = v49;
    v33 = v51;
  }
  if ( !v3 )
  {
    v38 = (unsigned __int16 *)(v37 + v33);
    *(_WORD *)(v37 + v33 + 4) = *(_WORD *)(a1 + 84);
    v37 = v49;
    v33 = v51;
    if ( v34 == (unsigned __int16 *)(v49 + v51) )
    {
      if ( !*(_DWORD *)(a1 + 76) )
        goto LABEL_88;
      *((_BYTE *)v38 + 3) = *(_BYTE *)v38 ^ *((_BYTE *)v38 + 2) ^ *((_BYTE *)v38 + 1);
      *(_DWORD *)v38 ^= *(_DWORD *)(a1 + 80);
    }
    else
    {
      v39 = v54[0];
      *((_BYTE *)v38 + 7) = 0;
      *((_BYTE *)v38 + 2) = 0;
      v40 = (unsigned __int16)(((unsigned int)v8 + v39 - v49 - v51) >> 3);
      *v38 = v40;
      if ( RtlpHeapErrorHandlerThreshold >= 1 && v40 <= 1 )
      {
        v41 = DbgPrint("(LONG)FreeEntry->Size > 1");
        RtlpHeapHandleError(v41);
      }
      *((_BYTE *)v38 + 3) = 0;
      v42 = (char *)*((_DWORD *)v9 + 6);
      if ( v42 == v9 )
      {
        v43 = 0;
      }
      else
      {
        v44 = ((unsigned int)((char *)v38 - v9) >> 16) + 1;
        if ( v44 <= 0 || v44 >= 254 )
          RtlpLogHeapFailure(3, v42);
        v43 = ((unsigned int)((char *)v38 - v9) >> 16) + 1;
      }
      v45 = *v38;
      *((_BYTE *)v38 + 6) = v43;
      RtlpInsertFreeBlock(a1, v38, v45);
    }
    v37 = v49;
    v33 = v51;
  }
LABEL_88:
  RtlpCreateUCREntry(a1, v9, v33 - 24, v37, (unsigned int)v8, (int *)v54);
  result = RtlpInsertFreeBlock(a1, v8, v54[0]);
  if ( (dword_682608 & 0x20) != 0 )
    result = RtlpLogHeapContractEvent(a1, v51, v49, 8 * *(_DWORD *)(a1 + 116), 0, 0);
  return result;
}

// PfpPrefetchPrivatePages 
 
int __fastcall PfpPrefetchPrivatePages(_DWORD *a1)
{
  _DWORD *v1; // r7
  int v3; // r9
  int v4; // r5
  int v5; // r3
  unsigned int v6; // r6
  int v7; // r8
  int v8; // r2
  int v9; // r3
  int v10; // r4
  int v11; // r2
  int v12; // r2
  int v13; // r8
  int v14; // r1
  int v15; // r2
  int v16; // r0
  unsigned int v17; // r9
  int v18; // r3
  int v19; // r2
  unsigned int v20; // r4
  int v21; // r2
  int v22; // r5
  int result; // r0
  int v24; // [sp+0h] [bp-50h]
  int v25; // [sp+4h] [bp-4Ch]
  unsigned int v26; // [sp+8h] [bp-48h]
  int v27; // [sp+Ch] [bp-44h]
  unsigned int v28; // [sp+10h] [bp-40h]
  int v29; // [sp+14h] [bp-3Ch]
  int v30; // [sp+18h] [bp-38h] BYREF
  unsigned int v31; // [sp+20h] [bp-30h] BYREF
  int v32; // [sp+24h] [bp-2Ch]
  int v33[2]; // [sp+28h] [bp-28h] BYREF
  unsigned int v34; // [sp+30h] [bp-20h]

  v1 = (_DWORD *)*a1;
  v33[0] = 0;
  v33[1] = 0;
  v34 = 0;
  v3 = 0;
  v24 = 0;
  KeQueryTickCount((int *)&v31);
  v29 = ((__int64)(v31 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24) + ((MEMORY[0xFFFF9004] * v32) << 8);
  v28 = *(unsigned __int16 *)(*a1 + 30);
  v4 = *(_DWORD *)(*a1 + 28) & 7 | (8 * (v28 & 7));
  v5 = v1[14];
  if ( (v5 & 0x10) == 0 )
    v4 |= 0x100u;
  if ( (v5 & 8) != 0 )
    v4 |= 0x200u;
  if ( (v5 & 0x20) != 0 )
    v4 |= 0x800u;
  v26 = 0;
  v6 = v34;
  if ( !v1[5] )
  {
LABEL_41:
    v22 = 0;
    goto LABEL_42;
  }
  v7 = 0;
  v27 = 0;
  while ( 1 )
  {
    v8 = *a1;
    v31 = 0;
    v32 = 0;
    v9 = *(_DWORD *)(v8 + 52);
    v10 = v1[11];
    if ( v9 && *(_DWORD *)(v9 + 4)
      || (*(_DWORD *)(v8 + 56) & 4) != 0 && ((v11 = a1[5], *(_DWORD *)(v11 + 44)) || (*(_DWORD *)(v11 + 40) & 4) != 0) )
    {
      v3 = 1;
      v24 = 1;
LABEL_36:
      v13 = v32;
      goto LABEL_37;
    }
    if ( PfpSourceBuildVaArray(v7 + v10, v33) < 0 || PfpSourceGetPrefetchSupport(v7 + v10, &v31) < 0 )
    {
      v6 = v34;
      goto LABEL_36;
    }
    v13 = v32;
    v6 = v34;
    if ( (v1[14] & 4) == 0 )
    {
      v14 = v33[0];
      v15 = v34;
      v16 = v32;
      v1[20] += v33[0];
      MmPrefetchVirtualMemory(v16, v14, v15, v4);
LABEL_33:
      ++v1[17];
      goto LABEL_37;
    }
    v17 = v33[0];
    v25 = v34;
    MmQueryMemoryListInformation((int)(a1 + 6), 0x58u, v12, &v30);
    if ( !v17 )
    {
LABEL_32:
      v3 = v24;
      goto LABEL_33;
    }
    while ( 1 )
    {
      v18 = *(_DWORD *)(*a1 + 52);
      if ( v18 )
      {
        if ( *(_DWORD *)(v18 + 4) )
          break;
      }
      if ( (*(_DWORD *)(*a1 + 56) & 4) != 0 )
      {
        v19 = a1[5];
        if ( *(_DWORD *)(v19 + 44) || (*(_DWORD *)(v19 + 40) & 4) != 0 )
          break;
      }
      if ( !PfpAvailablePagesForPrefetch(a1 + 6, v28) )
        break;
      if ( v17 <= 0x10 )
        v20 = v17;
      else
        v20 = 16;
      if ( MmPrefetchVirtualMemory(v13, v20, v25, v4) >= 0 )
        v1[20] += v20;
      PfpUpdateRepurposedByPrefetch((int)(a1 + 6), v20, v21);
      v17 -= v20;
      v25 += 8 * v20;
      if ( !v17 )
        goto LABEL_32;
    }
    v3 = 1;
    v24 = 1;
LABEL_37:
    if ( v13 )
      NtClose();
    if ( v3 )
      break;
    v7 = v27 + 24;
    ++v26;
    v27 += 24;
    if ( v26 >= v1[5] )
      goto LABEL_41;
  }
  v22 = -1073741248;
LABEL_42:
  if ( v6 )
    ExFreePoolWithTag(v6);
  KeQueryTickCount((int *)&v31);
  result = v22;
  *(_DWORD *)(*a1 + 96) += ((__int64)(v31 * (unsigned __int64)MEMORY[0xFFFF9004]) >> 24)
                         + ((MEMORY[0xFFFF9004] * v32) << 8)
                         - v29;
  return result;
}

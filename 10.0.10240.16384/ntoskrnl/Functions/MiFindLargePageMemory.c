// MiFindLargePageMemory 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiFindLargePageMemory(int a1, _DWORD *a2, signed int a3, int a4, unsigned int a5)
{
  int v8; // r2
  unsigned int v11; // r0
  int v12; // r5
  int v13; // r2
  unsigned __int16 *v14; // r9
  unsigned int v15; // r7
  int v16; // r3
  int v17; // r10
  int v18; // r0
  int v19; // r0
  _DWORD *v20; // r1 OVERLAPPED
  int v21; // lr
  int v22; // r0
  int v23; // r2
  int *v24; // r2 OVERLAPPED
  unsigned int v25; // r0
  int v26; // [sp+Ch] [bp-44h]
  int v27; // [sp+18h] [bp-38h] BYREF
  int v28; // [sp+1Ch] [bp-34h]
  _DWORD *v29; // [sp+20h] [bp-30h]
  int v30; // [sp+24h] [bp-2Ch]
  int v31; // [sp+28h] [bp-28h]
  unsigned __int16 *v32; // [sp+2Ch] [bp-24h]
  int v33; // [sp+30h] [bp-20h]

  v8 = *(_DWORD *)(a1 + 3712) - 128;
  v29 = a2;
  if ( a3 > v8 || !MiChargeResident((__int16 *)a1, a3, 0) )
    return 0;
  if ( (__int16 *)a1 == MiSystemPartition )
  {
    do
      v11 = __ldrex(&dword_634A2C[37]);
    while ( __strex(v11 + a3, &dword_634A2C[37]) );
  }
  v31 = 0;
  v12 = 0;
  v13 = 1;
  if ( a5 >> 3 == 1 )
  {
    v13 = 0;
  }
  else if ( a5 >> 3 == 3 && (a5 & 7) != 0 )
  {
    v13 = 2;
  }
  v30 = MiPlatformCacheAttributes[v13];
  v33 = a2[2];
  v32 = 0;
  v14 = 0;
  if ( !a4 )
    a4 = *((_DWORD *)*(&KiProcessorBlock + *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16C)) + 682) + 1;
  v15 = a4 - 1;
  if ( v15 >= (unsigned __int16)KeNumberNodes )
  {
    v15 = 0x80000000;
  }
  else
  {
    v14 = (unsigned __int16 *)(dword_6337E4 + 2 * (unsigned __int16)KeNumberNodes * v15);
    v32 = &v14[(unsigned __int16)KeNumberNodes];
  }
  v16 = dword_640504;
  v17 = 538968128;
LABEL_17:
  v28 = v16;
  while ( 1 )
  {
    if ( !v12 )
    {
      v12 = ExAllocatePoolWithTag(512, 16, 1816948045);
      if ( !v12 )
        break;
    }
    v18 = MiFindContiguousPages((__int16 *)a1, 1024, v28, 1024, 0x400u, v30, v15, v26, v17, (unsigned int *)&v27);
    if ( v18 < 0 )
    {
      if ( (v17 & 0x40) != 0 )
      {
        v17 &= 0xFFFFFFBF;
        v18 = MiFindContiguousPages((__int16 *)a1, 1024, v28, 1024, 0x400u, v30, v15, v26, v17, (unsigned int *)&v27);
      }
      if ( v18 < 0 )
      {
LABEL_34:
        if ( v15 != 0x80000000 && ++v14 != v32 )
        {
          v15 = *v14;
          v17 |= 0x40u;
          v16 = dword_640504;
          goto LABEL_17;
        }
LABEL_37:
        if ( v12 )
          ExFreePoolWithTag(v12);
        break;
      }
    }
    a3 -= 1024;
    v19 = MiUpdateLargePagePfns(v33, v27);
    v20 = v29;
    if ( v19 == 1 )
      v29[3] = 1;
    v21 = v31;
    v22 = v27;
    if ( v31 && (v23 = *(_DWORD *)(v31 + 8), v27 + 1024 == v23) )
    {
      *(_DWORD *)(v31 + 8) = v23 - 1024;
      *(_DWORD *)(v21 + 12) += 1024;
    }
    else
    {
      *(_DWORD *)(v12 + 8) = v27;
      *(_DWORD *)(v12 + 12) = 1024;
      v24 = (int *)v20[1];
      *(_QWORD *)v12 = *(_QWORD *)&v20;
      if ( (_DWORD *)*v24 != v20 )
        __fastfail(3u);
      *v24 = v12;
      v20[1] = v12;
      v31 = v12;
      v12 = 0;
    }
    if ( !a3 )
      goto LABEL_37;
    if ( (v17 & 0x40) == 0 )
    {
      v28 = v22 - 1;
      if ( (unsigned int)(v22 - 1) <= 0x400 )
        goto LABEL_34;
    }
  }
  if ( a3 )
  {
    MiReturnLargePages(v29);
    if ( (__int16 *)a1 == MiSystemPartition )
    {
      MiReturnResidentAvailable(a3);
      do
        v25 = __ldrex(&dword_634A2C[39]);
      while ( __strex(v25 + a3, &dword_634A2C[39]) );
    }
    else
    {
      MiReturnPartitionResidentAvailable(a1, a3);
    }
    return 0;
  }
  return 1;
}

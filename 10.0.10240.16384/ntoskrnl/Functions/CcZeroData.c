// CcZeroData 
 
int __fastcall CcZeroData(_DWORD *a1, int *a2, _QWORD *a3, int a4)
{
  int v4; // r5
  __int64 v5; // r6
  int v6; // r4
  BOOL v8; // r9
  unsigned int v9; // r4
  int v10; // r8
  unsigned int v12; // r0
  unsigned int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  unsigned int v16; // r1
  int v17; // kr08_4
  int v18; // r4
  unsigned int v19; // r2
  int v20; // r3
  char v21; // [sp+0h] [bp-48h]
  unsigned __int64 v23; // [sp+10h] [bp-38h] BYREF
  __int64 v25[5]; // [sp+20h] [bp-28h] BYREF

  HIDWORD(v5) = a2[1];
  v4 = *a2;
  v6 = a1[11];
  v25[0] = *(_QWORD *)a2;
  v21 = a4;
  LODWORD(v23) = a3;
  v8 = (v6 & 0x10) != 0 || !a1[6];
  v10 = (*a3 - __PAIR64__(HIDWORD(v5), v4)) >> 32;
  v9 = *(_DWORD *)a3 - v4;
  if ( v8 || __SPAIR64__(v10, v9) > 0x200000 )
  {
    if ( !a4 )
      return 0;
  }
  else
  {
    v12 = MmGetAvailablePages();
    if ( v12 < v13 )
      return sub_7EFB00();
  }
  if ( *(unsigned __int16 *)(IoGetRelatedDeviceObject(a1) + 172) )
    LODWORD(v5) = *(unsigned __int16 *)(IoGetRelatedDeviceObject(a1) + 172) - 1;
  else
    LODWORD(v5) = 0;
  if ( v8 )
  {
    if ( (v4 & (unsigned int)v5) == 0 )
      goto LABEL_20;
    v17 = v4;
    v4 = (v5 + v4) & ~(_DWORD)v5;
    v18 = *a2;
    HIDWORD(v5) = (v5 + (unsigned __int64)(unsigned int)v17) >> 32;
    v19 = v4 - *a2;
    v25[0] = __PAIR64__(HIDWORD(v5), v4);
    if ( CcZeroDataInCache((int)a1, a2, v19, v21) )
    {
      CcFlushCache(a1[5], (int)a2, v4 - v18);
      if ( (int)a2 < 0 )
        RtlRaiseStatus((int)a2);
      goto LABEL_20;
    }
    return 0;
  }
  if ( (unsigned int)MmGetAvailablePages() < 0x800
    && v10 >= 0
    && (v10 > 0 || v9 > 0x2000)
    && (v4 & (unsigned int)v5) != 0 )
  {
    v20 = (v5 + v4) & ~(_DWORD)v5;
LABEL_41:
    v9 = v20 - v4;
    goto LABEL_17;
  }
  v14 = MmGetAvailablePages();
  if ( v14 >= v16 )
    goto LABEL_16;
  if ( v10 < 0 )
    goto LABEL_17;
  if ( v10 <= 0 && v9 <= v15 )
  {
LABEL_16:
    if ( v10 >= 0 && (v10 > 0 || v9 > 0x200000) )
    {
      v20 = (v5 + v4 + 0x200000) & ~(_DWORD)v5;
      goto LABEL_41;
    }
LABEL_17:
    if ( !v9 || CcZeroDataInCache((int)a1, (int *)v25, v9, v21) )
      goto LABEL_19;
    return 0;
  }
  v9 = 0;
LABEL_19:
  HIDWORD(v5) = (__PAIR64__(HIDWORD(v5), v4) + v9) >> 32;
  v4 += v9;
  v25[0] = __PAIR64__(HIDWORD(v5), v4);
LABEL_20:
  if ( __SPAIR64__(HIDWORD(v5), v4) < *(_QWORD *)v23 )
  {
    v23 = (*(_QWORD *)v23 + (unsigned int)v5) & ((unsigned int)~(_DWORD)v5 | 0xFFFFFFFF00000000ui64);
    CcZeroDataOnDisk((int)a1, v25, (__int64 *)&v23);
  }
  return 1;
}

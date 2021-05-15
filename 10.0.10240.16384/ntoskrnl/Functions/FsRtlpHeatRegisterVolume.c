// FsRtlpHeatRegisterVolume 
 
int __fastcall FsRtlpHeatRegisterVolume(unsigned int a1, int a2, unsigned int *a3, int a4)
{
  int v4; // r7
  int *i; // r4
  int **v8; // r0
  int **v9; // r8
  int v10; // r4
  int *v11; // r5
  unsigned int v12; // r7
  unsigned int v13; // r3
  int v14; // r1
  int *v15; // r2
  int *v16; // r3
  int **v17; // r2
  int v18; // r2

  v4 = a2;
  ExAcquireResourceExclusiveLite((int)&algn_631E04[4], 1, (int)a3, a4);
  for ( i = (int *)FsRtlTieringHeatData; i != &FsRtlTieringHeatData; i = (int *)*i )
  {
    if ( !memcmp((unsigned int)(i + 3), a1, 16) )
    {
      ++i[2];
      *a3 = i[7];
      goto LABEL_18;
    }
  }
  v8 = (int **)ExAllocatePoolWithTag(1, 32, 1752453958);
  v9 = v8;
  if ( !v8 )
  {
    v10 = -1073741670;
    goto LABEL_19;
  }
  v11 = (int *)FsRtlTieringHeatData;
  v12 = (*(unsigned __int8 *)(a1 + 15) | (*(unsigned __int8 *)(a1 + 10) << 24)) ^ (*(unsigned __int16 *)(a1 + 6) | (*(unsigned __int16 *)(a1 + 4) << 16)) ^ *(_DWORD *)a1;
  while ( v11 != &FsRtlTieringHeatData )
  {
    v13 = v11[7];
    if ( v13 == v12 )
    {
      if ( !++v12 )
        v11 = &FsRtlTieringHeatData;
    }
    else if ( v13 > v12 )
    {
      break;
    }
    v11 = (int *)*v11;
  }
  memset(v8, 0, 32);
  v14 = *(_DWORD *)(a1 + 4);
  v15 = *(int **)(a1 + 8);
  v16 = *(int **)(a1 + 12);
  v9[3] = *(int **)a1;
  v9[4] = (int *)v14;
  v9[5] = v15;
  v9[6] = v16;
  v9[2] = (int *)1;
  v9[7] = (int *)v12;
  v17 = (int **)v11[1];
  *v9 = v11;
  v9[1] = (int *)v17;
  if ( *v17 != v11 )
    __fastfail(3u);
  *v17 = (int *)v9;
  v11[1] = (int)v9;
  *a3 = v12;
  McGenEventRegister(
    (int)MS_StorageTiering_Provider,
    v14,
    (int)&MS_StorageTiering_Provider_Context,
    &Microsoft_Windows_Storage_Tiering_IoHeatHandle);
  v4 = a2;
LABEL_18:
  v10 = 0;
LABEL_19:
  ExReleaseResourceLite((int)&algn_631E04[4]);
  if ( v10 >= 0 )
  {
    if ( (Microsoft_Windows_Storage_Tiering_IoHeatEnableBits & 1) != 0 )
      Template_jq(
        Microsoft_Windows_Storage_Tiering_IoHeatHandle,
        SHIDWORD(Microsoft_Windows_Storage_Tiering_IoHeatHandle),
        v18,
        v4);
    ZwUpdateWnfStateData();
  }
  return v10;
}

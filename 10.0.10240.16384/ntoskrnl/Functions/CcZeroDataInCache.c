// CcZeroDataInCache 
 
int __fastcall CcZeroDataInCache(int a1, int *a2, unsigned int a3, char a4)
{
  unsigned int v6; // r5
  int v7; // r8
  int v8; // r0
  int v9; // r6
  int v10; // r4
  char v11; // r2
  unsigned __int8 v13; // [sp+18h] [bp-50h]
  int *v14; // [sp+1Ch] [bp-4Ch] BYREF
  int v15; // [sp+20h] [bp-48h]
  int v16; // [sp+24h] [bp-44h]
  unsigned int v17; // [sp+28h] [bp-40h] BYREF
  int v18; // [sp+2Ch] [bp-3Ch]
  unsigned int v19; // [sp+30h] [bp-38h]
  int v20; // [sp+38h] [bp-30h] BYREF
  int v21; // [sp+3Ch] [bp-2Ch]
  _DWORD v22[10]; // [sp+40h] [bp-28h] BYREF

  v18 = a1;
  v6 = 0;
  v20 = *a2;
  v21 = a2[1];
  v14 = 0;
  v17 = 0;
  v16 = 0;
  v13 = 1;
  v15 = 0;
  while ( CcPinFileData(a1, &v20, a3 - v6, 0, 1, a4, &v14, (int *)&v17, v22) )
  {
    v7 = v22[0] - v20;
    v6 += v22[0] - v20;
    v19 = v6;
    v8 = IoAllocateMdl(v17, v22[0] - v20, 0, 0, 0);
    v9 = v8;
    v16 = v8;
    if ( !v8 )
      RtlRaiseStatus(-1073741670);
    v10 = *(unsigned __int8 *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3CD) + 2;
    v15 = v10;
    *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3CD) = 1;
    MmProbeAndLockPages(v8);
    *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3CD) = v10 - 2;
    v15 = 0;
    v20 = v22[0];
    v21 = v22[1];
    MmSetAddressRangeModified(v17, v7);
    CcSetDirtyPinnedData(v14, 0);
    CcUnpinFileDataEx((int)v14, 0, 0);
    v14 = 0;
    MmUnlockPages(v9);
    IoFreeMdl(v9);
    v16 = 0;
    a1 = v18;
    if ( a3 <= v6 )
      goto LABEL_7;
  }
  v13 = 0;
LABEL_7:
  v11 = v15;
  if ( v15 )
    *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x3CD) = v11 - 2;
  if ( v14 )
    CcUnpinFileDataEx((int)v14, 0, 0);
  if ( v16 )
    IoFreeMdl(v16);
  return v13;
}

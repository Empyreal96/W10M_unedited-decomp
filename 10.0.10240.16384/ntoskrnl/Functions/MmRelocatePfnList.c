// MmRelocatePfnList 
 
int __fastcall MmRelocatePfnList(unsigned int a1, _DWORD *a2, unsigned int a3, int a4)
{
  int v7; // r4
  int v8; // r6
  int v9; // r8
  int v10; // r1
  int v11; // r2
  int v12; // r3
  int v13; // [sp+10h] [bp-58h] BYREF
  int v14; // [sp+14h] [bp-54h]
  int v15; // [sp+18h] [bp-50h] BYREF
  unsigned int i; // [sp+1Ch] [bp-4Ch]
  int v17; // [sp+20h] [bp-48h] BYREF
  int v18; // [sp+28h] [bp-40h] BYREF
  int v19; // [sp+2Ch] [bp-3Ch]
  int v20; // [sp+30h] [bp-38h]
  int v21; // [sp+34h] [bp-34h]
  char v22[48]; // [sp+38h] [bp-30h] BYREF

  if ( a3 >= (unsigned __int16)KeNumberNodes )
    return -1073741584;
  if ( a4 )
    return -1073741583;
  v14 = a3 << byte_6337F5;
  MiCreatePteCopyList(a1, 0x100u, (int)v22);
  for ( i = (unsigned int)&a2[4 * a1]; (unsigned int)a2 < i; a2 += 4 )
  {
    v7 = a2[2];
    v8 = 0;
    v18 = 0;
    v19 = 0;
    v20 = v7;
    v21 = 0;
    if ( !MI_IS_PFN(v7) )
      goto LABEL_15;
    v9 = MmPfnDatabase;
    MiIdentifyPfnWrapper((int *)(MmPfnDatabase + 24 * v7), &v18);
    v8 = v21;
    if ( v21 != a2[3]
      || (v19 ^ a2[1]) & 0x1FFFFFF | (*a2 ^ v18) & 0xFFFFFE00
      || MiPfnsWorthTrying((unsigned __int16)MiSystemPartition[0], v9 + 24 * v7, 1, 0, &v13, &v17) )
    {
      goto LABEL_15;
    }
    if ( v13 == 1 )
      MiEmptyKernelStackCache();
    if ( MiClaimPhysicalRun(MiSystemPartition, v7, 1, (int)v22, 0x800000, v14, (int)&v15) || v15 == -1 )
LABEL_15:
      v21 = v8 | 2;
    else
      v20 = v15;
    v10 = v19;
    v11 = v20;
    v12 = v21;
    *a2 = v18;
    a2[1] = v10;
    a2[2] = v11;
    a2[3] = v12;
  }
  MiReleasePteCopyList((int)v22);
  return 0;
}

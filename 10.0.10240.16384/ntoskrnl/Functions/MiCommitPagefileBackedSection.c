// MiCommitPagefileBackedSection 
 
int __fastcall MiCommitPagefileBackedSection(unsigned int *a1, _DWORD *a2, unsigned int a3, unsigned int a4, unsigned int a5, int a6, int a7, _DWORD *a8, _DWORD *a9)
{
  int v12; // r0
  int v14; // r9
  unsigned int *v16[3]; // [sp+10h] [bp-30h] BYREF
  unsigned int *v17; // [sp+1Ch] [bp-24h] BYREF

  v12 = (unsigned __int8)a2[7] >> 3;
  v16[1] = (unsigned int *)a4;
  v16[2] = a1;
  if ( !MiIsPteProtectionCompatible(v12, a5) )
    return -1073741746;
  v14 = MiGetProtoPteAddress(a2, a3 >> 12, 1, v16);
  MiGetProtoPteAddress(a2, a4 >> 12, 1, &v17);
  if ( MiVadPureReserve((int)a2) )
    return sub_7E96F8();
  if ( MiChargeSegmentCommit(v16[0], v14, (a4 >> 12) - (a3 >> 12) + 1, 0) )
    return MiSetProtectionOnSection((int)a1, a2, a3, a4, a5, 0, a8, a9);
  return -1073741523;
}

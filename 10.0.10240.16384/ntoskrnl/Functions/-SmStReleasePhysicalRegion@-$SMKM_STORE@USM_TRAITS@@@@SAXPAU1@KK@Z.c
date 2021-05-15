// -SmStReleasePhysicalRegion@-$SMKM_STORE@USM_TRAITS@@@@SAXPAU1@KK@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStReleasePhysicalRegion(int a1, int a2)
{
  int v2; // r5
  int v4; // r4
  int result; // r0

  v2 = *(_DWORD *)(a1 + 3660);
  v4 = *(_DWORD *)(v2 + 4 * a2);
  MiFreePagesFromMdl(MiSystemPartition, v4 & 0xFFFFFFF8, 0);
  result = ExFreePoolWithTag(v4 & 0xFFFFFFF8);
  *(_DWORD *)(v2 + 4 * a2) = 0;
  return result;
}

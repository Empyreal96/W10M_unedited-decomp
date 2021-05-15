// sub_50AE98 
 
// positive sp value has been detected, the output may be wrong!
int __fastcall sub_50AE98(_DWORD *a1)
{
  int v2; // [sp-4h] [bp-4h]

  return ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(a1, v2);
}

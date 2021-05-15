// sub_50ECEC 
 
// positive sp value has been detected, the output may be wrong!
int __fastcall sub_50ECEC(_DWORD *a1)
{
  int v2; // [sp-4h] [bp-4h]

  return KiReleaseSpinLockInstrumented(a1, v2);
}

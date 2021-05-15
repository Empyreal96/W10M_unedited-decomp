// -SmStDirectReadCallout@-$SMKM_STORE@USM_TRAITS@@@@SAXPAX@Z 
 
int __fastcall SMKM_STORE<SM_TRAITS>::SmStDirectReadCallout(_DWORD *a1)
{
  int result; // r0

  result = SMKM_STORE<SM_TRAITS>::SmStDirectReadIssue(*a1, a1[1], a1[2]);
  a1[3] = result;
  return result;
}

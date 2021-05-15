// -StDrainReadContextList@-$ST_STORE@USM_TRAITS@@@@SAXPAU1@@Z 
 
int __fastcall ST_STORE<SM_TRAITS>::StDrainReadContextList(int a1)
{
  int result; // r0
  _DWORD *v2; // r4
  _DWORD *v3; // r0

  result = RtlpInterlockedFlushSList((unsigned __int64 *)(a1 + 1664));
  v2 = (_DWORD *)result;
  while ( v2 )
  {
    v3 = v2;
    v2 = (_DWORD *)*v2;
    result = ExFreePoolWithTag(v3, 0);
  }
  return result;
}

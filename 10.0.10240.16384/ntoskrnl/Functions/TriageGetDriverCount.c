// TriageGetDriverCount 
 
int __fastcall TriageGetDriverCount(int a1, _DWORD *a2)
{
  int result; // r0

  if ( !TriagepVerifyDump() || !(TriageImagePageSize + a1) )
    return -1073741811;
  result = 0;
  *a2 = *(_DWORD *)(TriageImagePageSize + a1 + 52);
  return result;
}

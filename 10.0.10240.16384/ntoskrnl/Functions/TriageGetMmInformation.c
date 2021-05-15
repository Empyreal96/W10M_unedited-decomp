// TriageGetMmInformation 
 
int __fastcall TriageGetMmInformation(int a1)
{
  int result; // r0

  if ( TriagepVerifyDump() && TriageImagePageSize + a1 )
    result = *(_DWORD *)(TriageImagePageSize + a1 + 20) + a1;
  else
    result = 0;
  return result;
}

// TriageGetBugcheckData 
 
int __fastcall TriageGetBugcheckData(_DWORD *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, _DWORD *a6)
{
  int result; // r0

  if ( !TriagepVerifyDump() )
    return -1073741811;
  result = 0;
  *a2 = a1[10];
  *a3 = a1[11];
  *a4 = a1[12];
  *a5 = a1[13];
  *a6 = a1[14];
  return result;
}

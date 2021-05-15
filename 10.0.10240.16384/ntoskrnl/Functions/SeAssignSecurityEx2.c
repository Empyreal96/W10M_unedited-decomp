// SeAssignSecurityEx2 
 
int __fastcall SeAssignSecurityEx2(int a1, int a2, int a3, int a4, unsigned __int8 a5, int a6, _DWORD *a7, int a8, int a9)
{
  if ( a7 && *a7 != 8 )
    return -1073741811;
  if ( a4 )
    return sub_52CFD4();
  return RtlpNewSecurityObject(a1, a2, a3, 0, 0, a5, a6, a8, a9, a7);
}

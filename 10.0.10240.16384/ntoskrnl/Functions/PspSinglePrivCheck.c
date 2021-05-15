// PspSinglePrivCheck 
 
int __fastcall PspSinglePrivCheck(int a1, int a2, char a3, int a4)
{
  int v4; // r6
  int **v6; // r7
  int v7; // r5
  _DWORD *v8; // t1

  v4 = a3;
  *(_BYTE *)(a4 + 36) = a3;
  if ( !a3 )
    return 1;
  *(_DWORD *)(a4 + 16) = 1;
  *(_DWORD *)(a4 + 20) = 1;
  SeCaptureSubjectContext(a4);
  v6 = PspWorkingSetPrivileges;
  *(_BYTE *)(a4 + 37) = 0;
  v7 = 0;
  while ( 1 )
  {
    v8 = *v6++;
    *(_DWORD *)(a4 + 24) = *v8;
    *(_DWORD *)(a4 + 28) = v8[1];
    *(_DWORD *)(a4 + 32) = 0;
    if ( SePrivilegeCheck(a4 + 16, a4, v4) == 1 )
      break;
    if ( (unsigned int)++v7 >= 2 )
      return *(unsigned __int8 *)(a4 + 37);
  }
  *(_BYTE *)(a4 + 37) = 1;
  return *(unsigned __int8 *)(a4 + 37);
}

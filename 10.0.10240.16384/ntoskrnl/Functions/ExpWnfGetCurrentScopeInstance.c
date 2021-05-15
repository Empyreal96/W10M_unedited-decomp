// ExpWnfGetCurrentScopeInstance 
 
int __fastcall ExpWnfGetCurrentScopeInstance(int a1, int a2, int a3, int *a4, int *a5, BOOL *a6)
{
  BOOL v7; // r2
  int *v8; // r3
  int v9; // r2
  BOOL v11; // r2

  switch ( a3 )
  {
    case 1:
      v7 = *(unsigned __int8 *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) != 1;
      *a6 = v7;
      if ( !v7 )
        a1 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      a1 = PsGetProcessSessionId(a1);
      goto LABEL_5;
    case 2:
      return ExpWnfQueryCurrentUserSID(a1, a2, a4, a5);
    case 0:
      *a5 = 0;
      v8 = a6;
      v9 = 1;
      goto LABEL_6;
  }
  v11 = *(unsigned __int8 *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) != 1;
  *a6 = v11;
  if ( v11 )
  {
LABEL_5:
    v8 = a5;
    *a4 = a1;
    v9 = 4;
LABEL_6:
    *v8 = v9;
    return 0;
  }
  return sub_7E940C();
}

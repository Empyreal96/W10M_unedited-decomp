// SePrivilegeCheck 
 
int __fastcall SePrivilegeCheck(int *a1, int *a2, char a3)
{
  int v4; // r0

  if ( !a3 )
    return 1;
  v4 = *a2;
  if ( !*a2 )
  {
    v4 = a2[2];
    return SepPrivilegeCheck(v4, a1 + 2, *a1, a1[1], a3);
  }
  if ( a2[1] >= 2 )
    return SepPrivilegeCheck(v4, a1 + 2, *a1, a1[1], a3);
  return 0;
}

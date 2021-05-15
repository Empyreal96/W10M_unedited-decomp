// RtlIsParentOfChildAppContainer 
 
int __fastcall RtlIsParentOfChildAppContainer(int a1, int a2, int a3, int a4)
{
  int v6; // r5
  _DWORD *v7; // r4
  int v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[0] = a3;
  v9[1] = a4;
  if ( RtlGetAppContainerSidType(a1, v9) >= 0 && v9[0] == 2 && RtlGetAppContainerSidType(a2, v9) >= 0 && v9[0] == 1 )
  {
    v6 = 1;
    while ( 1 )
    {
      v7 = (_DWORD *)RtlSubAuthoritySid(a1, v6);
      if ( *v7 != *(_DWORD *)RtlSubAuthoritySid(a2, v6) )
        break;
      if ( (unsigned int)++v6 >= 8 )
        return 1;
    }
  }
  return 0;
}

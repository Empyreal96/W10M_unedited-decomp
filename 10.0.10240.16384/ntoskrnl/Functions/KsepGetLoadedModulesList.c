// KsepGetLoadedModulesList 
 
int __fastcall KsepGetLoadedModulesList(int **a1)
{
  int i; // r4
  int *v3; // r5
  int v4; // r0
  int v5; // r4
  int v6; // r9
  int result; // r0

  if ( a1 )
  {
    for ( i = 288; ; i = 284 * v6 + 4 )
    {
      v3 = (int *)KsepPoolAllocatePaged(i);
      if ( !v3 )
      {
        v5 = -1073741670;
        goto LABEL_10;
      }
      v4 = ZwQuerySystemInformation();
      v5 = v4;
      v6 = *v3;
      if ( v4 >= 0 )
        break;
      if ( v4 != -1073741820 )
        goto LABEL_8;
      KsepPoolFreePaged((int)v3);
    }
    *a1 = v3;
LABEL_8:
    if ( v4 >= 0 )
      goto LABEL_10;
    result = sub_7CF350();
  }
  else
  {
    v5 = -1073741811;
LABEL_10:
    result = v5;
  }
  return result;
}

// PiControlMakeUserModeCallersCopy 
 
int __fastcall PiControlMakeUserModeCallersCopy(int *a1, int a2, unsigned int a3, int a4, char a5, int a6)
{
  int v10; // r4
  int v12; // r0

  if ( !a5 )
  {
    *a1 = a2;
    return 0;
  }
  if ( a3 )
  {
    if ( a6 )
    {
      v12 = ExAllocatePoolWithQuotaTag(9u, a3, 538996816);
      *a1 = v12;
      if ( !v12 )
        return -1073741670;
    }
    v10 = 0;
    if ( *a1 )
    {
      v10 = PiControlCopyUserModeCallersBuffer(*a1, a2, a3, a4);
      if ( v10 < 0 )
        JUMPOUT(0x7C5B76);
    }
    return v10;
  }
  return sub_7C5B70();
}

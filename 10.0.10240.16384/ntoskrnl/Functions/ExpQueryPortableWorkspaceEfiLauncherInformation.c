// ExpQueryPortableWorkspaceEfiLauncherInformation 
 
int __fastcall ExpQueryPortableWorkspaceEfiLauncherInformation(char *a1, int a2, _DWORD *a3)
{
  int v5; // r8
  _DWORD *v6; // r6
  int v7; // r4
  int v8; // r0
  int v9; // r0
  _DWORD *v10; // r5
  _DWORD *i; // r4
  char v12; // r3

  v5 = 0;
  v6 = 0;
  if ( dword_61A1F0 != 2 )
  {
    v7 = -1073741821;
    goto LABEL_25;
  }
  if ( a2 != 1 )
  {
    *a3 = 1;
    v7 = -1073741820;
    goto LABEL_25;
  }
  v8 = ZwEnumerateBootEntries();
  v7 = v8;
  if ( v8 >= 0 )
    goto LABEL_22;
  if ( v8 != -1073741789 )
    goto LABEL_25;
  v5 = ExAllocatePoolWithQuotaTag(9u, 0, 1868983881);
  if ( !v5 )
    goto LABEL_8;
  v7 = ZwEnumerateBootEntries();
  if ( v7 >= 0 )
  {
    v9 = ZwQueryBootEntryOrder();
    v7 = v9;
    if ( v9 >= 0 )
      goto LABEL_22;
    if ( v9 == -1073741789 )
    {
      v6 = (_DWORD *)ExAllocatePoolWithQuotaTag(9u, 0, 1868983881);
      if ( !v6 )
      {
LABEL_8:
        v7 = -1073741670;
        goto LABEL_25;
      }
      v7 = ZwQueryBootEntryOrder();
      if ( v7 >= 0 )
      {
        v10 = 0;
        for ( i = (_DWORD *)v5;
              i[7] != 16 || memcmp((unsigned int)(i + 8), (unsigned int)PORTABLE_WORKSPACE_LAUNCHER_EFI_ENTRY_ID, 16);
              i = (_DWORD *)((char *)i + *i) )
        {
          if ( !*i )
            goto LABEL_19;
        }
        v10 = i + 1;
LABEL_19:
        if ( v10 && v10[2] == *v6 )
        {
          v12 = 1;
LABEL_23:
          *a1 = v12;
          *a3 = 1;
          v7 = 0;
          goto LABEL_25;
        }
LABEL_22:
        v12 = 0;
        goto LABEL_23;
      }
    }
  }
LABEL_25:
  if ( v5 )
    ExFreePoolWithTag(v5);
  if ( v6 )
    ExFreePoolWithTag((unsigned int)v6);
  return v7;
}

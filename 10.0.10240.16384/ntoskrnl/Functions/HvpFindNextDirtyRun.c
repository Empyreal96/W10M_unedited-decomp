// HvpFindNextDirtyRun 
 
int __fastcall HvpFindNextDirtyRun(char **a1, char **a2, char **a3, char **a4, _DWORD *a5)
{
  char *v6; // r4
  int v9; // r0
  char *v10; // r5
  char *v11; // r3
  char *v13; // [sp+0h] [bp-20h]

  v13 = (char *)a3;
  v6 = *a1;
  if ( *a2 >= *a1 )
    return 0;
  v9 = RtlFindNextForwardRunClearCapped();
  v10 = *a2;
  if ( v9 )
  {
    v11 = v13;
    if ( v13 == v10 )
      return sub_548B80();
    v6 = &v13[v9];
  }
  else
  {
    v11 = v6;
  }
  *a2 = v6;
  *a3 = v10;
  *a4 = v11;
  if ( a5 )
    *a5 = v11 - v10;
  return 1;
}

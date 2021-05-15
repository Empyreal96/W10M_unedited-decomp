// ViXdvSearchAndReplaceThunkArrayOrderDependent 
 
int __fastcall ViXdvSearchAndReplaceThunkArrayOrderDependent(int a1, char *a2, int a3)
{
  char **i; // r0
  char *v6; // r1
  char *v7; // r0

  for ( i = &VfOrderDependentThunks; i[5] != a2 || !i[4]; i += 6 )
  {
    if ( !i[6] )
      return 0;
  }
  v6 = i[4];
  v7 = i[2];
  if ( *(char **)v6 != v7 )
    ++ViXdvThunksNotPristine;
  if ( v7 )
    ++ViXdvThunksBoundToXdv;
  else
    ++ViXdvThunksShared;
  *(_DWORD *)v6 = a3;
  return 1;
}

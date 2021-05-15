// ViThunkReplaceAllThunkedImports 
 
int __fastcall ViThunkReplaceAllThunkedImports(int a1, int a2, int a3, int a4)
{
  int v6; // r7
  char **v7; // r5
  _DWORD *v8; // r4
  int v9; // r6
  _DWORD *v10; // r2
  char **v11; // r2
  char *v12; // t1
  int v14; // r1

  v6 = a2;
  v7 = (char **)a1;
  if ( a3 || a4 != 1 )
    v8 = 0;
  else
    v8 = ViThunkFindAllSpecialTables(a1, a2);
  while ( v6 )
  {
    if ( v8 )
    {
      v9 = 0;
      if ( *v8 )
      {
        v10 = v8;
        while ( ViThunkReplaceImportEntry(*v10 + 12, v7) != 1 )
        {
          v10 = &v8[++v9];
          if ( !*v10 )
            goto LABEL_11;
        }
        goto LABEL_21;
      }
    }
LABEL_11:
    if ( KernelVerifier )
    {
LABEL_17:
      if ( !ViThunkReplaceImportIfThunkedRegular(v7, &VfPoolThunks) && !a3 && a4 == 1 )
        ViThunkReplaceImportEntry(&ViVerifierDriverAddedThunkListHead, v7);
      goto LABEL_21;
    }
    if ( !ViThunkReplaceImportIfThunkedRegular(v7, &VfRegularThunks) )
    {
      v11 = &VfOrderDependentThunks;
      if ( VfOrderDependentThunks )
      {
        while ( *v7 != v11[2] )
        {
          v12 = v11[6];
          v11 += 6;
          if ( !v12 )
            goto LABEL_16;
        }
        if ( !a3 )
        {
          v14 = (int)v11[1];
LABEL_28:
          MmReplaceImportEntry((unsigned int)v7, v14);
          goto LABEL_21;
        }
        v14 = (int)v11[3];
        if ( v14 )
          goto LABEL_28;
      }
      else
      {
LABEL_16:
        if ( !ViThunkReplaceImportIfThunkedRegular(v7, &VfXdvThunks) )
          goto LABEL_17;
      }
    }
LABEL_21:
    ++v7;
    --v6;
  }
  if ( v8 )
    ExFreePoolWithTag((unsigned int)v8);
  return 1;
}

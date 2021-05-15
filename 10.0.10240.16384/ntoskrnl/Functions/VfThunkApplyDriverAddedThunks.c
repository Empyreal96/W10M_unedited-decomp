// VfThunkApplyDriverAddedThunks 
 
int __fastcall VfThunkApplyDriverAddedThunks(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int v5; // r5
  unsigned int v7; // r6
  _DWORD *i; // r4
  int v9; // r7
  _DWORD *v10; // r2
  int v11; // r0
  int v12[6]; // [sp+0h] [bp-18h] BYREF

  v12[0] = a3;
  v12[1] = a4;
  v4 = RtlImageDirectoryEntryToData(*(_DWORD *)(a1 + 24), 1, 12, (int)v12);
  v5 = v4;
  if ( !v4 )
    return 0;
  v7 = (unsigned int)v12[0] >> 2;
  for ( i = (_DWORD *)ViThunkFindAllSpecialTables(v4, (unsigned int)v12[0] >> 2); v7; --v7 )
  {
    if ( !i )
      goto LABEL_10;
    v9 = 0;
    if ( !*i )
      goto LABEL_10;
    v10 = i;
    do
    {
      v11 = ViThunkReplaceImportEntry(*v10 + 12, v5);
      if ( v11 == 1 )
        break;
      v10 = &i[++v9];
    }
    while ( *v10 );
    if ( !v11 )
LABEL_10:
      ViThunkReplaceImportEntry(&ViVerifierDriverAddedThunkListHead, v5);
    v5 += 4;
  }
  if ( i )
    ExFreePoolWithTag((unsigned int)i);
  return 1;
}

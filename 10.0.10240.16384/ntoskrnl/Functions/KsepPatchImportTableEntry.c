// KsepPatchImportTableEntry 
 
int __fastcall KsepPatchImportTableEntry(int *a1, unsigned int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // t1

  if ( !a1 || !a2 || !a3 || !a4 )
    return -1073741811;
  v4 = 0;
  if ( !(a2 >> 2) )
    return -1073741275;
  while ( 1 )
  {
    v5 = *a1++;
    if ( v5 == a3 )
      break;
    if ( ++v4 >= a2 >> 2 )
      return -1073741275;
  }
  MmReplaceImportEntry((unsigned int)(a1 - 1), a4);
  return 0;
}

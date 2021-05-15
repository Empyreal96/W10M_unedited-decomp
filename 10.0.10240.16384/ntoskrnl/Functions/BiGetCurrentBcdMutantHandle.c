// BiGetCurrentBcdMutantHandle 
 
int __fastcall BiGetCurrentBcdMutantHandle(_DWORD *a1)
{
  if ( !BcdMutantHandle )
    return sub_813BE8();
  *a1 = BcdMutantHandle;
  return 0;
}

// ViThunkRecoverPristines 
 
int __fastcall ViThunkRecoverPristines(int result)
{
  int v1; // r5
  unsigned int v2; // r6
  int i; // r4
  int v4; // r2
  int v5; // r2
  int v6; // r1
  int v7; // r2
  int v8; // r1
  int v9; // r2

  v1 = result;
  v2 = 0;
  for ( i = result + 16; v2 < *(_DWORD *)(v1 + 12); i += 8 )
  {
    result = ViThunkReplaceSpecialPristine(i);
    if ( result != 1 )
    {
      result = ViThunkReplacePristine(&VfRegularThunks, 20, i);
      if ( result != 1 )
      {
        result = ViThunkReplacePristine(&VfOrderDependentThunks, 24, v4);
        if ( result != 1 )
        {
          result = ViThunkReplacePristine(&VfPoolThunks, 20, v5);
          if ( result != 1 )
          {
            result = ViThunkReplacePristine(&VfMandatoryThunks, v6, v7);
            if ( result != 1 )
              result = ViThunkReplacePristine(&VfXdvThunks, v8, v9);
          }
        }
      }
    }
    ++v2;
  }
  return result;
}

// ViXdvSearchAllThunkArrays 
 
BOOL __fastcall ViXdvSearchAllThunkArrays(int a1, int a2)
{
  int v4; // r1
  int v5; // r1
  int v6; // r1

  return ViXdvSearchAndReplaceThunkArray(&VfXdvThunks, a2, a1, a2)
      || ViXdvSearchAndReplaceThunkArray(&VfPoolThunks, v4, a1, a2)
      || ViXdvSearchAndReplaceThunkArray(&VfMandatoryThunks, v5, a1, a2)
      || ViXdvSearchAndReplaceThunkArray(&VfRegularThunks, v6, a1, a2)
      || ViXdvSearchAndReplaceThunkArrayOrderDependent(0, a1, a2);
}

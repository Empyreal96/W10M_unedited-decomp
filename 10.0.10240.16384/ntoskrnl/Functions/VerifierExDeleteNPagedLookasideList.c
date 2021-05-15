// VerifierExDeleteNPagedLookasideList 
 
int __fastcall VerifierExDeleteNPagedLookasideList(int a1)
{
  ViLookasideDelete();
  return pXdvExDeleteNPagedLookasideList(a1);
}

// ExpDeleteMutant 
 
int __fastcall ExpDeleteMutant(int a1)
{
  return KeReleaseMutant(a1, 1);
}

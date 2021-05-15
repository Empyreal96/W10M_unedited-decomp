// PopUpdateSingleThreadHeteroPolicies 
 
int __fastcall PopUpdateSingleThreadHeteroPolicies(int a1, int a2)
{
  KeUpdateThreadHeteroPolicy(a2);
  return 0;
}

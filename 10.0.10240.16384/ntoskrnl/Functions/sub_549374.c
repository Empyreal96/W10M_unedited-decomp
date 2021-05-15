// sub_549374 
 
void sub_549374()
{
  int v0; // r5

  KfRaiseIrql(2);
  MiMapPageInHyperSpaceWorker((v0 - MmPfnDatabase) / 24, 0, 0);
  JUMPOUT(0x4C9FE8);
}

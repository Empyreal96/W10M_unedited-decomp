// PspDetachSession 
 
int __fastcall PspDetachSession(int a1, int a2, int a3, int a4)
{
  MmDetachSession(a1, a2, a3, a4);
  return ObfDereferenceObject(a1);
}

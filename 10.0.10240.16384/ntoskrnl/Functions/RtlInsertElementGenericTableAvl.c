// RtlInsertElementGenericTableAvl 
 
int __fastcall RtlInsertElementGenericTableAvl(int a1, int a2, int a3, int a4)
{
  FindNodeOrParent(a1);
  return RtlInsertElementGenericTableFullAvl(a1, a2, a3, a4);
}

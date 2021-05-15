// PspGetProcessInJobHierarchyCallback 
 
int __fastcall PspGetProcessInJobHierarchyCallback(int a1, int *a2)
{
  int result; // r0

  ObfReferenceObjectWithTag(a1);
  result = -1073741248;
  *a2 = a1;
  return result;
}

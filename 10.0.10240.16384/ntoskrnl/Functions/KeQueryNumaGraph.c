// KeQueryNumaGraph 
 
int KeQueryNumaGraph()
{
  int v0; // r5
  int v1; // r0
  int v2; // r4

  v0 = (unsigned __int16)KeNumberNodes * (unsigned __int16)KeNumberNodes;
  v1 = ExAllocatePoolWithTag(1, 2 * v0, 1634563406);
  v2 = v1;
  if ( v1 )
    memmove(v1, KiNodeGraph, 2 * v0);
  return v2;
}

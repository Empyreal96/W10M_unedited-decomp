// KeQueryMaximumProcessorCount 
 
int __fastcall KeQueryMaximumProcessorCount(int a1, int a2)
{
  return KeQueryMaximumProcessorCountEx(0, a2);
}

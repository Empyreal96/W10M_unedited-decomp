// SeClearLearningModeObjectInformation 
 
int __fastcall SeClearLearningModeObjectInformation(int a1)
{
  unsigned int v1; // r4
  int result; // r0

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  __mrc(15, 0, 13, 0, 3);
  result = KeGetCurrentIrql(a1);
  if ( *(_DWORD *)(v1 + 1040) )
    result = sub_52E6DC();
  return result;
}

// EtwpInitializeProviderTraits 
 
int EtwpInitializeProviderTraits()
{
  int result; // r0

  KeInitializeGuardedMutex((int)&EtwpProviderTraitsKmMutex);
  EtwpProviderTraitsKmTree[0] = 0;
  EtwpProviderTraitsKmTree[1] = 0;
  result = KeInitializeGuardedMutex((int)&EtwpProviderTraitsUmMutex);
  EtwpProviderTraitsUmTree = 0;
  unk_61A984 = 0;
  return result;
}

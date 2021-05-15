// PiGetProviderList 
 
void *__fastcall PiGetProviderList(int a1)
{
  int v1; // r3
  void *result; // r0

  if ( a1 )
    v1 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 44);
  else
    v1 = 0;
  if ( v1 )
    result = (void *)(v1 + 8);
  else
    result = &PiDependencyNodeEmptyList;
  return result;
}

// IopDeleteDevice 
 
int __fastcall IopDeleteDevice(_DWORD *a1)
{
  int v2; // r0
  int result; // r0
  unsigned int *v4; // r2
  unsigned int v5; // r0

  IoDeleteAllDependencyRelations(a1);
  v2 = IopDestroyDeviceNode(*(_DWORD *)(a1[44] + 20));
  if ( (*(_DWORD *)(a1[44] + 16) & 0x1000) != 0 )
    return sub_7CA618(v2);
  __dmb(0xBu);
  v4 = a1 + 9;
  do
    v5 = __ldrex(v4);
  while ( __strex(0, v4) );
  __dmb(0xBu);
  if ( v5 )
    ExFreePoolWithTag(v5);
  result = a1[2];
  if ( result )
    result = ObfDereferenceObject(result);
  return result;
}

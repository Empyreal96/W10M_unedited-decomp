// sub_80B344 
 
void sub_80B344()
{
  unsigned int v0; // r7
  unsigned int v1; // r0

  ZwSetValueKey();
  v1 = *(_DWORD *)(v0 + 4);
  if ( v1 )
    ExFreePool(v1);
  RtlInitUnicodeString(v0, 0);
  JUMPOUT(0x78F64E);
}

// sub_5273F4 
 
void sub_5273F4()
{
  int v0; // r7
  int v1; // r4
  int v2; // r3

  v1 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v2 = *(_DWORD *)(v1 + 0x420);
  if ( v2 )
  {
    if ( (v2 & v0) != 0 )
      KeSetThreadChargeOnlySchedulingGroup(v1, 0);
    ObfDereferenceObjectWithTag(*(_DWORD *)(v1 + 1056) & ~v0);
    *(_DWORD *)(v1 + 1056) = 0;
  }
  JUMPOUT(0x4D8298);
}

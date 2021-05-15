// sub_96A0D0 
 
void sub_96A0D0()
{
  int v0; // r6
  unsigned __int16 *v1; // r7
  int v2; // r0
  unsigned int v3; // r5

  v2 = KeQueryNumaGraph();
  v3 = v2;
  if ( v2 )
  {
    memmove(*(_DWORD *)(v0 + 3428), v2, 2 * *v1 * *v1);
    ExFreePoolWithTag(v3);
  }
  JUMPOUT(0x9544DC);
}

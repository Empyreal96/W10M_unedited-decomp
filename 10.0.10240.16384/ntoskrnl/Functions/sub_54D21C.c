// sub_54D21C 
 
void sub_54D21C()
{
  int v0; // r5
  int v1; // r0

  v1 = *(_DWORD *)(v0 + 104);
  if ( v1 )
    KeSetEvent(v1, 0, 0);
  JUMPOUT(0x4D7400);
}

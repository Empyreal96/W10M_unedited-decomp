// sub_7EB384 
 
void sub_7EB384()
{
  int v0; // r4
  _DWORD *v1; // r1
  unsigned int *v2; // r2
  unsigned int v3; // r1

  v1 = *(_DWORD **)(v0 + 4 * MiWsSwapPageFileNumber(v0) + 3600);
  if ( v1[3] >= 0x10000u && v1[6] >= 0x10000u && (unsigned int)(*v1 - 0x10000) >= v1[2] )
  {
    v2 = (unsigned int *)(v0 + 648);
    do
      v3 = __ldrex(v2);
    while ( !v3 && __strex(1u, v2) );
    if ( !v3 )
      ExQueueWorkItem((_DWORD *)(v0 + 632), 3);
  }
  JUMPOUT(0x70812C);
}

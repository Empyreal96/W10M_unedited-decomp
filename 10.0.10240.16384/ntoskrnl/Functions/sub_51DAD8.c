// sub_51DAD8 
 
void sub_51DAD8()
{
  int v0; // r5
  int v1; // r6
  int v2; // r9
  int i; // r4
  int v4; // r3

  v2 = *(_DWORD *)(*(_DWORD *)(v0 + 16) + 4);
  v1 = **(_DWORD **)(v0 + 16);
  for ( i = 8 * (v1 + 1); v1; --v1 )
  {
    v4 = *(_DWORD *)(v2 + 4);
    v2 += 8;
    i += (4 * *(unsigned __int8 *)(v4 + 1) + 11) & 0xFFFFFFFC;
  }
  JUMPOUT(0x4E0B38);
}

// sub_80686C 
 
void sub_80686C()
{
  int v0; // r5
  int v1; // r6
  int v2; // r8
  unsigned int v3; // r9
  int v4; // r0
  unsigned int v5; // r2

  if ( (*(_DWORD *)(v2 + 28) & 0x4000000) != 0 )
  {
    if ( *(_DWORD *)(v1 + 12) )
    {
      v4 = MiGetSharedProtos(v2, v0, v1);
      if ( v4 )
      {
        v5 = *(_DWORD *)(v4 + 16);
        if ( v3 >= v5 && v3 < v5 + 4 * *(_DWORD *)(v1 + 28) )
          JUMPOUT(0x7545C8);
      }
    }
  }
  JUMPOUT(0x75462C);
}

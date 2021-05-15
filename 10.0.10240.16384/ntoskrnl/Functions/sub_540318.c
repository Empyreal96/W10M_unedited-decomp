// sub_540318 
 
void sub_540318()
{
  int v0; // r7
  unsigned int v1; // r0
  unsigned int v2; // r1
  int v3; // r2

  v1 = *(_DWORD *)(v0 + 120);
  v2 = 0;
  if ( v1 )
  {
    v3 = v0;
    do
    {
      if ( *(_DWORD *)(v3 + 200) )
        JUMPOUT(0x4AC11A);
      ++v2;
      v3 += 168;
    }
    while ( v2 < v1 );
  }
  PopPepGetReadyActivityType(v0 + 48, 4, 5);
  JUMPOUT(0x4AC17A);
}

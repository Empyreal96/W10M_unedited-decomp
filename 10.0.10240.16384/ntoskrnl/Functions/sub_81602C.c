// sub_81602C 
 
void __fastcall sub_81602C(int a1, int a2)
{
  unsigned int v2; // lr
  unsigned int *v3; // r2
  unsigned int v4; // r4
  unsigned int v5; // r6
  unsigned int v6; // r5

  v3 = (unsigned int *)(*(_DWORD *)(a2 + 16) + a1);
  *(_DWORD *)(a2 + 16) = v3;
  v4 = *v3;
  if ( *v3 )
  {
    v5 = 0;
    v6 = v3[1] + a1;
    v3[1] = v6;
    if ( v4 )
    {
      do
      {
        ++v5;
        *(_DWORD *)(v6 + 8) += a1;
        v6 += 12;
      }
      while ( v5 < *v3 );
    }
  }
  else
  {
    v3[1] = v2;
  }
  JUMPOUT(0x7ACC24);
}

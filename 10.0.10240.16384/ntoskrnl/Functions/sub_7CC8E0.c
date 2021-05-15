// sub_7CC8E0 
 
void sub_7CC8E0()
{
  int v0; // r5
  int v1; // r6
  _DWORD *v2; // r4

  if ( v0 )
  {
    v2 = (_DWORD *)v1;
    do
    {
      if ( v2[7] )
        KsepStringFree(v2 + 6);
      if ( v2[5] )
        KsepStringFree(v2 + 4);
      if ( v2[9] )
        KsepStringFree(v2 + 8);
      v2 += 13;
      --v0;
    }
    while ( v0 );
  }
  KsepPoolFreePaged(v1);
  JUMPOUT(0x7702F2);
}

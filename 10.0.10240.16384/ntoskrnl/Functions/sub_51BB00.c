// sub_51BB00 
 
void sub_51BB00()
{
  int v0; // r4
  int v1; // r5
  int v2; // r5

  if ( v0 )
  {
    v2 = v1 + 4 * v0;
    do
    {
      v2 -= 4;
      ZwClose();
      --v0;
    }
    while ( v0 );
  }
  JUMPOUT(0x444120);
}

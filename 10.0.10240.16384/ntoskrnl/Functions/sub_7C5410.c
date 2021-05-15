// sub_7C5410 
 
void sub_7C5410()
{
  int v0; // r5
  unsigned int v1; // r7
  int v2; // r8
  unsigned int v3; // r6

  if ( v0 )
  {
    v3 = 0;
    if ( !v1 )
LABEL_8:
      JUMPOUT(0x6C29AE);
    while ( SepPotentialGlobalTableAttribute(v0) && !SeSecurityAttributePresent(v2, v0) )
    {
      ++v3;
      v0 += 8;
      if ( v3 >= v1 )
        goto LABEL_8;
    }
  }
  JUMPOUT(0x6C29AC);
}

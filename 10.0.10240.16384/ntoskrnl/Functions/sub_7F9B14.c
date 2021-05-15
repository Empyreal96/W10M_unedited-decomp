// sub_7F9B14 
 
void sub_7F9B14()
{
  int v0; // r5
  int v1; // r7
  int v2; // r9

  if ( SepUpdateSiloInClientSecurity(v1, v0) < 0 )
    ObfDereferenceObject(v2);
  JUMPOUT(0x725B68);
}

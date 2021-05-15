// sub_5477D8 
 
void sub_5477D8()
{
  _DWORD *v0; // r5

  if ( *v0 )
  {
    KeSelectNodeForAffinity();
    JUMPOUT(0x4C44E4);
  }
  JUMPOUT(0x4C44D2);
}

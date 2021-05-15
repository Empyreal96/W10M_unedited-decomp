// sub_53DA7C 
 
void sub_53DA7C()
{
  int v0; // r6
  _BYTE *v1; // r0

  if ( !v0 )
  {
    v1 = (_BYTE *)ExAllocatePoolWithTag(512, 32);
    if ( v1 )
    {
      memset(v1, 0, 32);
      JUMPOUT(0x4A463A);
    }
    JUMPOUT(0x4A45FC);
  }
  JUMPOUT(0x4A4622);
}

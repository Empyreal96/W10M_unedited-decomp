// sub_7E0B68 
 
void sub_7E0B68()
{
  unsigned int *v0; // r4
  unsigned int *v1; // r6
  unsigned int v2; // r9
  unsigned int v3; // r8
  int v4; // r7

  if ( *v0 )
  {
    v3 = 0;
    if ( *v1 )
    {
      v4 = 0;
      do
      {
        ExFreePoolWithTag(*(_DWORD *)(*v0 + v4 + 36));
        ++v3;
        v4 += 40;
      }
      while ( v3 < *v1 );
    }
    ExFreePoolWithTag(*v0);
    *v1 = v2;
    *v0 = v2;
  }
  JUMPOUT(0x7777A6);
}

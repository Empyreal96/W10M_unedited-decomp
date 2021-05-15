// sub_7E7134 
 
void sub_7E7134()
{
  int v0; // r4
  _WORD *v1; // r5
  _DWORD *v2; // r7
  _WORD *v3; // r0

  if ( *v1 )
  {
    v3 = (_WORD *)ExAllocatePoolWithTag(1, 2, 1970499664);
    if ( v3 )
    {
      *v3 = 0;
      *v2 = v3;
      if ( v0 )
        JUMPOUT(0x6F4228);
      JUMPOUT(0x6F41FE);
    }
    JUMPOUT(0x6F4230);
  }
  JUMPOUT(0x6F4216);
}

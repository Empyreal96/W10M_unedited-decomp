// sub_7CFF50 
 
void sub_7CFF50()
{
  int v0; // r4
  int v1; // r0

  if ( !*(_DWORD *)(v0 + 1884) )
  {
    v1 = ExAllocatePoolWithTag(512, 1024, 2004042563);
    *(_DWORD *)(v0 + 1884) = v1;
    if ( !v1 )
      JUMPOUT(0x789C86);
  }
  JUMPOUT(0x789C7C);
}

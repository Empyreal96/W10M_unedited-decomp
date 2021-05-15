// WmiVerifierCopyEvent 
 
int __fastcall WmiVerifierCopyEvent(unsigned int *a1)
{
  unsigned int v2; // r6
  int v3; // r0
  int v4; // r4

  v2 = *a1;
  v3 = ExAllocatePoolWithTag(512, *a1);
  v4 = v3;
  if ( v3 )
    memmove(v3, (int)a1, v2);
  return v4;
}

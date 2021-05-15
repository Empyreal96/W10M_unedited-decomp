// sub_7C1D40 
 
void sub_7C1D40()
{
  int v0; // r5
  _DWORD *v1; // r8
  int v2; // r10
  int v3; // r4

  if ( v2 != 2 )
  {
    if ( v2 != 3 )
      JUMPOUT(0x6AA778);
    v3 = v1[72];
    __dmb(0xBu);
    PspUnlinkJobProcess(v3, (int)v1);
    MmLinkJobProcess(v0, v1);
    ObfReferenceObject(v0);
    ObfDereferenceObject(v3);
  }
  JUMPOUT(0x6AA770);
}

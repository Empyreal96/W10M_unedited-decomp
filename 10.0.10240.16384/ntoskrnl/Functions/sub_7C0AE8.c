// sub_7C0AE8 
 
void sub_7C0AE8()
{
  int v0; // r5
  int v1; // r6
  int v2; // r3
  int v3; // r0

  v2 = *(_DWORD *)(v0 + 576);
  __dmb(0xBu);
  if ( v2 == v0 )
  {
    v3 = *(_DWORD *)(v0 + 592);
    if ( v3 )
    {
      ObfDereferenceObject(v3);
      *(_DWORD *)(v0 + 592) = v1;
    }
  }
  JUMPOUT(0x6A8566);
}

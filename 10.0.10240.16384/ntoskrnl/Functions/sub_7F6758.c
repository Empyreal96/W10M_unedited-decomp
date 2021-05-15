// sub_7F6758 
 
void sub_7F6758()
{
  int v0; // r5
  int v1; // r6

  if ( *(_DWORD *)(v0 + 244) )
    SeDeassignPrimaryToken(v0);
  ObfReferenceObject(v1);
  *(_BYTE *)(v1 + 180) = 1;
  ObInitializeFastReference(v0 + 244, v1);
  JUMPOUT(0x719C34);
}

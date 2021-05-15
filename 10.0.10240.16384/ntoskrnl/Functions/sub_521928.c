// sub_521928 
 
void sub_521928()
{
  _DWORD *v0; // r4
  _DWORD *v1; // r5
  _DWORD *v2; // r0

  v2 = (_DWORD *)RtlSubtreePredecessor((int)v0);
  if ( (_DWORD *)*v0 == v0 )
    *v1 = v2;
  SwapSplayLinks(v2, v0);
  JUMPOUT(0x455E5E);
}

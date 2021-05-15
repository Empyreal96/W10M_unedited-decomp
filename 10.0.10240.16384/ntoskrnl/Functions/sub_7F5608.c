// sub_7F5608 
 
void sub_7F5608()
{
  int v0; // r5
  int v1; // r6
  int v2; // r8
  int *v3; // r10
  _DWORD *v4; // r0
  int v5; // r3

  if ( !v2 && (*(_DWORD *)(v1 + 736) & 1) == 0 )
  {
    v4 = (_DWORD *)MiAllocateVad(v0, 2147418111);
    if ( !v4 )
      JUMPOUT(0x7163AE);
    v5 = *v3;
    *v3 = (int)v4;
    *v4 = v5;
  }
  JUMPOUT(0x716388);
}

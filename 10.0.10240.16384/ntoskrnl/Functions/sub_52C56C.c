// sub_52C56C 
 
void sub_52C56C()
{
  int v0; // r5
  int v1; // r6
  int v2; // r2

  v2 = (*(_DWORD *)(v0 + 88) >> 12) & 3;
  if ( !v2 || v2 == 1 && v1 )
    JUMPOUT(0x471FD0);
  JUMPOUT(0x472024);
}

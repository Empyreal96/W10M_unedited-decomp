// sub_7F36B4 
 
void sub_7F36B4()
{
  int v0; // r4
  int v1; // r5

  if ( *(_DWORD *)(v0 + 16) == v1 )
    IopCleanupFileObjectIosbRange(v0);
  JUMPOUT(0x70D66A);
}

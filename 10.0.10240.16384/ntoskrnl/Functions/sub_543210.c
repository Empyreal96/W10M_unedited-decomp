// sub_543210 
 
void sub_543210()
{
  int v0; // r5

  if ( *(_QWORD *)(v0 + 16) != (*(_DWORD *)(v0 + 16) & 1) )
    JUMPOUT(0x4B6DF2);
  JUMPOUT(0x4B6DF4);
}

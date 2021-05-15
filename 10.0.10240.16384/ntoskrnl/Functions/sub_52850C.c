// sub_52850C 
 
void sub_52850C()
{
  int v0; // r4

  if ( *(_DWORD *)(v0 + 12) >= 4u )
  {
    *(_DWORD *)(v0 + 12) = 4;
    *(_DWORD *)(v0 + 16) = 0;
    JUMPOUT(0x4DDD96);
  }
  JUMPOUT(0x4DDDB2);
}

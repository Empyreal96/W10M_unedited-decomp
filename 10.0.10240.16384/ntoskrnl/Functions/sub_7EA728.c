// sub_7EA728 
 
void sub_7EA728()
{
  int v0; // r5
  int v1; // lr
  int v2; // r2
  int v3; // r3

  if ( !v1 )
  {
    CmpLockRegistry();
    ExAcquireResourceExclusiveLite(*(_DWORD *)(v0 + 1872), 1, v2, v3);
  }
  JUMPOUT(0x7059BA);
}

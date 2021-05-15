// sub_529754 
 
void sub_529754()
{
  int v0; // r6

  if ( *(_DWORD *)(v0 + 68) == *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) )
  {
    PopAcquirePowerRequestPushLock(1);
    JUMPOUT(0x466CC0);
  }
  JUMPOUT(0x466D2C);
}

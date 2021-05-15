// sub_52981C 
 
void sub_52981C()
{
  int v0; // r7

  if ( *(_DWORD *)(v0 + 68) == *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) )
  {
    PopAcquirePowerRequestPushLock(1);
    JUMPOUT(0x466E72);
  }
  JUMPOUT(0x466EF6);
}

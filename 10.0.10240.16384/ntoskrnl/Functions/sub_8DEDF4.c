// sub_8DEDF4 
 
void sub_8DEDF4()
{
  _DWORD *v0; // r4
  int v1; // r5
  int v2; // r0
  unsigned int *v3; // r2
  unsigned int v4; // r1

  v1 = BgpFwAllocateMemory(v0[41]);
  if ( v1 )
  {
    BgpFwReleaseLock();
    v2 = memmove(v1, v0[40], v0[41]);
    BgpFwAcquireLock(v2);
    if ( v0[39] )
    {
      BgpFwFreeMemory(v1);
    }
    else
    {
      __dmb(0xBu);
      v3 = v0 + 39;
      do
        v4 = __ldrex(v3);
      while ( __strex(v1, v3) );
      __dmb(0xBu);
    }
  }
  JUMPOUT(0x8DD186);
}

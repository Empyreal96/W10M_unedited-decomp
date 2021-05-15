// sub_8DF728 
 
void sub_8DF728()
{
  _DWORD *v0; // r4
  int v1; // r0
  unsigned int *v2; // r2
  unsigned int v3; // r1
  unsigned int v4; // r5
  unsigned int *v5; // r2
  unsigned int v6; // r1
  unsigned int v7; // r0

  v1 = v0[39];
  if ( v1 )
  {
    __dmb(0xBu);
    v2 = v0 + 39;
    do
      v3 = __ldrex(v2);
    while ( __strex(0, v2) );
    __dmb(0xBu);
    BgpFwFreeMemory(v1);
  }
  v4 = v0[40];
  if ( v4 )
  {
    __dmb(0xBu);
    v5 = v0 + 40;
    do
      v6 = __ldrex(v5);
    while ( __strex(0, v5) );
    __dmb(0xBu);
    BgpFwReleaseLock();
    v7 = ExFreePoolWithTag(v4);
    BgpFwAcquireLock(v7);
  }
  v0[41] = 0;
  JUMPOUT(0x8DDCD8);
}

// sub_7E9904 
 
void sub_7E9904()
{
  _DWORD *v0; // r4
  int v1; // r5
  int v2; // r7
  int v3; // r4
  unsigned int v4; // r1
  unsigned int *v5; // r2
  unsigned int v6; // r0

  if ( *v0 != v1 )
  {
    v3 = KeAbPreAcquire((unsigned int)&dword_618E28, 0, 0);
    do
      v4 = __ldrex((unsigned __int8 *)&dword_618E28);
    while ( __strex(v4 | 1, (unsigned __int8 *)&dword_618E28) );
    __dmb(0xBu);
    if ( (v4 & v2) != 0 )
      ExfAcquirePushLockExclusiveEx(&dword_618E28, v3, (unsigned int)&dword_618E28);
    if ( v3 )
      *(_BYTE *)(v3 + 14) |= v2;
    __dmb(0xBu);
    v5 = (unsigned int *)(v1 + 744);
    do
      v6 = __ldrex(v5);
    while ( __strex(v6 | 0x100, v5) );
    __dmb(0xBu);
  }
  JUMPOUT(0x70341A);
}

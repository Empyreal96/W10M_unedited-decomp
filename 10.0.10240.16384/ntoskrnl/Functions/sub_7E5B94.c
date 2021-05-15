// sub_7E5B94 
 
void sub_7E5B94()
{
  int v0; // r5
  _DWORD *v1; // r7
  int v2; // r10
  unsigned __int8 *v3; // r6
  int v4; // r0
  int v5; // r8
  unsigned int v6; // r2
  __int64 v7; // r2
  unsigned int v8; // r1

  if ( (v1[61] & 0x40) == 0 )
  {
    v3 = (unsigned __int8 *)(v1 + 23);
    ++*(_WORD *)(v0 - 14);
    v4 = KeAbPreAcquire((unsigned int)(v1 + 23), 0, 0);
    v5 = v4;
    do
      v6 = __ldrex(v3);
    while ( __strex(v6 | 1, v3) );
    __dmb(0xBu);
    if ( (v6 & v2) != 0 )
      ExfAcquirePushLockExclusiveEx(v1 + 23, v4, (unsigned int)(v1 + 23));
    if ( v5 )
      *(_BYTE *)(v5 + 14) |= v2;
    LODWORD(v7) = v1 + 56;
    HIDWORD(v7) = v1[57];
    *(_QWORD *)(v0 + 44) = v7;
    *(_DWORD *)v1[57] = v0 + 44;
    v1[57] = v0 + 44;
    ++v1[69];
    __dmb(0xBu);
    do
      v8 = __ldrex((unsigned int *)v3);
    while ( __strex(v8 - 1, (unsigned int *)v3) );
    if ( (v8 & 2) != 0 )
      JUMPOUT(0x6F0798);
    JUMPOUT(0x6F0754);
  }
  *(_DWORD *)(v0 + 32) = 0;
  *(_DWORD *)(v0 + 36) = 0;
  JUMPOUT(0x6F075A);
}

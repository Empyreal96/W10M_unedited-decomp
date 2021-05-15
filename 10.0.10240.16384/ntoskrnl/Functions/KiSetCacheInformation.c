// KiSetCacheInformation 
 
void KiSetCacheInformation()
{
  unsigned int v0; // r1
  unsigned int v1; // r3
  unsigned int v2; // r5
  unsigned int v3; // r4
  unsigned int v4; // r2
  int v5; // r3
  unsigned int v6; // r0

  v0 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  v1 = (unsigned int)KeGetPcr();
  v2 = (v1 & 0xFFFFF000) + 1408;
  v3 = 0;
  v4 = (v1 & 0xFFFFF000) + 4912;
  if ( *(_BYTE *)((v1 & 0xFFFFF000) + 0x1378) )
  {
    do
    {
      v5 = *(_DWORD *)(v4 + 8);
      if ( v5 == 2 || !v5 )
      {
        v6 = *(_DWORD *)(v4 + 4);
        if ( v6 > *(_DWORD *)(v0 + 124) )
        {
          *(_DWORD *)(v0 + 124) = v6;
          *(_BYTE *)(v0 + 29) = *(_BYTE *)(v4 + 1);
        }
      }
      ++v3;
      v4 += 12;
    }
    while ( v3 < *(unsigned __int8 *)(v2 + 3576) );
  }
}

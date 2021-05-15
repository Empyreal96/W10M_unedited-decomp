// ExAllocateCacheAwarePushLock 
 
int __fastcall ExAllocateCacheAwarePushLock(char a1)
{
  int v1; // r6
  int v2; // r4
  int v3; // r0
  int *v5; // r3
  int v6; // r2

  if ( (a1 & 1) != 0 )
    v1 = 512;
  else
    v1 = 1;
  v2 = ExAllocatePoolWithTag(v1, 128);
  if ( v2 )
  {
    if ( KeNumberNodes != 1 )
      JUMPOUT(0x554892);
    v3 = ExAllocatePoolWithTag(v1, 4096);
    if ( !v3 )
      return sub_554888();
    v5 = (int *)v2;
    v6 = 32;
    do
    {
      *(_BYTE *)(v3 + 4) = 1;
      *(_DWORD *)(v3 + 8) = v2;
      *(_DWORD *)v3 = 0;
      *v5++ = v3;
      v3 += 128;
      --v6;
    }
    while ( v6 );
  }
  return v2;
}

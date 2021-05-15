// sub_7F46A8 
 
void sub_7F46A8()
{
  int v0; // r8
  unsigned int v1; // r3
  unsigned int v2; // r6
  int v3; // r4
  int v4; // r0

  if ( v0 )
  {
    v1 = (unsigned int)KeGetPcr();
    v2 = (v1 & 0xFFFFF000) + 1408;
    v3 = *(_DWORD *)((v1 & 0xFFFFF000) + 0xB40);
    ++*(_DWORD *)(v3 + 12);
    if ( !RtlpInterlockedPopEntrySList((unsigned __int64 *)v3) )
    {
      ++*(_DWORD *)(v3 + 16);
      v4 = *(_DWORD *)(v2 + 1476);
      ++*(_DWORD *)(v4 + 12);
      if ( !RtlpInterlockedPopEntrySList((unsigned __int64 *)v4) )
        JUMPOUT(0x7132AC);
    }
    JUMPOUT(0x7132CA);
  }
  JUMPOUT(0x7132A8);
}

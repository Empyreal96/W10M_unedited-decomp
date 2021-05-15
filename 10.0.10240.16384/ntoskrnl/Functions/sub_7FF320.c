// sub_7FF320 
 
void sub_7FF320()
{
  _DWORD *v0; // r4
  unsigned int v1; // r3
  int v2; // r5
  unsigned int v3; // r2
  unsigned int v4; // r2

  v1 = (unsigned int)KeGetPcr();
  v2 = *(_DWORD *)((v1 & 0xFFFFF000) + 0xB20);
  v3 = *(unsigned __int16 *)(v2 + 8);
  ++*(_DWORD *)(v2 + 20);
  if ( *(unsigned __int16 *)(v2 + 4) < v3
    || (++*(_DWORD *)(v2 + 24),
        v2 = *(_DWORD *)((v1 & 0xFFFFF000) + 0xB24),
        v4 = *(unsigned __int16 *)(v2 + 8),
        ++*(_DWORD *)(v2 + 20),
        *(unsigned __int16 *)(v2 + 4) < v4) )
  {
    RtlpInterlockedPushEntrySList((unsigned __int64 *)v2, v0);
  }
  else
  {
    ++*(_DWORD *)(v2 + 24);
    (*(void (__fastcall **)(_DWORD *))(v2 + 44))(v0);
  }
  JUMPOUT(0x7365CE);
}

// SdbpGetNextTagId 
 
int __fastcall SdbpGetNextTagId(int a1, int a2)
{
  int v4; // r2
  int v5; // r3
  int v7; // r6
  unsigned int v8; // r0

  v5 = SdbGetTagFromTagID(a1, a2) & 0xF000;
  if ( v5 == 28672 && SdbGetTagDataSize(a1, a2) == -1 )
    return sub_7CCC58();
  v7 = SdbpGetTagHeadSize(a1, a2, v4, v5);
  if ( !v7 )
    return *(_DWORD *)(a1 + 12);
  v8 = SdbGetTagDataSize(a1, a2);
  if ( (*(_DWORD *)(a1 + 1328) & 1) == 0 )
    v8 = (v8 + 1) & 0xFFFFFFFE;
  return v8 + v7 + a2;
}

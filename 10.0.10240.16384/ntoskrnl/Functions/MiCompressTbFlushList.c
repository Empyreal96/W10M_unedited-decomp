// MiCompressTbFlushList 
 
int __fastcall MiCompressTbFlushList(int result)
{
  int v1; // r5
  unsigned int *v2; // r1
  unsigned int v3; // lr
  unsigned int *v4; // r7
  unsigned int v5; // r4
  unsigned int v6; // r6
  int v7; // r8
  unsigned int v8; // r3

  v1 = 0;
  v2 = (unsigned int *)(result + 20);
  v3 = 1;
  if ( *(_DWORD *)(result + 12) > 1u )
  {
    v4 = (unsigned int *)(result + 24);
    do
    {
      v5 = *v4;
      if ( ((*v4 >> 11) & 1) == 0 )
      {
        v6 = *v2;
        if ( ((*v2 >> 11) & 1) == 0 )
        {
          v7 = *v2 & 0x7FF;
          if ( (v5 & 0xFFFFF000) - (v7 << 12) - (v6 & 0xFFFFF000) != 4096 || v7 == 2047 )
          {
            *++v2 = v5;
          }
          else
          {
            if ( (*v4 & 0x7FF) + v7 + 1 > 0x7FF )
              return sub_5235A8();
            *v2 = v6 & 0xFFFFF800 | (v5 + v6 + 1) & 0x7FF;
            ++v1;
          }
        }
      }
      v8 = *(_DWORD *)(result + 12);
      ++v3;
      ++v4;
    }
    while ( v3 < v8 );
    if ( v1 )
      *(_DWORD *)(result + 12) = v8 - v1;
  }
  return result;
}

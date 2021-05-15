// EtwpCopySchematizedFilters 
 
int __fastcall EtwpCopySchematizedFilters(int result, int a2, int a3)
{
  int v3; // r4
  char v4; // r7
  unsigned int v5; // r5
  int v6; // r9
  int v7; // r10
  int v8; // r6
  int v9; // r8
  unsigned int v10; // r3
  int v11; // [sp+0h] [bp-20h]

  v3 = 0;
  v4 = 0;
  v5 = 0;
  v11 = a3;
  v6 = a2;
  v7 = result;
  v8 = a2;
  do
  {
    if ( *(_DWORD *)(v8 + 88) )
    {
      v9 = *(_DWORD *)(*(_DWORD *)(v6 + 344) + v5 + 32);
      if ( v9 )
      {
        if ( ((1 << v4) & a3) != 0 )
        {
          result = memmove(v7, *(_DWORD *)(*(_DWORD *)(v6 + 344) + v5 + 32), *(_DWORD *)(v9 + 16));
          a3 = v11;
          v3 = v7;
          v10 = (*(_DWORD *)(v9 + 16) + 7) & 0xFFFFFFF8;
          *(_DWORD *)(v7 + 20) = v10;
          v7 += v10;
        }
      }
    }
    v5 += 36;
    ++v4;
    v8 += 32;
  }
  while ( v5 < 0x120 );
  if ( v3 )
    *(_DWORD *)(v3 + 20) = 0;
  return result;
}

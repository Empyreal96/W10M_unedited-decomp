// RaspCreatePointList 
 
int __fastcall RaspCreatePointList(int a1, _DWORD *a2)
{
  _BYTE *v4; // r0
  _BYTE *v5; // r4
  unsigned int v6; // r1
  _BYTE *v7; // r2
  int v8; // r3

  v4 = (_BYTE *)RaspAllocateMemory(17 * *(unsigned __int16 *)(a1 + 24));
  v5 = v4;
  if ( !v4 )
    return -1073741670;
  memset(v4, 0, 17 * *(unsigned __int16 *)(a1 + 24));
  v6 = 0;
  if ( *(_WORD *)(a1 + 24) )
  {
    v7 = v5;
    do
    {
      *(_DWORD *)v7 = *(_DWORD *)(*(_DWORD *)(a1 + 38) + 4 * v6);
      *((_DWORD *)v7 + 1) = *(_DWORD *)(*(_DWORD *)(a1 + 42) + 4 * v6);
      v8 = *(_DWORD *)(a1 + 34);
      if ( v8 )
      {
        if ( (*(_BYTE *)(v8 + v6) & 1) != 0 )
          v7[16] = 1;
      }
      ++v6;
      v7 += 17;
    }
    while ( v6 < *(unsigned __int16 *)(a1 + 24) );
  }
  *a2 = v5;
  return 0;
}

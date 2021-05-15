// HvpAllocateMap 
 
int __fastcall HvpAllocateMap(int a1, int a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // r4
  _DWORD *i; // r6
  _BYTE *v8; // r0
  _BYTE *v9; // r7

  v5 = a3;
  if ( a4 < 0x400 )
  {
    if ( a3 > a4 )
      return 1;
    for ( i = (_DWORD *)(a2 + 4 * a3); ; ++i )
    {
      v8 = (_BYTE *)(*(int (__fastcall **)(int, _DWORD, int))(a1 + 12))(10240, 0, 959597891);
      v9 = v8;
      if ( !v8 )
        break;
      memset(v8, 0, 10240);
      ++v5;
      *i = v9;
      if ( v5 > a4 )
        return 1;
    }
  }
  return 0;
}

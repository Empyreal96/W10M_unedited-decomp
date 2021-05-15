// KiAbCleanupThreadState 
 
int __fastcall KiAbCleanupThreadState(int result)
{
  unsigned int v1; // r1
  int v2; // r2

  if ( (*(_DWORD *)(result + 76) & 1) != 0 )
  {
    v1 = 0;
    v2 = result + 488;
    do
    {
      if ( *(_DWORD *)(v2 + 16) )
        JUMPOUT(0x52AFE0);
      if ( (*(_DWORD *)(v2 + 12) & 0xFFFFFF00) != 0 )
        JUMPOUT(0x52AFDC);
      if ( result != v2 - 8 * *(unsigned __int8 *)(v2 + 12) )
        JUMPOUT(0x52AFD8);
      if ( *(_WORD *)(v2 + 44) )
        sub_52AFD4();
      ++v1;
      v2 += 48;
    }
    while ( v1 < 6 );
  }
  return result;
}

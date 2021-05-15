// ObpDestroyStackAndObjectTables 
 
unsigned int __fastcall ObpDestroyStackAndObjectTables(unsigned int a1, unsigned int a2, _DWORD *a3)
{
  int v4; // r2
  unsigned __int16 i; // r8
  unsigned int v8; // r0
  unsigned int v9; // r4
  int v10; // r2
  unsigned __int16 v11; // r4
  unsigned int v12; // r0
  unsigned int result; // r0

  v4 = 0;
  for ( i = 0; i < 0x191u; v4 = ++i )
  {
    v8 = *(_DWORD *)(a2 + 4 * v4);
    if ( v8 )
    {
      do
      {
        v9 = *(_DWORD *)(v8 + 4);
        ExFreePoolWithTag(v8);
        v8 = v9;
      }
      while ( v9 );
    }
  }
  ExFreePoolWithTag(a2);
  v10 = 0;
  if ( (*(_WORD *)(a1 + 2) & 0xFC00) != 0 )
  {
    v11 = 0;
    do
    {
      ExFreePoolWithTag(*(_DWORD *)(a1 + 4 * v10 + 4));
      v10 = ++v11;
    }
    while ( v11 < (unsigned int)(*(unsigned __int16 *)(a1 + 2) >> 10) );
  }
  v12 = a1;
  while ( 1 )
  {
    result = ExFreePoolWithTag(v12);
    if ( !a3 )
      break;
    v12 = (unsigned int)a3;
    a3 = (_DWORD *)*a3;
  }
  return result;
}

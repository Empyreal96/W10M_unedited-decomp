// EtwpGetDirectMappingCount 
 
int __fastcall EtwpGetDirectMappingCount(int a1, unsigned int a2, int a3, int a4, char a5)
{
  int result; // r0
  int v7; // r4
  unsigned __int16 i; // r5
  int v10; // r4
  unsigned __int16 j; // r5
  unsigned __int16 v12; // r2
  int v13; // r4

  result = 0;
  v7 = 0;
  for ( i = 0; i < 0x80u; v7 = ++i )
    *(_WORD *)(a3 + 4 * v7 + 2) = -1;
  v10 = 0;
  if ( a2 )
  {
    for ( j = 0; j < a2; v10 = ++j )
    {
      v12 = *(_WORD *)(a1 + 2 * v10);
      v13 = a3 + 4 * (__ROR4__(v12, a5) & a4);
      if ( *(unsigned __int16 *)(v13 + 2) == 0xFFFF )
      {
        result = (unsigned __int16)(result + 1);
        *(_WORD *)(v13 + 2) = v12;
      }
    }
  }
  return result;
}

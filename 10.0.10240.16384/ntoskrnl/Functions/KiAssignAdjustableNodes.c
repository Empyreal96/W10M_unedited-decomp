// KiAssignAdjustableNodes 
 
unsigned int __fastcall KiAssignAdjustableNodes(int a1, unsigned int a2, int a3, int a4)
{
  unsigned int result; // r0
  int v6; // r4
  unsigned __int16 i; // r6
  int v8; // r7
  unsigned int v9; // r5
  unsigned int v10; // r2

  result = 0;
  v6 = 0;
  if ( a2 )
  {
    for ( i = 0; i < a2; v6 = ++i )
    {
      v8 = *(_DWORD *)(a1 + 4 * v6);
      if ( (*(_BYTE *)(v8 + 289) & 8) == 0 )
      {
        v9 = 0;
        while ( 1 )
        {
          v10 = *(_DWORD *)(a4 + 4 * v9);
          if ( v10 >= *(unsigned __int8 *)(v8 + 288) )
            break;
          v9 = (unsigned __int16)(v9 + 1);
          if ( v9 )
            goto LABEL_10;
        }
        *(_WORD *)(v8 + 264) = v9;
        *(_BYTE *)(v8 + 289) |= 2u;
        *(_DWORD *)(a4 + 4 * v9) = v10 - *(unsigned __int8 *)(v8 + 288);
        if ( result <= v9 )
          result = (unsigned __int16)(v9 + 1);
      }
LABEL_10:
      ;
    }
  }
  return result;
}

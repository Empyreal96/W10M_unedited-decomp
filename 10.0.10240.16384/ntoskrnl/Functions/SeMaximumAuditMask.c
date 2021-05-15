// SeMaximumAuditMask 
 
int __fastcall SeMaximumAuditMask(int result, int a2, int a3, _DWORD *a4)
{
  unsigned int v7; // r6
  unsigned __int8 *v8; // r4
  unsigned int v9; // r8
  int v10; // r3
  int v11; // r7

  *a4 = 0;
  if ( result )
  {
    v7 = *(unsigned __int16 *)(result + 4);
    if ( *(_WORD *)(result + 4) )
    {
      v8 = (unsigned __int8 *)(result + 8);
      LOWORD(v9) = 0;
      do
      {
        result = v8[1];
        if ( (result & 8) == 0 )
        {
          v10 = *v8;
          if ( v10 == 2 || v10 == 13 )
          {
            v11 = *((_DWORD *)v8 + 1) & a2;
            if ( v11 && (result & 0x40) != 0 )
            {
              result = SepSidInToken(a3, 0, (int)(v8 + 8), 1, 0);
              if ( result )
                *a4 |= v11;
            }
          }
        }
        v9 = (unsigned __int16)(v9 + 1);
        v8 += *((unsigned __int16 *)v8 + 1);
      }
      while ( v9 < v7 );
    }
  }
  return result;
}

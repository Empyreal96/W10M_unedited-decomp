// SepSetAuditInfoForObjectType 
 
unsigned int __fastcall SepSetAuditInfoForObjectType(unsigned int result, int a2, int a3, int a4, unsigned int a5, unsigned __int8 a6, int a7, int a8, int a9, _BYTE *a10, _BYTE *a11)
{
  int v11; // r4
  _BYTE *v13; // r3
  unsigned int v14; // r1
  int v15; // r2
  __int16 v16; // r3

  v11 = 0;
  if ( (a3 & 0x2000000) != 0 )
  {
    if ( *(int *)(a8 + 4 * a7) < 0 )
      v11 = 128;
    else
      v11 = 64;
  }
  if ( ((*(_DWORD *)(a9 + 4 * a7) | a3) & a2) != 0 )
  {
    if ( (result & 0x40) != 0 && *(int *)(a8 + 4 * a7) >= 0 )
    {
      v13 = a10;
      v14 = a5;
      *a10 = 1;
      if ( a5 )
      {
        *(_WORD *)(a4 + 44 * a7 + 2) |= 1u;
        result = a6;
        if ( a6 )
        {
          result = (unsigned int)a11;
          return SepAuditTypeList(a4, v14, a8, a7, v13, (_BYTE *)result);
        }
      }
    }
    else if ( (result & 0x80) != 0 && *(int *)(a8 + 4 * a7) < 0 )
    {
      result = (unsigned int)a11;
      v14 = a5;
      *a11 = 1;
      if ( a5 )
      {
        *(_WORD *)(a4 + 44 * a7 + 2) |= 2u;
        if ( a6 )
        {
          v13 = a10;
          return SepAuditTypeList(a4, v14, a8, a7, v13, (_BYTE *)result);
        }
      }
    }
  }
  else
  {
    if ( (result & v11) == 0 )
      return result;
    if ( v11 == 128 )
    {
      *a11 = 1;
      if ( !a5 )
        return result;
      v15 = a4 + 44 * a7;
      v16 = *(_WORD *)(v15 + 2) | 2;
    }
    else
    {
      *a10 = 1;
      if ( !a5 )
        return result;
      v15 = a4 + 44 * a7;
      v16 = *(_WORD *)(v15 + 2) | 1;
    }
    *(_WORD *)(v15 + 2) = v16;
  }
  return result;
}

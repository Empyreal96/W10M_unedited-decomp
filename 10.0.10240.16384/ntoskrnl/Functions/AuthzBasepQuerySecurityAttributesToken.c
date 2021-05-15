// AuthzBasepQuerySecurityAttributesToken 
 
int __fastcall AuthzBasepQuerySecurityAttributesToken(int *a1, unsigned __int16 *a2, unsigned int a3, int a4, unsigned int a5, unsigned int *a6)
{
  int v7; // r4
  int v11; // r1
  unsigned __int16 *v12; // r2
  unsigned int v13; // r3
  unsigned int v14; // t1
  int result; // r0
  unsigned int v16; // r4
  unsigned int v17[8]; // [sp+8h] [bp-20h] BYREF

  v17[0] = a4;
  *a6 = 0;
  v7 = *a1;
  v17[0] = 0;
  if ( v7 )
  {
    v11 = 0;
    if ( a3 )
    {
      v12 = a2;
      do
      {
        v14 = *v12;
        v12 += 4;
        v13 = v14;
        if ( !v14 || !*(v12 - 3) || v13 > *(v12 - 3) || !*((_DWORD *)v12 - 1) )
          return -1073741811;
      }
      while ( ++v11 < a3 );
    }
    result = AuthzBasepGetSecurityAttributesCopyoutBufferSize(a1, a2, a3, v17);
    if ( result < 0 )
      return result;
    v16 = v17[0];
    if ( !v17[0] )
      return -1073741811;
    if ( a5 < v17[0] )
    {
      result = -1073741789;
      *a6 = v17[0];
    }
    else
    {
      memset((_BYTE *)a4, 0, a5);
      result = AuthzBasepCopyoutSecurityAttributes(a1, a2, a3, a4);
      *a6 = v16;
    }
  }
  else
  {
    if ( a5 < 0xC )
    {
      result = -1073741789;
    }
    else
    {
      *(_DWORD *)a4 = 0;
      *(_DWORD *)(a4 + 4) = 0;
      *(_DWORD *)(a4 + 8) = 0;
      *(_WORD *)a4 = 1;
      result = 0;
    }
    *a6 = 12;
  }
  return result;
}

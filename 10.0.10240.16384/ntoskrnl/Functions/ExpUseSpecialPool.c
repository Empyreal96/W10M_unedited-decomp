// ExpUseSpecialPool 
 
int __fastcall ExpUseSpecialPool(unsigned int a1, int a2, int a3, int a4)
{
  int v4; // r2
  int i; // r1
  int v6; // r5
  int v8; // [sp+0h] [bp-10h] BYREF
  _DWORD v9[3]; // [sp+4h] [bp-Ch] BYREF

  v8 = a3;
  v9[0] = a4;
  if ( a1 <= 0xFF0 && MmSpecialPoolTag && a1 )
  {
    v8 = a2;
    v9[0] = MmSpecialPoolTag;
    v4 = 0;
    for ( i = 0; ; ++i )
    {
      v6 = *((unsigned __int8 *)v9 + i);
      if ( v6 == 42 )
        return 1;
      if ( v6 != 63 && (v4 != 3 || (*((_BYTE *)&v8 + i) & 0x7F) != v6) && *((unsigned __int8 *)&v8 + i) != v6 )
        break;
      if ( (unsigned int)++v4 >= 4 )
        return 1;
    }
    if ( MmSpecialPoolTag >= a1 + 8 && MmSpecialPoolTag < a1 + 16 )
      return 1;
  }
  return 0;
}

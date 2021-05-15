// RtlDeleteAce 
 
int __fastcall RtlDeleteAce(int a1, unsigned int a2, int a3, int a4)
{
  int i; // r2
  unsigned int v7; // r0
  unsigned int v8; // r1
  unsigned int v9; // r0
  _BYTE *v10; // r3
  int v11; // r2
  int v13[4]; // [sp+0h] [bp-10h] BYREF

  v13[0] = a4;
  if ( !RtlValidAcl((unsigned __int8 *)a1) || a2 >= *(unsigned __int16 *)(a1 + 4) || !RtlFirstFreeAce(a1, v13) )
    return -1073741811;
  for ( i = a1 + 8; a2; --a2 )
    i += *(unsigned __int16 *)(i + 2);
  v7 = *(unsigned __int16 *)(i + 2);
  v8 = v13[0] - i;
  if ( v7 < v13[0] - i )
    return sub_7EB450();
  v9 = v8 - v7;
  if ( v9 < v8 )
  {
    v10 = (_BYTE *)(v9 + i);
    if ( v8 != v9 )
    {
      v11 = v13[0];
      do
        *v10++ = 0;
      while ( v10 != (_BYTE *)v11 );
    }
  }
  --*(_WORD *)(a1 + 4);
  return 0;
}

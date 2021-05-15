// SeShutdownServerSilo 
 
int __fastcall SeShutdownServerSilo(int a1, _DWORD *a2, int a3, int a4)
{
  int result; // r0
  int v6; // r0
  _DWORD *v7; // r2
  unsigned int *v8; // r1
  unsigned int i; // r5
  unsigned int v10; // r6
  int v11; // r1
  _DWORD *v12; // r2
  unsigned int *v13; // r4
  unsigned int j; // r1
  unsigned int v15; // r5
  int v16; // r1
  _DWORD *v17; // [sp+0h] [bp-18h] BYREF
  int v18; // [sp+4h] [bp-14h]
  int v19; // [sp+8h] [bp-10h]

  v17 = a2;
  v18 = a3;
  v19 = a4;
  result = SepDeleteUnreferencedLogonSessionsInSilo();
  if ( a2 )
  {
    v6 = a2[2];
    if ( v6 )
      ObfDereferenceObject(v6);
    result = a2[3];
    if ( result )
      result = ObfDereferenceObject(result);
    v7 = (_DWORD *)*a2;
    if ( *a2 )
    {
      v8 = v7 + 5;
      __pld(v7 + 5);
      for ( i = v7[5]; ; i = v10 )
      {
        result = i - 1;
        if ( (int)(i - 1) <= 0 )
          break;
        __dmb(0xBu);
        do
          v10 = __ldrex(v8);
        while ( v10 == i && __strex(result, v8) );
        if ( v10 == i )
          goto LABEL_17;
      }
      if ( i != 1 )
        __fastfail(0xEu);
      v11 = v7[22];
      v17 = (_DWORD *)v7[1];
      v18 = v7[2];
      result = SepDeReferenceLogonSession(&v17, v11);
    }
LABEL_17:
    v12 = (_DWORD *)a2[1];
    if ( v12 )
    {
      v13 = v12 + 5;
      __pld(v12 + 5);
      for ( j = v12[5]; ; j = v15 )
      {
        result = j - 1;
        if ( (int)(j - 1) <= 0 )
          break;
        __dmb(0xBu);
        do
          v15 = __ldrex(v13);
        while ( v15 == j && __strex(result, v13) );
        if ( v15 == j )
          return result;
      }
      if ( j != 1 )
        __fastfail(0xEu);
      v16 = v12[22];
      v17 = (_DWORD *)v12[1];
      v18 = v12[2];
      result = SepDeReferenceLogonSession(&v17, v16);
    }
  }
  return result;
}

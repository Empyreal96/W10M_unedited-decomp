// MiReplenishLocalCommit 
 
_DWORD *__fastcall MiReplenishLocalCommit(_DWORD *result, int a2, int a3, int a4)
{
  _DWORD *v5; // r6
  unsigned int v6; // r8
  unsigned int *v7; // r10
  unsigned int v8; // r5
  unsigned int *v9; // r4
  _DWORD *v10; // r1
  unsigned int i; // r3
  unsigned int v12; // r2
  unsigned int v13; // r2

  v5 = result;
  v6 = a3 + a4;
  v7 = result + 961;
  do
    v8 = __ldrex(v7);
  while ( v8 == a3 && __strex(v6, v7) );
  if ( v8 == a3 )
  {
    if ( v6 < result[805] )
    {
      if ( v6 >= result[804] )
        JUMPOUT(0x523A20);
      if ( v6 > result[800] )
        result[800] = v6;
      v9 = (unsigned int *)(a2 + 3580);
      __pld((void *)(a2 + 3580));
      v10 = *(_DWORD **)(a2 + 3580);
      for ( i = (unsigned int)v10 + a4; i <= 0x200; i = (unsigned int)result + a4 )
      {
        do
          result = (_DWORD *)__ldrex(v9);
        while ( result == v10 && __strex((unsigned int)v10 + a4, v9) );
        if ( result == v10 )
          return result;
        v10 = result;
      }
      do
        result = (_DWORD *)__ldrex(v7);
      while ( __strex((unsigned int)result - a4, v7) );
      v12 = v5[805];
      if ( (unsigned int)result >= v12 && (unsigned int)result - a4 < v12
        || (v13 = v5[804], (unsigned int)result - a4 < v13) && (unsigned int)result >= v13 )
      {
        result = (_DWORD *)MiSyncCommitSignals(v5, 0);
      }
    }
    else
    {
      result = (_DWORD *)sub_523A18();
    }
  }
  return result;
}

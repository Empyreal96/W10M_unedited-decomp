// RtlEnumerateGenericTable 
 
_DWORD *__fastcall RtlEnumerateGenericTable(int *a1, int a2)
{
  __int64 v4; // r0
  _DWORD *v5; // r4
  _DWORD *i; // r3

  if ( !RtlIsGenericTableEmpty(a1) )
  {
    if ( a2 )
    {
      v5 = (_DWORD *)*a1;
      for ( i = *(_DWORD **)(*a1 + 4); i; i = (_DWORD *)i[1] )
        v5 = i;
      goto LABEL_8;
    }
    v5 = RtlRealSuccessor((_DWORD *)*a1);
    if ( v5 )
    {
LABEL_8:
      LODWORD(v4) = v5;
      *a1 = RtlSplay(v4);
      return v5 + 6;
    }
  }
  return 0;
}

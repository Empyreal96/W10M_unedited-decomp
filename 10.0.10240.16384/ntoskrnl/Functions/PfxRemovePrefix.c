// PfxRemovePrefix 
 
void __fastcall PfxRemovePrefix(int a1, __int16 *a2)
{
  __int16 *v2; // r3
  __int16 *i; // r2
  __int16 *v4; // r4
  int v5; // r0
  int v6; // r1
  __int16 *v7; // r3
  int v8; // r2
  int v9; // r2
  _WORD *v10; // r1

  if ( (unsigned int)(*a2 - 513) <= 1 )
  {
    v2 = (__int16 *)*((_DWORD *)a2 + 2);
    for ( i = a2 + 4; v2 != i; v2 = *(__int16 **)v2 )
      i = v2;
    v4 = i - 4;
    v5 = RtlDelete((_DWORD *)a2 + 2);
    if ( v5 )
    {
      if ( v4 + 4 != (__int16 *)v5 )
      {
        v9 = *((_DWORD *)v4 + 1);
        v10 = (_WORD *)(v5 - 8);
        while ( *(__int16 **)(v9 + 4) != v4 )
          v9 = *(_DWORD *)(v9 + 4);
        *v10 = 513;
        *(_DWORD *)(v9 + 4) = v10;
        *(_DWORD *)(v5 - 4) = *((_DWORD *)v4 + 1);
        *v4 = 514;
        *((_DWORD *)v4 + 1) = 0;
      }
    }
    else
    {
      v6 = *((_DWORD *)v4 + 1);
      v7 = *(__int16 **)(v6 + 4);
      v8 = v6;
      while ( v7 != v4 )
      {
        v8 = *(_DWORD *)(v8 + 4);
        v7 = *(__int16 **)(v8 + 4);
      }
      *(_DWORD *)(v8 + 4) = v6;
    }
  }
}

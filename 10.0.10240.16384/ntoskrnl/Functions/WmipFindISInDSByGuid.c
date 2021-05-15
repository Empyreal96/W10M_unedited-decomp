// WmipFindISInDSByGuid 
 
_DWORD *__fastcall WmipFindISInDSByGuid(int a1, unsigned int a2)
{
  _DWORD *v2; // r4
  _DWORD *v4; // r5
  int v5; // r3

  v2 = *(_DWORD **)(a1 + 20);
  v4 = (_DWORD *)(a1 + 20);
  while ( 1 )
  {
    if ( v2 == v4 )
      return 0;
    v5 = v2[2];
    if ( v5 )
    {
      if ( !memcmp(a2, v5 + 40, 16) )
        break;
    }
    v2 = (_DWORD *)*v2;
  }
  WmipReferenceEntry((int)(v2 - 5));
  return v2 - 5;
}

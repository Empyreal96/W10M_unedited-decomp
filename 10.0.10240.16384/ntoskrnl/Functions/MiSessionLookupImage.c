// MiSessionLookupImage 
 
_DWORD *__fastcall MiSessionLookupImage(int a1)
{
  _DWORD *v2; // r4
  int v3; // r0

  v2 = *(_DWORD **)(*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324) + 68);
  if ( !v2 )
    return 0;
  do
  {
    v3 = MiSessionImageCompare(a1, v2);
    if ( v3 > 0 )
    {
      v2 = (_DWORD *)v2[1];
    }
    else
    {
      if ( v3 >= 0 )
        break;
      v2 = (_DWORD *)*v2;
    }
  }
  while ( v2 );
  if ( !v2 )
    return 0;
  return v2;
}

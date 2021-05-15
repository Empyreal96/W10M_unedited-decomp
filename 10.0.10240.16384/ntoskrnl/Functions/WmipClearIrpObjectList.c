// WmipClearIrpObjectList 
 
_DWORD *__fastcall WmipClearIrpObjectList(_DWORD *result)
{
  _DWORD *v1; // r2
  _DWORD *v2; // r1
  _DWORD *v3; // r3
  int v4; // r4

  v1 = result + 16;
  v2 = (_DWORD *)result[16];
  if ( v2 != result + 16 )
  {
    do
    {
      v3 = v2 - 13;
      v2 = (_DWORD *)*v2;
      v3[12] = 0;
      result = (_DWORD *)v3[14];
      v4 = v3[13];
      if ( *(_DWORD **)(v4 + 4) != v3 + 13 || (_DWORD *)*result != v3 + 13 )
        sub_51B9B4(result, v2);
      *result = v4;
      *(_DWORD *)(v4 + 4) = result;
    }
    while ( v2 != v1 );
  }
  return result;
}

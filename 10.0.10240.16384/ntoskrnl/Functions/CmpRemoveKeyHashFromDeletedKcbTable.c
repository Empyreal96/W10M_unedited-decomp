// CmpRemoveKeyHashFromDeletedKcbTable 
 
int __fastcall CmpRemoveKeyHashFromDeletedKcbTable(int result, _DWORD *a2)
{
  unsigned int v2; // r3
  int v3; // r3
  _DWORD *v4; // r2
  _DWORD *v5; // r3

  v2 = 101027 * (*a2 ^ (*a2 >> 9));
  v3 = *(_DWORD *)(result + 1852) + 12 * ((*(_DWORD *)(result + 1856) - 1) & (v2 ^ (v2 >> 9)));
  v4 = (_DWORD *)(v3 + 8);
  if ( v3 != -8 )
  {
    do
    {
      v5 = (_DWORD *)*v4;
      if ( !*v4 )
        break;
      if ( v5 == a2 )
      {
        *v4 = v5[1];
        return result;
      }
      v4 = v5 + 1;
    }
    while ( v5 != (_DWORD *)-4 );
  }
  return result;
}

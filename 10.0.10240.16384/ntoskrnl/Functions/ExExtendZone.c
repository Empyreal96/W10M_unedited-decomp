// ExExtendZone 
 
int __fastcall ExExtendZone(_DWORD *a1, _DWORD *a2, unsigned int a3)
{
  _DWORD *v3; // r4
  int v4; // r3
  unsigned int v5; // r1
  int v6; // r3

  if ( ((unsigned __int8)a2 & 7) != 0 || (a3 & 7) != 0 || a1[2] > a3 )
    return -1073741823;
  v3 = a2 + 2;
  *a2 = a1[1];
  v4 = a1[2];
  a1[1] = a2;
  v5 = 8;
  if ( a3 - v4 >= 8 )
  {
    do
    {
      *v3 = *a1;
      v6 = a1[2];
      *a1 = v3;
      v3 = (_DWORD *)((char *)v3 + v6);
      v5 += v6;
    }
    while ( v5 <= a3 - v6 );
  }
  a1[3] += v5;
  return 0;
}

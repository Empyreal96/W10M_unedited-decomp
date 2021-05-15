// DbgkpTriageDumpWrite 
 
int __fastcall DbgkpTriageDumpWrite(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v3; // r5
  unsigned int v5; // r0
  int v6; // r7
  int v7; // r3

  v3 = (_DWORD *)*a1;
  *a2 = 0;
  v3[995] |= 0xFFu;
  v5 = a1[5];
  v6 = 16 * v3[1049] + 4;
  if ( v5 + v6 < v5 || v5 + v6 > a1[1] )
    return -1073741670;
  memmove((int)v3 + v5, (int)v3 + v3[1048], 16 * v3[1049] + 4);
  v7 = a1[5];
  v3[1048] = v7;
  v3[1025] = v7 + v6;
  v3[1000] = v7 + v6;
  v3[1001] = 0;
  v3[1026] = v7 + v6 - 4;
  *(_DWORD *)((char *)v3 + v7 + v6 - 4) = 1145524820;
  *a2 = v7 + v6;
  return 0;
}

// IopCommitConfiguration 
 
int __fastcall IopCommitConfiguration(_DWORD **a1)
{
  _DWORD *v2; // r7
  int i; // r6
  _DWORD *v4; // r5
  int v5; // r3
  int v6; // r0

  v2 = *a1;
  for ( i = 0; v2 != a1; v4[8] = v4 + 7 )
  {
    v4 = v2 - 11;
    v5 = *(v2 - 8);
    v2 = (_DWORD *)*v2;
    v6 = (*(int (__fastcall **)(_DWORD, int, _DWORD))(v5 + 16))(*(_DWORD *)(v5 + 4), 2, 0);
    if ( v6 < 0 )
      i = v6;
    *((_BYTE *)v4 + 53) = 0;
    *((_BYTE *)v4 + 52) = 0;
    v4[11] = v4 + 11;
    v4[12] = v4 + 11;
    v4[9] = v4 + 9;
    v4[10] = v4 + 9;
    v4[5] = v4 + 5;
    v4[6] = v4 + 5;
    v4[7] = v4 + 7;
  }
  return i;
}

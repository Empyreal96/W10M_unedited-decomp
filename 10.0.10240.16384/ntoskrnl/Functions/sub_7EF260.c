// sub_7EF260 
 
void sub_7EF260()
{
  int v0; // r5
  unsigned int v1; // r7
  _WORD *v2; // r8
  _DWORD *v3; // r9
  int v4; // r6
  unsigned int v5; // r0
  unsigned int v6; // r4
  unsigned int v7; // r0
  unsigned int v8; // r2
  unsigned int v9; // r1

  v4 = *(_DWORD *)(v0 + 48);
  v5 = wcslen((unsigned __int16 *)(v4 + 4));
  v6 = v5;
  if ( v5 < v1 && !wcsncmp(v2, (unsigned __int16 *)(v4 + 4), v5) )
  {
    v7 = wtol((int)&v2[v6]);
    v8 = v7;
    v9 = **(_DWORD **)(v0 + 48);
    if ( v7 >= v9 && v7 < *(_DWORD *)(v0 + 36) + v9 && (v7 || WmipIsNumber(&v2[v6])) )
    {
      *v3 = v8 - v9;
      JUMPOUT(0x781D34);
    }
  }
  JUMPOUT(0x781D1C);
}

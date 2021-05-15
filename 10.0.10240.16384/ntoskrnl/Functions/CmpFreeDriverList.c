// CmpFreeDriverList 
 
int __fastcall CmpFreeDriverList(int result, _DWORD *a2)
{
  _DWORD *v3; // r4
  int v4; // r5
  int v5; // r0
  _DWORD *v6; // r7
  int v7; // r0
  int v8; // r0

  v3 = (_DWORD *)*a2;
  v4 = result;
  if ( (_DWORD *)*a2 != a2 )
  {
    do
    {
      v5 = v3[14];
      v6 = (_DWORD *)*v3;
      if ( v5 )
        (*(void (__fastcall **)(int, _DWORD))(v4 + 16))(v5, *((unsigned __int16 *)v3 + 26));
      v7 = v3[5];
      if ( v7 )
        (*(void (__fastcall **)(int, _DWORD))(v4 + 16))(v7, *((unsigned __int16 *)v3 + 9));
      v8 = v3[3];
      if ( v8 )
        (*(void (__fastcall **)(int, _DWORD))(v4 + 16))(v8, *((unsigned __int16 *)v3 + 5));
      result = (*(int (__fastcall **)(_DWORD *, int))(v4 + 16))(v3, 68);
      v3 = v6;
    }
    while ( v6 != a2 );
  }
  return result;
}

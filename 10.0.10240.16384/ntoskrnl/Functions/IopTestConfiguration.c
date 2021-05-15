// IopTestConfiguration 
 
int __fastcall IopTestConfiguration(int a1, int a2, _DWORD *a3)
{
  _DWORD *v4; // r5
  int result; // r0
  int v8; // r4
  char v9; // r3
  char v10[4]; // [sp+8h] [bp-30h] BYREF
  int v11; // [sp+Ch] [bp-2Ch] BYREF
  int v12[10]; // [sp+10h] [bp-28h] BYREF

  v4 = (_DWORD *)*a3;
  result = 0;
  if ( (_DWORD *)*a3 != a3 )
  {
    while ( 1 )
    {
      if ( !*((_BYTE *)v4 + 9) )
        return sub_80DC68(result);
      v8 = *(v4 - 8);
      v11 = 0;
      v12[0] = 0;
      ((void (__fastcall *)(int, int, _DWORD, _DWORD, int *, int *, _DWORD *))PnpLookupArbitersNewResources)(
        a1,
        a2,
        *(v4 - 7),
        *((unsigned __int8 *)v4 - 36),
        v12,
        &v11,
        v4 - 6);
      result = (*(int (__fastcall **)(_DWORD, _DWORD, char *))(v8 + 16))(*(_DWORD *)(v8 + 4), 0, v10);
      v9 = *((_BYTE *)v4 + 8);
      if ( result < 0 )
        break;
      *((_BYTE *)v4 + 8) = v9 & 0xFC | 1;
      *((_BYTE *)v4 + 9) = 0;
      v4 = (_DWORD *)*v4;
      if ( v4 == a3 )
        return result;
    }
    *((_BYTE *)v4 + 8) = v9 | 2;
  }
  return result;
}

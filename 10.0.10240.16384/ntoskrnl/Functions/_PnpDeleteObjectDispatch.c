// _PnpDeleteObjectDispatch 
 
int __fastcall PnpDeleteObjectDispatch(int a1, int a2, int a3, int a4)
{
  int v8; // r4
  int (__fastcall *v10[2])(int, _DWORD, int, int, int *); // [sp+8h] [bp-40h] BYREF
  int v11; // [sp+10h] [bp-38h] BYREF
  char v12[28]; // [sp+14h] [bp-34h] BYREF

  v10[0] = 0;
  v11 = 0;
  memset(v12, 0, sizeof(v12));
  if ( (_WORD)a4 )
    return -1073741811;
  v8 = PnpCtxGetObjectDispatchCallback(a1, a3, v10);
  if ( v8 >= 0 )
  {
    if ( v10[0] )
    {
      v11 = a4;
      v8 = v10[0](a1, a2, a3, 4, &v11);
      if ( v8 >= 0 && a3 >= 6 )
        PnpObjectRaiseDeleteEvent(a1, a2, a3);
    }
    else
    {
      v8 = -1073741822;
    }
  }
  return v8;
}

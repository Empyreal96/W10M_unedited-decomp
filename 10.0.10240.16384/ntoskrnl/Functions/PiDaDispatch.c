// PiDaDispatch 
 
int __fastcall PiDaDispatch(int a1, int a2)
{
  int v3; // r2
  __int16 **v5; // r3
  int v7; // r6
  int v8; // r4
  char *v9; // r9
  char **v10; // r8
  char *v11; // t1

  v3 = *(_DWORD *)(a2 + 96);
  if ( *(_BYTE *)v3 )
  {
    v5 = &(&IrpHandlingTable)[3 * *(_DWORD *)(*(_DWORD *)(v3 + 28) + 12)];
    return ((int (__fastcall *)(int, int))v5[1])(a1, a2);
  }
  v7 = *(_DWORD *)(v3 + 28);
  if ( *(_DWORD *)(v7 + 52) )
  {
    v8 = 0;
    v9 = *(char **)(v7 + 52);
    v10 = (char **)&IrpHandlingTable;
    while ( 1 )
    {
      v11 = *v10;
      v10 += 3;
      if ( !wcscmp(v11, v9) )
        break;
      if ( (unsigned int)++v8 >= 5 )
        return sub_7C6E38();
    }
    v5 = &(&IrpHandlingTable)[3 * v8];
    *(_DWORD *)(v7 + 12) = v8;
    return ((int (__fastcall *)(int, int))v5[1])(a1, a2);
  }
  return sub_7C6E38();
}

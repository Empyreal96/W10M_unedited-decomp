// IopQueryReconfiguration 
 
int __fastcall IopQueryReconfiguration(int a1, int a2)
{
  char v2; // r4
  int v4; // r3
  int v5; // r2
  bool v6; // zf
  char v8[48]; // [sp+8h] [bp-30h] BYREF

  v2 = a1;
  v4 = *(_DWORD *)(*(_DWORD *)(a2 + 176) + 20);
  if ( a1 == 4 )
  {
    v6 = *(_DWORD *)(v4 + 172) == 777;
LABEL_7:
    if ( !v6 )
      return -1073741823;
    goto LABEL_10;
  }
  if ( a1 == 5 )
  {
    v6 = *(_DWORD *)(v4 + 172) == 776;
    goto LABEL_7;
  }
  if ( a1 != 6 )
    return -1073741823;
  v5 = *(_DWORD *)(v4 + 172);
  if ( v5 != 777 )
  {
    v6 = v5 == 776;
    goto LABEL_7;
  }
LABEL_10:
  memset(v8, 0, 40);
  v8[0] = 27;
  v8[1] = v2;
  return IopSynchronousCall(a2, (int)v8, -1073741637, 0, 0);
}

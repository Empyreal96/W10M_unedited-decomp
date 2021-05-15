// IopGetNetworkOpenInformation 
 
int __fastcall IopGetNetworkOpenInformation(int a1, int a2)
{
  int result; // r0
  _DWORD *v5; // r2
  int v6; // r2
  int v7; // r2
  int v8; // r2
  int v9; // r2
  int v10; // r2
  char v11[8]; // [sp+8h] [bp-58h] BYREF
  int v12[10]; // [sp+10h] [bp-50h] BYREF
  int v13[10]; // [sp+38h] [bp-28h] BYREF

  result = IoQueryFileInformation(a1, 4, 40, (int)v12, (int)v11);
  if ( result >= 0 )
  {
    result = IoQueryFileInformation(a1, 5, 24, (int)v13, (int)v11);
    if ( result >= 0 )
    {
      v5 = *(_DWORD **)(a2 + 68);
      *v5 = v12[0];
      v5[1] = v12[1];
      v6 = *(_DWORD *)(a2 + 68);
      *(_DWORD *)(v6 + 8) = v12[2];
      *(_DWORD *)(v6 + 12) = v12[3];
      v7 = *(_DWORD *)(a2 + 68);
      *(_DWORD *)(v7 + 16) = v12[4];
      *(_DWORD *)(v7 + 20) = v12[5];
      v8 = *(_DWORD *)(a2 + 68);
      *(_DWORD *)(v8 + 24) = v12[6];
      *(_DWORD *)(v8 + 28) = v12[7];
      v9 = *(_DWORD *)(a2 + 68);
      *(_DWORD *)(v9 + 32) = v13[0];
      *(_DWORD *)(v9 + 36) = v13[1];
      v10 = *(_DWORD *)(a2 + 68);
      *(_DWORD *)(v10 + 40) = v13[2];
      *(_DWORD *)(v10 + 44) = v13[3];
      *(_DWORD *)(*(_DWORD *)(a2 + 68) + 48) = v12[8];
    }
  }
  return result;
}

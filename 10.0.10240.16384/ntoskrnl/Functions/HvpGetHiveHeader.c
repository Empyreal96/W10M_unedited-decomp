// HvpGetHiveHeader 
 
int __fastcall HvpGetHiveHeader(int a1, _DWORD *a2, _DWORD *a3, int a4)
{
  int v5; // r0
  int (__fastcall *v6)(int, int, int); // r3
  int v8; // r6
  _BYTE *v10; // r0
  _DWORD *v11; // r5
  unsigned int v13; // r2
  unsigned int v14; // r2
  unsigned int v15; // r3
  int v16; // r3
  int v17; // r2
  int v18[8]; // [sp+8h] [bp-20h] BYREF

  v18[0] = a4;
  v5 = *(_DWORD *)(a1 + 64);
  v6 = *(int (__fastcall **)(int, int, int))(a1 + 12);
  v8 = 0;
  *a2 = 0;
  v10 = (_BYTE *)v6(v5, 1, 842222915);
  v11 = v10;
  if ( !v10 )
    return 2;
  memset(v10, 0, 4096);
  v18[0] = 0;
  if ( !(*(int (__fastcall **)(int, _DWORD, int *, _DWORD *))(a1 + 24))(a1, 0, v18, v11) )
    return sub_7F3D44();
  if ( *v11 != 1718052210 )
    return sub_7F3D44();
  if ( v11[127] != HvpHeaderCheckSum(v11) )
    return sub_7F3D44();
  v13 = v11[10];
  if ( !v13 || v13 > 0x7FFFE000 || (v13 & 0xFFF) != 0 )
    return sub_7F3D44();
  if ( v11[7] || (v14 = v11[5], v14 > 1) || (v15 = v11[6], v15 < 3) || v14 == 1 && v15 > 5 || v11[8] != 1 )
  {
    (*(void (__fastcall **)(_DWORD *, _DWORD))(a1 + 16))(v11, *(_DWORD *)(a1 + 64));
  }
  else
  {
    v16 = v11[3];
    v17 = v11[1];
    *a2 = v11;
    *a3 = v16;
    a3[1] = v11[4];
    if ( v17 == v11[2] )
    {
      v11[11] = 1;
      v8 = 3;
    }
    else
    {
      v8 = 5;
    }
  }
  return v8;
}

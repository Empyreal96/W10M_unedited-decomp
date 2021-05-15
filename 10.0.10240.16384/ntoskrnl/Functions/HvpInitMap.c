// HvpInitMap 
 
int __fastcall HvpInitMap(int a1)
{
  int v2; // r9
  int v3; // r6
  unsigned int v4; // r5
  _BYTE *v5; // r7
  _BYTE *v6; // r8
  unsigned int v8; // r2
  unsigned int v9; // r10
  int (__fastcall *v10)(int, _DWORD, int); // r3
  _BYTE *v11; // r0
  _BYTE *v12; // r5
  int v13; // r5
  _BYTE *v14; // r0
  int v15; // r10
  int v16; // r0
  int v17; // r3
  unsigned int v18; // [sp+8h] [bp-20h]

  v2 = *(_DWORD *)(a1 + 28);
  v3 = 0;
  v4 = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 40);
  v5 = 0;
  v6 = 0;
  if ( (v4 & 0xFFF) != 0 )
    return sub_805CE8();
  v8 = v4 >> 12;
  if ( v4 >> 12 )
    v9 = (v8 - 1) >> 9;
  else
    v9 = 0;
  *(_DWORD *)(a1 + 952) = v4;
  v18 = v9;
  if ( !*(_DWORD *)(a1 + 40) )
  {
    v3 = (v8 + 3) & 0xFFFFFFFC;
    if ( !v3 )
      v3 = 4;
    v6 = (_BYTE *)(*(int (__fastcall **)(int, int, int))(a1 + 12))(v3, 1, 926043459);
    if ( !v6 )
      JUMPOUT(0x805CF2);
    v16 = (*(int (__fastcall **)(int, int, int))(a1 + 12))(v3, 1, 926043459);
    v5 = (_BYTE *)v16;
    if ( !v16 )
    {
      v13 = -1073741801;
      SetFailureLocation(v2, 0, 5, -1073741801, 32);
LABEL_26:
      if ( v6 )
      {
        if ( *(_BYTE **)(a1 + 40) == v6 )
          *(_DWORD *)(a1 + 40) = 0;
        (*(void (__fastcall **)(_BYTE *, int))(a1 + 16))(v6, v3);
      }
      if ( v5 )
      {
        if ( *(_BYTE **)(a1 + 56) == v5 )
          *(_DWORD *)(a1 + 56) = 0;
        (*(void (__fastcall **)(_BYTE *, int))(a1 + 16))(v5, v3);
      }
      return v13;
    }
    memset(v6, 0, v3);
    memset(v5, 0, v3);
    *(_DWORD *)(a1 + 36) = v4 >> 9;
    *(_DWORD *)(a1 + 40) = v6;
    *(_DWORD *)(a1 + 52) = v4 >> 9;
    *(_DWORD *)(a1 + 56) = v5;
    *(_DWORD *)(a1 + 48) = v3;
  }
  v10 = *(int (__fastcall **)(int, _DWORD, int))(a1 + 12);
  if ( !v9 )
  {
    v11 = (_BYTE *)v10(10240, 0, 909266243);
    v12 = v11;
    if ( v11 )
    {
      memset(v11, 0, 10240);
      *(_DWORD *)(a1 + 956) = a1 + 960;
      *(_DWORD *)(a1 + 960) = v12;
      return 0;
    }
    v17 = 32;
LABEL_22:
    v13 = -1073741670;
    SetFailureLocation(v2, 0, 5, -1073741670, v17);
    goto LABEL_26;
  }
  v14 = (_BYTE *)v10(4096, 0, 942820675);
  v15 = (int)v14;
  if ( !v14 )
  {
    v17 = 48;
    goto LABEL_22;
  }
  memset(v14, 0, 4096);
  if ( !HvpAllocateMap(a1, v15, 0, v18) )
  {
    v13 = -1073741670;
    SetFailureLocation(v2, 0, 5, -1073741670, 64);
    HvpFreeMap(a1, v15, 0, v18);
    (*(void (__fastcall **)(int, int))(a1 + 16))(v15, 4096);
    goto LABEL_26;
  }
  *(_DWORD *)(a1 + 956) = v15;
  *(_DWORD *)(a1 + 960) = 0;
  return 0;
}

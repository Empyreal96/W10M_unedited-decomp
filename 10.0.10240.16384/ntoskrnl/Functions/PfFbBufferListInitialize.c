// PfFbBufferListInitialize 
 
int __fastcall PfFbBufferListInitialize(int a1, int *a2, int a3)
{
  int result; // r0
  unsigned int v6; // r6
  int v7; // r0
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int *v11; // r7
  int v12; // r1
  int v13; // r2
  int v14; // r3

  if ( a3 )
    return sub_817894();
  memset((_BYTE *)a1, 0, 80);
  v6 = a2[3];
  *(_DWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 12) = 0;
  *(_DWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 28) = 0;
  if ( v6 < 0x18 )
    v6 = 24;
  v7 = *a2;
  v8 = a2[1];
  v9 = a2[2];
  v10 = a2[3];
  v11 = a2 + 4;
  *(_DWORD *)(a1 + 32) = v7;
  *(_DWORD *)(a1 + 36) = v8;
  *(_DWORD *)(a1 + 40) = v9;
  *(_DWORD *)(a1 + 44) = v10;
  result = *v11;
  v12 = v11[1];
  v13 = v11[2];
  v14 = v11[3];
  *(_DWORD *)(a1 + 48) = *v11;
  *(_DWORD *)(a1 + 52) = v12;
  *(_DWORD *)(a1 + 56) = v13;
  *(_DWORD *)(a1 + 60) = v14;
  *(_DWORD *)(a1 + 44) = v6;
  *(_DWORD *)a1 = 0;
  return result;
}

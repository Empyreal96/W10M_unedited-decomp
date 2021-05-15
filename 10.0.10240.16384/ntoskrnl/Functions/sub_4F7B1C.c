// sub_4F7B1C 
 
int __fastcall sub_4F7B1C(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  int result; // r0
  int (**v7)[4]; // r8
  int v8; // r9
  _DWORD *v9; // lr
  int v10; // r1
  int v11; // r2
  int v12; // r3

  if ( a2 < 0x8E )
    return sub_5553B4();
  memset((_BYTE *)a3, 0, 142);
  v7 = &WheapWmiGuidList;
  *(_DWORD *)(a3 + 16) = 3;
  v8 = 3;
  v9 = (_DWORD *)(a3 + 20);
  do
  {
    v10 = (**v7)[1];
    v11 = (**v7)[2];
    v12 = (**v7)[3];
    *v9 = (**v7)[0];
    v9[1] = v10;
    v9[2] = v11;
    v9[3] = v12;
    --v8;
    v9[4] = v7[2];
    v9[5] = v7[1];
    v9[6] = 104;
    v9 += 7;
    v7 += 3;
  }
  while ( v8 );
  *(_WORD *)(a3 + 104) = 36;
  memmove(a3 + 106, (int)L"WHEA_WMI_PROVIDER", 0x24u);
  *(_DWORD *)a3 = 142;
  result = 0;
  *a4 = 142;
  return result;
}

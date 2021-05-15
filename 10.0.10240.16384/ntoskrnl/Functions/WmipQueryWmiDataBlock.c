// WmipQueryWmiDataBlock 
 
int __fastcall WmipQueryWmiDataBlock(int a1, int a2, int a3, int a4, int a5, int *a6, unsigned int a7, _DWORD *a8)
{
  _DWORD *v8; // r4
  _DWORD *v9; // r8
  int v11; // r3
  int v12; // r0
  int v13; // r0
  int v14; // r6
  int v15[42]; // [sp+8h] [bp-A8h] BYREF

  v8 = a8;
  v9 = 0;
  v15[0] = a2;
  switch ( a3 )
  {
    case 0:
      JUMPOUT(0x81843E);
    case 1:
      JUMPOUT(0x8183DC);
    case 2:
      JUMPOUT(0x818360);
  }
  if ( a3 != 3 )
    return sub_818330();
  if ( a7 < 8 )
  {
    v11 = 0;
    v12 = 0;
    v8 = 0;
  }
  else
  {
    v11 = a7 - 8;
    v9 = a8 + 1;
    v12 = (int)(a8 + 2);
  }
  v15[0] = v11;
  v13 = WmipGetSMBiosTableData(v12, v15, v8);
  v14 = v15[0] + 8;
  if ( v13 >= 0 )
  {
    *v9 = v15[0];
    *a6 = v14;
  }
  return IoWMICompleteRequest(v13);
}

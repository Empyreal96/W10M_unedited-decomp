// BiGetDriveLayoutBlock 
 
int __fastcall BiGetDriveLayoutBlock(int a1, _DWORD *a2, int a3)
{
  int v6; // r0
  unsigned int v7; // r7
  int v8; // r4
  _DWORD *v10; // r2

  *a2 = 0;
  memset((_BYTE *)a3, 0, 40);
  v6 = ExAllocatePoolWithTag(1, 106, 1262764866);
  v7 = v6;
  if ( !v6 )
    return -1073741801;
  swprintf_s(v6, 53, (int)L"\\Device\\Harddisk%lu\\Partition%lu", a1);
  v8 = BiGetDriveLayoutInformation(v7, a2);
  if ( v8 < 0 )
    return sub_8142E4();
  v10 = (_DWORD *)*a2;
  *(_DWORD *)a3 = 0;
  if ( *v10 )
  {
    if ( *v10 == 1 )
    {
      *(_DWORD *)(a3 + 4) = 0;
      *(_DWORD *)(a3 + 8) = v10[2];
      *(_DWORD *)(a3 + 12) = v10[3];
      *(_DWORD *)(a3 + 16) = v10[4];
      *(_DWORD *)(a3 + 20) = v10[5];
    }
    else
    {
      v8 = -1073741811;
    }
  }
  else
  {
    *(_DWORD *)(a3 + 4) = 1;
    *(_DWORD *)(a3 + 8) = v10[2];
  }
  if ( v8 < 0 )
    JUMPOUT(0x81430A);
  ExFreePoolWithTag(v7);
  return v8;
}

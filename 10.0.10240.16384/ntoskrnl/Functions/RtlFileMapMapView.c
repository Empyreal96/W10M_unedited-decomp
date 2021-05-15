// RtlFileMapMapView 
 
int __fastcall RtlFileMapMapView(int a1, char a2)
{
  int v4; // r4
  int v5; // r0
  int v7[6]; // [sp+48h] [bp-30h] BYREF

  memset(v7, 0, sizeof(v7));
  if ( *(_DWORD *)(a1 + 16) )
    return -1073741554;
  v4 = ZwQueryInformationFile();
  if ( v4 >= 0 )
  {
    v4 = ZwCreateSection();
    if ( v4 >= 0 )
    {
      v4 = ZwMapViewOfSection();
      if ( v4 >= 0 )
      {
        v5 = MmSecureVirtualMemory(0, 0, 2);
        if ( v5 )
        {
          *(_BYTE *)(a1 + 29) = 1;
          *(_DWORD *)(a1 + 4) = 0;
          *(_BYTE *)(a1 + 30) = 1;
          *(_BYTE *)(a1 + 31) = a2;
          *(_DWORD *)(a1 + 16) = 0;
          *(_DWORD *)(a1 + 20) = 0;
          *(_DWORD *)(a1 + 24) = v5;
          v4 = 0;
          *(_DWORD *)(a1 + 8) = v7[2];
          *(_DWORD *)(a1 + 12) = v7[3];
        }
        else
        {
          v4 = -1073741823;
        }
      }
    }
  }
  return v4;
}

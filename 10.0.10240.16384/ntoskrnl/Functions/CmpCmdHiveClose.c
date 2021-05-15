// CmpCmdHiveClose 
 
BOOL __fastcall CmpCmdHiveClose(int a1)
{
  unsigned int i; // r5
  int v3; // r6
  int v5; // [sp+Ch] [bp-5Ch]
  int v6; // [sp+10h] [bp-58h] BYREF
  int v7; // [sp+14h] [bp-54h]
  int v8; // [sp+28h] [bp-40h]
  int v9; // [sp+2Ch] [bp-3Ch]
  int v10; // [sp+30h] [bp-38h]
  int v11; // [sp+34h] [bp-34h]

  v5 = IoSetThreadHardErrorMode(0);
  if ( *(_DWORD *)(a1 + 1776) && ZwQueryInformationFile() >= 0 )
  {
    KeQuerySystemTime(&v6);
    if ( *(_BYTE *)(a1 + 73) )
    {
      v10 = v6;
      v11 = v7;
    }
    else if ( *(_QWORD *)(a1 + 3280) )
    {
      v10 = *(_DWORD *)(a1 + 3280);
      v11 = *(_DWORD *)(a1 + 3284);
    }
    v8 = v6;
    v9 = v7;
    ZwSetInformationFile();
  }
  for ( i = 0; i < 6; ++i )
  {
    v3 = a1 + 4 * i;
    if ( *(_DWORD *)(v3 + 1776) )
    {
      if ( i )
      {
        ZwSetInformationObject();
        ZwClose();
      }
      else
      {
        CmpTrackHiveClose = 1;
        ZwSetInformationObject();
        ZwClose();
        CmpTrackHiveClose = 0;
      }
      *(_DWORD *)(v3 + 1776) = 0;
    }
  }
  return IoSetThreadHardErrorMode(v5);
}

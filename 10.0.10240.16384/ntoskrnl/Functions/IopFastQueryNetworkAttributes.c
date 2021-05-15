// IopFastQueryNetworkAttributes 
 
int __fastcall IopFastQueryNetworkAttributes(int a1, int a2, char a3, int a4, int *a5, int a6)
{
  int v6; // r8
  int v10; // r0
  int v11; // r4
  int v13; // [sp+10h] [bp-138h] BYREF
  _DWORD v14[28]; // [sp+18h] [bp-130h] BYREF
  char v15; // [sp+88h] [bp-C0h] BYREF

  v6 = a3;
  memset(v14, 0, sizeof(v14));
  v14[0] = 7340040;
  HIWORD(v14[11]) = 7;
  v14[15] = 1;
  v14[10] = a4 | 0x200000;
  v14[14] = 1;
  BYTE1(v14[20]) = 1;
  HIBYTE(v14[20]) = 1;
  v14[21] = &v15;
  v14[25] = 0;
  v14[17] = a6;
  v14[6] = a1;
  if ( !v6 )
    *(_DWORD *)(a1 + 12) |= 0x200u;
  v10 = ObOpenObjectByName(a1, (int)IoFileObjectType, v6, 0, a2, (int)v14, &v13);
  v11 = v10;
  if ( v14[25] )
    FsRtlpRestoreCallerEcpsToCallerList(v10, v14[25]);
  if ( v14[4] == -1096154543 )
  {
    *a5 = v14[2];
    a5[1] = v14[3];
  }
  else
  {
    if ( v11 >= 0 )
    {
      ObCloseHandle(v13);
      v11 = -1073741788;
    }
    *a5 = v11;
  }
  return 1;
}

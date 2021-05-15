// MiCreateSectionForDriver 
 
int __fastcall MiCreateSectionForDriver(int a1, int a2, _DWORD *a3)
{
  int v5; // r3
  int v8; // r1
  int v9; // r4
  int v10; // r4
  int v11; // r0
  int v12; // [sp+Ch] [bp-54h]
  int v13; // [sp+10h] [bp-50h]
  int v14; // [sp+1Ch] [bp-44h] BYREF
  _DWORD v15[2]; // [sp+20h] [bp-40h] BYREF
  int v16; // [sp+30h] [bp-30h] BYREF
  int v17; // [sp+34h] [bp-2Ch]
  int v18; // [sp+38h] [bp-28h]
  int v19; // [sp+3Ch] [bp-24h]
  int v20; // [sp+40h] [bp-20h]
  int v21; // [sp+44h] [bp-1Ch]

  v15[0] = 0;
  v15[1] = 0;
  byte_632F2C = 1;
  v5 = (unsigned __int8)KdDebuggerEnabled;
  *a3 = 0;
  if ( v5 && !KdDebuggerNotPresent && KdPullRemoteFile() >= 0 )
    return sub_7CDA50();
  v16 = 24;
  v17 = 0;
  v18 = a1;
  v20 = 0;
  v21 = 0;
  v19 = 576;
  v9 = ZwOpenFile();
  if ( v9 >= 0 )
  {
    v10 = 0x100000;
    if ( (a2 & 1) != 0 )
    {
      v10 = 3145728;
    }
    else if ( a2 < 0 )
    {
      v10 = 5242880;
    }
    v16 = 24;
    v17 = 0;
    v18 = 0;
    v20 = 0;
    v21 = 0;
    v19 = 576;
    if ( (a2 & 1) != 0 )
      v11 = MmGetSessionIdEx(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
    else
      v11 = -1;
    v9 = MmCreateSystemSection(&v14, v8, (int)&v16, (int)v15, 5, v10, 0, v12, v13, v11);
    ObCloseHandle(0);
    if ( v9 < 0 )
    {
      MiLogFailedDriverLoad(a1, 0, 0, v9);
    }
    else
    {
      v9 = 0;
      *a3 = v14;
    }
  }
  return v9;
}

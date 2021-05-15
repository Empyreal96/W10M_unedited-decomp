// PspLocateSystemDll 
 
int __fastcall PspLocateSystemDll(int a1)
{
  int result; // r0
  int v3; // r4
  int v4; // r0
  int v5; // r4
  int v6; // r0
  int v7; // r1
  int v8; // r0
  int v9; // [sp+8h] [bp-40h]
  int v10; // [sp+Ch] [bp-3Ch] BYREF
  int v11; // [sp+10h] [bp-38h] BYREF
  int v12; // [sp+14h] [bp-34h] BYREF
  int v13[2]; // [sp+20h] [bp-28h] BYREF
  int v14; // [sp+28h] [bp-20h]
  int v15; // [sp+2Ch] [bp-1Ch]
  int v16; // [sp+30h] [bp-18h]
  int v17; // [sp+34h] [bp-14h]

  v13[0] = 24;
  v13[1] = 0;
  v15 = 576;
  v14 = a1 + 12;
  v16 = 0;
  v17 = 0;
  result = ZwOpenFile();
  if ( result >= 0 )
  {
    v14 = 0;
    v3 = MmCreateSpecialImageSection(&v10, (int)v13, 12, v9, 2);
    v4 = ObCloseHandle(v9);
    if ( v3 < 0 )
      sub_81B030(v4);
    v5 = ObReferenceObjectByHandle(v10, 983071, MmSectionObjectType, 0, (int)&v11, 0);
    ObCloseHandle(v10);
    if ( v5 < 0 )
      KeBugCheckEx(107, v5, 4, 0, 0);
    v6 = MmGetSectionInformation(v11, 2, &v12);
    if ( v6 < 0 )
      KeBugCheckEx(107, v6, 8, 0, 0);
    v7 = v11;
    *(_DWORD *)(a1 + 32) = v12;
    ObInitializeFastReference(a1, v7);
    *(_DWORD *)(a1 + 4) = 0;
    v8 = PspMapSystemDll(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), a1, 0, 1);
    if ( v8 < 0 )
      KeBugCheckEx(107, v8, 5, 0, 0);
    result = 0;
  }
  return result;
}

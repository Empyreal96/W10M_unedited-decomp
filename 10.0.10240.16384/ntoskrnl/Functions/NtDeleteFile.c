// NtDeleteFile 
 
int __fastcall NtDeleteFile(int a1)
{
  int v2; // r5
  _BYTE *v3; // r0
  int v5; // r4
  int v6; // [sp+10h] [bp-128h] BYREF
  _DWORD v7[28]; // [sp+18h] [bp-120h] BYREF
  char v8; // [sp+88h] [bp-B0h] BYREF

  v2 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v3 = memset(v7, 0, sizeof(v7));
  v7[0] = 7340040;
  v7[10] = 4096;
  HIWORD(v7[11]) = 7;
  v7[15] = 1;
  BYTE2(v7[20]) = 1;
  v7[21] = &v8;
  v7[22] = 32;
  v7[6] = a1;
  if ( IoCountOperations == 1 )
    return sub_81BC28(v3);
  v5 = ObOpenObjectByName(a1, (int)IoFileObjectType, v2, 0, 0x10000, (int)v7, &v6);
  IopCleanupExtraCreateParameters((int)v7);
  if ( v7[4] == -1096154543 )
    v5 = v7[2];
  return v5;
}

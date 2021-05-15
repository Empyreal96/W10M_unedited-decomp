// NtOpenDirectoryObject 
 
int __fastcall NtOpenDirectoryObject(unsigned int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // r5
  _DWORD *v5; // r4
  int result; // r0
  char v7; // [sp+10h] [bp-20h]
  int v8; // [sp+18h] [bp-18h]
  unsigned int varg_r0; // [sp+38h] [bp+8h]

  v8 = a3;
  v4 = (_DWORD *)a1;
  varg_r0 = a1;
  v7 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v7 )
  {
    v5 = (_DWORD *)a1;
    if ( a1 >= MmUserProbeAddress )
      v5 = (_DWORD *)MmUserProbeAddress;
    *v5 = *v5;
  }
  result = ObOpenObjectByName(a3, ObpDirectoryObjectType, v7);
  *v4 = v8;
  return result;
}

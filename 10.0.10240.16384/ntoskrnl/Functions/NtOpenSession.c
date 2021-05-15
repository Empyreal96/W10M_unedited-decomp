// NtOpenSession 
 
int __fastcall NtOpenSession(unsigned int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // r5
  _DWORD *v5; // r4
  int result; // r0
  char v7; // [sp+10h] [bp-20h]
  _DWORD _18[12]; // [sp+18h] [bp-18h] BYREF

  _18[11] = a4;
  _18[0] = a3;
  _18[1] = a4;
  _18[10] = a3;
  _18[9] = a2;
  v4 = (_DWORD *)a1;
  _18[8] = a1;
  v7 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v7 )
  {
    v5 = (_DWORD *)a1;
    if ( a1 >= MmUserProbeAddress )
      v5 = (_DWORD *)MmUserProbeAddress;
    *v5 = *v5;
  }
  result = ObOpenObjectByName(a3, MmSessionObjectType, v7, 0, a2, 0, _18);
  *v4 = _18[0];
  return result;
}

// NtOpenSemaphore 
 
int __fastcall NtOpenSemaphore(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *v4; // r4
  int result; // r0
  char v6; // [sp+10h] [bp-20h]
  int v7; // [sp+18h] [bp-18h]
  _DWORD *varg_r0; // [sp+38h] [bp+8h]

  v7 = a3;
  v4 = a1;
  varg_r0 = a1;
  v6 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v6 )
  {
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      a1 = (_DWORD *)MmUserProbeAddress;
    *a1 = *a1;
  }
  result = ObOpenObjectByName(a3, ExSemaphoreObjectType, v6);
  if ( result >= 0 )
    *v4 = v7;
  return result;
}

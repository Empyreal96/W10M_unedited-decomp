// NtOpenTimer 
 
int __fastcall NtOpenTimer(_DWORD *a1, int a2, int a3, int a4)
{
  _DWORD *v4; // r4
  int result; // r0
  char v6; // [sp+10h] [bp-20h]
  int v7; // [sp+18h] [bp-18h] BYREF
  int v8; // [sp+1Ch] [bp-14h]
  _DWORD *varg_r0; // [sp+38h] [bp+8h]
  int varg_r1; // [sp+3Ch] [bp+Ch]
  int varg_r2; // [sp+40h] [bp+10h]
  int varg_r3; // [sp+44h] [bp+14h]

  varg_r3 = a4;
  v7 = a3;
  v8 = a4;
  varg_r2 = a3;
  varg_r1 = a2;
  v4 = a1;
  varg_r0 = a1;
  v6 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v6 )
  {
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      a1 = (_DWORD *)MmUserProbeAddress;
    *a1 = *a1;
  }
  result = ObOpenObjectByName(a3, ExTimerObjectType, v6, 0, a2, 0, &v7);
  v8 = result;
  if ( result >= 0 )
    *v4 = v7;
  return result;
}

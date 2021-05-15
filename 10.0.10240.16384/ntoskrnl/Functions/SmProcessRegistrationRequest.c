// SmProcessRegistrationRequest 
 
int __fastcall SmProcessRegistrationRequest(unsigned int a1, int a2, _DWORD *a3, int a4)
{
  int v6; // r5
  int v8; // [sp+0h] [bp-20h] BYREF
  int v9; // [sp+4h] [bp-1Ch]
  int v10; // [sp+8h] [bp-18h]
  unsigned int varg_r0; // [sp+28h] [bp+8h]
  int varg_r1; // [sp+2Ch] [bp+Ch]
  _DWORD *varg_r2; // [sp+30h] [bp+10h]
  int varg_r3; // [sp+34h] [bp+14h]

  varg_r1 = a2;
  varg_r3 = a4;
  v10 = a4;
  LOBYTE(varg_r3) = a4;
  varg_r2 = a3;
  varg_r0 = a1;
  v8 = 0;
  v9 = 0;
  if ( a2 != 8 )
    return -1073741306;
  if ( (_BYTE)a4 )
  {
    if ( (a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(a1);
    if ( a1 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_BYTE *)a1 = *(_BYTE *)a1;
    *(_BYTE *)(a1 + 4) = *(_BYTE *)(a1 + 4);
  }
  v8 = *(_DWORD *)a1;
  v9 = *(_DWORD *)(a1 + 4);
  if ( (unsigned __int8)v8 != 2 || (v8 & 0xFFFFFF00) != 0 )
    return -1073741811;
  v6 = SmGetRegistrationInfo((char)a4, &v8);
  if ( v6 >= 0 )
  {
    *(_DWORD *)a1 = v8;
    *(_DWORD *)(a1 + 4) = v9;
    *a3 = 8;
  }
  return v6;
}

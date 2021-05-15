// NtCreateNamedPipeFile 
 
int __fastcall NtCreateNamedPipeFile(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int *a14)
{
  _DWORD v15[6]; // [sp+38h] [bp-48h] BYREF
  int v16; // [sp+50h] [bp-30h]
  int v17; // [sp+54h] [bp-2Ch]
  char v18; // [sp+58h] [bp-28h]
  int varg_r0; // [sp+88h] [bp+8h]
  int varg_r1; // [sp+8Ch] [bp+Ch]
  int varg_r2; // [sp+90h] [bp+10h]
  int varg_r3; // [sp+94h] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  varg_r1 = a2;
  if ( a14 )
  {
    v18 = 1;
    if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    {
      if ( ((unsigned __int8)a14 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      v16 = *a14;
      v17 = a14[1];
    }
    else
    {
      v16 = *a14;
      v17 = a14[1];
    }
  }
  else
  {
    v18 = 0;
  }
  v15[0] = a8;
  v15[1] = a9;
  v15[2] = a10;
  v15[3] = a11;
  v15[4] = a12;
  v15[5] = a13;
  return ((int (__fastcall *)(int, int, int, int, _DWORD, _DWORD, int, int, int, _DWORD, _DWORD, int, _DWORD *, _DWORD, int, int, int))IoCreateFile)(
           a1,
           a2,
           a3,
           a4,
           0,
           0,
           a5,
           a6,
           a7,
           0,
           0,
           1,
           v15,
           0,
           a1,
           a3,
           a4);
}

// NtCreateMailslotFile 
 
int __fastcall NtCreateMailslotFile(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int *a8)
{
  _DWORD v9[2]; // [sp+38h] [bp-38h] BYREF
  int v10; // [sp+40h] [bp-30h]
  int v11; // [sp+44h] [bp-2Ch]
  char v12; // [sp+48h] [bp-28h]
  int varg_r0; // [sp+78h] [bp+8h]
  int varg_r1; // [sp+7Ch] [bp+Ch]
  int varg_r2; // [sp+80h] [bp+10h]
  int varg_r3; // [sp+84h] [bp+14h]

  varg_r0 = a1;
  varg_r2 = a3;
  varg_r3 = a4;
  varg_r1 = a2;
  if ( a8 )
  {
    v12 = 1;
    if ( *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A) )
    {
      if ( ((unsigned __int8)a8 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      v10 = *a8;
      v11 = a8[1];
    }
    else
    {
      v10 = *a8;
      v11 = a8[1];
    }
  }
  else
  {
    v12 = 0;
  }
  v9[0] = a6;
  v9[1] = a7;
  return IoCreateFile(a1, a2, a3, a4, 0, 0, 3, 2, a5, 0, 0, 2, (int)v9, 0);
}

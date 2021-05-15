// sub_8AA7B8 
 
int __fastcall sub_8AA7B8(int a1, int a2)
{
  int v3; // r2
  unsigned int *v4; // r3
  unsigned int v5; // r5
  int v6; // r4
  unsigned int v8; // [sp+8h] [bp-38h] BYREF
  unsigned int v9; // [sp+Ch] [bp-34h] BYREF
  _DWORD v10[12]; // [sp+10h] [bp-30h] BYREF

  v3 = *(unsigned __int8 *)(a1 + 12);
  v4 = 0;
  v8 = 0;
  if ( !v3 )
    v4 = &v8;
  if ( sub_8AA708(a1, a2, v3, &v9, v4) < 0 )
    return 0;
  if ( !*(_BYTE *)(a1 + 12) )
  {
    memset(v10, 0, 32);
    LOBYTE(v10[1]) = 2;
    v10[3] = 472231598;
    v10[4] = 1150356927;
    v10[5] = -903776863;
    v10[6] = 186814704;
  }
  v5 = v8;
  v6 = sub_8AA490((__int64 *)a1, (int)v10, v8, v9);
  if ( v5 )
    ExFreePoolWithTag(v5);
  return v6;
}

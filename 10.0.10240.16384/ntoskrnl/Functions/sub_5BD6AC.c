// sub_5BD6AC 
 
int __fastcall sub_5BD6AC(int a1, int a2)
{
  int v4; // r5
  int v6[6]; // [sp+8h] [bp-60h] BYREF
  char v7[40]; // [sp+20h] [bp-48h] BYREF
  int v8; // [sp+48h] [bp-20h]
  int v9; // [sp+4Ch] [bp-1Ch]
  int anonymous1; // [sp+70h] [bp+8h]
  int anonymous2; // [sp+74h] [bp+Ch]

  anonymous1 = a1;
  anonymous2 = a2;
  v6[0] = 1;
  v6[1] = 0;
  v6[2] = 48;
  memmove((int)v7, a1, 0x20u);
  v8 = 4;
  v9 = a2;
  v4 = sub_89FFCC(4, 72, v6);
  if ( v4 >= 0 && off_9204BC )
    off_9204BC(a1, 32, a2);
  return v4;
}

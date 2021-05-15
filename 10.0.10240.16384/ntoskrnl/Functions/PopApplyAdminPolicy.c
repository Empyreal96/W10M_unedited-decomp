// PopApplyAdminPolicy 
 
int __fastcall PopApplyAdminPolicy(int a1, int *a2)
{
  int v2; // r0
  int *v3; // r1
  int v4; // r2
  unsigned int v5; // r3
  unsigned int v6; // r4
  unsigned int v7; // r3
  int v9; // [sp+0h] [bp-28h] BYREF
  int v10; // [sp+4h] [bp-24h]
  unsigned int v11; // [sp+8h] [bp-20h]
  unsigned int v12; // [sp+Ch] [bp-1Ch]
  unsigned int v13; // [sp+10h] [bp-18h]
  unsigned int v14; // [sp+14h] [bp-14h]

  v2 = *a2;
  v4 = a2[1];
  v5 = a2[2];
  v6 = a2[3];
  v3 = a2 + 4;
  v9 = v2;
  v10 = v4;
  v11 = v5;
  v12 = v6;
  v7 = v3[1];
  v13 = *v3;
  v14 = v7;
  if ( (unsigned int)(v2 - 2) > 3 || (unsigned int)(v10 - 2) > 3 || v2 > v10 || v11 > v12 || v13 > v14 )
    return -1073741811;
  if ( memcmp((unsigned int)&v9, (unsigned int)&PopAdminPolicy, 24) )
  {
    PopAdminPolicy = v9;
    dword_61E9A4 = v10;
    dword_61E9A8 = v11;
    dword_61E9AC = v12;
    dword_61E9B0 = v13;
    dword_61E9B4 = v14;
  }
  return 0;
}

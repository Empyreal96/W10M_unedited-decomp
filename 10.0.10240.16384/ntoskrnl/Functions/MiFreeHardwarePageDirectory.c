// MiFreeHardwarePageDirectory 
 
int __fastcall MiFreeHardwarePageDirectory(int a1)
{
  _DWORD *v2; // r1
  int v3; // r2
  char *v4; // r3
  int v5; // r4
  int v6; // r1
  int v7; // r2
  int v8; // r3
  int result; // r0
  int v10; // [sp+0h] [bp-38h] BYREF
  __int16 v11; // [sp+4h] [bp-34h]
  __int16 v12; // [sp+6h] [bp-32h]
  int v13; // [sp+10h] [bp-28h]
  int v14; // [sp+14h] [bp-24h]
  int v15; // [sp+18h] [bp-20h]
  char v16; // [sp+1Ch] [bp-1Ch] BYREF

  v2 = (_DWORD *)(((*(_DWORD *)(a1 + 32) >> 10) & 0x3FFFFC) - 0x40000000);
  v3 = *v2 >> 12;
  v10 = 0;
  v11 = 44;
  v13 = 0;
  v15 = 0;
  v14 = 0x4000;
  v12 = 2;
  v4 = &v16;
  v5 = 4;
  do
  {
    *(_DWORD *)v4 = v3;
    v4 += 4;
    ++v3;
    --v5;
  }
  while ( v5 );
  MiReleasePtes(&dword_634D58, (unsigned int)v2, 4u);
  result = MmFreePagesFromMdl((int)&v10, v6, v7, v8);
  *(_DWORD *)(a1 + 28) = 0;
  *(_DWORD *)(a1 + 32) = 0;
  return result;
}

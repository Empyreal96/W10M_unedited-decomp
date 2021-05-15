// WheapGetTimestamp 
 
unsigned int __fastcall WheapGetTimestamp(int a1)
{
  int v2; // r2
  int v3; // r3
  unsigned int result; // r0
  int v5; // r2
  int v6; // r1
  char v7; // r3
  _DWORD v8[2]; // [sp+0h] [bp-20h] BYREF
  __int16 v9; // [sp+8h] [bp-18h] BYREF
  __int16 v10; // [sp+Ah] [bp-16h]
  __int16 v11; // [sp+Ch] [bp-14h]
  __int16 v12; // [sp+Eh] [bp-12h]
  __int16 v13; // [sp+10h] [bp-10h]
  __int16 v14; // [sp+12h] [bp-Eh]

  KeQuerySystemTime(v8);
  result = RtlTimeToTimeFields((int)v8, &v9, v2, v3);
  v5 = *(_DWORD *)(a1 + 4);
  v6 = v9;
  *(_BYTE *)a1 = v14;
  v7 = v13;
  *(_DWORD *)(a1 + 4) = v5;
  *(_BYTE *)(a1 + 1) = v7;
  *(_BYTE *)(a1 + 2) = v12;
  *(_DWORD *)a1 &= 0xFEFFFFFF;
  *(_BYTE *)(a1 + 4) = v11;
  *(_BYTE *)(a1 + 5) = v10;
  *(_BYTE *)(a1 + 7) = v6 / 100;
  *(_BYTE *)(a1 + 6) = v6 % 100;
  return result;
}

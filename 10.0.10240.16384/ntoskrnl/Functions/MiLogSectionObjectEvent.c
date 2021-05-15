// MiLogSectionObjectEvent 
 
int __fastcall MiLogSectionObjectEvent(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int v5; // r2
  int v6; // r1
  int v7; // r0
  int v9; // [sp+0h] [bp-10h]
  int v10; // [sp+8h] [bp-8h] BYREF
  int v11; // [sp+Ch] [bp-4h]

  v11 = a4;
  v4 = MiSectionControlArea(a1);
  v10 = v5;
  v11 = *(_DWORD *)(*(_DWORD *)v4 + 40);
  if ( v6 == 1 )
    v7 = 647;
  else
    v7 = 648;
  MiLogPerfMemoryEvent(v7, 0x20400001u, (int)&v10, 8, 4200706);
  return v9;
}

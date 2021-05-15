// MmMapApiSetView 
 
int __fastcall MmMapApiSetView(int a1)
{
  int result; // r0
  int v3; // [sp+18h] [bp-20h] BYREF
  int v4; // [sp+1Ch] [bp-1Ch] BYREF
  _DWORD v5[6]; // [sp+20h] [bp-18h] BYREF

  v3 = 0;
  v5[0] = 0;
  v5[1] = 0;
  v4 = 0;
  result = MmMapViewOfSection(dword_632ED0, a1, &v3, 0, 0, v5, &v4, 1, 0x400000, 2);
  if ( result >= 0 )
    *(_DWORD *)(*(_DWORD *)(a1 + 320) + 56) = v3;
  return result;
}

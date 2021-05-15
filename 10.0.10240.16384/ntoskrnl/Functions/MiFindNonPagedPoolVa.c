// MiFindNonPagedPoolVa 
 
int __fastcall MiFindNonPagedPoolVa(__int16 a1, unsigned int a2, int a3, _DWORD *a4)
{
  int v8; // r0
  int v10[6]; // [sp+8h] [bp-38h] BYREF
  char v11; // [sp+20h] [bp-20h]

  v10[0] = 0;
  v11 = 0;
  if ( (a1 & 0x200) != 0 )
  {
    v8 = MiScanNonPagedPoolVa(a2, a3, 0, v10);
    if ( v8 != -1 )
    {
      *a4 = 0;
      return *(_DWORD *)(dword_6337E8 + 176 * a3 + 136) + (v8 << 12);
    }
  }
  v8 = MiScanNonPagedPoolVa(a2, a3, 1, v10);
  if ( v8 != -1 )
  {
    *a4 = 2;
    return *(_DWORD *)(dword_6337E8 + 176 * a3 + 136) + (v8 << 12);
  }
  v8 = MiExpandNonPagedPool(a1, a2, a3, -1, 0, a4);
  if ( v8 != -1 )
    return *(_DWORD *)(dword_6337E8 + 176 * a3 + 136) + (v8 << 12);
  return sub_50EC1C();
}

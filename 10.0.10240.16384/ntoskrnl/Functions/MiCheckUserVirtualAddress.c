// MiCheckUserVirtualAddress 
 
int __fastcall MiCheckUserVirtualAddress(unsigned int a1, int *a2, int a3, unsigned int *a4)
{
  char v4; // r9
  int result; // r0
  int v9; // r2
  int v10; // r1
  int v11; // r3
  unsigned int v12; // r2
  _DWORD *v13; // r0
  unsigned int *v14; // [sp+0h] [bp-20h] BYREF

  v14 = a4;
  v4 = (char)a4;
  if ( (a1 & 0xFFFFF000) == 2147352576 )
    return sub_538050();
  if ( (*(_DWORD *)(a3 + 28) & 7) == 2 && (*(_DWORD *)(a3 + 40) & 0x20000000) != 0 )
  {
    v13 = MiLocateVadEvent(a3, 32);
    if ( v13 && v13[2] != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
      goto LABEL_16;
  }
  v9 = *(_DWORD *)(a3 + 28);
  if ( v9 < 0 )
    goto LABEL_16;
  v10 = *(_DWORD *)(a3 + 28) & 7;
  if ( v10 == 1 )
    goto LABEL_16;
  if ( (v9 & 0x8000) != 0 )
  {
    if ( v10 != 3 && v10 != 5 && (*(_DWORD *)(a3 + 32) & 0x80000000) != 0 )
    {
      *a2 = (unsigned __int8)v9 >> 3;
      return 0;
    }
LABEL_16:
    *a2 = 24;
    return 0;
  }
  if ( (*(_BYTE *)(a3 + 43) & 1) != 0 )
    goto LABEL_16;
  v11 = (unsigned __int8)v9 >> 3;
  *a2 = v11;
  if ( v11 == 7 && v10 == 2 )
    *a2 = 256;
  result = MiGetProtoPteAddress((_DWORD *)a3, a1 >> 12, v4, &v14);
  if ( !result )
    *a2 = 24;
  v12 = *(_DWORD *)(a3 + 68);
  if ( (v12 & 0x80000000) != 0 && (a1 >> 12) - *(_DWORD *)(a3 + 12) > (unsigned int)((*(_QWORD *)v12 - 1i64) >> 12) )
    *a2 = 24;
  return result;
}

// MiFindActualFaultingPte 
 
int __fastcall MiFindActualFaultingPte(unsigned int a1, int a2, int a3, int a4)
{
  unsigned int v5; // r4
  char *v6; // r2
  int i; // r1
  int result; // r0
  int *v9; // t1
  int v10; // r3
  int v11; // r1
  int v12; // r0
  int v13[2]; // [sp+0h] [bp-20h] BYREF
  unsigned int v14; // [sp+8h] [bp-18h] BYREF
  int v15; // [sp+Ch] [bp-14h]
  char v16; // [sp+10h] [bp-10h] BYREF

  v13[0] = a1;
  v13[1] = a2;
  v14 = a3;
  v15 = a4;
  if ( (*(_DWORD *)(((a1 >> 20) & 0xFFC) - 1070596096) & 0x402) != 1026 )
  {
    v5 = ((a1 >> 10) & 0x3FFFFC) - 0x40000000;
    v14 = v5;
    v15 = ((v5 >> 10) & 0x3FFFFC) - 0x40000000;
    v6 = &v16;
    for ( i = 2; i != 1; --i )
    {
      v9 = (int *)*((_DWORD *)v6 - 1);
      v6 -= 4;
      result = (int)v9;
      v10 = *v9;
      if ( (*v9 & 2) == 0 )
        return result;
    }
    if ( (v10 & 0x400) == 0 )
    {
      v11 = *(_DWORD *)v5;
      if ( (*(_DWORD *)v5 & 2) == 0 )
      {
        if ( (v11 & 0x400) == 0 )
          return v5;
        if ( (v11 & 0xFFFFE000) != -8192 )
        {
          v12 = (*(_DWORD *)v5 & 0x1FC | (*(_DWORD *)v5 >> 2) & 0x3FFFFE00) - 0x40000000;
          goto LABEL_10;
        }
        v12 = MiCheckVirtualAddress(a1, &v14, v13);
        if ( v12 )
        {
LABEL_10:
          result = MiFindActualFaultingPte(v12);
          if ( result )
            return result;
          return v5;
        }
      }
    }
  }
  return 0;
}

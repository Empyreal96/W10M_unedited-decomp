// IoWMIQuerySingleInstance 
 
int __fastcall IoWMIQuerySingleInstance(int a1, unsigned __int16 *a2, unsigned int *a3, int a4)
{
  int v4; // r6
  unsigned int v5; // r8
  unsigned int v6; // r5
  int v7; // r4
  int v11; // r5
  int v12; // r3
  unsigned int v14[8]; // [sp+10h] [bp-20h] BYREF

  v4 = a4;
  v5 = *a3;
  v6 = (*a2 + 73) & 0xFFFFFFF8;
  v7 = a4;
  if ( !a4 || v5 < v6 )
  {
    v7 = ExAllocatePoolWithTag(512, v6, 1885957463);
    v5 = v6;
  }
  if ( !v7 )
    return -1073741670;
  memset((_BYTE *)v7, 0, 64);
  *(_DWORD *)(v7 + 44) = 2;
  *(_DWORD *)(v7 + 12) = 0;
  *(_DWORD *)(v7 + 16) = 0;
  *(_DWORD *)(v7 + 48) = 64;
  *(_DWORD *)v7 = v6;
  *(_DWORD *)(v7 + 56) = v6;
  *(_WORD *)(v7 + 64) = *a2;
  memmove(v7 + 66, *((_DWORD *)a2 + 1), *a2);
  v14[0] = *(_DWORD *)v7;
  v11 = WmipQuerySetExecuteSI(a1, 0, 0, 1, v7, v5, v14);
  if ( v11 >= 0 )
  {
    v12 = *(_DWORD *)(v7 + 44);
    if ( (v12 & 0x100) != 0 )
    {
      v11 = -1073741637;
    }
    else
    {
      if ( (v12 & 0x20) != 0 )
      {
        *a3 = *(_DWORD *)(v7 + 48);
      }
      else
      {
        *a3 = v14[0];
        if ( v7 == v4 )
          return v11;
      }
      v11 = -1073741789;
    }
  }
  if ( v7 != v4 )
    ExFreePoolWithTag(v7);
  return v11;
}

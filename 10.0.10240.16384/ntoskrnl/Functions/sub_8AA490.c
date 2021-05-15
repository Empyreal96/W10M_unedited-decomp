// sub_8AA490 
 
int __fastcall sub_8AA490(__int64 *a1, int a2, int a3, unsigned int a4)
{
  unsigned int v5; // r10
  __int64 v8; // kr00_8
  unsigned int v9; // r5
  unsigned int *v10; // r3
  unsigned int v12; // r3
  int v13; // r2
  int v14; // r7
  int v15; // r0
  int v16; // r4
  unsigned int *v17; // r3
  int v18; // r3
  unsigned int v19; // r0

  v5 = a4 + 28;
  if ( a4 <= 0x3FFFE4 )
  {
    v8 = *a1;
    v9 = (a4 + 31) & 0xFFFFFFFC;
    if ( (int)v8 - HIDWORD(v8) >= v9 )
    {
      if ( !*((_BYTE *)a1 + 12) )
      {
        memmove(*((_DWORD *)a1 + 4) + HIDWORD(v8), a2, 0x1Cu);
        v10 = (unsigned int *)(*((_DWORD *)a1 + 1) + *((_DWORD *)a1 + 4));
        *v10 = v5;
        if ( a3 )
          memmove((int)(v10 + 7), a3, a4);
      }
      *((_DWORD *)a1 + 1) += v9;
LABEL_7:
      ++*((_DWORD *)a1 + 2);
      return 0;
    }
    v12 = v8 + v9;
    if ( (unsigned int)v8 + v9 >= (unsigned int)v8 && v12 <= 0x400000 )
    {
      v13 = 0x400000 - v12;
      if ( 0x400000 - v12 >= 0x1000 )
        v13 = 4096;
      v14 = v13 + v12;
      if ( *((_BYTE *)a1 + 12) )
      {
        v16 = 0;
      }
      else
      {
        v15 = ExAllocatePoolWithTag(1, v14, 542329939);
        v16 = v15;
        if ( !v15 )
          return -1073741670;
        memmove(v15, *((_DWORD *)a1 + 4), *((_DWORD *)a1 + 1));
        memmove(*((_DWORD *)a1 + 1) + v16, a2, 0x1Cu);
        v17 = (unsigned int *)(*((_DWORD *)a1 + 1) + v16);
        *v17 = v5;
        if ( a3 )
          memmove((int)(v17 + 7), a3, a4);
      }
      v18 = *((_DWORD *)a1 + 1);
      v19 = *((_DWORD *)a1 + 4);
      *(_DWORD *)a1 = v14;
      *((_DWORD *)a1 + 1) = v18 + v9;
      if ( v19 )
        ExFreePoolWithTag(v19);
      *((_DWORD *)a1 + 4) = v16;
      goto LABEL_7;
    }
  }
  return -2147483643;
}

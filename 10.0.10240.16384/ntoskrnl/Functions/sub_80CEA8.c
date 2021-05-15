// sub_80CEA8 
 
void __fastcall sub_80CEA8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, _DWORD *a21)
{
  int *v21; // r5
  unsigned int v22; // r7
  int v23; // r8
  int v24; // r9
  int v25; // r10
  int v26; // r0
  _DWORD *v27; // r2
  char *v28; // r2

  if ( (*(_DWORD *)(a4 + 24) & 0x1000) != 0 )
  {
    *v21 = 0;
  }
  else
  {
    *a21 = v22 + 32;
    if ( v22 + 32 >= v22 )
    {
      v26 = ExAllocatePoolWithTag(1, v22 + 32, 1936483400);
      *v21 = v26;
      if ( v26 )
      {
        memmove(v26, v25, v22);
        if ( v24 )
        {
          HalTranslateBusAddress(0, 0, *(_DWORD *)(*(_DWORD *)v23 + 36), 0);
        }
        else
        {
          a9 = *(_DWORD *)(*(_DWORD *)v23 + 36);
          a10 = 0;
        }
        v27 = (_DWORD *)*v21;
        *v27 = *(_DWORD *)*v21 + 1;
        v28 = (char *)v27 + v22;
        *(_DWORD *)v28 = 1;
        *((_DWORD *)v28 + 1) = 0;
        *((_DWORD *)v28 + 3) = 1;
        *((_WORD *)v28 + 5) = 0;
        *((_WORD *)v28 + 4) = 0;
        v28[16] = 1;
        v28[17] = 2;
        *((_WORD *)v28 + 9) = 1;
        *((_DWORD *)v28 + 5) = a9;
        *((_DWORD *)v28 + 6) = a10;
        *((_DWORD *)v28 + 7) = 8;
        JUMPOUT(0x794248);
      }
    }
  }
  *a21 = 0;
  JUMPOUT(0x79424A);
}

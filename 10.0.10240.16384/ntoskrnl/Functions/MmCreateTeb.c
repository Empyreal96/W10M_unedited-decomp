// MmCreateTeb 
 
int __fastcall MmCreateTeb(int a1, _DWORD *a2, _DWORD *a3, int a4, int *a5)
{
  int v8; // r4
  int v9; // r5
  int v11; // [sp+4h] [bp-3Ch] BYREF
  _BYTE v12[56]; // [sp+8h] [bp-38h] BYREF

  KiStackAttachProcess(a1, 0, (int)v12);
  v8 = MiCreatePebOrTeb(a1, 0, 4096, &v11);
  if ( v8 >= 0 )
  {
    v9 = v11;
    *(_DWORD *)(v11 + 16) = 7680;
    *(_DWORD *)(v9 + 464) = 65534;
    *(_WORD *)(v9 + 3066) = 522;
    *(_DWORD *)(v9 + 3068) = v9 + 3072;
    *(_DWORD *)(v9 + 36) = a3[1];
    *(_DWORD *)(v9 + 32) = *a3;
    *(_DWORD *)(v9 + 1720) = a3[1];
    *(_DWORD *)(v9 + 1716) = *a3;
    *(_DWORD *)(v9 + 24) = v9;
    *(_DWORD *)v9 = -1;
    *(_DWORD *)(v9 + 48) = *(_DWORD *)(a1 + 320);
    *(_DWORD *)(v9 + 4) = a2[2];
    *(_DWORD *)(v9 + 8) = a2[3];
    *(_DWORD *)(v9 + 3596) = a2[4];
    *(_DWORD *)(v9 + 3964) = BBTBuffer;
    KiUnstackDetachProcess((unsigned int)v12, 0);
    *a5 = v9;
  }
  else
  {
    KiUnstackDetachProcess((unsigned int)v12, 0);
  }
  return v8;
}

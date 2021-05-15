// sub_5338D4 
 
void __fastcall sub_5338D4(int a1, int a2, unsigned __int8 a3, int a4, int a5, int a6, unsigned __int8 a7, int a8, int a9, int *a10)
{
  int v10; // r4
  unsigned int v11; // r7
  int v12; // r9
  _DWORD *v13; // r10
  int v14; // r2
  char *v15; // r0
  int *v16; // r4

  if ( v11 < 0x200000 && (*(_BYTE *)(*v13 + 8 * a1 + 19) & a3) == 0 )
  {
    v14 = *(_DWORD *)(v10 + 6548) + 1;
    *(_DWORD *)(v10 + 6548) = v14;
    if ( (MmPageValidationFrequency & v14) == 0 )
    {
      if ( *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0x1384) )
      {
        a10 = (int *)MiMapPageInHyperSpaceWorker(v11, (int)&a7, v12);
        v15 = RtlCompareMemoryUlong(a10, (char *)0x1000, 0);
        v16 = a10;
        if ( v15 != (char *)4096 )
          MiPageNotZero(a10, v11);
        MiUnmapPageInHyperSpaceWorker((int)v16, a7, v12);
      }
    }
  }
  JUMPOUT(0x48CCFC);
}

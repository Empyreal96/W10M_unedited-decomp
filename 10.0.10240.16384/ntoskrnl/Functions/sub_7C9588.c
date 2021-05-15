// sub_7C9588 
 
void __fastcall sub_7C9588(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r0
  unsigned int v9; // r1
  int v10; // r3
  __int64 v11; // r4
  __int64 v12; // r2

  while ( *(_DWORD *)v11 != (_DWORD)v11 )
  {
    HIDWORD(v11) = *(_DWORD *)v11;
    v12 = *(_QWORD *)*(_DWORD *)v11;
    if ( __PAIR64__(*(_DWORD *)(v12 + 4), HIDWORD(v12)) != v11 )
      __fastfail(3u);
    *(_DWORD *)v11 = v12;
    *(_DWORD *)(v12 + 4) = v11;
    IopProcessSetInterfaceState(HIDWORD(v11) + 8, 1, 0);
    ExFreePoolWithTag(*(_DWORD *)(HIDWORD(v11) + 12));
    ExFreePoolWithTag(HIDWORD(v11));
  }
  v8 = ExReleaseResourceLite((int)&PnpRegistryDeviceResource);
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v10 = (__int16)(*(_WORD *)(v9 + 0x134) + 1);
  *(_WORD *)(v9 + 308) = v10;
  if ( !v10 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
    KiCheckForKernelApcDelivery(v8);
  __asm { POP.W           {R4,R5,R11,PC} }
}

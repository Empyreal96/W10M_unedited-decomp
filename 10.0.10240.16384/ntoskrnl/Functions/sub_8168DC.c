// sub_8168DC 
 
void sub_8168DC(int a1, int a2, int a3, int a4, int a5, ...)
{
  unsigned int v5; // r6
  int v6; // r8
  int v7; // r2
  int v8; // r3
  unsigned int v9; // r4
  unsigned int v10; // r0
  int v11; // r0
  unsigned int v12; // r1
  int v13; // r3
  int *v14; // r2
  unsigned int v15; // r0
  unsigned int v16; // r0
  int v17; // r4
  int v18; // r0
  int v19; // r3
  int *v20; // [sp+4h] [bp+4h] BYREF
  va_list va; // [sp+4h] [bp+4h]
  int v22; // [sp+8h] [bp+8h]
  int *v23; // [sp+Ch] [bp+Ch] BYREF
  va_list va1; // [sp+Ch] [bp+Ch]
  va_list va2; // [sp+10h] [bp+10h] BYREF

  va_start(va2, a5);
  va_start(va1, a5);
  va_start(va, a5);
  v20 = va_arg(va1, int *);
  v22 = va_arg(va1, _DWORD);
  va_copy(va2, va1);
  v23 = va_arg(va2, int *);
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = *(__int16 *)(v7 + 0x134) - 1;
  *(_WORD *)(v7 + 308) = v8;
  ExAcquireResourceExclusiveLite((int)&SepRmGlobalSaclLock, 1, v7, v8);
  if ( SepRmGlobalSaclFind((int **)va, (int **)va1, va2, 0) < 0 )
  {
    if ( v22 )
    {
      v17 = ExAllocatePoolWithTag(1, 16, 1818448711);
      if ( v17 )
      {
        v18 = ExAllocatePoolWithTag(1, v5, 1818448711);
        *(_DWORD *)(v17 + 8) = v18;
        if ( v18 )
        {
          *(_WORD *)(v17 + 6) = v5;
          *(_WORD *)(v17 + 4) = v5;
          memmove(v18, v6, v5);
          *(_DWORD *)(v17 + 12) = a5;
          v19 = SepRmGlobalSaclHead;
          SepRmGlobalSaclHead = v17;
          *(_DWORD *)v17 = v19;
          JUMPOUT(0x7AD95A);
        }
        ExFreePoolWithTag(v17);
      }
    }
  }
  else
  {
    v9 = (unsigned int)v20;
    if ( v22 )
    {
      v10 = v20[3];
      if ( v10 )
        ExFreePoolWithTag(v10);
      *(_DWORD *)(v9 + 12) = a5;
      v11 = ExReleaseResourceLite((int)&SepRmGlobalSaclLock);
      v12 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v13 = (__int16)(*(_WORD *)(v12 + 0x134) + 1);
      *(_WORD *)(v12 + 308) = v13;
      if ( !v13 && *(_DWORD *)(v12 + 100) != v12 + 100 && !*(_WORD *)(v12 + 310) )
        KiCheckForKernelApcDelivery(v11);
      JUMPOUT(0x7AD966);
    }
    v14 = v23;
    if ( !v23 )
      v14 = &SepRmGlobalSaclHead;
    *v14 = *v20;
    v15 = *(_DWORD *)(v9 + 8);
    if ( v15 )
    {
      ExFreePoolWithTag(v15);
      *(_DWORD *)(v9 + 8) = 0;
    }
    v16 = *(_DWORD *)(v9 + 12);
    if ( v16 )
    {
      ExFreePoolWithTag(v16);
      *(_DWORD *)(v9 + 12) = 0;
    }
    ExFreePoolWithTag(v9);
  }
  JUMPOUT(0x7AD958);
}

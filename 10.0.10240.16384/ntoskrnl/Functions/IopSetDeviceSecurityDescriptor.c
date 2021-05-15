// IopSetDeviceSecurityDescriptor 
 
int __fastcall IopSetDeviceSecurityDescriptor(int a1, _DWORD *a2, int a3)
{
  unsigned int v6; // r5
  int v7; // r0
  int v8; // r6
  unsigned int *v9; // r4
  int v10; // r1
  int v11; // r0
  int v12; // r3
  int v13; // r4
  int v14; // r2
  int v15; // r3
  int v16; // r2
  int v17; // r0
  __int16 v18; // r3
  int v19; // r1
  int v21; // r0
  __int16 v22; // r3
  int v23; // [sp+8h] [bp-28h] BYREF
  int v24[9]; // [sp+Ch] [bp-24h] BYREF

  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  while ( 1 )
  {
    --*(_WORD *)(v6 + 308);
    v7 = ExAcquireResourceSharedLite((int)&IopSecurityResource, 1);
    v8 = *(_DWORD *)(a1 + 152);
    if ( v8 )
    {
      v9 = (unsigned int *)(v8 - 8);
      do
        v10 = __ldrex(v9);
      while ( __strex(v10 + 1, v9) );
      if ( v10 <= 0 )
        sub_7EEF94(v7);
    }
    v11 = ExReleaseResourceLite((int)&IopSecurityResource);
    v12 = (__int16)(*(_WORD *)(v6 + 308) + 1);
    *(_WORD *)(v6 + 308) = v12;
    if ( !v12 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
      KiCheckForKernelApcDelivery(v11);
    v23 = v8;
    v13 = SeSetSecurityDescriptorInfo(0, a2, a3, &v23);
    if ( v13 < 0 )
      break;
    v13 = ObLogSecurityDescriptor(v23, v24, 1);
    ExFreePoolWithTag(v23);
    if ( v13 < 0 )
      goto LABEL_19;
    v15 = *(__int16 *)(v6 + 308) - 1;
    *(_WORD *)(v6 + 308) = v15;
    ExAcquireResourceExclusiveLite((int)&IopSecurityResource, 1, v14, v15);
    if ( *(_DWORD *)(a1 + 152) == v8 )
    {
      v16 = *(_DWORD *)(a1 + 176);
      *(_DWORD *)(a1 + 152) = v24[0];
      *(_DWORD *)(v16 + 16) &= 0xFFFFF7FF;
      v17 = ExReleaseResourceLite((int)&IopSecurityResource);
      v18 = *(_WORD *)(v6 + 308) + 1;
      *(_WORD *)(v6 + 308) = v18;
      if ( !v18 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
        KiCheckForKernelApcDelivery(v17);
      v19 = 2;
      goto LABEL_13;
    }
    v21 = ExReleaseResourceLite((int)&IopSecurityResource);
    v22 = *(_WORD *)(v6 + 308) + 1;
    *(_WORD *)(v6 + 308) = v22;
    if ( !v22 && *(_DWORD *)(v6 + 100) != v6 + 100 && !*(_WORD *)(v6 + 310) )
      KiCheckForKernelApcDelivery(v21);
    ObDereferenceSecurityDescriptor(v8, 1);
    ObDereferenceSecurityDescriptor(v24[0], 1);
  }
  if ( v8 )
  {
LABEL_19:
    v19 = 1;
LABEL_13:
    ObDereferenceSecurityDescriptor(v8, v19);
  }
  return v13;
}

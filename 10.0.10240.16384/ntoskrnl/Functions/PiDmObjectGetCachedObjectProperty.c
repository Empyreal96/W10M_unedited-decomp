// PiDmObjectGetCachedObjectProperty 
 
int __fastcall PiDmObjectGetCachedObjectProperty(int a1, int a2, int a3, int a4, unsigned int a5, int a6, int a7, int a8, int a9)
{
  int v11; // r7
  int result; // r0
  int v13; // r9
  int v14; // r6
  unsigned int v15; // r2
  int *v16; // r0
  int v17; // r5
  unsigned int *v18; // r2
  unsigned int v19; // r1
  int v20; // r0
  unsigned int v21; // r1
  __int16 v22; // r3
  int v23; // r6
  int v24; // r4
  int v25; // r6
  char *v26; // [sp+18h] [bp-68h] BYREF
  int v27; // [sp+1Ch] [bp-64h] BYREF
  char v28[96]; // [sp+20h] [bp-60h] BYREF

  if ( a7 )
  {
    v11 = a8;
    if ( !a8 )
      return sub_7C6950();
  }
  else
  {
    v11 = 0;
  }
  if ( a1 >= 6 )
    return -1073741802;
  if ( a4 )
    return -1073741802;
  v13 = 0;
  v14 = PiDmGetObjectManagerForObjectType(a1);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v15 + 308);
  ExAcquireResourceSharedLite(v14, 1);
  v26 = v28;
  if ( a2
    && PiDmInitializeComparisonObject(a2, *(_DWORD *)(v14 + 112), v28) >= 0
    && (v16 = (int *)RtlLookupElementGenericTableAvl(v14 + 56, (int)&v26)) != 0 )
  {
    v17 = *v16;
    if ( *v16 )
    {
      __dmb(0xBu);
      v18 = (unsigned int *)(v17 + 4);
      do
        v19 = __ldrex(v18);
      while ( __strex(v19 + 1, v18) );
      __dmb(0xBu);
      goto LABEL_13;
    }
  }
  else
  {
    v17 = 0;
  }
  v13 = -1073741772;
LABEL_13:
  v20 = ExReleaseResourceLite(v14);
  v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v22 = *(_WORD *)(v21 + 0x134) + 1;
  *(_WORD *)(v21 + 308) = v22;
  if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
    KiCheckForKernelApcDelivery(v20);
  if ( v13 < 0 )
    return v13;
  if ( a1 == 3
    && *(_DWORD *)(a5 + 16) == 2
    && !memcmp(a5, (unsigned int)DEVPKEY_Device_ContainerId, 16)
    && PiDmObjectGetCachedObjectReference(3, a2, v17, DEVPKEY_Device_InstanceId, &v27) >= 0 )
  {
    v24 = v27;
    v25 = PiDmObjectGetCachedObjectPropertyData(*(_DWORD *)(v27 + 20), *(_DWORD *)(v27 + 12), v27, a5, a6, a7, v11, a9);
    PiDmObjectRelease(v24);
    PiDmObjectRelease(v17);
    result = v25;
  }
  else
  {
    v23 = PiDmObjectGetCachedObjectPropertyData(a1, a2, v17, a5, a6, a7, v11, a9);
    PiDmObjectRelease(v17);
    result = v23;
  }
  return result;
}

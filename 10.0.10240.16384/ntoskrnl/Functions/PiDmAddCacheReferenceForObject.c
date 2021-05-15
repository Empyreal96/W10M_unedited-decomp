// PiDmAddCacheReferenceForObject 
 
int __fastcall PiDmAddCacheReferenceForObject(int a1, unsigned __int16 *a2, int *a3)
{
  int v6; // r5
  void *v7; // r6
  unsigned int v8; // r4
  int v9; // r3
  int v10; // r2
  int v11; // r4
  int *v12; // r0
  int v13; // r3
  unsigned int *v14; // r2
  unsigned int v15; // r1
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  int v20; // [sp+8h] [bp-70h] BYREF
  _DWORD *v21; // [sp+Ch] [bp-6Ch] BYREF
  _DWORD *v22; // [sp+10h] [bp-68h] BYREF
  int v23; // [sp+14h] [bp-64h] BYREF
  _DWORD v24[24]; // [sp+18h] [bp-60h] BYREF

  v22 = v24;
  v21 = 0;
  v6 = 0;
  v7 = PiDmGetObjectManagerForObjectType(a1);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(__int16 *)(v8 + 0x134) - 1;
  *(_WORD *)(v8 + 308) = v9;
  ExAcquireResourceExclusiveLite((int)v7, 1, v10, v9);
  v11 = PiDmInitializeComparisonObject(a2, a1, v24);
  if ( v11 < 0 )
    goto LABEL_7;
  v12 = (int *)RtlLookupElementGenericTableFullAvl((int)v7 + 56, (int)&v22, &v21, &v23);
  if ( v12 )
    v6 = *v12;
  else
    v6 = 0;
  v20 = v6;
  if ( v6 )
  {
    v13 = *(_DWORD *)(v6 + 8) + 1;
LABEL_6:
    *(_DWORD *)(v6 + 8) = v13;
    goto LABEL_7;
  }
  v11 = PiDmObjectCreate(a1, a2, &v20);
  if ( v11 >= 0 )
  {
    if ( !RtlInsertElementGenericTableFullAvl((int)v7 + 56, (int)&v20, 4u, 0, v21, v23) )
      return sub_7C8F54();
    v6 = v20;
    v13 = 1;
    goto LABEL_6;
  }
  v6 = v20;
LABEL_7:
  if ( a3 )
  {
    *a3 = v6;
    if ( v6 )
    {
      __dmb(0xBu);
      v14 = (unsigned int *)(v6 + 4);
      do
        v15 = __ldrex(v14);
      while ( __strex(v15 + 1, v14) );
      __dmb(0xBu);
    }
  }
  v16 = ExReleaseResourceLite((int)v7);
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v16);
  return v11;
}

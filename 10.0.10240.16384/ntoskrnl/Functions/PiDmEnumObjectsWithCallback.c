// PiDmEnumObjectsWithCallback 
 
int __fastcall PiDmEnumObjectsWithCallback(int a1, int (__fastcall *a2)(unsigned int *, int, char *), int a3)
{
  int v5; // r5
  void *v6; // r0
  int v7; // r6
  const __int16 *v8; // r3
  unsigned int v9; // r2
  unsigned int **v10; // r0
  unsigned int *v12; // r4
  unsigned int *v13; // r2
  unsigned int v14; // r1
  int v15; // r0
  unsigned int v16; // r1
  __int16 v17; // r3
  unsigned int v18; // r2
  unsigned int **v19; // r0
  unsigned int *v20; // r2
  unsigned int v21; // r1
  int v22; // r0
  unsigned int v23; // r1
  __int16 v24; // r3
  char v25[4]; // [sp+10h] [bp-78h] BYREF
  char *v26; // [sp+14h] [bp-74h] BYREF
  int v27; // [sp+18h] [bp-70h] BYREF
  int v28; // [sp+1Ch] [bp-6Ch] BYREF
  int (__fastcall *v29)(unsigned int *, int, char *); // [sp+20h] [bp-68h]
  char v30; // [sp+28h] [bp-60h] BYREF
  const __int16 *v31; // [sp+34h] [bp-54h]
  int v32; // [sp+38h] [bp-50h]
  int v33; // [sp+3Ch] [bp-4Ch]

  v26 = &v30;
  v27 = 0;
  v28 = 0;
  v25[0] = 0;
  v29 = a2;
  v5 = 0;
  v6 = PiDmGetObjectManagerForObjectType(a1);
  v32 = 0;
  v33 = a1;
  v7 = (int)v6;
  if ( a1 == 3 )
    v8 = L"\\\\?\\";
  else
    v8 = (const __int16 *)&dword_8CE900;
  v31 = v8;
  v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v9 + 308);
  ExAcquireResourceSharedLite((int)v6, 1);
  v10 = (unsigned int **)RtlEnumerateGenericTableLikeADirectory(v7 + 56, 0, 0, 0, &v28, &v27, (int)&v26);
  if ( !v10 )
    return sub_7EE100();
  v12 = *v10;
  __dmb(0xBu);
  v13 = v12 + 1;
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 + 1, v13) );
  __dmb(0xBu);
  v15 = ExReleaseResourceLite(v7);
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v17 = *(_WORD *)(v16 + 0x134) + 1;
  *(_WORD *)(v16 + 308) = v17;
  if ( !v17 && *(_DWORD *)(v16 + 100) != v16 + 100 && !*(_WORD *)(v16 + 310) )
    KiCheckForKernelApcDelivery(v15);
  if ( v12 )
  {
    while ( 1 )
    {
      if ( PiDmObjectIsEnumerable(v12) )
        v5 = v29(v12, a3, v25);
      if ( v5 < 0 || v25[0] )
        break;
      v26 = (char *)v12;
      v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      --*(_WORD *)(v18 + 308);
      ExAcquireResourceSharedLite(v7, 1);
      v19 = (unsigned int **)RtlEnumerateGenericTableLikeADirectory(v7 + 56, 0, 0, 1, &v28, &v27, (int)&v26);
      if ( v19 )
      {
        v12 = *v19;
        __dmb(0xBu);
        v20 = v12 + 1;
        do
          v21 = __ldrex(v20);
        while ( __strex(v21 + 1, v20) );
        __dmb(0xBu);
      }
      else
      {
        v12 = 0;
      }
      v22 = ExReleaseResourceLite(v7);
      v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v24 = *(_WORD *)(v23 + 0x134) + 1;
      *(_WORD *)(v23 + 308) = v24;
      if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
        KiCheckForKernelApcDelivery(v22);
      PiDmObjectRelease((int)v26);
      if ( !v12 )
        return v5;
    }
    PiDmObjectRelease((int)v12);
  }
  return v5;
}

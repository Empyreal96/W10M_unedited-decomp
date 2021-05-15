// MiCombineIdenticalPages 
 
int __fastcall MiCombineIdenticalPages(int a1, int a2, int a3, char a4, _DWORD *a5)
{
  int v7; // r6
  int v8; // r7
  int v9; // r5
  int v10; // r1
  int v11; // r2
  unsigned int *v12; // r2
  unsigned int v13; // r1
  unsigned int *v14; // r1
  int v15; // r3
  unsigned int v16; // r4
  unsigned int *v17; // r1
  int v18; // r3
  unsigned int v19; // r4
  unsigned int *v20; // r1
  int v21; // r3
  unsigned int v22; // r4
  int v23; // r0
  __int16 v24; // r3
  int v25; // [sp+8h] [bp-58h] BYREF
  int v26; // [sp+10h] [bp-50h] BYREF
  int v27; // [sp+14h] [bp-4Ch]
  int v28; // [sp+18h] [bp-48h]
  int v29; // [sp+1Ch] [bp-44h]
  char v30[64]; // [sp+20h] [bp-40h] BYREF

  *a5 = 0;
  v26 = 0;
  v27 = 0;
  v28 = 0;
  v29 = 0;
  if ( dword_681254 )
    return sub_80FC5C();
  v7 = 0;
  if ( !a2 || (v8 = ObReferenceObjectByHandle(a2, 1, ExEventObjectType, a4, (int)&v25, 0), v7 = v25, v8 >= 0) )
  {
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v9 + 308);
    MI_LOCK_COMBINE_PAGES_EXCLUSIVE(a1, v9);
    if ( *(_DWORD *)(a1 + 3460) || (v8 = MiInitializeStaticCombining((_DWORD *)(a1 + 3280), v10, v11, 0), v8 >= 0) )
    {
      MI_UNLOCK_COMBINE_PAGES_EXCLUSIVE(a1, v9);
      MiCombiningInProgress((int *)(a1 + 3280), (int)v30, 1);
      v8 = MiCombineAllPhysicalMemory((int *)(a1 + 3280), v7, (int)v30, (int)&v26);
      v12 = (unsigned int *)(a1 + 3496);
      *a5 = v26;
      do
        v13 = __ldrex(v12);
      while ( __strex(v13 + 1, v12) );
      v14 = (unsigned int *)(a1 + 3488);
      v15 = v27;
      do
        v16 = __ldrex(v14);
      while ( __strex(v16 + v15, v14) );
      v17 = (unsigned int *)(a1 + 3472);
      v18 = v28;
      do
        v19 = __ldrex(v17);
      while ( __strex(v19 + v18, v17) );
      v20 = (unsigned int *)(a1 + 3480);
      v21 = v29;
      do
        v22 = __ldrex(v20);
      while ( __strex(v22 + v21, v20) );
      v23 = MiCombiningInProgress((int *)(a1 + 3280), (int)v30, 0);
    }
    else
    {
      v23 = MI_UNLOCK_COMBINE_PAGES_EXCLUSIVE(a1, v9);
    }
    v24 = *(_WORD *)(v9 + 308) + 1;
    *(_WORD *)(v9 + 308) = v24;
    if ( !v24 && *(_DWORD *)(v9 + 100) != v9 + 100 && !*(_WORD *)(v9 + 310) )
      KiCheckForKernelApcDelivery(v23);
    if ( v7 )
      ObfDereferenceObject(v7);
  }
  return v8;
}

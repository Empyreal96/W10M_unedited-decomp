// sub_7BEFC8 
 
void __fastcall sub_7BEFC8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
{
  int v14; // r0
  unsigned int v15; // r1
  __int16 v16; // r3
  int v17; // r0
  int v18; // r5
  unsigned int v19; // r0
  int v20; // r1
  int v21; // r2
  int v22; // r3
  int v23; // r4
  int v24; // r5
  _DWORD *v25; // r6
  int v26; // r7
  int v27; // r8
  _DWORD *v28; // r9
  unsigned int *v29; // r2
  unsigned int v30; // r1
  signed int v31; // r1
  int v32; // r0
  unsigned int v33; // r1
  int v34; // r3

  __dmb(0xBu);
  v29 = (unsigned int *)(v23 + 20);
  do
  {
    v30 = __ldrex(v29);
    v31 = v30 - 1;
  }
  while ( __strex(v31, v29) );
  if ( v31 > 0 )
  {
    v32 = ExReleaseResourceLite(v27 + 8 * v24);
    v33 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v34 = (__int16)(*(_WORD *)(v33 + 0x134) + 1);
    *(_WORD *)(v33 + 308) = v34;
    if ( !v34 && *(_DWORD *)(v33 + 100) != v33 + 100 && !*(_WORD *)(v33 + 310) )
      KiCheckForKernelApcDelivery(v32);
  }
  else
  {
    if ( v31 )
      __fastfail(0xEu);
    __dmb(0xBu);
    *v28 = *(_DWORD *)v23;
    v14 = ExReleaseResourceLite(v27 + 8 * v24);
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = *(_WORD *)(v15 + 0x134) + 1;
    *(_WORD *)(v15 + 308) = v16;
    if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
      KiCheckForKernelApcDelivery(v14);
    if ( (*(_DWORD *)(v23 + 24) & 4) != 0 && (*(_DWORD *)(v23 + 12) || *(_DWORD *)(v23 + 16)) )
      SepDeReferenceLogonSession((_DWORD *)(v23 + 12), *(_DWORD *)(v23 + 88));
    v17 = *(_DWORD *)(v23 + 32);
    if ( v17 )
    {
      ObfDereferenceObject(v17);
      *(_DWORD *)(v23 + 32) = 0;
    }
    v18 = *(_DWORD *)(v23 + 28);
    if ( v18 )
    {
      *(_DWORD *)(v23 + 28) = 0;
      SepCleanupLUIDDeviceMapDirectory(v25, v26);
      ObfDereferenceDeviceMap(v18, v20, v21, v22);
    }
    if ( (*(_DWORD *)(v23 + 24) & 1) != 0 )
      SepInformFileSystemsOfDeletedLogon(v25, v26);
    v19 = *(_DWORD *)(v23 + 40);
    if ( v19 )
      ExFreePoolWithTag(v19);
    SepDeleteLogonSessionClaims(v23);
    if ( SepTokenSidSharingEnabled )
      SepDeleteLogonSessionSidValues(v23);
    ObDestroyHandleRevocationBlock((_DWORD **)(v23 + 72));
    SepInformLsaOfDeletedLogon(v25, *(_DWORD *)(v23 + 88), (_DWORD *)v23);
    SepDeleteSessionLowboxEntries();
  }
  __asm { POP.W           {R2-R9,R11,PC} }
}

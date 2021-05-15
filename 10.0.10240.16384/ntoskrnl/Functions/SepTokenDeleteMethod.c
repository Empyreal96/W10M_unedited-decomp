// SepTokenDeleteMethod 
 
int __fastcall SepTokenDeleteMethod(int a1, int a2, int a3, int a4)
{
  int result; // r0
  _DWORD *v6; // r1
  int v7; // r1
  _DWORD *v8; // r5
  unsigned int *v9; // r2
  unsigned int i; // r1
  unsigned int v11; // r6
  int v12; // r0
  unsigned int v13; // r0
  unsigned int v14; // r0
  _DWORD *v15; // r0
  int v16; // r1
  int v17; // [sp+0h] [bp-18h] BYREF
  int v18; // [sp+4h] [bp-14h]
  int v19; // [sp+8h] [bp-10h]

  v17 = a2;
  v18 = a3;
  v19 = a4;
  if ( *(_DWORD *)(a1 + 636) )
    return sub_7FB418();
  if ( SepTokenSidSharingEnabled )
    SepDeleteTokenUserAndGroups((_DWORD *)a1);
  if ( (*(_DWORD *)(a1 + 176) & 0x20) == 0 )
  {
    v6 = *(_DWORD **)(a1 + 628);
    if ( v6 )
      SepDereferenceLowBoxNumberEntry(*(_DWORD *)(a1 + 120), v6);
    v7 = *(_DWORD *)(a1 + 632);
    if ( v7 )
      SepDereferenceLowBoxHandlesEntry(*(_DWORD *)(a1 + 192), v7);
    v8 = *(_DWORD **)(a1 + 192);
    v9 = v8 + 5;
    __pld(v8 + 5);
    for ( i = v8[5]; (int)(i - 1) > 0; i = v11 )
    {
      __dmb(0xBu);
      do
        v11 = __ldrex(v9);
      while ( v11 == i && __strex(i - 1, v9) );
      if ( v11 == i )
        goto LABEL_16;
    }
    if ( i != 1 )
      __fastfail(0xEu);
    v16 = v8[22];
    v17 = v8[1];
    v18 = v8[2];
    SepDeReferenceLogonSession(&v17, v16);
  }
LABEL_16:
  v12 = *(_DWORD *)(a1 + 644);
  if ( v12 )
    ObfDereferenceObject(v12);
  if ( *(_BYTE *)(a1 + 118) == 2 )
    SepModifyTokenPolicyCounter(a1 + 88, 0);
  SepRefDerefLuidToIndexEntryIfNecessary(a1, 1);
  AuthzBasepFreeSecurityAttributesList(*(_DWORD *)(a1 + 476));
  ExFreePoolWithTag(*(_DWORD *)(a1 + 476));
  v13 = *(_DWORD *)(a1 + 160);
  if ( v13 )
    ExFreePoolWithTag(v13);
  if ( *(_DWORD *)(a1 + 484) )
    SepFreeTokenCapabilities(a1);
  v14 = *(_DWORD *)(a1 + 480);
  if ( v14 )
    ExFreePoolWithTag(v14);
  v15 = *(_DWORD **)(a1 + 48);
  if ( v15 )
  {
    ExDeleteResourceLite(v15);
    ExFreePoolWithTag(*(_DWORD *)(a1 + 48));
  }
  result = *(_DWORD *)(a1 + 640);
  if ( result )
    result = ExFreePoolWithTag(result);
  return result;
}

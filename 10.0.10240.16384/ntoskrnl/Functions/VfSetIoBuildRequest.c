// VfSetIoBuildRequest 
 
int __fastcall VfSetIoBuildRequest(_DWORD *a1)
{
  int v2; // r5
  _DWORD *v3; // r0
  int v4; // r3
  int v5; // r2
  int v6; // r3

  v2 = 0;
  v3 = (_DWORD *)VfIrpDatabaseEntryFindAndLock(a1);
  if ( v3 )
  {
    v2 = 1;
    v3[9] |= 0x1000u;
    v4 = a1[2];
    if ( (v4 & 0x10) != 0 && (v4 & 0x40) != 0 && (v4 & 0x20) != 0 )
    {
      v5 = a1[24];
      v6 = *(unsigned __int8 *)(v5 - 40);
      if ( v6 == 14 || v6 == 15 )
      {
        v3[30] = a1[3];
        v3[31] = *(_DWORD *)(v5 - 32);
      }
    }
    VfIrpDatabaseEntryReleaseLock(v3);
  }
  return v2;
}

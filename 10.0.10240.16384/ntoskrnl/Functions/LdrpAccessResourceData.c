// LdrpAccessResourceData 
 
int __fastcall LdrpAccessResourceData(int a1, unsigned int a2, int a3, int a4)
{
  int v5; // r5
  unsigned int v8; // r0
  int v9; // r1
  int v11; // r0
  int v12; // [sp+4h] [bp-1Ch] BYREF
  int v13[6]; // [sp+8h] [bp-18h] BYREF

  v13[0] = a4;
  v5 = a1;
  v12 = 0;
  if ( !a1 || !a2 )
    return -1073741811;
  if ( PnPBootDriversInitialized != 1 )
    return LdrpAccessResourceDataNoMultipleLanguage(v5, a2, a3, a4);
  v8 = RtlImageDirectoryEntryToData(a1, 1, 2, (int)v13);
  if ( v8 )
  {
    if ( a2 >= v8 )
      return sub_80BFB4();
    v11 = LdrpGetAlternateResourceModuleHandleEx(v5, v9, a2, &v12);
    if ( v11 )
    {
      if ( v11 != -1 )
        v5 = v11;
    }
    return LdrpAccessResourceDataNoMultipleLanguage(v5, a2, a3, a4);
  }
  return -1073741687;
}

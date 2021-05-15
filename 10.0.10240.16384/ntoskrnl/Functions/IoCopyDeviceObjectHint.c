// IoCopyDeviceObjectHint 
 
int __fastcall IoCopyDeviceObjectHint(int a1, int a2)
{
  int v4; // r4
  int v5; // r1
  _DWORD *v6; // r5
  int v8[4]; // [sp+8h] [bp-10h] BYREF

  v4 = 0;
  v8[0] = IopGetFileObjectExtension(a2, 1, 0);
  if ( v8[0] )
    return -1073741823;
  v6 = (_DWORD *)IopGetFileObjectExtension(a1, 1, 0);
  if ( v6 )
  {
    v4 = IopGetSetSpecificExtension(a2, v5, 16, 1, v8, 0);
    if ( !v4 )
      *(_DWORD *)v8[0] = *v6;
  }
  return v4;
}

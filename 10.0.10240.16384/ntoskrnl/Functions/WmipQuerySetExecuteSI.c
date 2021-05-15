// WmipQuerySetExecuteSI 
 
int __fastcall WmipQuerySetExecuteSI(int a1, _DWORD *a2, char a3, int a4, int a5, unsigned int a6, unsigned int *a7)
{
  int v10; // r4
  int v11; // r0
  int v12; // r10
  char v13; // [sp+8h] [bp-80h] BYREF
  char v14[3]; // [sp+9h] [bp-7Fh] BYREF
  int v15; // [sp+Ch] [bp-7Ch] BYREF
  int *v16; // [sp+10h] [bp-78h] BYREF
  int v17[5]; // [sp+14h] [bp-74h] BYREF
  int v18; // [sp+28h] [bp-60h] BYREF

  v17[1] = (int)a7;
  if ( a1 )
    return sub_816360();
  v11 = ObReferenceObjectByHandle(
          *(_DWORD *)(a5 + 16),
          DesiredAccessForFunction[a4],
          WmipGuidObjectType,
          a3,
          (int)v17,
          0);
  v12 = v17[0];
  v10 = v11;
  if ( v11 >= 0 )
  {
    v16 = &v18;
    v15 = 16;
    v10 = WmipPrepareWnodeSI(v17[0], a5, &v15, &v16, &v13, v14);
    if ( v10 >= 0 )
    {
      if ( v14[0] )
        JUMPOUT(0x816398);
      if ( v13 )
        JUMPOUT(0x8163AC);
      if ( !a2 )
        JUMPOUT(0x816466);
      v10 = WmipForwardWmiIrp(a2, a4, *(_DWORD *)(a5 + 4), a5 + 24, a6, a5);
      if ( v10 >= 0 )
      {
        *a7 = a2[7];
        if ( *a7 > a6 )
          v10 = -1073741811;
      }
    }
    if ( v12 )
      ObfDereferenceObject(v12);
  }
  return v10;
}

// SepLengthSidAndAttributesArray 
 
int __fastcall SepLengthSidAndAttributesArray(unsigned int a1, unsigned int a2, _DWORD *a3)
{
  int v6; // r0
  unsigned int v7; // r5
  int v8; // r4
  int v10; // [sp+4h] [bp-2Ch]
  int v11; // [sp+8h] [bp-28h]
  unsigned int v12; // [sp+18h] [bp-18h] BYREF
  int v13[5]; // [sp+1Ch] [bp-14h] BYREF

  v12 = 0;
  v13[0] = 0;
  v6 = ExAllocatePoolWithTag(1, 4, 1632855379);
  v7 = v6;
  if ( !v6 )
    return -1073741670;
  v8 = SeCaptureSidAndAttributesArray(a1, a2, 0, v6, 4u, v10, v11, v13, &v12);
  if ( v8 == -1073741789 )
    v8 = 0;
  *a3 = v12;
  ExFreePoolWithTag(v7);
  return v8;
}

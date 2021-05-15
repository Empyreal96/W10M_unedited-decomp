// SeIsSystemContext 
 
int __fastcall SeIsSystemContext(int a1, _BYTE *a2)
{
  int v4; // [sp+18h] [bp-20h] BYREF
  char v5[4]; // [sp+1Ch] [bp-1Ch] BYREF
  _DWORD v6[6]; // [sp+20h] [bp-18h] BYREF

  v4 = 0;
  v6[0] = 0;
  v6[1] = 0;
  v6[3] = 0;
  v6[2] = a1;
  *a2 = 0;
  if ( SeAccessCheck(
         (int)SepSystemContextSecurityDescriptor,
         (int)v6,
         0,
         1,
         0,
         0,
         (int)SystemContextGenericMapping,
         1,
         (int)v5,
         (int)&v4) )
  {
    *a2 = 1;
  }
  return v4;
}

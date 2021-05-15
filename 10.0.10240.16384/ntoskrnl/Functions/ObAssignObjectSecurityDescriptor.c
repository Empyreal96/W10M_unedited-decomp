// ObAssignObjectSecurityDescriptor 
 
int __fastcall ObAssignObjectSecurityDescriptor(int a1, unsigned int a2, int a3, int a4)
{
  int v7; // r5
  int v8; // r3
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a4;
  if ( !a2 )
    return sub_805980();
  v7 = ObLogSecurityDescriptor(a2, v9, 8);
  if ( v7 >= 0 )
  {
    ExFreePoolWithTag(a2);
    if ( v9[0] )
      v8 = v9[0] + 7;
    else
      v8 = 0;
    *(_DWORD *)(a1 - 4) = v8;
  }
  return v7;
}

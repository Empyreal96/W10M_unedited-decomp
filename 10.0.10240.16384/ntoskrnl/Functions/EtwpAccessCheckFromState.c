// EtwpAccessCheckFromState 
 
int __fastcall EtwpAccessCheckFromState(int a1, int a2, int a3)
{
  int v5; // [sp+18h] [bp-10h] BYREF
  int v6; // [sp+1Ch] [bp-Ch] BYREF
  char v7[8]; // [sp+20h] [bp-8h] BYREF

  v5 = 0;
  EtwpGetSecurityDescriptorByGuid(a1, &v5);
  SeAccessCheckFromState(v5, a3, 0, 128, 0, 0, (int)EtwpGenericMapping, 1, (int)v7, (int)&v6);
  EtwpFreeSecurityDescriptor(&v5);
  return v6;
}

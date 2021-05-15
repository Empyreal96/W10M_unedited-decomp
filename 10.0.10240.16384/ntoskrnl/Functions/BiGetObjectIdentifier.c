// BiGetObjectIdentifier 
 
int __fastcall BiGetObjectIdentifier(unsigned __int16 *a1, unsigned __int16 *a2, int a3, int a4)
{
  int v5; // r4
  unsigned __int16 *v7[2]; // [sp+0h] [bp-18h] BYREF
  _DWORD v8[4]; // [sp+8h] [bp-10h] BYREF

  v7[0] = a1;
  v7[1] = a2;
  v8[0] = a3;
  v8[1] = a4;
  v5 = BiGetKeyName(a1, v7);
  if ( v5 >= 0 )
  {
    RtlInitUnicodeString((unsigned int)v8, v7[0]);
    v5 = RtlGUIDFromString((unsigned __int16 *)v8, a2);
    ExFreePoolWithTag((unsigned int)v7[0]);
  }
  return v5;
}

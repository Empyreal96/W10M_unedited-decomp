// BiDeleteRegistryValue 
 
int __fastcall BiDeleteRegistryValue(int a1)
{
  int v2; // r5
  int v3; // r4
  int v5; // [sp+0h] [bp-20h] BYREF
  char v6[24]; // [sp+8h] [bp-18h] BYREF

  RtlInitUnicodeString((unsigned int)v6, L"TreatAsSystem");
  v5 = 0;
  v2 = BiOpenKey(a1, L"Description", 131103, &v5);
  v3 = v5;
  if ( v2 >= 0 )
    v2 = BiZwDeleteValueKey();
  if ( v3 != a1 && v3 )
    BiZwClose();
  return v2;
}

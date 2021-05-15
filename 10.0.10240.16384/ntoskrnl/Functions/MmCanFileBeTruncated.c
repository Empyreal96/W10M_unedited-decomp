// MmCanFileBeTruncated 
 
int __fastcall MmCanFileBeTruncated(int a1, int *a2)
{
  int v2; // r0
  int v3; // r4
  int v5; // r3
  char v6[8]; // [sp+8h] [bp-18h] BYREF
  int v7[4]; // [sp+10h] [bp-10h] BYREF

  if ( a2 )
  {
    v7[0] = *a2;
    v5 = a2[1];
    a2 = v7;
    v7[1] = v5;
  }
  v2 = MiCanFileBeTruncatedInternal(a1, a2, 0, 0, v6);
  v3 = (unsigned __int8)v6[0];
  if ( v6[0] == 17 )
    return 0;
  if ( v2 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
      return sub_51AE4C();
    __dmb(0xBu);
    *(_DWORD *)(v2 + 36) = 0;
    KfLowerIrql(v3);
  }
  return 1;
}

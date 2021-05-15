// MmDoesFileHaveUserWritableReferences 
 
int __fastcall MmDoesFileHaveUserWritableReferences(int a1, int a2, int a3, int a4)
{
  int v4; // r0
  int v5; // r4
  int v7; // [sp+0h] [bp-8h] BYREF

  v7 = a4;
  v4 = MiLockSectionControlArea(a1, 1, &v7);
  if ( !v4 )
    return 0;
  v5 = *(_DWORD *)(v4 + 52);
  if ( !v5 )
    v5 = *(_QWORD *)(v4 + 64) > 1ui64;
  if ( (dword_682604 & 0x10000) == 0 )
  {
    __dmb(0xBu);
    *(_DWORD *)(v4 + 36) = 0;
    KfLowerIrql((unsigned __int8)v7);
    return v5;
  }
  return sub_53D1BC();
}

// sub_812DCC 
 
void __fastcall sub_812DCC(int a1, int a2, int a3, int a4, int a5)
{
  unsigned int *v5; // r6
  int v6; // r0
  int v7; // r3
  unsigned int v8; // r5

  v6 = ExAllocatePoolWithTag(1, a5, 1262764866);
  v8 = v6;
  if ( v6 )
  {
    if ( SyspartGetSystemPartition(v6, a5, (int)&a5, v7) >= 0 )
      *v5 = v8;
    else
      ExFreePoolWithTag(v8);
  }
  JUMPOUT(0x7A45E2);
}

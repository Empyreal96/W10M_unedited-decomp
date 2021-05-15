// KseDriverUnloadImage 
 
int __fastcall KseDriverUnloadImage(int a1, int a2, int a3, int a4)
{
  int v4; // r3
  unsigned int v5; // r4
  int v7[8]; // [sp+0h] [bp-20h] BYREF

  v7[0] = a4;
  if ( !a1 )
    return -1073741811;
  v4 = dword_6416D4;
  __dmb(0xBu);
  if ( v4 != 2 )
    return -1073741637;
  if ( (KseEngine & 1) != 0 )
    return -1073741637;
  v5 = *(_DWORD *)(a1 + 24);
  if ( MmIsSessionAddress(v5) )
    return -1073741637;
  if ( KsepIsModuleShimmed((int)&KseEngine, v5, v7) )
    return sub_7CEB9C();
  return 0;
}

// PopFxPluginWork 
 
int __fastcall PopFxPluginWork(int a1)
{
  int v2; // r6
  unsigned int *v3; // r7
  int v4; // r5
  int result; // r0
  unsigned int v6; // r2
  unsigned int v7; // r2
  _BYTE v8[48]; // [sp+0h] [bp-30h] BYREF

  v2 = *(_DWORD *)(a1 + 20);
  v3 = (unsigned int *)(a1 + 16);
  do
  {
    v4 = PopFxEnableWorkOrderWatchdog(a1);
    result = PopPluginWork(v2, v8);
    if ( result )
      result = PopFxProcessWork(v2, v8);
    if ( v4 )
    {
      result = KeCancelTimer(v4);
      if ( !result )
        sub_53F8F8();
    }
    __dmb(0xBu);
    do
    {
      v6 = __ldrex(v3);
      v7 = v6 - 1;
    }
    while ( __strex(v7, v3) );
    __dmb(0xBu);
  }
  while ( v7 );
  return result;
}

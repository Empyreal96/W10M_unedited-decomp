// PfSnPrefetchScenario 
 
int __fastcall PfSnPrefetchScenario(unsigned int a1, char a2, int a3, unsigned int a4)
{
  int v6; // r0
  _DWORD *v7; // r6
  unsigned int v8; // r4
  unsigned int v9; // r1
  unsigned int v10; // r0
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r1
  unsigned int v15[4]; // [sp+0h] [bp-10h] BYREF

  v15[0] = a4;
  v6 = ExAllocatePoolWithTag(512, 152, 1632658243);
  v7 = (_DWORD *)v6;
  if ( !v6 )
  {
    v13 = -1073741670;
LABEL_13:
    if ( a1 )
      ExFreePoolWithTag(a1);
    return v13;
  }
  PfSnAsyncContextInitialize(v6, a1, v15, (a2 & 0x10) != 0);
  __pld(v15);
  a1 = 0;
  v8 = v15[0] & 0xFFFFFFFE;
  v9 = (v15[0] & 0xFFFFFFFE) + 2;
  do
    v10 = __ldrex(v15);
  while ( v10 == v8 && __strex(v9, v15) );
  __dmb(0xBu);
  if ( v10 != v8 )
    return sub_808F20(v10, v9, v15);
  v12 = KeQueryPriorityThread(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  ExQueueWorkItem(v7, v12 + 32);
  v13 = 0;
  do
    v14 = __ldrex(v15);
  while ( !v14 && __strex(1u, v15) );
  __dmb(0xBu);
  if ( v14 && v14 != 1 )
  {
    ExfWaitForRundownProtectionRelease(v15, v14);
    goto LABEL_13;
  }
  return v13;
}
